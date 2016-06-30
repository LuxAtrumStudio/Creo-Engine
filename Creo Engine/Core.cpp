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
	LOGGING::TerminateLogging();
	return(1);
}