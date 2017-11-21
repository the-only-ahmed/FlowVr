#pragma once

#include <nodes/NodeDataModel>
#include <sstream>

#include "ComponentNode.hpp"

using QtNodes::NodeData;
using QtNodes::NodeDataType;

// The class can potentially incapsulate any user data which
/// need to be transferred within the Node Editor graph
class LightComponent : public ComponentNode {
public:

  LightComponent() : ComponentNode(), _intensity(0.0) {}

            /*      GETTERS       */
  double getIntensity() const { return _intensity; }

            /*      SETTERS       */
  void setIntensity(double value) { _intensity = value; }

  QString toString() const override {
    return "LightComponent";
  }

  QJsonObject Value() const override {
    QJsonObject modelJson;

    return modelJson;
  }

  LightComponent &operator=(const LightComponent *src) {
    ComponentNode::operator = (src);
    this->_intensity = src->getIntensity();

    return *this;
  }

  QString getXml() const override {
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

protected:

  double _intensity;
};
