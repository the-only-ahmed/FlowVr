#pragma once

#include <nodes/NodeDataModel>
#include <sstream>
#include <QtCore/QDir>

#include "ComponentNode.hpp"

using QtNodes::NodeData;
using QtNodes::NodeDataType;

/// The class can potentially incapsulate any user data which
/// need to be transferred within the Node Editor graph
class OutputNode : public NodeData {
public:

  OutputNode() {
    _projectName = QDir().currentPath().section("/", -1).toUtf8().constData();
  }

  NodeDataType type(QString tp) const override { return NodeDataType {"output", tp}; }
  NodeDataType type() const override  { return NodeDataType {"output", "Output"}; }

  void setView(ComponentNode *view) {
    this->_view = view;
  }

  void removeView() {
     delete this->_view;
    this->_view = nullptr;
  }

  ComponentNode  *getView() { return this->_view; }

  QString toString() const  {
    return "Output";
  }

  std::string getProjectName() {
    return _projectName;
  }

private:

  std::string _projectName;
  ComponentNode *_view = nullptr;
};
