#include "PointLightDataModel.hpp"

PointLightDataModel::PointLightDataModel() {}

unsigned int PointLightDataModel::nPorts(PortType portType) const {
  unsigned int result;

  if (portType == PortType::In)
    result = 4;
  else
    result = 1;

  return result;
}

NodeDataType  PointLightDataModel::dataType(PortType type, PortIndex index) const {
  if (type == PortType::In) {
    switch (index) {
      case 0:
        return StyleData().type();
      case 1:
        return DecimalData().type("decay");
      case 2:
        return DecimalData().type("distance");
      default:
        return DecimalData().type("intensity");
    }
  } else {
    return PointLightData().type();
  }
}

std::shared_ptr<NodeData> PointLightDataModel::outData(PortIndex) {
  return _light;
}

void PointLightDataModel::setInData(std::shared_ptr<NodeData> data, PortIndex portIndex) {
  if (portIndex == 0) {
    PortIndex const outPortIndex = 0;

    auto styleData = std::dynamic_pointer_cast<StyleData>(data);
    _style = styleData;
    auto stl = _style.lock();

    if (stl) {
      modelValidationState = NodeValidationState::Valid;
      modelValidationError = QString();
      _light->setStyle(&(*styleData));
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
        _light->setDecay(floatData->number());
        break;
      case 2:
        _light->setDistance(floatData->number());
        break;
      case 3:
        _light->setIntensity(floatData->number());
      }
    emit dataUpdated(outPortIndex);
  }
}

NodeValidationState PointLightDataModel::validationState() const {
  return modelValidationState;
}

QString PointLightDataModel::validationMessage() const {
  return modelValidationError;
}
