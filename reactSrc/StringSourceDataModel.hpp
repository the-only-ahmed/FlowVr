#pragma once

#include <QtCore/QObject>
#include <QtWidgets/QLineEdit>

#include "StringData.hpp"

#include <nodes/NodeDataModel>

#include <iostream>

using QtNodes::PortType;
using QtNodes::PortIndex;
using QtNodes::NodeData;
using QtNodes::NodeDataModel;

/// The model dictates the number of inputs and outputs for the Node.
/// In this example it has no logic.
class StringSourceDataModel : public NodeDataModel {
  Q_OBJECT

public:
  StringSourceDataModel();

  virtual
  ~StringSourceDataModel() {}

public:

  QString  caption() const override  { return QString("String"); }

  bool  captionVisible() const override { return false; }

  QString  name() const override  { return QString("String"); }

  std::unique_ptr<NodeDataModel>  clone() const override  { return std::make_unique<StringSourceDataModel>(); }

public:

  unsigned int  nPorts(PortType portType) const override;

  NodeDataType  dataType(PortType portType, PortIndex portIndex) const override;

  std::shared_ptr<NodeData>  outData(PortIndex port) override;

  void  setInData(std::shared_ptr<NodeData>, int) override  { }

  QWidget *embeddedWidget() override { return _lineEdit; }

private slots:

  void  onTextEdited(QString const &string);

private:

  QLineEdit * _lineEdit;
};
