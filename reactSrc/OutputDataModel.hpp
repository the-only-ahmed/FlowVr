#pragma once

#include <QtCore/QObject>
#include <QPushButton>

#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>
#include <QFile>

#include <nodes/NodeDataModel>
#include <nodes/FlowScene>

#include <iostream>

#include "OutputNode.hpp"

using QtNodes::PortType;
using QtNodes::PortIndex;
using QtNodes::NodeData;
using QtNodes::NodeDataType;
using QtNodes::NodeDataModel;
using QtNodes::NodeValidationState;

using QtNodes::FlowScene;

/// The model dictates the number of inputs and outputs for the Node.
/// In this example it has no logic.
class OutputDataModel : public NodeDataModel {
  Q_OBJECT

public:
  OutputDataModel();

  virtual
  ~OutputDataModel() {}

public:

  QString  caption() const override  { return QStringLiteral("Output"); }

  bool  captionVisible() const override  { return true; }

  QString  name() const override  { return QStringLiteral("Output"); }

  std::unique_ptr<NodeDataModel>  clone() const override  { return std::make_unique<OutputDataModel>(); }

public:

  unsigned int  nPorts(PortType portType) const override;

  NodeDataType  dataType(PortType portType, PortIndex portIndex) const override;

  std::shared_ptr<NodeData>  outData(PortIndex port) override;

  void  setInData(std::shared_ptr<NodeData>, int) override;

  QWidget *embeddedWidget() override { return _button; }

  NodeValidationState  validationState() const override;

  QString  validationMessage() const override;

  QJsonObject  save() const override;

  void Warning(bool correct) override;

private slots:
  void handleButton();

private:
  void saveJson(QJsonDocument document, QString fileName);
  void saveXML();
  void writeToFile(std::string content);

  std::string beginJS;
  std::string endJS;
  std::string _projectName;

  QPushButton *_button = nullptr;

  std::weak_ptr<ComponentNode> _input;

  std::shared_ptr<OutputNode> _output = std::make_shared<OutputNode>();

  NodeValidationState modelValidationState = NodeValidationState::Warning;
  QString modelValidationError = QStringLiteral("Missing or incorrect inputs");
};
