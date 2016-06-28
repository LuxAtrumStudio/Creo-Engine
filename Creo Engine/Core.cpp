#include <iostream>
#include "Conscientia\Conscientia.h"
#include "Creo\Group Headers\OpenGL Libraries.h"
#include "Creo\Graphics\Graphics Framework.h"
using namespace std;
GFRAMEWORK gFramework;

void DisplayFunc() {
	gFramework.RenderScene();
}
void ReshapeFunc(int width, int height) {
	gFramework.ChangeSize(width, height);
}

int main(int argc, char** argv) {
	LOGGING::InitializeLogging();
	gFramework.InitializeGLUT(&argc, argv);
	gFramework.gWindow.GenorateWindowFromSettings();
	glutDisplayFunc(DisplayFunc);
	glutReshapeFunc(ReshapeFunc);
	glutMainLoop();
	LOGGING::TerminateLogging();
	return(1);
}