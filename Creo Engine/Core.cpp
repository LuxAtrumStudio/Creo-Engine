#include <iostream>
#include "Conscientia\Conscientia.h"
#include "Creo\Group Headers\OpenGL Libraries.h"
#include "Creo\Graphics\Graphics Framework.h"
using namespace std;
GFRAMEWORK gFramework;

int main(int argc, char** argv) {
	LOGGING::InitializeLogging();
	gFramework.InitializeGLFW();
	gFramework.gWindow.GenorateWindowFromSettings();
	gFramework.InitializeGLEW();
	gFramework.CreateVertexArray();
	gFramework.gObject.Regular2DPolyGenVertices(4, 1, 1);
	gFramework.gObject.CreateVertexBuffer();
	gFramework.LoadShaders("Creo/Resources/Vertex Shader.glsl", "Creo/Resources/Fragment Shader.glsl");
	do {
		if (globalCriticalError == true) {
			LOGGING::LogData("Terminating program due to Critical Error", "Core.cpp/main");
			glfwSetWindowShouldClose(gFramework.gWindow.window, 1);
		}
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(gFramework.FetchProgramID(0));
		gFramework.gObject.DrawObject();
		glfwSwapBuffers(gFramework.gWindow.window);
		glfwPollEvents();
	} while (glfwGetKey(gFramework.gWindow.window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(gFramework.gWindow.window) == 0);
	LOGGING::TerminateLogging();
	return(1);
}