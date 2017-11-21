#pragma once

#include <QtGui/QPixmap>

#include <nodes/NodeDataModel>

using QtNodes::NodeData;
using QtNodes::NodeDataType;

/// The class can potentially incapsulate any user data which
/// need to be transferred within the Node Editor graph
class PixmapData : public NodeData
{
public:

  PixmapData() {}

  PixmapData(QPixmap const &pixmap, QString const path) : _pixmap(pixmap), _path(path) {}

  QString getPath() { return this->_path; }
  QPixmap getImage() { return this->_pixmap; }

  void setPath(QString const path) { this->_path = path; }
  void setImage(QPixmap const &pixmap) { this->_pixmap = _pixmap; }

  NodeDataType type(QString tp) const override { return NodeDataType {"pixmap", tp}; }

  NodeDataType  type() const override  {
    //       id      name
    return {"pixmap", "Pic"};
  }

  //QPixmap  pixmap() const { return _pixmap; }

private:

  QString _path;
  QPixmap _pixmap;
};
