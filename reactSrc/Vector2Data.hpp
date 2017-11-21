#pragma once

#include <nodes/NodeDataModel>
#include <QJsonDocument>
#include <QJsonArray>
#include <sstream>

using QtNodes::NodeData;
using QtNodes::NodeDataType;

/// The class can potentially incapsulate any user data which
/// need to be transferred within the Node Editor graph
class Vector2Data : public NodeData {
public:

  Vector2Data() : _x(0.0), _y(0.0) {}

  Vector2Data(double const &x, double const &y) : _x(x), _y(y) { }

  NodeDataType type(QString tp) const override { return NodeDataType {"vector2", tp}; }

  NodeDataType type() const override  { return NodeDataType {"vector2", "Vector2"}; }

  double x() const { return _x; }
  double y() const { return _y; }

  QString toString() const {
    std::stringstream sstm;
    sstm << "["<<_x<<"@ "<<_y<<"]";
    QString str = QString::fromStdString(sstm.str());

    return str;
  }

  QJsonObject Value() const {
    QJsonObject modelJson;

    modelJson["x"] = _x;
    modelJson["y"] = _y;

    return modelJson;
  }

  Vector2Data &operator=(const Vector2Data *src) {
    this->_x = src->x();
    this->_y = src->y();

    return *this;
  }

  static QString jsonToString(QJsonObject obj) {
    QJsonDocument doc;
    doc.setObject(obj);

    QString res;
    QString strJson(doc.toJson(QJsonDocument::Compact));

    QStringList pairs = strJson.split(","); // separate by comma

    for (int i = 0; i < pairs.count(); i++) {
      if (!res.isEmpty())
        res += ",";
      QStringList pairItems = pairs[i].split(":");
      pairItems[0].remove(QChar('\"'));
      res += pairItems[0];
      for (int j=1; j < pairItems.count(); ++j)
         res += ":"+ pairItems[j];
    }

    res.replace("\"[","[");
    res.replace("]\"","]");
    res.replace("\"","\'");

    res.replace("\'{", "[{");
    res.replace("}\'", "}]");

    return res;
  }

private:

  double _x;
  double _y;
};
