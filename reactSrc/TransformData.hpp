#pragma once

#include <nodes/NodeDataModel>
#include <sstream>
#include <iostream>

#include <QXmlStreamAttribute>
#include <QJsonDocument>

#include "Vector3Data.hpp"
#include "Vector2Data.hpp"

using QtNodes::NodeData;
using QtNodes::NodeDataType;

/// The class can potentially incapsulate any user data which
/// need to be transferred within the Node Editor graph
class TransformData : public NodeData {
public:

  TransformData() { }

  NodeDataType type(QString tp) const override { return NodeDataType {"transform", tp}; }

  NodeDataType type() const override  { return NodeDataType {"transform", "Transform"}; }

            /*      GETTERS       */
  Vector3Data *getTranslation() const { return _translate; }
  Vector3Data *getRotation() const { return _rotate; }
  Vector3Data *getScale() const { return _scale; }

            /*      SETTERS       */
  void setTranslation(Vector3Data *translate) { _translate = translate; }
  void setRotation(Vector3Data *rotate) { _rotate = rotate; }
  void setScale(Vector3Data *scale) { _scale = scale; }

  QString toString() const {
    QString res = Vector2Data::jsonToString(Value());

    return res;
  }

  QJsonObject Value() const {
    QJsonObject modelJson;

    if (_translate != nullptr) {
      QString str = _translate->toString();
      if (!(str.isNull() && str.isEmpty())) {
        modelJson["translate"] = str;
      }
    }

    if (_rotate != nullptr) {
      //QString str = _rotate->toString();
      //if (!(str.isNull() && str.isEmpty())) {
        modelJson["rotateX"] = _rotate->Value()["x"];
        modelJson["rotateY"] = _rotate->Value()["y"];
        modelJson["rotateZ"] = _rotate->Value()["z"];
      //}
    }

    if (_scale != nullptr) {
      QString str = _scale->toString();
      if (!(str.isNull() && str.isEmpty())) {
        modelJson["scale"] = str;
      }
    }

    return modelJson;
  }

  TransformData &operator=(const TransformData *src) {
    this->_translate = src->getTranslation();
    this->_rotate = src->getRotation();
    this->_scale = src->getScale();

    return *this;
  }

private:

  Vector3Data *_translate = nullptr;
  Vector3Data *_rotate = nullptr;
  Vector3Data *_scale = nullptr;
};
