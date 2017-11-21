#include "SphereDataModel.hpp"

SphereDataModel::SphereDataModel() {}

unsigned int SphereDataModel::nPorts(PortType portType) const {
  unsigned int result;

  if (portType == PortType::In)
    result = 6;
  else
    result = 1;

  return result;
}

NodeDataType  SphereDataModel::dataType(PortType type, PortIndex index) const {
  if (type == PortType::In) {
    switch (index) {
      case 0:
        return StyleData().type();
      case 1:
        return DecimalData().type("heightSegments");
      case 2:
        return DecimalData().type("widthSegments");
      case 3:
        return DecimalData().type("radius");
      case 4:
        return BooleanData().type("lit");
      default:
        return BooleanData().type("wireframe");
    }
  } else {
    return SphereData().type();
  }
}

std::shared_ptr<NodeData> SphereDataModel::outData(PortIndex) {
  return _sphere;
}

void SphereDataModel::setInData(std::shared_ptr<NodeData> data, PortIndex portIndex) {
  if (portIndex == 0) {
    PortIndex const outPortIndex = 0;

    auto styleData = std::dynamic_pointer_cast<StyleData>(data);
    _style = styleData;
    auto stl = _style.lock();

    if (stl) {
      modelValidationState = NodeValidationState::Valid;
      modelValidationError = QString();
      _sphere->setStyle(&(*styleData));
    } else {
      modelValidationState = NodeValidationState::Warning;
      modelValidationError = QStringLiteral("Missing or incorrect inputs");
      _style.reset();
    }
    emit dataUpdated(outPortIndex);
  } else if (portIndex < 4) {
    PortIndex const outPortIndex = 0;

    auto floatData = std::dynamic_pointer_cast<DecimalData>(data);
    switch (portIndex) {
      case 1:
        _sphere->setHeightSegments(floatData->number());
        break;
      case 2:
        _sphere->setWidthSegments(floatData->number());
        break;
      case 3:
        _sphere->setRadius(floatData->number());
      }
    emit dataUpdated(outPortIndex);
  } else {
    PortIndex const outPortIndex = 0;
    auto boolData = std::dynamic_pointer_cast<BooleanData>(data);

    if (portIndex == 4) {
      _lit = boolData;
      auto stl = _lit.lock();

      if (stl)
        _sphere->setLit(boolData->getValue());
      else
        boolData.reset();
    } else {
      _wireframe = boolData;
      auto stl = _wireframe.lock();

      if (stl)
        _sphere->setWireframe(boolData->getValue());
      else
        boolData.reset();
    }

    emit dataUpdated(outPortIndex);
  }
}

NodeValidationState SphereDataModel::validationState() const {
  return modelValidationState;
}

QString SphereDataModel::validationMessage() const {
  return modelValidationError;
}
