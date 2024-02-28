#include "Engine/Engine.h"
#include "Engine/Application.h"

class Editor : public Engine::Application
{
public:
	Editor()
	{
		// Will eventually ONLY create a window, not handle events, graphics, or anything else. (Does everything for now just so the code actually runs)
		Engine::CreateWindow();
	}
};

int main()
{
	Editor editor;
	editor.Run();
}