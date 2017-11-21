#pragma once

#include <nodes/NodeDataModel>
#include <sstream>
#include <iostream>

#include <QXmlStreamAttribute>
#include <QJsonDocument>

#include "Vector2Data.hpp"
#include "TransformData.hpp"

using QtNodes::NodeData;
using QtNodes::NodeDataType;

/// The class can potentially incapsulate any user data which
/// need to be transferred within the Node Editor graph
class StyleData : public NodeData {
public:

  StyleData() : /*_backgroundColor("#FFFFFF"), _textAlign("center"), _textAlignVertical("center"),*/
                  _fontSize(0.0), _paddingLeft(0.0), _paddingRight(0.0), _opacity(0.0) {

        //_position = new Vector3Data();
  }

  // StyleData() { }

  NodeDataType type(QString tp) const override { return NodeDataType {"style", tp}; }

  NodeDataType type() const override  { return NodeDataType {"style", "Style"}; }

            /*      GETTERS       */
  QString getBackgroundColor() const { return _backgroundColor; }
  QString getTextAlignment() const { return _textAlign; }
  QString getTextAlignmentVertical() const { return _textAlignVertical; }

  double getFontSize() const { return _fontSize; }
  double getPaddingLeft() const { return _paddingLeft; }
  double getPaddingRight() const { return _paddingRight; }

  double getOpacity() const { return _opacity; }
  QString getColor() const { return _color; }

  Vector2Data *getLayoutOrigin() const { return _layoutOrigin; }
  TransformData *getTransform() const { return _transform; }

            /*      SETTERS       */
  void setBackgroundColor(QString color) { _backgroundColor = color;}
  void setTextAlignment(QString align) {
    _textAlign = align;
  }
  void setTextAlignmentVertical(QString align) {
   _textAlignVertical = align;
 }

  void setFontSize(double size) { _fontSize = size; }
  void setPaddingLeft(double padding) { _paddingLeft = padding; }
  void setPaddingRight(double padding) { _paddingRight = padding; }

  void setOpacity(double opacity) { _opacity = opacity; }
  void setColor(QString color) { _color = color; }

  void setLayoutOrigin(Vector2Data *v2) { _layoutOrigin = v2; }
  void setTransform(TransformData *transform) { _transform = transform; }

  QString toString() const {
    return "style";
  }

  QXmlStreamAttribute getAttribute() const {
    //Value();
    QString res = Vector2Data::jsonToString(Value());

  //  std::cout << res.toUtf8().constData() << std::endl;

    QXmlStreamAttribute attribute(toString(), res);

    return attribute;
  }

  QJsonObject Value() const {
    QJsonObject modelJson;

    if (!(_backgroundColor.isNull() && _backgroundColor.isEmpty()))
      modelJson["backgroundColor"] = _backgroundColor;
    if (!(_textAlign.isNull() && _textAlign.isEmpty()))
      modelJson["textAlign"] = _textAlign;
    if (!(_textAlignVertical.isNull() && _textAlignVertical.isEmpty()))
      modelJson["textAlignVertical"] = _textAlignVertical;

    if (_transform != nullptr)
      modelJson["transform"] = _transform->toString();

    if (_layoutOrigin != nullptr) {
      QString str = _layoutOrigin->toString();
      if (!(str.isNull() && str.isEmpty())) {
        modelJson["layoutOrigin"] = str;
      }
    }

    modelJson["fontSize"] = _fontSize;
    modelJson["paddingLeft"] = _paddingLeft;
    modelJson["paddingRight"] = _paddingRight;

    if (!(_color.isNull() && _color.isEmpty()))
      modelJson["color"] = _color;

    modelJson["opacity"] = _opacity;

    return modelJson;
  }

  StyleData &operator=(const StyleData *src) {
    this->_color = src->getColor();
    this->_backgroundColor = src->getBackgroundColor();
    this->_textAlign = src->getTextAlignment();
    this->_textAlignVertical = src->getTextAlignmentVertical();

    this->_fontSize = src->getFontSize();
    this->_paddingLeft = src->getPaddingLeft();
    this->_paddingRight = src->getPaddingRight();

    this->_layoutOrigin = src->getLayoutOrigin();
    this->_transform = src->getTransform();
    this->_opacity = src->getOpacity();
    return *this;
  }

private:

  QString _backgroundColor;
  QString _textAlign;
  QString _textAlignVertical;
  QString _color;

  double _fontSize;
  double _paddingLeft;
  double _paddingRight;
  double _opacity;

  Vector2Data *_layoutOrigin = nullptr;
  TransformData *_transform = nullptr;
};
