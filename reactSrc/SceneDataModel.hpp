#pragma once

#include <QtCore/QObject>
#include <QtWidgets/QLabel>

#include "SceneData.hpp"
#include <nodes/NodeDataModel>

#include <iostream>

using QtNodes::PortType;
using QtNodes::PortIndex;
using QtNodes::NodeData;
using QtNodes::NodeDataModel;
using QtNodes::NodeValidationState;

class SceneDataModel : public NodeDataModel {
  Q_OBJECT

public:
  SceneDataModel();

  virtual
  ~SceneDataModel() {}

public:

  QString  caption() const override  { return QString("Scene"); }

  bool  captionVisible() const override { return true; }

  QString  name() const override  { return QString("Scene"); }

  std::unique_ptr<NodeDataModel>  clone() const override {
    return std::make_unique<SceneDataModel>();
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
  std::weak_ptr<StyleData> _style;

  std::shared_ptr<SceneData> _scene = std::make_shared<SceneData>();

  NodeValidationState modelValidationState = NodeValidationState::Valid;
  QString modelValidationError = QString();
};
