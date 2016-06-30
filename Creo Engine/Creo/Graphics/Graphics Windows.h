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
	GLuint VertexArrayID;
	void GenorateWindow(int width, int height, string name);
	void GenorateWindowFromSettings();
	void SetWindowData();
	void MakeCurrent();
	void CreateVertexArray();
private:
};
