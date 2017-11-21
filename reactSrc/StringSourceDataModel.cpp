#include "StringSourceDataModel.hpp"

StringSourceDataModel::StringSourceDataModel() : _lineEdit(new QLineEdit("Default Text")) {
  connect(_lineEdit, &QLineEdit::textEdited,
          this, &StringSourceDataModel::onTextEdited);
}


unsigned int StringSourceDataModel::nPorts(PortType portType) const {
  unsigned int result = 1;

  switch (portType) {
    case PortType::In:
      result = 0;
      break;

    case PortType::Out:
      result = 1;

    default:
      break;
  }

  return result;
}


void StringSourceDataModel::onTextEdited(QString const &string) {
  Q_UNUSED(string);

  emit dataUpdated(0);
}


NodeDataType StringSourceDataModel::dataType(PortType, PortIndex) const {
  return StringData().type();
}


std::shared_ptr<NodeData> StringSourceDataModel::outData(PortIndex) {
  return std::make_shared<StringData>(_lineEdit->text());
}
