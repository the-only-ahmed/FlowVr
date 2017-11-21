#pragma once

#include <nodes/NodeDataModel>
#include <sstream>
#include <iostream>

#include <QXmlStreamAttribute>
#include <QJsonDocument>

#include "FileData.hpp"
#include "Vector2Data.hpp"

using QtNodes::NodeData;
using QtNodes::NodeDataType;

class SourceData : public NodeData {
public:

  SourceData() { }

  NodeDataType type(QString tp) const override { return NodeDataType {"Source", tp}; }

  NodeDataType type() const override  { return NodeDataType {"source", "Source"}; }

  QString getObject() const { return _object; }
  QString getMaterial() const { return _material; }

  void setObject(QString value) { _object = value; }
  void setMaterial(QString value) { _material = value; }

  QString toString() const {
    return "Source";
  }

  QXmlStreamAttribute getAttribute() const {
    QString res = Vector2Data::jsonToString(Value());
    QXmlStreamAttribute attribute(toString(), res);

    return attribute;
  }

  QJsonObject Value() const {
    QJsonObject modelJson;

    if (!(_object.isNull() && _object.isEmpty())) {
      modelJson["obj"] = FileData::fileToDir(_object);
    }

    if (!(_material.isNull() && _material.isEmpty()))
      modelJson["mtl"] = FileData::fileToDir(_material);

    return modelJson;
  }

  SourceData &operator=(const SourceData *src) {
    this->_object = src->getObject();
    this->_material = src->getMaterial();

    return *this;
  }

private:

  QString _object;
  QString _material;
};
