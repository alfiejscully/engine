#include <string>
#include <fstream>
#include <iostream>
#include <exception>

#include <glm/glm.hpp>
#include <GL/glew.h>

class VertexArray;

class ShaderProgram
{
private:
	std::ifstream m_file;
	std::string m_line;

	//source variables for shaders 
	std::string m_vertexSrc;
	std::string m_fragmentSrc;

	const GLchar *m_vertexShader;
	const GLchar *m_fragmentShader;

	//ID Varibles 
	GLuint m_vertexShaderID;
	GLuint m_fragmentShaderID;
	GLuint m_shaderProgramID;

	GLint success = 0;
	GLint m_posAttribute;
	GLint m_colourAttribute;

public:
	ShaderProgram(std::string _vertex, std::string _fragment);
	~ShaderProgram();

	void Draw();
	void DrawTriangle();
};