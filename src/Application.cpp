#define GLEW_STATIC

#include <iostream>
#include <string>
#include "GL/glew.h"
#include "GLFW/glfw3.h"

using namespace std;

#include "UI.h"
#include "Mesh.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void inputEvents(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}


void main() 
{

	

	glfwInit();

	//Window Creation
	GLFWwindow* window;
	GLFWmonitor* monitor;

	//Window Creation Hints
	monitor = glfwGetPrimaryMonitor();

	const GLFWvidmode* mode = glfwGetVideoMode(monitor);

	glfwWindowHint(GLFW_RED_BITS, mode->redBits);
	glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
	glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
	glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

	glfwWindowHint(GLFW_MAXIMIZED, 1);

	//Creation Main Function
	window = glfwCreateWindow(mode->width, mode->height, "OpenGL Renderer", NULL, NULL);


	//Make created window the current one
	glfwMakeContextCurrent(window);

	//Initialize glew after glfw opengl context is set
	if (glewInit() != GLEW_OK)
		throw std::exception("Failed to initialize GLEW\n");


	//Framebuffer Size and Callback
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glViewport(0, 0, mode->width, mode->height);


	//Shader Setup
	//Currently using default shader in gpu

	

	//Buffers
	GLuint mainBuffer;
	
	glGenBuffers(1, &mainBuffer);

	glBindBuffer(GL_ARRAY_BUFFER, mainBuffer);

	Mesh m({0.5,0.5,0.0,
			0.0,0.0,0.0,
			0.5,0.0,0.0},
					  {	0.5,0.5,0.0,
					  	0.1,0.0,0.0,
					  	0.5,0.0,0.0 }, mainBuffer);

	


	//UI Setup
	setupUI(window);






	while (!glfwWindowShouldClose(window))
	{

		glClearColor(0.823529411f, 0.7294117647f, 0.01176470588f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);



		//Render Functions Below
		
		
		
		m.drawMesh();



		//UI Rendering
		FullUIRender(window);

		glfwSwapBuffers(window);
		glfwPollEvents();
		inputEvents(window);

	}

	destroyIMGUI();
	glfwDestroyWindow(window);
	glfwTerminate();

}