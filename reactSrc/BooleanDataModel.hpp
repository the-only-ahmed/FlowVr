#pragma once

#include <QtCore/QObject>
#include <QListWidget>

#include <nodes/NodeDataModel>
#include <QListWidgetItem>

#include <iostream>

class BooleanData;

using QtNodes::PortType;
using QtNodes::PortIndex;
using QtNodes::NodeData;
using QtNodes::NodeDataType;
using QtNodes::NodeDataModel;
using QtNodes::NodeValidationState;

/// The model dictates the number of inputs and outputs for the Node.
/// In this example it has no logic.
class BooleanDataModel : public NodeDataModel {
  Q_OBJECT

public:
  BooleanDataModel();

  virtual
  ~BooleanDataModel() {}

public:

  QString  caption() const override  { return QStringLiteral("Boolean"); }

  bool  captionVisible() const override  { return true; }

  QString  name() const override  { return QStringLiteral("Boolean"); }

  std::unique_ptr<NodeDataModel>  clone() const override  { return std::make_unique<BooleanDataModel>(); }

public:

  unsigned int  nPorts(PortType portType) const override;

  NodeDataType  dataType(PortType portType, PortIndex portIndex) const override;

  std::shared_ptr<NodeData>  outData(PortIndex port) override;

  void  setInData(std::shared_ptr<NodeData>, int) override  { }

  QWidget *embeddedWidget() override { return _widget; }

  NodeValidationState  validationState() const override;

  QString  validationMessage() const override;

private slots:
  void onListMailItemClicked(QListWidgetItem* item);;

private:

  std::shared_ptr<BooleanData> _bool = std::make_shared<BooleanData>();;

  QWidget *_widget;
  QListWidget * _listWidget;

  NodeValidationState modelValidationState = NodeValidationState::Valid;
  QString modelValidationError = QString();
};
