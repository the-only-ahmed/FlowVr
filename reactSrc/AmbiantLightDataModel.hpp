#pragma once

#include <QtCore/QObject>

#include "AmbiantLightData.hpp"
#include "DecimalData.hpp"

#include <nodes/NodeDataModel>

#include <iostream>

using QtNodes::PortType;
using QtNodes::PortIndex;
using QtNodes::NodeData;
using QtNodes::NodeDataModel;
using QtNodes::NodeValidationState;

class AmbiantLightDataModel : public NodeDataModel {
  Q_OBJECT

public:
  AmbiantLightDataModel();

  virtual
  ~AmbiantLightDataModel() {}

public:

  QString  caption() const override  { return QString("AmbiantLight"); }

  bool  captionVisible() const override { return true; }

  QString  name() const override  { return QString("AmbiantLight"); }

  std::unique_ptr<NodeDataModel>  clone() const override {
    return std::make_unique<AmbiantLightDataModel>();
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
  std::weak_ptr<DecimalData> _intensity;

  std::shared_ptr<AmbiantLightData> _light = std::make_shared<AmbiantLightData>();

  NodeValidationState modelValidationState = NodeValidationState::Valid;
  QString modelValidationError = QString();
};
