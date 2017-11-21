#include "TextDataModel.hpp"

TextDataModel::TextDataModel() {}

unsigned int TextDataModel::nPorts(PortType portType) const {
  unsigned int result;

  if (portType == PortType::In)
    result = 2;
  else
    result = 1;

  return result;
}

NodeDataType  TextDataModel::dataType(PortType type, PortIndex index) const {
  if (type == PortType::In) {
    if (index == 0)
      return StyleData().type();
    else
      return StringData().type();
  } else {
    return TextData().type();
  }
}

std::shared_ptr<NodeData> TextDataModel::outData(PortIndex) {
  return _text;
}

void TextDataModel::setInData(std::shared_ptr<NodeData> data, PortIndex portIndex) {
  if (portIndex == 0) {
    PortIndex const outPortIndex = 0;

    auto styleData = std::dynamic_pointer_cast<StyleData>(data);
    _style = styleData;
    auto stl = _style.lock();

    if (stl) {
      modelValidationState = NodeValidationState::Valid;
      modelValidationError = QString();
      _text->setStyle(&(*styleData));
    } else {
      modelValidationState = NodeValidationState::Warning;
      modelValidationError = QStringLiteral("Missing or incorrect inputs");
      _style.reset();
    }
    emit dataUpdated(outPortIndex);

  } else {
    PortIndex const outPortIndex = 0;

    auto strData = std::dynamic_pointer_cast<StringData>(data);
    _str = strData;
    auto str = _str.lock();

    if (str) {
      modelValidationState = NodeValidationState::Valid;
      modelValidationError = QString();
      _text->setText(strData->text());
    } else {
      modelValidationState = NodeValidationState::Warning;
      modelValidationError = QStringLiteral("Missing or incorrect inputs");
      _str.reset();
    }
    emit dataUpdated(outPortIndex);
  }
}

NodeValidationState TextDataModel::validationState() const {
  return modelValidationState;
}

QString TextDataModel::validationMessage() const {
  return modelValidationError;
}
