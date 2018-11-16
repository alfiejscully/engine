#include <vector>
#include <SDL2/SDL.h>

class Keyboard
{
private:

	std::vector<int> m_keyCodes;
	
	bool m_quit = false;

public:

	bool getKey(int keyCode);
	bool getKeyDown(int keyCode);
	bool getKeyUp(int keyCode);

	void PollEvents();
	bool IsClosed() const { return m_quit; }
};