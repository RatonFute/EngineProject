#include <Windows.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CLOSE:
		PostQuitMessage(69);
		break;

	//case WM_KEYDOWN:
	//	if (wParam == 'F')
	//	{
	//		SetWindowText(hWnd, L"KeyDown");
	//	}
	//	break;
	//}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}


int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)

{
	const auto pClassName = L"fenetreDeMerde";

	WNDCLASSEX wc = { sizeof(wc) };
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WndProc;
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
		0,
		pClassName,
		L"Je vais tout casser",
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		980,
		720,
		nullptr, //parent window
		nullptr, //menus
		hInstance,
		nullptr
	);

	//show the window
	ShowWindow(hWnd, SW_SHOW);

	//message pump
	MSG msg;
	BOOL gResult;
	while ((gResult = GetMessage(&msg, nullptr,0,0) > 0))
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