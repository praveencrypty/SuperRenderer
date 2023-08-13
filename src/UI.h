#pragma once
#include <iostream>

#include "imgui/imgui.h"
#include "imgui/imgui_internal.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"



void setupUI(GLFWwindow* window);
void startIMGUIFrame();
void endIMGUIFrame();
void destroyIMGUI();

void UIComponents();

void UIRenderLoop(GLFWwindow* window);

void FullUIRender(GLFWwindow* window);

void ImGUI_Styling();
