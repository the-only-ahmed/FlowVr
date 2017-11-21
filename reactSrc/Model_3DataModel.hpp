#pragma once

#include <QtCore/QObject>
#include <QtWidgets/QLabel>

#include "Model_3Data.hpp"
#include "BooleanData.hpp"
#include "StringData.hpp"

#include <nodes/NodeDataModel>

#include <iostream>

using QtNodes::PortType;
using QtNodes::PortIndex;
using QtNodes::NodeData;
using QtNodes::NodeDataModel;
using QtNodes::NodeValidationState;

class Model_3DataModel : public NodeDataModel {
  Q_OBJECT

public:
  Model_3DataModel();

  virtual
  ~Model_3DataModel() {}

public:

  QString  caption() const override  { return QString("3D Model"); }

  bool  captionVisible() const override { return true; }

  QString  name() const override  { return QString("3D Model"); }

  std::unique_ptr<NodeDataModel>  clone() const override {
    return std::make_unique<Model_3DataModel>();
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
  std::weak_ptr<SourceData> _source;

  std::weak_ptr<StringData> _texture;
  std::weak_ptr<BooleanData> _lit;
  std::weak_ptr<BooleanData> _wireframe;

  std::shared_ptr<Model_3Data> _model = std::make_shared<Model_3Data>();

  NodeValidationState modelValidationState = NodeValidationState::Valid;
  QString modelValidationError = QString();
};
