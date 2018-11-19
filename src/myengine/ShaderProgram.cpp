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

	while (!m_file.eof()) //loops while its not at the end of the file 
	{
		std::getline(m_file, m_line);
		m_vertexSrc += m_line + "\n";
	}

	m_file.close(); //closes the vertex file 

	m_file.open(_fragment.c_str()); //opens fragment file 

	if (!m_file.is_open()) //checks if fragment file is not opening  
	{
		throw std::exception();
	}
	else
	{
		std::cout << "Fragment file has been opened \n\n";
	}

	while (!m_file.eof()) //loops until its reaches the end of the file 
	{
		std::getline(m_file, m_line);
		m_fragmentSrc += m_line + "\n";
	}

	m_file.close(); //closes the fragment file
 
	// Create and compile the vertex shader
	m_vertexShader = m_vertexSrc.c_str();
	m_vertexShaderID = glCreateShader(GL_VERTEX_SHADER); 
	glShaderSource(m_vertexShaderID, 1, &m_vertexShader, NULL);
	glCompileShader(m_vertexShaderID);
	glGetShaderiv(m_vertexShaderID, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		throw std::exception();
	}
	else
	{
		std::cout << "Vertex Working\n";
	}

	// Create and compile the fragment shader
	m_fragmentShader = m_fragmentSrc.c_str();
	m_fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(m_fragmentShaderID, 1, &m_fragmentShader, NULL);
	glCompileShader(m_fragmentShaderID);
	glGetShaderiv(m_fragmentShaderID, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		throw std::exception();
	}
	else
	{
		std::cout << "Fragment Working\n";
	}

	m_shaderProgramID = glCreateProgram();
	glAttachShader(m_shaderProgramID, m_vertexShaderID);
	glAttachShader(m_shaderProgramID, m_fragmentShaderID);

	glBindFragDataLocation(m_shaderProgramID, 0, "outColor");

	glLinkProgram(m_shaderProgramID);
	glUseProgram(m_shaderProgramID);

	m_posAttribute = glGetAttribLocation(m_shaderProgramID, "position");
	glVertexAttribPointer(m_posAttribute, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), 0);
	glEnableVertexAttribArray(m_posAttribute);

	m_colourAttribute = glGetAttribLocation(m_shaderProgramID, "color");
	glVertexAttribPointer(m_colourAttribute, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(2 * sizeof(float)));
	glEnableVertexAttribArray(m_colourAttribute);

}

void ShaderProgram::Draw()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glDrawArrays(GL_TRIANGLES, 0, 3);
}

ShaderProgram::~ShaderProgram()
{
	glDeleteProgram(m_shaderProgramID);
	glDeleteShader(m_fragmentShaderID);
	glDeleteShader(m_vertexShaderID);
}