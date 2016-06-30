#include "../Group Headers/Libraries.h"
#include "../Group Headers/OpenGL Libraries.h"
#include "../../Conscientia/Conscientia.h"
#include "Graphics Framework.h"
using namespace std;

GFRAMEWORK::GFRAMEWORK()
{
}

GFRAMEWORK::~GFRAMEWORK()
{
}

void GFRAMEWORK::InitializeGLFW()
{
	if (!glfwInit()) {
		LOGGING::LogError("Failed to initialize GLFW", "Graphics Framework.cpp/GFRAMEWORK/InitializeGLFW");
		globalCriticalError = true;
	}
	else {
		LOGGING::LogSuccess("Initialized GLFW", "Graphics Framework.cpp/GFRAMEWORK/InitializeGLFW");
	}
}

void GFRAMEWORK::InitializeGLEW()
{
	glewExperimental = true;
	if (glewInit() != GLEW_OK) {
		LOGGING::LogError("Failed to initialized GLEW", "Graphics Framework.cpp/GFRAMEWORK/InitializeGLEW");
		globalCriticalError = true;
	}
	else {
		LOGGING::LogSuccess("Initialized GLEW", "Graphics Framework.cpp/GFRAMEWORK/InitializeGLEW");
	}
}