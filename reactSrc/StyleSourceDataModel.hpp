#pragma once

#include <QtCore/QObject>
#include <QtWidgets/QLineEdit>

#include <nodes/NodeDataModel>

#include <iostream>

// #include "IntegerData.hpp"
#include "StyleData.hpp"
#include "DecimalData.hpp"
#include "StringData.hpp"

using QtNodes::PortType;
using QtNodes::PortIndex;
using QtNodes::NodeData;
using QtNodes::NodeDataType;
using QtNodes::NodeDataModel;
using QtNodes::NodeValidationState;

/// The model dictates the number of inputs and outputs for the Node.
/// In this example it has no logic.
class StyleSourceDataModel : public NodeDataModel {
  Q_OBJECT

public:
  StyleSourceDataModel() {};

  virtual
  ~StyleSourceDataModel() {}

public:

  QString  caption() const override  { return QStringLiteral("Style"); }

  bool  captionVisible() const override  { return true; }

  QString  name() const override  { return QStringLiteral("Style"); }

  std::unique_ptr<NodeDataModel>  clone() const override  { return std::make_unique<StyleSourceDataModel>(); }

public:

  unsigned int  nPorts(PortType portType) const override;

  NodeDataType  dataType(PortType portType, PortIndex portIndex) const override;

  std::shared_ptr<NodeData>  outData(PortIndex port) override;

  void  setInData(std::shared_ptr<NodeData>, int) override;

  QWidget *embeddedWidget() override { return nullptr; }

  NodeValidationState  validationState() const override;

  QString  validationMessage() const override;

private:

  std::weak_ptr<DecimalData> _fontSize;
  std::weak_ptr<DecimalData> _paddingLeft;
  std::weak_ptr<DecimalData> _paddingRight;

  std::weak_ptr<StringData> _backgroundColor;
  std::weak_ptr<StringData> _textAlign;
  std::weak_ptr<StringData> _textAlignVertical;

  std::weak_ptr<Vector2Data> _layoutOrigin;
  std::weak_ptr<TransformData> _transform;

  std::weak_ptr<DecimalData> _opacity;

  std::shared_ptr<StyleData> _style = std::make_shared<StyleData>();

  NodeValidationState modelValidationState = NodeValidationState::Valid;
  QString modelValidationError = QString();
};
