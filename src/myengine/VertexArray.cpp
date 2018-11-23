#include "VertexArray.h"
#include "VertexBuffer.h"

#include <fstream>
#include <iostream>

void VertexArray::splitStringWhitespace(std::string& _input, std::vector<std::string>& _output)
{
	std::string m_current;

	_output.clear();

	for (size_t i = 0; i < _input.length(); i++)
	{
		if (_input.at(i) == ' ' ||
			_input.at(i) == '\r' ||
			_input.at(i) == '\n' ||
			_input.at(i) == '\t')
		{
			if (m_current.length() > 0)
			{
				_output.push_back(m_current);
				m_current = "";
			}
		}
		else
		{
			m_current += _input.at(i);
		}
	}

	if (m_current.length() > 0)
	{
		_output.push_back(m_current);
	}
}

void VertexArray::splitString(std::string& _input, char _splitter, std::vector<std::string>& _output)
{
	std::string m_current;

	_output.clear();

	for (size_t i = 0; i < _input.length(); i++)
	{
		if (_input.at(i) == _splitter)
		{
			_output.push_back(m_current);
			m_current = "";
		}
		else
		{
			m_current += _input.at(i);
		}
	}

	if (m_current.length() > 0)
	{
		_output.push_back(m_current);
	}
}

VertexArray::VertexArray()
{
	m_dirty = false;

	glGenVertexArrays(1, &m_vaoID);

	if (!m_vaoID)
	{
		throw std::exception();
	}

	m_buffers.resize(10);
}

VertexArray::VertexArray(std::string _path)
{
	m_dirty = false;

	glGenVertexArrays(1, &m_vaoID);

	if (!m_vaoID)
	{
		throw std::exception();
	}

	m_buffers.resize(10);
	std::ifstream file(_path.c_str());

	if (!file.is_open())
	{
		throw std::exception();
	}

	std::string line;
	std::vector<std::string> splitLine;
	std::vector<glm::vec3> positions;
	std::vector<glm::vec2> texCoords;
	std::vector<glm::vec3> normals;

	VertexBuffer *positionBuffer = NULL;
	VertexBuffer *texCoordBuffer = NULL;
	VertexBuffer *normalBuffer = NULL;

	while (!file.eof())
	{
		std::getline(file, line);
		if (line.length() < 1) continue;
		splitStringWhitespace(line, splitLine);
		if (splitLine.size() < 1) continue;

		if (splitLine.at(0) == "v")
		{
			if (!positionBuffer) positionBuffer = new VertexBuffer();

			positions.push_back(glm::vec3(
				atof(splitLine.at(1).c_str()),
				atof(splitLine.at(2).c_str()),
				atof(splitLine.at(3).c_str())));
		}
		else if (splitLine.at(0) == "vt")
		{
			if (!texCoordBuffer) texCoordBuffer = new VertexBuffer();

			texCoords.push_back(glm::vec2(
				atof(splitLine.at(1).c_str()),
				1.0f - atof(splitLine.at(2).c_str())));
		}
		else if (splitLine.at(0) == "vn")
		{
			if (!normalBuffer) normalBuffer = new VertexBuffer();

			normals.push_back(glm::vec3(
				atof(splitLine.at(1).c_str()),
				atof(splitLine.at(2).c_str()),
				atof(splitLine.at(3).c_str())));
		}
		else if (splitLine.at(0) == "f")
		{
			std::vector<std::string> subsplit;
			splitString(splitLine.at(1), '/', subsplit);

			positionBuffer->Add(positions.at(atoi(subsplit.at(0).c_str()) - 1));
			if (texCoordBuffer) texCoordBuffer->Add(texCoords.at(atoi(subsplit.at(1).c_str()) - 1));
			if (normalBuffer) normalBuffer->Add(normals.at(atoi(subsplit.at(2).c_str()) - 1));
			splitString(splitLine.at(2), '/', subsplit);
			positionBuffer->Add(positions.at(atoi(subsplit.at(0).c_str()) - 1));
			if (texCoordBuffer) texCoordBuffer->Add(texCoords.at(atoi(subsplit.at(1).c_str()) - 1));
			if (normalBuffer) normalBuffer->Add(normals.at(atoi(subsplit.at(2).c_str()) - 1));
			splitString(splitLine.at(3), '/', subsplit);
			positionBuffer->Add(positions.at(atoi(subsplit.at(0).c_str()) - 1));
			if (texCoordBuffer) texCoordBuffer->Add(texCoords.at(atoi(subsplit.at(1).c_str()) - 1));
			if (normalBuffer) normalBuffer->Add(normals.at(atoi(subsplit.at(2).c_str()) - 1));

			if (splitLine.size() < 5) continue;
			splitString(splitLine.at(3), '/', subsplit);

			positionBuffer->Add(positions.at(atoi(subsplit.at(0).c_str()) - 1));
			if (texCoordBuffer) texCoordBuffer->Add(texCoords.at(atoi(subsplit.at(1).c_str()) - 1));
			if (normalBuffer) normalBuffer->Add(normals.at(atoi(subsplit.at(2).c_str()) - 1));
			splitString(splitLine.at(4), '/', subsplit);
			positionBuffer->Add(positions.at(atoi(subsplit.at(0).c_str()) - 1));
			if (texCoordBuffer) texCoordBuffer->Add(texCoords.at(atoi(subsplit.at(1).c_str()) - 1));
			if (normalBuffer) normalBuffer->Add(normals.at(atoi(subsplit.at(2).c_str()) - 1));
			splitString(splitLine.at(1), '/', subsplit);
			positionBuffer->Add(positions.at(atoi(subsplit.at(0).c_str()) - 1));
			if (texCoordBuffer) texCoordBuffer->Add(texCoords.at(atoi(subsplit.at(1).c_str()) - 1));
			if (normalBuffer) normalBuffer->Add(normals.at(atoi(subsplit.at(2).c_str()) - 1));
		}
	}

	setBuffer("in_Position", positionBuffer);
	if (texCoordBuffer) setBuffer("in_TexCoord", texCoordBuffer);
	if (normalBuffer) setBuffer("in_Normal", normalBuffer);
}

void VertexArray::setBuffer(std::string _attribute, VertexBuffer *buffer)
{
	if (_attribute == "in_Position")
	{
		m_buffers.at(0) = buffer;
	}
	else if (_attribute == "in_Color")
	{
		m_buffers.at(1) = buffer;
	}
	else if (_attribute == "in_TexCoord")
	{
		m_buffers.at(2) = buffer;
	}
	else if (_attribute == "in_Normal")
	{
		m_buffers.at(3) = buffer;
	}
	else
	{
		throw std::exception();
	}

	m_dirty = true;
}

int VertexArray::getVertexCount()
{
	if (!m_buffers.at(0))
	{
		throw std::exception();
	}

	return m_buffers.at(0)->GetDataSize() / m_buffers.at(0)->GetComponents();
}

GLuint VertexArray::GetID()
{
	if (m_dirty)
	{
		glBindVertexArray(m_vaoID);

		for (size_t i = 0; i < m_buffers.size(); i++)
		{
			if (m_buffers.at(i))
			{
				glBindBuffer(GL_ARRAY_BUFFER, m_buffers.at(i)->GetID());

				glVertexAttribPointer(i, m_buffers.at(i)->GetComponents(), GL_FLOAT, GL_FALSE,
					m_buffers.at(i)->GetComponents() * sizeof(GLfloat), (void *)0);

				glEnableVertexAttribArray(i);
			}
			else
			{
				glDisableVertexAttribArray(i);
			}
		}
	}
	return m_vaoID;
}
