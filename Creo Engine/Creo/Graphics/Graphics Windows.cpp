#include "../Group Headers/Libraries.h"
#include "../Group Headers/OpenGL Libraries.h"
#include "../../Conscientia/Conscientia.h"
#include "Graphics Windows.h"
using namespace std;

GWINDOWS::GWINDOWS()
{
}

GWINDOWS::~GWINDOWS()
{
}

void GWINDOWS::GenorateWindow(int width, int height, string title)
{
	SetWindowData();
	window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
	if (window == NULL) {
		LOGGING::LogError("Failed to genorate window", "Graphics Windows.cpp/GWINDOWS/GenorateWindow");
		globalCriticalError = true;
	}
	else {
		LOGGING::LogSuccess("Genorated window", "Graphics Windows.cpp/GWINDOWS/GenorateWindow");
		MakeCurrent();
		glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	}
}

void GWINDOWS::GenorateWindowFromSettings()
{
	string title = programName;
	if (programDevelopmentMode == true) {
		title = title + " " + to_string(programMajorVersion) + "." + to_string(programMinorVersion) + "." + to_string(programSubVersion) + "." + to_string(programUpdateVersion);
	}
	GenorateWindow(programWindowWidth, programWindowHeight, title);
}

void GWINDOWS::SetWindowData()
{
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	LOGGING::LogSuccess("Set window data", "Graphics Windows.cpp/GWINDOW/SetWindowData");
}

void GWINDOWS::MakeCurrent()
{
	glfwMakeContextCurrent(window);
	LOGGING::LogSuccess("Made current window current context", "Graphics Windows.cpp/GWINDOW/MakeCurrent");
}

void GWINDOWS::CreateVertexArray()
{
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);
	LOGGING::LogSuccess("Created vertex array", "Graphics Windows.cpp/GWINDOW/CreateVertexArray");
}