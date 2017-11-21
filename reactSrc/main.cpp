#include <nodes/NodeData>
#include <nodes/FlowScene>
#include <nodes/FlowView>
#include <nodes/ConnectionStyle>

#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QMenuBar>

#include <nodes/DataModelRegistry>

#include "OutputDataModel.hpp"

#include "ViewDataModel.hpp"
#include "PanoDataModel.hpp"
#include "TextDataModel.hpp"
#include "StyleSourceDataModel.hpp"
#include "SphereDataModel.hpp"
#include "SceneDataModel.hpp"
#include "Model_3DataModel.hpp"

#include "TransformDataModel.hpp"
#include "Vector3SourceDataModel.hpp"
#include "Vector2SourceDataModel.hpp"
#include "NumberSourceDataModel.hpp"
#include "BooleanDataModel.hpp"
#include "StringSourceDataModel.hpp"
#include "ImageLoaderModel.hpp"
#include "FileLoaderModel.hpp"
#include "SourceDataModel.hpp"

#include "PointLightDataModel.hpp"
#include "AmbiantLightDataModel.hpp"

#include "NumberDisplayDataModel.hpp"

#include "AdditionModel.hpp"
#include "SubtractionModel.hpp"
#include "MultiplicationModel.hpp"
#include "DivisionModel.hpp"
#include "ModuloModel.hpp"

#include "DecimalToIntegerModel.hpp"
#include "IntegerToDecimalModel.hpp"

using QtNodes::DataModelRegistry;
using QtNodes::FlowScene;
using QtNodes::FlowView;
using QtNodes::ConnectionStyle;

std::list<QString> ComponentNode::_components;


static std::shared_ptr<DataModelRegistry> registerDataModels() {

  auto ret = std::make_shared<DataModelRegistry>();
  ret->registerModel<OutputDataModel>("Output");

  ret->registerModel<ViewDataModel>("Views");
  ret->registerModel<StyleSourceDataModel>("Views");
  ret->registerModel<PanoDataModel>("Views");
  ret->registerModel<TextDataModel>("Views");
  ret->registerModel<SphereDataModel>("Views");
  ret->registerModel<SceneDataModel>("Views");
  ret->registerModel<Model_3DataModel>("Views");

  ret->registerModel<TransformDataModel>("Sources");
  ret->registerModel<Vector3SourceDataModel>("Sources");
  ret->registerModel<Vector2SourceDataModel>("Sources");
  ret->registerModel<NumberSourceDataModel>("Sources");
  ret->registerModel<StringSourceDataModel>("Sources");
  ret->registerModel<BooleanDataModel>("Sources");
  ret->registerModel<ImageLoaderModel>("Sources");
  ret->registerModel<FileLoaderModel>("Sources");
  ret->registerModel<SourceDataModel>("Sources");

  ret->registerModel<PointLightDataModel>("Lights");
  ret->registerModel<AmbiantLightDataModel>("Lights");

  ret->registerModel<NumberDisplayDataModel>("Displays");

  ret->registerModel<AdditionModel>("Operators");
  ret->registerModel<SubtractionModel>("Operators");
  ret->registerModel<MultiplicationModel>("Operators");
  ret->registerModel<DivisionModel>("Operators");
  ret->registerModel<ModuloModel>("Operators");

  ret->registerModel<DecimalToIntegerModel, true>("Type converters");
  ret->registerModel<IntegerToDecimalModel, true>("Type converters");

  return ret;
}

static void setStyle() {
  ConnectionStyle::setConnectionStyle(
  R"({
    "ConnectionStyle": {
      "ConstructionColor": "gray",
      "NormalColor": "black",
      "SelectedColor": "gray",
      "SelectedHaloColor": "deepskyblue",
      "HoveredColor": "deepskyblue",

      "LineWidth": 3.0,
      "ConstructionLineWidth": 2.0,
      "PointDiameter": 10.0,
      "UseDataDefinedColors": true
    }
  })");
}

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  setStyle();

  QWidget mainWidget;

  auto menuBar    = new QMenuBar();
  auto saveAction = menuBar->addAction("Save..");
  auto loadAction = menuBar->addAction("Load..");

  QVBoxLayout *l = new QVBoxLayout(&mainWidget);

  l->addWidget(menuBar);
  auto scene = new FlowScene(registerDataModels());
  l->addWidget(new FlowView(scene));
  l->setContentsMargins(0, 0, 0, 0);
  l->setSpacing(0);

  QObject::connect(saveAction, &QAction::triggered,
                   scene, &FlowScene::save);

  QObject::connect(loadAction, &QAction::triggered,
                   scene, &FlowScene::load);


  mainWidget.setWindowTitle("Node Editor: simplest React Vr platrform");
  mainWidget.resize(800, 600);
  mainWidget.showNormal();

  return app.exec();
}
