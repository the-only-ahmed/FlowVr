#pragma once

#include <nodes/NodeDataModel>
#include <sstream>

#include "LightComponent.hpp"

using QtNodes::NodeData;
using QtNodes::NodeDataType;

// The class can potentially incapsulate any user data which
/// need to be transferred within the Node Editor graph
class AmbiantLightData : public LightComponent {
public:

  AmbiantLightData() : LightComponent() {}

  QString toString() const override {
    return "AmbiantLight";
  }

  QJsonObject Value() const override {
    QJsonObject modelJson;

    return modelJson;
  }

  AmbiantLightData &operator=(const AmbiantLightData *src) {
    LightComponent::operator = (src);

    return *this;
  }

  QString getXml() const override {
    ComponentNode::addComponent(toString());
    QString out;

    QXmlStreamWriter stream(&out);

    //stream.writeStartDocument();
    stream.writeStartElement(toString());

    if (_style != nullptr)
      stream.writeAttribute(_style->getAttribute());

    if (_intensity > 0)
      stream.writeAttribute("intensity", QString::number(_intensity, 'f', 2));

    stream.writeEndElement();
    stream.writeEndDocument();

    return out;
  }
};
