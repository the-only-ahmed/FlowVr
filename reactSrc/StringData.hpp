#pragma once

#include <nodes/NodeDataModel>

using QtNodes::NodeData;
using QtNodes::NodeDataType;

/// The class can potentially incapsulate any user data which
/// need to be transferred within the Node Editor graph
class StringData : public NodeData
{
public:

  StringData() {}

  StringData(QString const &text) : _text(text)  {}

  NodeDataType type(QString tp) const override { return NodeDataType {"text", tp}; }
  
  NodeDataType type() const override  { return NodeDataType {"text", "Text"}; }

  QString text() const { return _text; }

private:

  QString _text;
};
