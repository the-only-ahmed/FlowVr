#pragma once

#include <QtCore/QObject>
#include <QtWidgets/QLabel>

#include "SourceData.hpp"
#include "FileData.hpp"

#include <nodes/NodeDataModel>

#include <iostream>

using QtNodes::PortType;
using QtNodes::PortIndex;
using QtNodes::NodeData;
using QtNodes::NodeDataModel;
using QtNodes::NodeValidationState;

class SourceDataModel : public NodeDataModel {
  Q_OBJECT

public:
  SourceDataModel();

  virtual
  ~SourceDataModel() {}

public:

  QString  caption() const override  { return QString("Source"); }

  bool  captionVisible() const override { return true; }

  QString  name() const override  { return QString("Source"); }

  std::unique_ptr<NodeDataModel>  clone() const override {
    return std::make_unique<SourceDataModel>();
  }

public:

  unsigned int nPorts(PortType portType) const override;

  NodeDataType  dataType(PortType portType, PortIndex portIndex) const override;

  std::shared_ptr<NodeData>  outData(PortIndex port) override;

  QWidget *embeddedWidget() override { return nullptr; }

  void  setInData(std::shared_ptr<NodeData>, int) override;

  NodeValidationState  validationState() const override;

  QString  validationMessage() const override;

private:
  std::weak_ptr<FileData> _object;
  std::weak_ptr<FileData> _material;

  std::shared_ptr<SourceData> _source = std::make_shared<SourceData>();

  NodeValidationState modelValidationState = NodeValidationState::Valid;
  QString modelValidationError = QString();
};
