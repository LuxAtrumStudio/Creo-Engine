#include "../Group Headers/Libraries.h"
#include "../Group Headers/OpenGL Libraries.h"
#include "Graphics Data.h"
#include "Graphics Shaders.h"
#include "Graphics Points.h"
using namespace std;

class GOBJECT {
public:
	GOBJECT();
	~GOBJECT();
	vector<glm::vec3> vertices;
	void Regular2DPolyGenVertices(int sides, float sizeX, float sizeY);
private:
};
