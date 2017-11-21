#include "StyleSourceDataModel.hpp"

#include <QtCore/QJsonValue>
#include <QtGui/QDoubleValidator>

unsigned int StyleSourceDataModel::nPorts(PortType portType) const {
  unsigned int result = 1;

  switch (portType) {
    case PortType::In:
      result = 10;
      break;
    case PortType::Out:
      result = 1;
    default:
      break;
  }

  return result;
}

void StyleSourceDataModel::setInData(std::shared_ptr<NodeData> data, PortIndex portIndex) {
  if (portIndex == 0 || portIndex == 1 || portIndex == 2 || portIndex == 7) {
    auto numberData = std::dynamic_pointer_cast<DecimalData>(data);

    if (portIndex == 0)
      _style->setFontSize(numberData->number());
    else if (portIndex == 1)
      _style->setPaddingLeft(numberData->number());
    else if (portIndex == 2)
      _style->setPaddingRight(numberData->number());
    else
      _style->setOpacity(numberData->number());

  } else if (portIndex == 3 || portIndex == 4 || portIndex == 5 || portIndex == 8) {
    auto strData = std::dynamic_pointer_cast<StringData>(data);

    if (portIndex == 3)
      _style->setBackgroundColor(strData->text());
    else if (portIndex == 4)
      _style->setTextAlignment(strData->text());
    else if (portIndex == 5)
      _style->setTextAlignmentVertical(strData->text());
    else
      _style->setColor(strData->text());

  } else if (portIndex == 6) {
    auto vector2Data = std::dynamic_pointer_cast<Vector2Data>(data);

    PortIndex const outPortIndex = 0;

    _layoutOrigin = vector2Data;
    auto lay = _layoutOrigin.lock();

    if (lay) {
      modelValidationState = NodeValidationState::Valid;
      modelValidationError = QString();
      _style->setLayoutOrigin(&(*vector2Data));
    } else {
      modelValidationState = NodeValidationState::Warning;
      modelValidationError = QStringLiteral("Missing or incorrect inputs");
      _transform.reset();
    }

    emit dataUpdated(outPortIndex);
  } else {
    auto transformData = std::dynamic_pointer_cast<TransformData>(data);

    PortIndex const outPortIndex = 0;

    _transform = transformData;
    auto pos = _transform.lock();

    if (pos) {
      modelValidationState = NodeValidationState::Valid;
      modelValidationError = QString();
      _style->setTransform(&(*transformData));
    } else {
      modelValidationState = NodeValidationState::Warning;
      modelValidationError = QStringLiteral("Missing or incorrect inputs");
      _transform.reset();
    }

    emit dataUpdated(outPortIndex);
  }
}

NodeDataType StyleSourceDataModel::dataType(PortType type, PortIndex index) const {
  if (type == PortType::In) {
    switch (index) {
      case 0:
        return DecimalData().type("fontSize");
      case 1:
        return DecimalData().type("paddingLeft");
      case 2:
        return DecimalData().type("paddingRight");
      case 3:
        return StringData().type("backgroundColor");
      case 4:
        return StringData().type("textAlign");
      case 5:
        return StringData().type("textAlignVertical");
      case 6:
        return Vector2Data().type("layoutOrigin");
      case 7:
        return DecimalData().type("opacity");
      case 8:
        return StringData().type("color");
      default:
        return TransformData().type();
    }
  } else
    return StyleData().type();
}

std::shared_ptr<NodeData> StyleSourceDataModel::outData(PortIndex) {
  return _style;
}

NodeValidationState StyleSourceDataModel::validationState() const {
  return modelValidationState;
}

QString StyleSourceDataModel::validationMessage() const {
  return modelValidationError;
}
