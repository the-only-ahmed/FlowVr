#include "SceneDataModel.hpp"

SceneDataModel::SceneDataModel() {}

unsigned int SceneDataModel::nPorts(PortType portType) const {
  unsigned int result;

  if (portType == PortType::In)
    result = 1;
  else
    result = 1;

  return result;
}

NodeDataType  SceneDataModel::dataType(PortType type, PortIndex index) const {
  if (type == PortType::In) {
    return StyleData().type();
  } else {
    return SceneData().type();
  }
}

std::shared_ptr<NodeData> SceneDataModel::outData(PortIndex) {
  return _scene;
}

void SceneDataModel::setInData(std::shared_ptr<NodeData> data, PortIndex portIndex) {
  if (portIndex == 0) {
    PortIndex const outPortIndex = 0;

    auto styleData = std::dynamic_pointer_cast<StyleData>(data);
    _style = styleData;
    auto stl = _style.lock();

    if (stl) {
      modelValidationState = NodeValidationState::Valid;
      modelValidationError = QString();
      _scene->setStyle(&(*styleData));
    } else {
      modelValidationState = NodeValidationState::Warning;
      modelValidationError = QStringLiteral("Missing or incorrect inputs");
      _style.reset();
    }
    emit dataUpdated(outPortIndex);
  }
}

NodeValidationState SceneDataModel::validationState() const {
  return modelValidationState;
}

QString SceneDataModel::validationMessage() const {
  return modelValidationError;
}
