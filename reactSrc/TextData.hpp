#pragma once

#include <nodes/NodeDataModel>
#include <sstream>

#include "StringData.hpp"
#include "ComponentNode.hpp"

using QtNodes::NodeData;
using QtNodes::NodeDataType;

/// The class can potentially incapsulate any user data which
/// need to be transferred within the Node Editor graph
class TextData : public ComponentNode {
public:

  TextData() : ComponentNode() {}

  TextData(QString const &text) : ComponentNode(), _text(text)  {}

            /*      GETTERS       */
  QString  getText() const { return _text; }
            /*      SETTERS       */
  void setText(QString const &text) { _text = text; }

  QString toString() const override {
    return "Text";
  }

  QJsonObject Value() const override {
    QJsonObject modelJson;

    QJsonObject childJson = ComponentNode::Value();
    if (!(_text.isNull() && _text.isEmpty()))
      childJson["text"] = _text;

    modelJson[toString()] = childJson;

    return modelJson;
  }

  TextData &operator=(const TextData *src) {
    ComponentNode::operator = (src);
    this->_text = src->getText();

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

    stream.writeCharacters(_text);

    stream.writeEndElement();
    stream.writeEndDocument();

    return out;
  }

private:

  QString _text;
};
