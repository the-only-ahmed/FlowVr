#include "BooleanDataModel.hpp"

#include <QtCore/QJsonValue>
#include <QtGui/QDoubleValidator>

#include "BooleanData.hpp"

BooleanDataModel::BooleanDataModel() : _widget(new QWidget()) {
  _widget->setObjectName(QStringLiteral("widget"));
  _widget->setGeometry(QRect(0, 20, 50, 40));
  _listWidget = new QListWidget(_widget);
  _listWidget->setObjectName(QStringLiteral("listWidget"));

  new QListWidgetItem(tr("true"), _listWidget);
  new QListWidgetItem(tr("false"), _listWidget);

  connect(_listWidget, SIGNAL(itemClicked(QListWidgetItem*)),
                this, SLOT(onListMailItemClicked(QListWidgetItem*)));

  // PortIndex const outPortIndex = 0;
  // if (_listWidget->currentItem() != nullptr) {
  //   const QString& s = _listWidget->currentItem()->text();
  //   // std::cout << s.toUtf8().constData() << std::endl;
  //   _bool->setValue(s == "true" ? true : false);

  // } else {
    modelValidationState = NodeValidationState::Warning;
    modelValidationError = QStringLiteral("Missing or incorrect inputs");
  // }
  // emit dataUpdated(outPortIndex);
}

void BooleanDataModel::onListMailItemClicked(QListWidgetItem* item) {
  modelValidationState = NodeValidationState::Valid;
  modelValidationError = QString();

  const QString& s = _listWidget->currentItem()->text();
  _bool->setValue(s == "true" ? true : false);
}

unsigned int BooleanDataModel::nPorts(PortType portType) const {
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

NodeDataType BooleanDataModel::dataType(PortType, PortIndex) const {
  return BooleanData().type();
}

std::shared_ptr<NodeData> BooleanDataModel::outData(PortIndex portIndex) {
  return _bool;
}

NodeValidationState BooleanDataModel::validationState() const {
  return modelValidationState;
}

QString BooleanDataModel::validationMessage() const {
  return modelValidationError;
}
