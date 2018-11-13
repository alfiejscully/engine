#include <SDL2/SDL.h>

class Environment
{
private:

	float m_deltaTime;
	float m_lastTime;
	float m_diff;
	float m_time;
	float m_idealTime = 1.0f / 60.0f;

public:

	float GetDeltaTime();
};