#include "FileLoaderModel.hpp"

#include <QtCore/QEvent>
#include <QtCore/QDir>

#include <QtWidgets/QFileDialog>

FileLoaderModel::FileLoaderModel() : _label(new QLabel("Double click to load file")) {
  _label->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);

  QFont f = _label->font();
  f.setBold(true);
  f.setItalic(true);

  _label->setFont(f);
  _label->setFixedSize(150, 25);
  _label->installEventFilter(this);
}

unsigned int FileLoaderModel::nPorts(PortType portType) const {
  unsigned int result = 1;

  switch (portType) {
    case PortType::In:
      result = 0;
      break;

    case PortType::Out:
      result = 1;

    default:
      break;
  }

  return result;
}

bool FileLoaderModel::eventFilter(QObject *object, QEvent *event) {
  if (object == _label) {
    int w = _label->width();
    int h = _label->height();

    if (event->type() == QEvent::MouseButtonPress) {

      QString fileName =
        QFileDialog::getOpenFileName(nullptr, tr("Open File"), QDir::homePath(),
                                      tr("File Files (*.obj *.mtl)"));

      _file->setPath(fileName);
      _label->setText(fileName.section('/', -1));
      emit dataUpdated(0);

      return true;
    }
  }

  return false;
}

NodeDataType FileLoaderModel::dataType(PortType, PortIndex) const {
  return FileData().type();
}

std::shared_ptr<NodeData> FileLoaderModel::outData(PortIndex) {
  return _file;
}
