#include <string>
#include <glm/glm.hpp>
#include <fstream>
#include <iostream>
#include <exception>
#include <GL/glew.h>

class ShaderProgram
{
private:
	std::ifstream m_file;
	std::string m_vertexSrc;
	std::string m_fragmentSrc;
	std::string m_line;

public:
	ShaderProgram(std::string _vertex, std::string _fragment);
	~ShaderProgram();
};