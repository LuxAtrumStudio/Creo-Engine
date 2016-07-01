#include "../Group Headers/Libraries.h"
#include "../Group Headers/OpenGL Libraries.h"
#include "../../Conscientia/Conscientia.h"
#include "Graphics Framework.h"
using namespace std;

GFRAMEWORK::GFRAMEWORK()
{
}

GFRAMEWORK::~GFRAMEWORK()
{
}

void GFRAMEWORK::InitializeGLFW()
{
	if (!glfwInit()) {
		LOGGING::LogError("Failed to initialize GLFW", "Graphics Framework.cpp/GFRAMEWORK/InitializeGLFW");
		globalCriticalError = true;
	}
	else {
		LOGGING::LogSuccess("Initialized GLFW", "Graphics Framework.cpp/GFRAMEWORK/InitializeGLFW");
	}
}

void GFRAMEWORK::InitializeGLEW()
{
	glewExperimental = true;
	if (glewInit() != GLEW_OK) {
		LOGGING::LogError("Failed to initialized GLEW", "Graphics Framework.cpp/GFRAMEWORK/InitializeGLEW");
		globalCriticalError = true;
	}
	else {
		LOGGING::LogSuccess("Initialized GLEW", "Graphics Framework.cpp/GFRAMEWORK/InitializeGLEW");
	}
}

void GFRAMEWORK::LoadShaders(string vertexFilePath, string fragmentFilePath)
{
	GenorateShaders();
	CompileShader(0, GetFileAsString(vertexFilePath));
	CompileShader(1, GetFileAsString(fragmentFilePath));
	LinkProgram();
}

string GFRAMEWORK::GetFileAsString(string filePath)
{
	string fileAsString;
	ifstream load(filePath.c_str());
	if (load.is_open()) {
		LOGGING::LogSuccess("Loaded file with file path: \"" + filePath + "\"", "Graphics Framework.cpp/GFRAMEWORK/GetFileAsString");
		string line = "";
		while (getline(load, line)) {
			fileAsString += "\n" + line;
		}
		load.close();
	}
	else {
		LOGGING::LogError("Failed to open file path: \"" + filePath + "\"", "Graphics Framework.cpp/GFRAMEWORK/GetFileAsString");
		globalCriticalError = true;
	}
	return (fileAsString);
}

void GFRAMEWORK::GenorateShaders()
{
	vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	LOGGING::LogSuccess("Created shaders", "Graphics Framework.cpp/GFRAMEWORK/GenorateShader");
}

void GFRAMEWORK::CompileShader(int shaderType, string fileString)
{
	GLint result = GL_FALSE;
	int infoLogLength;
	if (shaderType == 0) {
		char const * vertexSourcePointer = fileString.c_str();
		glShaderSource(vertexShaderID, 1, &vertexSourcePointer, NULL);
		glCompileShader(vertexShaderID);

		glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &result);
		glGetShaderiv(vertexShaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
		if (infoLogLength > 0) {
			vector<char> vertexShaderErrorMessage(infoLogLength + 1);
			glGetShaderInfoLog(vertexShaderID, infoLogLength, NULL, &vertexShaderErrorMessage[0]);
			LOGGING::LogError("Failed to compile vertex shader", "Graphics Framework.cpp/GRAMEWORK/CompileShader");
			string errorMessage = "" + vertexShaderErrorMessage[0];
			LOGGING::LogError(errorMessage, "Graphics Framework.cpp/GRAMEWORK/CompileShader");
			globalCriticalError = true;
		}
		else {
			LOGGING::LogSuccess("Compiled vertex shader", "Graphics Framework.cpp/GRAMEWORK/CompileShade");
		}
	}
	if (shaderType == 1) {
		char const * fragmentSourcePointer = fileString.c_str();
		glShaderSource(fragmentShaderID, 1, &fragmentSourcePointer, NULL);
		glCompileShader(fragmentShaderID);

		glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &result);
		glGetShaderiv(fragmentShaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
		if (infoLogLength > 0) {
			vector<char> fragmentShaderErrorMessage(infoLogLength + 1);
			glGetShaderInfoLog(fragmentShaderID, infoLogLength, NULL, &fragmentShaderErrorMessage[0]);
			LOGGING::LogError("Failed to compile fragment shader", "Graphics Framework.cpp/GRAMEWORK/CompileShader");
			string errorMessage = "" + fragmentShaderErrorMessage[0];
			LOGGING::LogError(errorMessage, "Graphics Framework.cpp/GRAMEWORK/CompileShader");
			globalCriticalError = true;
		}
		else {
			LOGGING::LogSuccess("Compiled fragment shader", "Graphics Framework.cpp/GRAMEWORK/CompileShade");
		}
	}
}

void GFRAMEWORK::LinkProgram()
{
	GLuint programID = glCreateProgram();
	glAttachShader(programID, vertexShaderID);
	glAttachShader(programID, fragmentShaderID);
	glLinkProgram(programID);

	GLint result = GL_FALSE;
	int infoLogLength;

	glGetProgramiv(programID, GL_LINK_STATUS, &result);
	glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &infoLogLength);
	if (infoLogLength > 0) {
		vector<char> programErrorMessage(infoLogLength + 1);
		glGetProgramInfoLog(programID, infoLogLength, NULL, &programErrorMessage[0]);
		LOGGING::LogError("Failed to link program", "Graphics Framework.cpp/GRAMEWORK/CompileShader");
		string errorMessage = "" + programErrorMessage[0];
		LOGGING::LogError(errorMessage, "Graphics Framework.cpp/GRAMEWORK/CompileShader");
		globalCriticalError = true;
	}
	else {
		LOGGING::LogSuccess("Linked program with ID: " + to_string(programID), "Graphics Framework.cpp/GRAMEWORK/CompileShade");
	}
	glDetachShader(programID, vertexShaderID);
	glDetachShader(programID, fragmentShaderID);

	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);
	programs.push_back(programID);
}

GLuint GFRAMEWORK::FetchProgramID(int id)
{
	return (programs[id]);
}