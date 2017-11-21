#include "ViewDataModel.hpp"

ViewDataModel::ViewDataModel() {}

ViewDataModel::~ViewDataModel() {
  // _views
}

unsigned int ViewDataModel::nPorts(PortType portType) const {
  unsigned int result;

  if (portType == PortType::In) {
    result = _view->getViews().size() + 3;
  } else
    result = 1;

  return result;
}

NodeDataType  ViewDataModel::dataType(PortType type, PortIndex index) const {
  if (type == PortType::In) {
    if (index == 0)
      return StyleData().type();
    else
      return ViewData().type();
  } else {
    return ViewData().type();
  }
}

std::shared_ptr<NodeData> ViewDataModel::outData(PortIndex) {
  return _view;
}

void ViewDataModel::setInData(std::shared_ptr<NodeData> data, PortIndex portIndex) {
  if (portIndex == 0) {
    PortIndex const outPortIndex = 0;

    auto styleData = std::dynamic_pointer_cast<StyleData>(data);
    _style = styleData;
    auto stl = _style.lock();

    if (stl) {
      modelValidationState = NodeValidationState::Valid;
      modelValidationError = QString();
      _view->setStyle(&(*styleData));
    } else {
      modelValidationState = NodeValidationState::Warning;
      modelValidationError = QStringLiteral("Missing or incorrect inputs");
      _style.reset();
    }
    emit dataUpdated(outPortIndex);

  } else {
    auto viewData = std::dynamic_pointer_cast<ComponentNode>(data);
    //_childView = viewData;
    _view->addView(&(*viewData));
  }
}

NodeValidationState ViewDataModel::validationState() const {
  return modelValidationState;
}

QString ViewDataModel::validationMessage() const {
  return modelValidationError;
}
