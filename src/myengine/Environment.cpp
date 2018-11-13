#include "Environment.h"

float Environment::GetDeltaTime()
{
	m_lastTime = SDL_GetTicks();

	m_time = SDL_GetTicks();
	m_diff = m_time - m_lastTime;
	m_deltaTime = m_diff / 1000.0f;
	m_lastTime = m_time;

	if (m_idealTime > m_deltaTime)
	{
		SDL_Delay((m_idealTime - m_deltaTime) * 1000.0f);
	}

	return m_deltaTime;
}