#pragma once

#include <nodes/NodeDataModel>

using QtNodes::NodeData;
using QtNodes::NodeDataType;

/// The class can potentially incapsulate any user data which
/// need to be transferred within the Node Editor graph
class BooleanData : public NodeData {
public:

  BooleanData() : _bool(false) {}

  BooleanData(bool const &boolean) : _bool(boolean)  {}

  void setValue(bool const &boolean) { _bool = boolean; }

  NodeDataType type(QString tp) const override  { return NodeDataType {"boolean", tp}; }

  NodeDataType type() const override  { return NodeDataType {"boolean", "Boolean"}; }

  bool getValue() const { return _bool; }

  QString booleanAsText() const { return _bool?"true":"false"; }

private:

  bool _bool;
};
