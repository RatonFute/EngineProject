#pragma comment (lib, "d3d12.lib")
#include <Windows.h>
#include <d3d12.h>


LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CLOSE:
		PostQuitMessage(69);
		break;

	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR	lpCmdLine,
	int		nCmdShow)
{
	const auto pClassName = L"fenetreDeMerde";
	//register window class
	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = DefWindowProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = pClassName;
	wc.hIconSm = nullptr;
	RegisterClassEx(&wc);
	//create window instance
	HWND hWnd = CreateWindowExW(
		0, pClassName,
		L"Je vais tout casser",
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		200, 200, 980, 720,
		nullptr, nullptr, hInstance, nullptr
	);
	//HWND pWnd = CreateWindowExW(
	//	0, pClassName,
	//	L"Popup",
	//	WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
	//	400, 350, 640, 480,
	//	nullptr, nullptr, hInstance, nullptr
	//);
	//show the window
	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);
	//ShowWindow(pWnd, SW_SHOW);

	//message pump
	MSG msg;
	BOOL gResult;
	while (gResult = GetMessage(&msg, 0, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	if (gResult == -1)
	{
		return -1;
	}
	else
	{
		return msg.wParam;
	}
}

