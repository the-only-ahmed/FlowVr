#!/bin/sh

mkdir build
cd build
cmake ..
make
ln -s $(pwd)/bin/react_editor ~/Desktop/flow_editor
cd ../../
