#include "Engine/Application.h"

class Editor : public Engine::Application
{
public:
	Editor()
	{

	}
};

int main()
{
	Editor editor;
	editor.Run();
}