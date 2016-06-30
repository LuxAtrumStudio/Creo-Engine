#pragma once
#include "../Group Headers/OpenGL Libraries.h"
using namespace std;

//Developer Settings
#ifndef DEVMODE
extern bool programDevelopmentMode;
#endif // !DEVMODE

//Program Settings
#ifndef PROGRAMSETTINGS
extern string programName;
extern int programMajorVersion;
extern int programMinorVersion;
extern int programSubVersion;
extern int programUpdateVersion;
extern int programWindowWidth;
extern int programWindowHeight;
#endif // !PROGRAMSETTINGS
