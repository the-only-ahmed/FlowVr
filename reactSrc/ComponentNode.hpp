#pragma once

#include <nodes/NodeDataModel>
#include <sstream>

#include "StyleData.hpp"

using QtNodes::NodeData;
using QtNodes::NodeDataType;

/// The class can potentially incapsulate any user data which
/// need to be transferred within the Node Editor graph
class ComponentNode : public NodeData {
public:

  ComponentNode() { }

  NodeDataType type(QString tp) const override { return NodeDataType {"component", tp}; }

  NodeDataType type() const override  { return NodeDataType {"component", "View"}; }

            /*      GETTERS       */
  StyleData *getStyle() const { return _style; }

            /*      SETTERS       */
  void setStyle(StyleData *style) { _style = style; }

  ComponentNode &operator=(const ComponentNode *src) {
    this->_style = src->getStyle();

    return *this;
  }

  virtual QString toString() const { return "ComponentNode"; }

  virtual QString getXml() const { return ""; };

  virtual QJsonObject Value() const {
    QJsonObject modelJson;

    if (_style != nullptr)
      modelJson[_style->toString()] = _style->Value();

    return modelJson;
  }

  static void QxmlReader(QXmlStreamWriter *writer, QString str) {
    QXmlStreamReader reader(str);

    while(!reader.atEnd()) {
      //if(reader.isStartDocument())
        //writer->writeStartDocument();

      if(reader.isStartElement()) {
        writer->writeStartElement(reader.name().toString());
        //std::cout << reader.name().toString().toUtf8().constData() << '\n';
      }

      writer->writeAttributes(reader.attributes());

      if(reader.isCharacters())
        writer->writeCharacters(reader.text().toString());

      if(reader.isEndElement())
        writer->writeEndElement();

      if(reader.isEndDocument())
        writer->writeEndElement();

      reader.readNext();
    }
  }

  static void addComponent(QString component) {
    bool found = (std::find(_components.begin(), _components.end(), component) != _components.end());
    if (!found)
      _components.push_back(component);
  }

  static std::list<QString> getComponents() {
    return _components;
  }

protected:

  StyleData *_style = nullptr;

private:

  static std::list<QString> _components;
};
