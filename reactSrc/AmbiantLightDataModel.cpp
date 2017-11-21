#include "AmbiantLightDataModel.hpp"

AmbiantLightDataModel::AmbiantLightDataModel() {}

unsigned int AmbiantLightDataModel::nPorts(PortType portType) const {
  unsigned int result;

  if (portType == PortType::In)
    result = 2;
  else
    result = 1;

  return result;
}

NodeDataType  AmbiantLightDataModel::dataType(PortType type, PortIndex index) const {
  if (type == PortType::In) {
    switch (index) {
      case 0:
        return StyleData().type();
      default:
        return DecimalData().type("intensity");
    }
  } else {
    return AmbiantLightData().type();
  }
}

std::shared_ptr<NodeData> AmbiantLightDataModel::outData(PortIndex) {
  return _light;
}

void AmbiantLightDataModel::setInData(std::shared_ptr<NodeData> data, PortIndex portIndex) {
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
  } else {
    PortIndex const outPortIndex = 0;

    auto floatData = std::dynamic_pointer_cast<DecimalData>(data);
    _intensity = floatData;
    auto tmp = _intensity.lock();

    if (tmp) {
      _light->setIntensity(floatData->number());
      modelValidationState = NodeValidationState::Valid;
      modelValidationError = QString();
    } else {
      modelValidationState = NodeValidationState::Warning;
      modelValidationError = QStringLiteral("Missing or incorrect inputs");
      _intensity.reset();
    }

    emit dataUpdated(outPortIndex);
  }
}

NodeValidationState AmbiantLightDataModel::validationState() const {
  return modelValidationState;
}

QString AmbiantLightDataModel::validationMessage() const {
  return modelValidationError;
}
