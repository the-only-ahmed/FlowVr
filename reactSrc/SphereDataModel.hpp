#pragma once

#include <QtCore/QObject>
#include <QtWidgets/QLabel>

#include "SphereData.hpp"
#include "DecimalData.hpp"
#include "BooleanData.hpp"

#include <nodes/NodeDataModel>

#include <iostream>

using QtNodes::PortType;
using QtNodes::PortIndex;
using QtNodes::NodeData;
using QtNodes::NodeDataModel;
using QtNodes::NodeValidationState;

class SphereDataModel : public NodeDataModel {
  Q_OBJECT

public:
  SphereDataModel();

  virtual
  ~SphereDataModel() {}

public:

  QString  caption() const override  { return QString("Sphere"); }

  bool  captionVisible() const override { return true; }

  QString  name() const override  { return QString("Sphere"); }

  std::unique_ptr<NodeDataModel>  clone() const override {
    return std::make_unique<SphereDataModel>();
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

  std::weak_ptr<BooleanData> _lit;
  std::weak_ptr<BooleanData> _wireframe;

  std::shared_ptr<SphereData> _sphere = std::make_shared<SphereData>();

  NodeValidationState modelValidationState = NodeValidationState::Valid;
  QString modelValidationError = QString();
};
