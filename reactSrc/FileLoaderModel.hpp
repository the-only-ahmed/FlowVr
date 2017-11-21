#pragma once

#include <iostream>

#include <QtCore/QObject>
#include <QtWidgets/QLabel>

#include <nodes/DataModelRegistry>
#include <nodes/NodeDataModel>

#include "FileData.hpp"

using QtNodes::PortType;
using QtNodes::PortIndex;
using QtNodes::NodeData;
using QtNodes::NodeDataType;
using QtNodes::NodeDataModel;
using QtNodes::NodeValidationState;

/// The model dictates the number of inputs and outputs for the Node.
/// In this example it has no logic.
class FileLoaderModel : public NodeDataModel {
  Q_OBJECT

public:
  FileLoaderModel();

  virtual
  ~FileLoaderModel() {}

public:

  QString  caption() const override  { return QString("File"); }

  QString  name() const override { return QString("FileLoader"); }

  std::unique_ptr<NodeDataModel>  clone() const override  { return std::make_unique<FileLoaderModel>(); }

public:

  virtual QString  modelName() const  { return QString("Source File"); }

  unsigned int  nPorts(PortType portType) const override;

  NodeDataType  dataType(PortType portType, PortIndex portIndex) const override;

  std::shared_ptr<NodeData>  outData(PortIndex port) override;

  void  setInData(std::shared_ptr<NodeData>, int) override  { }

  QWidget *embeddedWidget() override { return _label; }

  bool  resizable() const override { return true; }

protected:

  bool  eventFilter(QObject *object, QEvent *event) override;

private:

  QLabel  *_label;

  std::shared_ptr<FileData> _file = std::make_shared<FileData>();
};
