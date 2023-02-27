
// Developed by Coffee Loader

namespace WinMod {

	uintptr_t Resolution[2]{ GetSystemMetrics(SM_CXSCREEN),GetSystemMetrics(SM_CYSCREEN) };
	uintptr_t Resolution4Per3[2]{ Resolution[1] / 3 * 4, (Resolution[0] - Resolution4Per3[0]) / 2 };
	HWND WinHandle{ 0 };

	int main() {

		system("start Background.exe");
		//AllocConsole(); FILE* Console = freopen("CONOUT$", "w", stdout);
		
		while (!WinHandle) {
			WinHandle = FindWindowA("GUILTYGEAR X2 #RELOAD", NULL);
			Sleep(16);
		}

		SetWindowLongA(WinHandle, GWL_STYLE, 0x14000000);
		SetWindowPos(WinHandle, HWND_TOPMOST, Resolution4Per3[1], 0, Resolution4Per3[0], Resolution[1], NULL);

		DWORD PID; GetWindowThreadProcessId(WinHandle, &PID);
		HANDLE GAME{ OpenProcess(PROCESS_ALL_ACCESS, FALSE, PID) };
		WriteProcessMemory(GAME, (LPVOID)0x60147F, new int (0x0101), 2, 0);

		for (size_t i = 0; i < 60; i++) {
			BringWindowToTop(WinHandle);
			SetForegroundWindow(WinHandle);
			Sleep(16);
		}

		return EXIT_SUCCESS;
	}

}

