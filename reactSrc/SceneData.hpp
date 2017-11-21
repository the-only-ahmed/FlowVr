#pragma once

#include <nodes/NodeDataModel>
#include <sstream>
#include <iostream>

#include <list>
#include <QJsonObject>
#include <QJsonArray>

#include "ComponentNode.hpp"

using QtNodes::NodeData;
using QtNodes::NodeDataType;

/// The class can potentially incapsulate any user data which
/// need to be transferred within the Node Editor graph
class SceneData : public ComponentNode {
public:

  SceneData() : ComponentNode() {}

  QString toString() const override {
    return "Scene";
  }

  QJsonObject Value() const override {
    QJsonObject modelJson;
    // QJsonObject childJson = ComponentNode::Value();
    //
    // QJsonArray array;
    //
    // if (_views.size() > 0) {
    //   std::list<ComponentNode*>::const_iterator it;
    //   for (it = _views.begin(); it != _views.end(); it++) {
    //     array.push_back((*it)->Value());
    //   }
    //   childJson["data"] = array;
    // }
    //
    // modelJson[toString()] = array;

    return modelJson;
  }

  SceneData &operator=(const SceneData *src) {
    ComponentNode::operator = (src);

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

    stream.writeEndElement();
    stream.writeEndDocument();

    return out;
  }
};
