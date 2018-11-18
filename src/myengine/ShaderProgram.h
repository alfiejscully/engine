#include <string>
#include <fstream>
#include <iostream>
#include <exception>

#include <glm/glm.hpp>
#include <GL/glew.h>

class ShaderProgram
{
private:
	std::ifstream m_file;
	std::string m_vertexSrc;
	std::string m_fragmentSrc;
	std::string m_line;

	const GLchar *m_vertexShader;
	const GLchar *m_fragmentShader;

	GLuint m_vertexShaderID;
	GLuint m_fragmentShaderID;
	GLuint m_shaderProgramID;

	GLint success = 0;
	GLint m_posAttribute;

public:
	ShaderProgram(std::string _vertex, std::string _fragment);
	~ShaderProgram();

	void Draw();
};