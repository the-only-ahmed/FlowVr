#pragma once

#include <nodes/NodeDataModel>
#include <sstream>

#include "PixmapData.hpp"
#include "FileData.hpp"
#include "ComponentNode.hpp"

using QtNodes::NodeData;
using QtNodes::NodeDataType;

/// The class can potentially incapsulate any user data which
/// need to be transferred within the Node Editor graph
class PanoData : public ComponentNode {
public:

  PanoData() : ComponentNode() { }

  PanoData(QPixmap const &pixmap, QString const path) : ComponentNode(), _pixmap(pixmap), _path(path) {}

            /*      GETTERS       */
  QPixmap  getPath() const { return _path; }
  QPixmap  getPicture() const { return _pixmap; }
            /*      SETTERS       */
  void setPath(QString const path) { _path = path; }

  void setPicture(QPixmap const &pixmap) { _pixmap = pixmap; }

  QString toString() const override {
    return "Pano";
  }

  QJsonObject Value() const override {
    QJsonObject modelJson;

    modelJson["uri"] = FileData::fileToDir(_path);

    return modelJson;
  }

  PanoData &operator=(const PanoData *src) {
    ComponentNode::operator = (src);
    this->_pixmap = src->getPicture();

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

    if (!(_path.isNull() && _path.isEmpty())) {
      stream.writeAttribute("source", Vector2Data::jsonToString(Value()));
    }

    stream.writeEndElement();
    stream.writeEndDocument();

    return out;
  }

private:

  QPixmap _pixmap;
  QString _path;
};
