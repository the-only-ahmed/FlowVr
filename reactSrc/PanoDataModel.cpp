#include "PanoDataModel.hpp"

PanoDataModel::PanoDataModel() {}

unsigned int PanoDataModel::nPorts(PortType portType) const {
  unsigned int result;

  if (portType == PortType::In)
    result = 2;
  else
    result = 1;

  return result;
}

NodeDataType  PanoDataModel::dataType(PortType type, PortIndex index) const {
  if (type == PortType::In) {
    if (index == 0)
      return StyleData().type();
    else
      return PixmapData().type();
  } else {
    return PanoData().type();
  }
}

std::shared_ptr<NodeData> PanoDataModel::outData(PortIndex) {
  return _pano;
}

void PanoDataModel::setInData(std::shared_ptr<NodeData> data, PortIndex portIndex) {
  if (portIndex == 0) {
    PortIndex const outPortIndex = 0;

    auto styleData = std::dynamic_pointer_cast<StyleData>(data);
    _style = styleData;
    auto stl = _style.lock();

    if (stl) {
      modelValidationState = NodeValidationState::Valid;
      modelValidationError = QString();
      _pano->setStyle(&(*styleData));
    } else {
      modelValidationState = NodeValidationState::Warning;
      modelValidationError = QStringLiteral("Missing or incorrect inputs");
      _style.reset();
    }
    emit dataUpdated(outPortIndex);

  } else {
    PortIndex const outPortIndex = 0;

    auto photoData = std::dynamic_pointer_cast<PixmapData>(data);
    _picture = photoData;
    auto pic = _picture.lock();

    if (pic) {
      modelValidationState = NodeValidationState::Valid;
      modelValidationError = QString();
      _pano->setPicture(photoData->getImage());
      _pano->setPath(photoData->getPath());
    } else {
      modelValidationState = NodeValidationState::Warning;
      modelValidationError = QStringLiteral("Missing or incorrect inputs");
      _picture.reset();
    }
    emit dataUpdated(outPortIndex);
  }
}

NodeValidationState PanoDataModel::validationState() const {
  return modelValidationState;
}

QString PanoDataModel::validationMessage() const {
  return modelValidationError;
}
