#include "ShaderProgram.h"

ShaderProgram::ShaderProgram(std::string _vertex, std::string _fragment)
{
	m_file.open(_vertex.c_str()); //opens the vertex file 
	
	if (!m_file.is_open()) //checks to see if vertex file is open
	{
		throw std::exception();
	}
	else
	{
		std::cout << "Vertex file has been opened \n\n";
	}

	while (!m_file.eof())
	{
		std::getline(m_file, m_line);
		m_vertexSrc += m_line + "\n";
	}

	m_file.close(); //closes the vertex file 

	m_file.open(_fragment.c_str()); //opens fragment file 

	if (!m_file.is_open()) //checks if fragment file is open 
	{
		throw std::exception();
	}
	else
	{
		std::cout << "Fragment file has been opened \n\n";
	}

	while (!m_file.eof())
	{
		std::getline(m_file, m_line);
		m_fragmentSrc += m_line + "\n";
	}


}

ShaderProgram::~ShaderProgram()
{}