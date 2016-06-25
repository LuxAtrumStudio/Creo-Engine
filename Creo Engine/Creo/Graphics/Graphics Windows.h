#include "../Group Headers/Libraries.h"
#include "../Group Headers/OpenGL Libraries.h"
#include "Graphics Data.h"
using namespace std;

class GWINDOWS
{
public:
	GWINDOWS();
	~GWINDOWS();
	void SetDisplayMode(unsigned int mode);
	void SetPosition(int x, int y);
	void SetSize(int width, int height);
	void GenorateWindow();
	void GenorateWindowFromSettings();
private:
	int positionX, positionY, width, height, windowPointer;
	unsigned int displayMode;
};
