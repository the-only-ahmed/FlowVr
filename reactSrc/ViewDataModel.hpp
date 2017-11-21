#pragma once

#include <QtCore/QObject>
#include <QtWidgets/QLabel>

#include "ViewData.hpp"

#include <nodes/NodeDataModel>

#include <iostream>

using QtNodes::PortType;
using QtNodes::PortIndex;
using QtNodes::NodeData;
using QtNodes::NodeDataModel;
using QtNodes::NodeValidationState;

class ViewDataModel : public NodeDataModel {
  Q_OBJECT

public:
  ViewDataModel();
  ~ViewDataModel();

public:

  QString  caption() const override  { return QString("View"); }

  bool  captionVisible() const override { return true; }

  QString  name() const override  { return QString("View"); }

  std::unique_ptr<NodeDataModel>  clone() const override {
    return std::make_unique<ViewDataModel>();
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
  //std::weak_ptr<ComponentNode> _childView;

  std::shared_ptr<ViewData> _view = std::make_shared<ViewData>();

  NodeValidationState modelValidationState = NodeValidationState::Valid;
  QString modelValidationError = QString();
};
