#pragma once

#include <QtCore/QObject>
#include <QtWidgets/QLabel>

#include "PointLightData.hpp"
#include "DecimalData.hpp"

#include <nodes/NodeDataModel>

#include <iostream>

using QtNodes::PortType;
using QtNodes::PortIndex;
using QtNodes::NodeData;
using QtNodes::NodeDataModel;
using QtNodes::NodeValidationState;

class PointLightDataModel : public NodeDataModel {
  Q_OBJECT

public:
  PointLightDataModel();

  virtual
  ~PointLightDataModel() {}

public:

  QString  caption() const override  { return QString("PointLight"); }

  bool  captionVisible() const override { return true; }

  QString  name() const override  { return QString("PointLight"); }

  std::unique_ptr<NodeDataModel>  clone() const override {
    return std::make_unique<PointLightDataModel>();
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

  std::shared_ptr<PointLightData> _light = std::make_shared<PointLightData>();

  NodeValidationState modelValidationState = NodeValidationState::Valid;
  QString modelValidationError = QString();
};
