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
class ViewData : public ComponentNode {
public:

  ViewData() : ComponentNode() {}

  std::list<ComponentNode*> getViews() const { return _views; }

  void removeView(ComponentNode *view) {
    bool found = (std::find(_views.begin(), _views.end(), view) != _views.end());
    if (!found)
      _views.remove(view);
  }

  void addView(ComponentNode *view) {
    bool found = (std::find(_views.begin(), _views.end(), view) != _views.end());
    if (!found)
      _views.push_back(view);
  }

  QString toString() const override {
    return "View";
  }

  QJsonObject Value() const override {
    QJsonObject modelJson;
    QJsonObject childJson = ComponentNode::Value();

    QJsonArray array;

    if (_views.size() > 0) {
      std::list<ComponentNode*>::const_iterator it;
      for (it = _views.begin(); it != _views.end(); it++) {
        array.push_back((*it)->Value());
      }
      childJson["data"] = array;
    }

    modelJson[toString()] = array;

    return modelJson;
  }

  ViewData &operator=(const ViewData *src) {
    ComponentNode::operator = (src);
    this->_views = src->getViews();

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

    if (_views.size() > 0) {
      int i = 0;
      std::list<int> _positions;

      std::cout << "size = " << _views.size() << '\n';
      std::list<ComponentNode*>::const_iterator it;
      for (it = _views.begin(); it != _views.end(); it++) {
        if (*it != nullptr)
          ComponentNode::QxmlReader(&stream, (*it)->getXml());
      }
    }

    stream.writeEndElement();
    stream.writeEndDocument();

    return out;
  }

private:

  std::list<ComponentNode*> _views;
};
