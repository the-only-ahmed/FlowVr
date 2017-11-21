#include "TransformDataModel.hpp"

#include <QtCore/QJsonValue>
#include <QtGui/QDoubleValidator>

unsigned int TransformDataModel::nPorts(PortType portType) const {
  unsigned int result = 1;

  switch (portType) {
    case PortType::In:
      result = 3;
      break;
    case PortType::Out:
      result = 1;
    default:
      break;
  }

  return result;
}

void TransformDataModel::setInData(std::shared_ptr<NodeData> data, PortIndex portIndex) {
  auto vector3Data = std::dynamic_pointer_cast<Vector3Data>(data);
  //PortIndex const outPortIndex = 0;

  switch (portIndex) {
    case 0:
      _transform->setTranslation(&(*vector3Data));
      break;
    case 1:
      _transform->setRotation(&(*vector3Data));
      break;
    case 2:
      _transform->setScale(&(*vector3Data));
      break;
  }

  /*if (portIndex == 0) {

    _translate = vector3Data;
    auto vec = _translate.lock();

    if (vec) {
      modelValidationState = NodeValidationState::Valid;
      modelValidationError = QString();
      _transform->setPosition(&(*vector3Data));
    } else {
      modelValidationState = NodeValidationState::Warning;
      modelValidationError = QStringLiteral("Missing or incorrect inputs");
      _translate.reset();
    }
  }*/

    //emit dataUpdated(outPortIndex);
}

NodeDataType TransformDataModel::dataType(PortType type, PortIndex index) const {
  if (type == PortType::In) {
    switch (index) {
      case 0:
        return Vector3Data().type("translate");
      case 1:
        return Vector3Data().type("rotation");
      default:
        return Vector3Data().type("scale");
    }
  } else
    return TransformData().type();
}

std::shared_ptr<NodeData> TransformDataModel::outData(PortIndex) {
  return _transform;
}

NodeValidationState TransformDataModel::validationState() const {
  return modelValidationState;
}

QString TransformDataModel::validationMessage() const {
  return modelValidationError;
}
