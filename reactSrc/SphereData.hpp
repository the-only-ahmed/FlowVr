#pragma once

#include <nodes/NodeDataModel>
#include <sstream>

#include "ComponentNode.hpp"

using QtNodes::NodeData;
using QtNodes::NodeDataType;

// The class can potentially incapsulate any user data which
/// need to be transferred within the Node Editor graph
class SphereData : public ComponentNode {
public:

  SphereData() : ComponentNode(), _heightSegments(0.0), _widthSegments(0.0),
                    _radius(0.0), _lit(false), _wireframe(false) {}

  // SphereData(QString const &text) : ComponentNode(), _text(text)  {}

            /*      GETTERS       */
  double getHeightSegments() const { return _heightSegments; }
  double getWidthSegments() const { return _widthSegments; }
  double getRadius() const { return _radius; }

  bool isLit() const { return _lit; }
  bool isWireframe() const { return _wireframe; }
            /*      SETTERS       */
  void setHeightSegments(double const value) { _heightSegments = value; }
  void setWidthSegments(double value) { _widthSegments = value; }
  void setRadius(double value) { _radius = value; }

  void setLit(bool value) { _lit = value; }
  void setWireframe(bool value) { _wireframe = value; }

  QString toString() const override {
    return "Sphere";
  }

  QJsonObject Value() const override {
    QJsonObject modelJson;

    // QJsonObject childJson = ComponentNode::Value();
    // if (!(_text.isNull() && _text.isEmpty()))
    //   childJson["text"] = _text;
    //
    // modelJson[toString()] = childJson;

    return modelJson;
  }

  SphereData &operator=(const SphereData *src) {
    ComponentNode::operator = (src);
    this->_heightSegments = src->getHeightSegments();
    this->_widthSegments = src->getWidthSegments();
    this->_radius = src->getRadius();

    this->_lit = src->isLit();
    this->_wireframe = src->isWireframe();

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

    if (_heightSegments > 0)
      stream.writeAttribute("heightSegments", "?"+QString::number(_heightSegments, 'f', 2)+"?");
    if (_widthSegments > 0)
      stream.writeAttribute("widthSegments", "?"+QString::number(_widthSegments, 'f', 2)+"?");
    if (_radius > 0)
      stream.writeAttribute("radius", "?"+QString::number(_radius, 'f', 2)+"?");

    if (_lit)
      stream.writeAttribute("lit", "?true?");
    if (_wireframe)
      stream.writeAttribute("wireframe", "?true?");

    stream.writeEndElement();
    stream.writeEndDocument();

    return out;
  }

private:

  double _heightSegments;
  double _widthSegments;
  double _radius;

  bool _lit;
  bool _wireframe;
};
