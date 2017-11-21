#pragma once

#include <nodes/NodeDataModel>
#include <sstream>

#include "LightComponent.hpp"

using QtNodes::NodeData;
using QtNodes::NodeDataType;

// The class can potentially incapsulate any user data which
/// need to be transferred within the Node Editor graph
class PointLightData : public LightComponent {
public:

  PointLightData() : LightComponent(), _decay(0.0), _distance(0.0) {}

            /*      GETTERS       */
  double getDecay() const { return _decay; }
  double getDistance() const { return _distance; }

            /*      SETTERS       */
  void setDecay(double const value) { _decay = value; }
  void setDistance(double value) { _distance = value; }

  QString toString() const override {
    return "PointLight";
  }

  QJsonObject Value() const override {
    QJsonObject modelJson;

    return modelJson;
  }

  PointLightData &operator=(const PointLightData *src) {
    LightComponent::operator = (src);
    this->_decay = src->getDecay();
    this->_distance = src->getDistance();

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

    if (_decay > 0)
      stream.writeAttribute("_decay", QString::number(_decay, 'f', 2));
    if (_distance > 0)
      stream.writeAttribute("distance", QString::number(_distance, 'f', 2));
    if (_intensity > 0)
      stream.writeAttribute("intensity", QString::number(_intensity, 'f', 2));

    stream.writeEndElement();
    stream.writeEndDocument();

    return out;
  }

private:

  double _decay;
  double _distance;
};
