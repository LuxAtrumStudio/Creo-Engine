#include "../Group Headers/Libraries.h"
#include "../Group Headers/OpenGL Libraries.h"
#include "../../Conscientia/Conscientia.h"
#include "Graphics Windows.h"
#include "../Declarations/Definitions.h"
using namespace std;

GWINDOWS::GWINDOWS()
{
}

GWINDOWS::~GWINDOWS()
{
}

void GWINDOWS::SetDisplayMode(unsigned int mode)
{
	glutInitDisplayMode(mode);
	LOGGING::LogSuccess("Set window display mode to :" + to_string(mode), "Graphics Windows.cpp/GWINDOWS/SetDisplayMode");
}

void GWINDOWS::SetPosition(int x, int y)
{
	glutInitWindowPosition(x, y);
	LOGGING::LogSuccess("Set window position to: [" + to_string(x) + "x" + to_string(y) + "]", "Graphics Windows.cpp / GWINDOWS / SetPosition");
}

void GWINDOWS::SetSize(int width, int height)
{
	glutInitWindowSize(width, height);
	LOGGING::LogSuccess("Set window size to: [" + to_string(width) + "x" + to_string(height) + "]", "Graphics Windows.cpp/GWINDOWS/SetSize");
}

void GWINDOWS::GenorateWindow()
{
	string windowTitle;
	windowTitle = programName;
	if (programDevelopmentMode == true) {
		windowTitle = "DEV:" + windowTitle + " " + to_string(programMajorVersion) + "." + to_string(programMinorVersion) + "." + to_string(programSubVersion) + "." + to_string(programUpdateVersion);
	}
	windowPointer = glutCreateWindow(windowTitle.c_str());
	LOGGING::LogSuccess("Created window with title: \"" + windowTitle + "\"", "Graphics Windows.cpp/GWINDOWS/GenorateWindow");
}

void GWINDOWS::GenorateWindowFromSettings()
{
	SetDisplayMode(programDisplayMode);
	SetPosition(programWindowPositionX, programWindowPositionY);
	SetSize(programWindowWidth, programWindowHeight);
	GenorateWindow();
}