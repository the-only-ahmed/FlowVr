#pragma once

#include <nodes/NodeDataModel>
#include <sstream>

#include "ComponentNode.hpp"
#include "SourceData.hpp"

using QtNodes::NodeData;
using QtNodes::NodeDataType;

// The class can potentially incapsulate any user data which
/// need to be transferred within the Node Editor graph
class Model_3Data : public ComponentNode {
public:

  Model_3Data() : ComponentNode(), _lit(false), _wireframe(false) {}

  // Model_3Data(QString const &text) : ComponentNode(), _text(text)  {}

            /*      GETTERS       */
  SourceData *getSource() const { return _source; }
  QString getTexture() const { return _texture; }

  bool isLit() const { return _lit; }
  bool isWireframe() const { return _wireframe; }
            /*      SETTERS       */
  void setSource(SourceData *value) { _source = value; }
  void setTexture(QString value) { _texture = value; }

  void setLit(bool value) { _lit = value; }
  void setWireframe(bool value) { _wireframe = value; }

  QString toString() const override {
    return "Model";
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

  Model_3Data &operator=(const Model_3Data *src) {
    ComponentNode::operator = (src);
    this->_source = src->getSource();
    this->_texture = src->getTexture();

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
    if (_source != nullptr)
      stream.writeAttribute(_source->getAttribute());

    if (!(_texture.isNull() && _texture.isEmpty()))
      stream.writeAttribute("texture", _texture);

    if (_lit)
      stream.writeAttribute("lit", "true");
    if (_wireframe)
      stream.writeAttribute("wireframe", "true");

    stream.writeEndElement();
    stream.writeEndDocument();

    return out;
  }

private:

  SourceData *_source = nullptr;

  QString _texture;

  bool _lit;
  bool _wireframe;
};
