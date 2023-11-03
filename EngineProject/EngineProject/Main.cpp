#include <d3d12.h>
#include "Window.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance,
	PSTR cmdLine, int showCmd)
{
	Render::Window::getInstance()->CreateGameWin(L"Window", 100, 100);
	
}