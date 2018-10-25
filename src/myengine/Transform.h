#include <glm/glm.hpp>
#include "Component.h"

class Transform: public Component 
{
private:

	glm::vec3 m_localPosition;
	glm::vec3 m_localRotation;
	glm::vec3 m_localScale;

public:

	//setter variables 
	void SetLocalPosition(glm::vec3 _posistion);
	void SetLocalRotation(glm::vec3 _rotation);
	void SetLocalScale(glm::vec3 _scale);

	//getter variables
	glm::vec3 GetLocalPosition();
	glm::vec3 GetLocalRotation();
	glm::vec3 GetLocalScale();

	void Translate(glm::vec3 _amount);
	void Rotate(glm::vec3 _amount);
	void Scale(glm::vec3 _amount);
};