#pragma once

#include <QtCore/QObject>
#include <QtWidgets/QLabel>

#include "TextData.hpp"

#include <nodes/NodeDataModel>

#include <iostream>

using QtNodes::PortType;
using QtNodes::PortIndex;
using QtNodes::NodeData;
using QtNodes::NodeDataModel;
using QtNodes::NodeValidationState;

class TextDataModel : public NodeDataModel {
  Q_OBJECT

public:
  TextDataModel();

  virtual
  ~TextDataModel() {}

public:

  QString  caption() const override  { return QString("Text"); }

  bool  captionVisible() const override { return true; }

  QString  name() const override  { return QString("Text"); }

  std::unique_ptr<NodeDataModel>  clone() const override {
    return std::make_unique<TextDataModel>();
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
  std::weak_ptr<StringData> _str;

  std::shared_ptr<TextData> _text = std::make_shared<TextData>();

  NodeValidationState modelValidationState = NodeValidationState::Valid;
  QString modelValidationError = QString();
};
