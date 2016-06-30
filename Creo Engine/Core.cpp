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
	do {
		glfwSwapBuffers(gFramework.gWindow.window);
		glfwPollEvents();
	} while (glfwGetKey(gFramework.gWindow.window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(gFramework.gWindow.window) == 0);
	LOGGING::TerminateLogging();
	return(1);
}