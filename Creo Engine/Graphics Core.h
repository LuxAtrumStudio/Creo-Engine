#include "Libraries.h"
#include "OpenGL Libraries.h"
using namespace std;
class GRAPHICSCORE {
private:
public:
	void Initalize();
	void Display();
	void Reshape(int width, int height);
	void Keyboard(unsigned char key, int x, int y);
	unsigned int Defaults(unsigned int displayMode, int &width, int &height);
};