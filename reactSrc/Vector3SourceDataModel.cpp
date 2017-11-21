#include "Vector3SourceDataModel.hpp"

#include <QtCore/QJsonValue>
#include <QtGui/QDoubleValidator>

unsigned int Vector3SourceDataModel::nPorts(PortType portType) const {
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

void Vector3SourceDataModel::setInData(std::shared_ptr<NodeData> data, PortIndex portIndex) {
  auto numberData = std::dynamic_pointer_cast<DecimalData>(data);

  if (portIndex == 0) {
    _x = numberData;
  } else if (portIndex == 1) {
    _y = numberData;
  } else {
    _z = numberData;
  }

  {
    PortIndex const outPortIndex = 0;

    auto n1 = _x.lock();
    auto n2 = _y.lock();
    auto n3 = _z.lock();

    if (n1 && n2 && n3) {
      modelValidationState = NodeValidationState::Valid;
      modelValidationError = QString();
      _v3 = std::make_shared<Vector3Data>(n1->number(), n2->number(), n3->number());
    } else {
      modelValidationState = NodeValidationState::Warning;
      modelValidationError = QStringLiteral("Missing or incorrect inputs");
      _v3.reset();
    }

    emit dataUpdated(outPortIndex);
  }
}

NodeDataType Vector3SourceDataModel::dataType(PortType p, PortIndex index) const {
  if (p == PortType::In) {
    switch (index) {
      case 0:
        return DecimalData().type("x");
      case 1:
        return DecimalData().type("y");
      default:
        return DecimalData().type("z");
    }
  } else
    return Vector3Data().type();
}

std::shared_ptr<NodeData> Vector3SourceDataModel::outData(PortIndex) {
  return _v3;
}

NodeValidationState Vector3SourceDataModel::validationState() const {
  return modelValidationState;
}

QString Vector3SourceDataModel::validationMessage() const {
  return modelValidationError;
}
