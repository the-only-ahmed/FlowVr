#pragma once

#include <QtCore/QObject>
#include <QtWidgets/QLabel>

#include "PanoData.hpp"

#include <nodes/NodeDataModel>

#include <iostream>

using QtNodes::PortType;
using QtNodes::PortIndex;
using QtNodes::NodeData;
using QtNodes::NodeDataModel;
using QtNodes::NodeValidationState;

class PanoDataModel : public NodeDataModel {
  Q_OBJECT

public:
  PanoDataModel();

  virtual
  ~PanoDataModel() {}

public:

  QString  caption() const override  { return QString("Pano"); }

  bool  captionVisible() const override { return true; }

  QString  name() const override  { return QString("Pano"); }

  std::unique_ptr<NodeDataModel>  clone() const override {
    return std::make_unique<PanoDataModel>();
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
  std::weak_ptr<PixmapData> _picture;

  std::shared_ptr<PanoData> _pano = std::make_shared<PanoData>();

  NodeValidationState modelValidationState = NodeValidationState::Valid;
  QString modelValidationError = QString();
};
