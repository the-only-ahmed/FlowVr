#pragma once

#include <QtCore/QObject>
#include <QtWidgets/QLineEdit>

#include <nodes/NodeDataModel>

#include <iostream>

#include "TransformData.hpp"

using QtNodes::PortType;
using QtNodes::PortIndex;
using QtNodes::NodeData;
using QtNodes::NodeDataType;
using QtNodes::NodeDataModel;
using QtNodes::NodeValidationState;

/// The model dictates the number of inputs and outputs for the Node.
/// In this example it has no logic.
class TransformDataModel : public NodeDataModel {
  Q_OBJECT

public:
  TransformDataModel() {};

  virtual
  ~TransformDataModel() {}

public:

  QString  caption() const override  { return QStringLiteral("Transform"); }

  bool  captionVisible() const override  { return true; }

  QString  name() const override  { return QStringLiteral("Transform"); }

  std::unique_ptr<NodeDataModel>  clone() const override  { return std::make_unique<TransformDataModel>(); }

public:

  unsigned int  nPorts(PortType portType) const override;

  NodeDataType  dataType(PortType portType, PortIndex portIndex) const override;

  std::shared_ptr<NodeData>  outData(PortIndex port) override;

  void  setInData(std::shared_ptr<NodeData>, int) override;

  QWidget *embeddedWidget() override { return nullptr; }

  NodeValidationState  validationState() const override;

  QString  validationMessage() const override;

private:

  std::weak_ptr<Vector3Data> _translate;
  std::weak_ptr<Vector3Data> _rotate;
  std::weak_ptr<Vector3Data> _scale;

  std::shared_ptr<TransformData> _transform = std::make_shared<TransformData>();

  NodeValidationState modelValidationState = NodeValidationState::Valid;
  QString modelValidationError = QString();
};
