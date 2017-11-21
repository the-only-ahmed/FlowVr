#pragma once

#include <QtCore/QObject>
#include <QtWidgets/QLineEdit>

#include <nodes/NodeDataModel>

#include <iostream>

#include "Vector3Data.hpp"
#include "DecimalData.hpp"

using QtNodes::PortType;
using QtNodes::PortIndex;
using QtNodes::NodeData;
using QtNodes::NodeDataType;
using QtNodes::NodeDataModel;
using QtNodes::NodeValidationState;

/// The model dictates the number of inputs and outputs for the Node.
/// In this example it has no logic.
class Vector3SourceDataModel : public NodeDataModel {
  Q_OBJECT

public:
  Vector3SourceDataModel() {};

  virtual
  ~Vector3SourceDataModel() {}

public:

  QString  caption() const override  { return QStringLiteral("Vector3"); }

  bool  captionVisible() const override  { return true; }

  QString  name() const override  { return QStringLiteral("Vector3"); }

  std::unique_ptr<NodeDataModel>  clone() const override  { return std::make_unique<Vector3SourceDataModel>(); }

public:

  unsigned int  nPorts(PortType portType) const override;

  NodeDataType  dataType(PortType portType, PortIndex portIndex) const override;

  std::shared_ptr<NodeData>  outData(PortIndex port) override;

  void  setInData(std::shared_ptr<NodeData>, int) override;

  QWidget *embeddedWidget() override { return nullptr; }

  NodeValidationState  validationState() const override;

  QString  validationMessage() const override;

private:

  std::weak_ptr<DecimalData> _x;
  std::weak_ptr<DecimalData> _y;
  std::weak_ptr<DecimalData> _z;

  std::shared_ptr<Vector3Data> _v3;

  NodeValidationState modelValidationState = NodeValidationState::Warning;
  QString modelValidationError = QStringLiteral("Missing or incorrect inputs");
};
