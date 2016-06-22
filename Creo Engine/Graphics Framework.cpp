#pragma once
#include "Libraries.h"
#include "OpenGL Libraries.h"
#include "Conscientia.h"
#include "Graphics Header.h"
using namespace std;

void GRAPHICSFRAMEWORK::Initialize(int argc, char** argv) {
	glutInit(&argc, argv);
	LOGGING::LogSuccess("Initialized GLUT", "Graphics Framework/GRAPHICSFRAMEWORK/Initialize");
	int width = 500, height = 500;
	unsigned int displayMode = GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH | GLUT_STENCIL;
	displayMode = graphicsCore.Defaults(displayMode, width, height);
	glutInitDisplayMode(displayMode);
	LOGGING::LogSuccess("Initialized Display Mode", "Graphics Framework/GRAPHICSFRAMEWORK/Initialize");
	glutInitContextVersion(4, 4);
	LOGGING::LogSuccess("Initialized Version", "Graphics Framework/GRAPHICSFRAMEWORK/Initialize");
	glutInitContextProfile(GLUT_CORE_PROFILE);
	LOGGING::LogSuccess("Initialized Context Profile", "Graphics Framework/GRAPHICSFRAMEWORK/Initialize");
	glutInitWindowSize(width, height);
	glutInitWindowPosition(300, 200);
	int window = glutCreateWindow(argv[0]);
	LOGGING::LogSuccess("Created Window", "Graphics Framework/GRAPHICSFRAMEWORK/Initialize");
}