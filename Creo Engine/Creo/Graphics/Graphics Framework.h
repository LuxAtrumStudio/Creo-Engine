#include "../Group Headers/Libraries.h"
#include "../Group Headers/OpenGL Libraries.h"
#include "Graphics Windows.h"
#include "Graphics Object.h"
using namespace std;

class GFRAMEWORK
{
public:
	GWINDOWS gWindow;
	GFRAMEWORK();
	~GFRAMEWORK();
	void InitializeGLUT(int* argc, char** argv);
private:
};
