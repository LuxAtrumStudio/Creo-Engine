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

void GFRAMEWORK::InitializeGLUT(int * argc, char ** argv)
{
	glutInit(argc, argv);
	LOGGING::LogSuccess("Initialized GLUT", "Graphics Framework.cpp/GFRAMEWORK/InitializeGLUT");
}

void GFRAMEWORK::RenderScene()
{
	ClearWindow();
	glBegin(GL_TRIANGLES);
	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(0.0, 0.5, 0.0);
	glEnd();
	glutSwapBuffers();
}

void GFRAMEWORK::ClearWindow()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}