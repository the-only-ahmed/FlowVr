#include "SourceDataModel.hpp"

SourceDataModel::SourceDataModel() {}

unsigned int SourceDataModel::nPorts(PortType portType) const {
  unsigned int result;

  if (portType == PortType::In)
    result = 2;
  else
    result = 1;

  return result;
}

NodeDataType  SourceDataModel::dataType(PortType type, PortIndex index) const {
  if (type == PortType::In) {
    if (index == 0)
      return FileData().type("object");
    else
      return FileData().type("material");
  } else {
    return SourceData().type();
  }
}

std::shared_ptr<NodeData> SourceDataModel::outData(PortIndex) {
  return _source;
}

void SourceDataModel::setInData(std::shared_ptr<NodeData> data, PortIndex portIndex) {
  PortIndex const outPortIndex = 0;
  auto fileData = std::dynamic_pointer_cast<FileData>(data);

  if (portIndex == 0) {
    _object = fileData;
    auto obj = _object.lock();

    if (obj) {
      modelValidationState = NodeValidationState::Valid;
      modelValidationError = QString();
      _source->setObject(fileData->getPath());
    } else {
      modelValidationState = NodeValidationState::Warning;
      modelValidationError = QStringLiteral("Missing or incorrect inputs");
      _object.reset();
    }
  } else {
    _material = fileData;
    auto mtl = _material.lock();

    if (mtl) {
      modelValidationState = NodeValidationState::Valid;
      modelValidationError = QString();
      _source->setMaterial(fileData->getPath());
    } else {
      modelValidationState = NodeValidationState::Warning;
      modelValidationError = QStringLiteral("Missing or incorrect inputs");
      _material.reset();
    }
  }

  emit dataUpdated(outPortIndex);
}

NodeValidationState SourceDataModel::validationState() const {
  return modelValidationState;
}

QString SourceDataModel::validationMessage() const {
  return modelValidationError;
}
