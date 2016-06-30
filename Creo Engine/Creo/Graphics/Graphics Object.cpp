#include "../Group Headers/Libraries.h"
#include "../Group Headers/OpenGL Libraries.h"
#include "../../Conscientia/Conscientia.h"
#include "Graphics Object.h"
using namespace std;

GOBJECT::GOBJECT() {
}

GOBJECT::~GOBJECT() {
}

void GOBJECT::Regular2DPolyGenVertices(int sides, float sizeX, float sizeY)
{
	double theta = 0;
	double thetaStep = (2 * pi) / sides;
	double thetaStart;
	if ((sides % 2) == 0) {
		thetaStart = -(pi / 2);
	}
	else if ((sides % 2) != 0) {
		thetaStart = -(pi / 2) + (thetaStep / 2);
	}
	for (theta = thetaStart; theta < thetaStart + (thetaStep * sides); theta = theta + thetaStep) {
		float x, y;
		y = cos(theta) * sizeY;
		x = sin(theta) * sizeX;
		glm::vec3 vertex;
		vertex = { x, y, 0 };
		LOGGING::LogData("(" + to_string(x) + "," + to_string(y) + ")", "DEV");
		vertices.push_back(vertex);
	}
}