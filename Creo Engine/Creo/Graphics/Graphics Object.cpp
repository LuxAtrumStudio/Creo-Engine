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
		double x, y;
		x = cos(theta);
		y = sin(theta);
		glm::vec3 vertex;
		vertex = { x, y, 0 };
		LOGGING::LogData(to_string(theta), "THETA");
		LOGGING::LogData("(" + to_string(x) + "," + to_string(y) + ")", "DEV");
		vertices.push_back(vertex);
	}
}

void GOBJECT::CreateVertexBuffer()
{
	GLfloat *vertexBufferData = new GLfloat[vertices.size() * 3];
	unsigned index = 0;
	for (unsigned i = 0; i < vertices.size(); i++) {
		vertexBufferData[index] = vertices[i].x;
		index = index + 1;
		vertexBufferData[index] = vertices[i].y;
		index = index + 1;
		vertexBufferData[index] = vertices[i].z;
		index = index + 1;
	}
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * vertices.size() * 3, vertexBufferData, GL_STATIC_DRAW);
}

void GOBJECT::DrawObject()
{
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glVertexAttribPointer(0, vertices.size(), GL_FLOAT, GL_FALSE, 0, (void*)0);

	glDrawArrays(GL_TRIANGLES, 0, vertices.size());
	glDisableVertexAttribArray(0);
}