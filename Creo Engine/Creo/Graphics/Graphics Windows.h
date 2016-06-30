#include "../Group Headers/Libraries.h"
#include "../Group Headers/OpenGL Libraries.h"
#include "Graphics Data.h"
using namespace std;

class GWINDOWS
{
public:
	GWINDOWS();
	~GWINDOWS();
	GLFWwindow* window;
	void GenorateWindow(int width, int height, string name);
	void GenorateWindowFromSettings();
	void SetWindowData();
	void MakeCurrent();
private:
};
