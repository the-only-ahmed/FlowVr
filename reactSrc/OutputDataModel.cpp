#include "OutputDataModel.hpp"

#include <QMessageBox>
#include <QtCore/QJsonValue>
#include <QXmlStreamWriter>
#include <QtGui/QDoubleValidator>

#include <iostream>
#include <fstream>

OutputDataModel::OutputDataModel() {
  _button = new QPushButton("&Render");
  _projectName = _output->getProjectName();

  connect(_button, SIGNAL (pressed()), this, SLOT (handleButton()));

  endJS = ");\n}\n};\n\nAppRegistry.registerComponent('"+_projectName+"', () => "+_projectName+");\n";
}

void OutputDataModel::handleButton() {
  if (_output->getView() == nullptr) {
    QMessageBox msgBox;
    msgBox.setText("Missing or incorrect inputs");
    msgBox.exec();
  } else {

    beginJS = "import React, { Component } from 'react';\n";
    beginJS += "import {\nAppRegistry,\nasset,\n";

    std::list<QString>::const_iterator it;
    std::list<QString> components = ComponentNode::getComponents();
    for (it = components.begin(); it != components.end(); it++) {
      std::cout << (*it).toUtf8().constData() << '\n';
      beginJS += (*it).toUtf8().constData();
      beginJS += ",\n";
    }

    beginJS += "} from 'react-vr';\n";
    beginJS += "\nexport default class "+_projectName+" extends Component {\nrender() {\nreturn (";

    saveXML();
  }
}

void OutputDataModel::saveXML() {
  if (_input.lock()) {
    //QString key = _output.get()->toString();
    QString output;
    QXmlStreamWriter writer(&output);
    writer.setAutoFormatting(true);

    ComponentNode::QxmlReader(&writer, _input.lock().get()->getXml());

    writer.writeEndDocument();

    output.replace("\"{", "{{");
    output.replace("}\"", "}}");
    output.replace("@", ",");

    output.replace("\"?", "{");
    output.replace("?\"", "}");

    // std::cout << output.toUtf8().constData() << '\n';

    writeToFile(output.toUtf8().constData());
  }
}

void OutputDataModel::writeToFile(std::string content) {
  std::ofstream myfile;
  myfile.open ("index.vr.js");
  myfile << beginJS << content << endJS;
  myfile.close();
}

void OutputDataModel::saveJson(QJsonDocument document, QString fileName) {
    QFile jsonFile(fileName);
    jsonFile.open(QFile::WriteOnly);
    jsonFile.write(document.toJson());
}

QJsonObject OutputDataModel::save() const {
  QJsonObject modelJson;// = NodeDataModel::save();

  if (_input.lock()) {
    QString key = _output.get()->toString();
    QJsonObject value = _input.lock().get()->Value();
    modelJson[key] = value;//
  }

  return modelJson;
}

unsigned int OutputDataModel::nPorts(PortType portType) const {
  unsigned int result = 1;

  switch (portType) {
    case PortType::In:
      result = 1;
      break;
    case PortType::Out:
      result = 0;
    default:
      break;
  }

  return result;
}

void OutputDataModel::Warning(bool correct) {
  //PortIndex const outPortIndex = 0;

  if (correct) {
    modelValidationState = NodeValidationState::Valid;
    modelValidationError = QString();
    _output->setView(_input.lock().get());
  } else {
    modelValidationState = NodeValidationState::Warning;
    modelValidationError = QStringLiteral("Missing or incorrect inputs");
    _input.reset();
    _output->removeView();
  }
  //emit dataUpdated(outPortIndex);
}

void OutputDataModel::setInData(std::shared_ptr<NodeData> data, PortIndex portIndex) {
  auto inData = std::dynamic_pointer_cast<ComponentNode>(data);

  _input = inData;
  Warning(true);
}

NodeDataType OutputDataModel::dataType(PortType p, PortIndex) const {
  return ComponentNode().type();
}

std::shared_ptr<NodeData> OutputDataModel::outData(PortIndex) {
  return _output;
}

NodeValidationState OutputDataModel::validationState() const {
  return modelValidationState;
}

QString OutputDataModel::validationMessage() const {
  return modelValidationError;
}
