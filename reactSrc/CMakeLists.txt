file(GLOB_RECURSE CPPS  ./*.cpp )

#set ( UIS
# ../forms/mainwindow.ui
#)
#QT5_WRAP_UI( UI_HEADERS ${UIS} )
#add_executable(react_editor ${CPPS} ${UI_HEADERS})

add_executable(react_editor ${CPPS})

target_link_libraries(react_editor nodes)
