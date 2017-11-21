#pragma once

#include <nodes/NodeDataModel>
#include <QtCore/QDir>

using QtNodes::NodeData;
using QtNodes::NodeDataType;

/// The class can potentially incapsulate any user data which
/// need to be transferred within the Node Editor graph
class FileData : public NodeData
{
public:

  FileData() {}

  FileData(QString const path) : _path(path) {}

  QString getPath() { return this->_path; }

  void setPath(QString const path) { this->_path = path; }

  NodeDataType type(QString tp) const override { return NodeDataType {"file", tp}; }

  NodeDataType  type() const override  {
    //       id      name
    return {"file", "File"};
  }

  static QString fileToDir(QString path) {
    QString assets_path = (QDir().currentPath() + "/static_assets");

    QString::SectionFlag flag = QString::SectionSkipEmpty;
    QString str = path.section('/', 0, -2);
    QString name = "../static_assets/" + path.section('/', -1);

    if (str != assets_path) {
      std::string cmd = std::string("/bin/cp \"") + path.toUtf8().constData();
      cmd += std::string("\" ") + assets_path.toUtf8().constData();

      char buf[BUFSIZ];
      FILE *ptr;

      if ((ptr = popen(cmd.c_str(), "r")) != NULL) {
           while (fgets(buf, BUFSIZ, ptr) != NULL)
              (void) printf("%s", buf);

           fclose(ptr);
      }
    }

    return name;
  }

private:

  QString _path;
};
