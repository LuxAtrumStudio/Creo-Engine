#include "../Group Headers/Libraries.h"
#include "../Group Headers/OpenGL Libraries.h"
#include "Graphics Windows.h"
#include "Graphics Object.h"
using namespace std;

class GFRAMEWORK
{
public:
	GWINDOWS gWindow;
	GOBJECT gObject;
	GFRAMEWORK();
	~GFRAMEWORK();

	void InitializeGLFW();
	void InitializeGLEW();

	vector<GLuint> programs;

	void LoadShaders(string vertexFilePath, string fragmentFilePath);
	string GetFileAsString(string filePath);
	void GenorateShaders();
	void CompileShader(int shaderType, string fileString);
	void LinkProgram();
	GLuint FetchProgramID(int id);
private:
	GLuint vertexShaderID, fragmentShaderID;
};
