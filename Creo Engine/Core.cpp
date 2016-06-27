#include <iostream>
#include "Conscientia\Conscientia.h"
#include "Creo\Group Headers\OpenGL Libraries.h"
#include "Creo\Graphics\Graphics Framework.h"
using namespace std;
GFRAMEWORK gFramework;

void DisplayFunc() {
	gFramework.RenderScene();
}

int main(int argc, char** argv) {
	LOGGING::InitializeLogging();
	gFramework.InitializeGLUT(&argc, argv);
	gFramework.gWindow.GenorateWindowFromSettings();
	glutDisplayFunc(DisplayFunc);
	glutMainLoop();
	LOGGING::TerminateLogging();
	return(1);
}