#include "Transform.h"


void Transform::SetLocalPosition(glm::vec3 _posistion)
{
	m_localPosition = _posistion;
}
void Transform::SetLocalRotation(glm::vec3 _rotation)
{
	m_localRotation = _rotation;
}
void Transform::SetLocalScale(glm::vec3 _scale)
{
	m_localScale = _scale;
}

glm::vec3 Transform::GetLocalPosition()
{
	return m_localPosition;
}

glm::vec3 Transform::GetLocalRotation()
{
	return m_localRotation;
}

glm::vec3 Transform::GetLocalScale()
{
	return m_localScale;
}

void Transform::Translate(glm::vec3 _amount)
{
	m_localPosition += _amount;
}

void Transform::Rotate(glm::vec3 _amount)
{
	m_localRotation += _amount;
}

void Transform::Scale(glm::vec3 _amount)
{
	m_localScale += _amount;
}