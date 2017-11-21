#include "Model_3DataModel.hpp"

Model_3DataModel::Model_3DataModel() {}

unsigned int Model_3DataModel::nPorts(PortType portType) const {
  unsigned int result;

  if (portType == PortType::In)
    result = 5;
  else
    result = 1;

  return result;
}

NodeDataType  Model_3DataModel::dataType(PortType type, PortIndex index) const {
  if (type == PortType::In) {
    switch (index) {
      case 0:
        return StyleData().type();
      break;
      case 1:
        return SourceData().type();
      break;
      case 2:
        return StringData().type("texture");
      break;
      case 3:
        return BooleanData().type("lit");
      break;
      default:
        return BooleanData().type("wireframe");
      break;
    }
  } else {
    return Model_3Data().type();
  }
}

std::shared_ptr<NodeData> Model_3DataModel::outData(PortIndex) {
  return _model;
}

void Model_3DataModel::setInData(std::shared_ptr<NodeData> data, PortIndex portIndex) {
  if (portIndex == 0) {
    PortIndex const outPortIndex = 0;

    auto styleData = std::dynamic_pointer_cast<StyleData>(data);
    _style = styleData;
    auto stl = _style.lock();

    if (stl) {
      modelValidationState = NodeValidationState::Valid;
      modelValidationError = QString();
      _model->setStyle(&(*styleData));
    } else {
      modelValidationState = NodeValidationState::Warning;
      modelValidationError = QStringLiteral("Missing or incorrect inputs");
      _style.reset();
    }
    emit dataUpdated(outPortIndex);

  } else if (portIndex == 1) {
    PortIndex const outPortIndex = 0;

    auto sourceData = std::dynamic_pointer_cast<SourceData>(data);
    _source = sourceData;
    auto src = _source.lock();

    if (src) {
      modelValidationState = NodeValidationState::Valid;
      modelValidationError = QString();
      _model->setSource(&(*(sourceData)));
    } else {
      modelValidationState = NodeValidationState::Warning;
      modelValidationError = QStringLiteral("Missing or incorrect inputs");
      _source.reset();
    }
    emit dataUpdated(outPortIndex);
  } else if (portIndex == 2) {
    PortIndex const outPortIndex = 0;

    auto txtData = std::dynamic_pointer_cast<StringData>(data);
    _texture = txtData;
    auto txt = _texture.lock();

    if (txt)
      _model->setTexture(txtData->text());
    else
      _texture.reset();

    emit dataUpdated(outPortIndex);
  } else {
    PortIndex const outPortIndex = 0;

    auto boolData = std::dynamic_pointer_cast<BooleanData>(data);
    if (portIndex == 3) {
      _lit = boolData;
      auto lit = _lit.lock();

      if (lit)
        _model->setLit(boolData->getValue());
      else
        _lit.reset();
    } else {
      _wireframe = boolData;
      auto wire = _wireframe.lock();

      if (wire)
        _model->setWireframe(boolData->getValue());
      else
        _wireframe.reset();
    }

    emit dataUpdated(outPortIndex);
  }
}

NodeValidationState Model_3DataModel::validationState() const {
  return modelValidationState;
}

QString Model_3DataModel::validationMessage() const {
  return modelValidationError;
}
