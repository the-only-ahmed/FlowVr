#pragma once

#include <nodes/NodeDataModel>
#include <sstream>

using QtNodes::NodeData;
using QtNodes::NodeDataType;

/// The class can potentially incapsulate any user data which
/// need to be transferred within the Node Editor graph
class Vector3Data : public NodeData {
public:

  Vector3Data() : _x(0.0), _y(0.0), _z(0.0) {}

  Vector3Data(double const &x, double const &y, double const &z) : _x(x), _y(y), _z(z) {}

  NodeDataType type(QString tp) const override { return NodeDataType {"vector3", tp}; }

  NodeDataType type() const override  { return NodeDataType {"vector3", "Vector3"}; }

  double x() const { return _x; }
  double y() const { return _y; }
  double z() const { return _z; }

  QString toString() const {
    std::stringstream sstm;
    sstm << "["<<_x<<"@ "<<_y<<"@ "<<_z<<"]";
    QString str = QString::fromStdString(sstm.str());

    return str;
  }

  QJsonObject Value() const {
    QJsonObject modelJson;

    modelJson["x"] = _x;
    modelJson["y"] = _y;
    modelJson["z"] = _z;

    return modelJson;
  }

  Vector3Data &operator=(const Vector3Data *src) {
    this->_x = src->x();
    this->_y = src->y();
    this->_z = src->z();

    return *this;
  }

private:

  double _x;
  double _y;
  double _z;
};
