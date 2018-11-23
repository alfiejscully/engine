#include <GL/glew.h>
#include <glm/glm.hpp>

#include <vector>
#include <string>

class VertexBuffer;

class VertexArray
{
private:
	GLuint m_vaoID;
	bool m_dirty;
	std::vector<VertexBuffer *> m_buffers;

	void splitStringWhitespace(std::string& _input, std::vector<std::string>& _output);
	void splitString(std::string& _input, char _splitter, std::vector<std::string>& _output);

public:
	VertexArray();
	VertexArray(std::string _path);
	void setBuffer(std::string _attribute, VertexBuffer *buffer);
	int getVertexCount();
	GLuint GetID();

};