TEMPLATE = app
TARGET = RendererApp
QT -= core gui


CONFIG += debug_and_release

IMGUI_DIR =  $$PWD/view/Renderer_API_external_libraries/imgui
#INCLUDEPATH += $${IMGUI_DIR}
#INCLUDEPATH += $${IMGUI_DIR}/backends

SOURCES += $${IMGUI_DIR}/imgui.cpp $${IMGUI_DIR}/imgui_demo.cpp $${IMGUI_DIR}/imgui_draw.cpp $${IMGUI_DIR}/imgui_tables.cpp $${IMGUI_DIR}/imgui_widgets.cpp
SOURCES += $${IMGUI_DIR}/ImGuiFileDialog.cpp


SOURCES += $${IMGUI_DIR}/backends/imgui_impl_glfw.cpp $${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
SOURCES += main.cpp 

CONFIG(debug, debug|release) {
  OBJECTS_DIR = $$PWD/build/release
} 
else {
OBJECTS_DIR = $$PWD/build/debug
}

DESTDIR = $$PWD


# Library settings per platform
unix {
    # Linux
    LIBS += -lGL -lGLEW -lglfw
}

macx {
    # macOS
    LIBS += -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
    LIBS += -L/usr/local/lib -L/opt/local/lib -L/opt/homebrew/lib
    LIBS += -lglfw
    INCLUDEPATH += /usr/local/include -I/opt/local/include -I/opt/homebrew/include
}

win32 {
    # Windows (MinGW)
    LIBS += -lglfw3 -lgdi32 -lopengl32 -limm32
}

win32|unix: QMAKE_CLEAN += $$TARGET