#include "Vector2SourceDataModel.hpp"

#include <QtCore/QJsonValue>
#include <QtGui/QDoubleValidator>

unsigned int Vector2SourceDataModel::nPorts(PortType portType) const {
  unsigned int result = 1;

  switch (portType) {
    case PortType::In:
      result = 2;
      break;
    case PortType::Out:
      result = 1;
    default:
      break;
  }

  return result;
}

void Vector2SourceDataModel::setInData(std::shared_ptr<NodeData> data, PortIndex portIndex) {
  auto numberData = std::dynamic_pointer_cast<DecimalData>(data);

  if (portIndex == 0) {
    _x = numberData;
  } else {
    _y = numberData;
  }

  {
    PortIndex const outPortIndex = 0;

    auto n1 = _x.lock();
    auto n2 = _y.lock();

    if (n1 && n2) {
      modelValidationState = NodeValidationState::Valid;
      modelValidationError = QString();
      _v2 = std::make_shared<Vector2Data>(n1->number(), n2->number());
    } else {
      modelValidationState = NodeValidationState::Warning;
      modelValidationError = QStringLiteral("Missing or incorrect inputs");
      _v2.reset();
    }

    emit dataUpdated(outPortIndex);
  }
}

NodeDataType Vector2SourceDataModel::dataType(PortType p, PortIndex index) const {
  if (p == PortType::In) {
    switch (index) {
      case 0:
        return DecimalData().type("x");
      default:
        return DecimalData().type("y");
      }
  } else
    return Vector2Data().type();
}

std::shared_ptr<NodeData> Vector2SourceDataModel::outData(PortIndex) {
  return _v2;
}

NodeValidationState Vector2SourceDataModel::validationState() const {
  return modelValidationState;
}

QString Vector2SourceDataModel::validationMessage() const {
  return modelValidationError;
}
