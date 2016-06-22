#pragma once
#include "Libraries.h"
#include "OpenGL Libraries.h"
#include "Graphics Core.h"
using namespace std;

class GRAPHICSFRAMEWORK {
private:
	GRAPHICSCORE graphicsCore;
public:
	void Initialize(int argc, char** argv);
};