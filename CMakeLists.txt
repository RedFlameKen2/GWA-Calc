cmake_minimum_required(VERSION 3.27)
project(GWACalc C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(GWACalc
        ImGui/imgui.cpp
        ImGui/imgui.h
        ImGui/imgui_draw.cpp
        ImGui/imgui_internal.h
        ImGui/imgui_widgets.cpp
        ImGui/imgui_tables.cpp
        main.cpp
)
