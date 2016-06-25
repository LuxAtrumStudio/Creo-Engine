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