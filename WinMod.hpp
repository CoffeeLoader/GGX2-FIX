
// Developed by Coffee Loader

namespace WinMod {

	uintptr_t Resolution[2]{ GetSystemMetrics(SM_CXSCREEN),GetSystemMetrics(SM_CYSCREEN) };
	uintptr_t Resolution4Per3[2]{ Resolution[1] * (4 / 3), (Resolution[0] - Resolution4Per3[0]) / 2 };

	HWND WinHandle{ FindWindowA("GUILTYGEAR X2 #RELOAD", NULL) };
	bool OriginalAspect{ false };
	uintptr_t Limit = 0;

	int main() {

		//AllocConsole();
		//FILE* Console = freopen("CONOUT$", "w", stdout);

		while (!WinHandle) {
			WinHandle = FindWindowA("GUILTYGEAR X2 #RELOAD", NULL);
			Sleep(16);

			Limit++;
			if (Limit > 120) {
				return EXIT_SUCCESS;
			}
		}

		SetWindowLongA(WinHandle, GWL_STYLE, 0x14000000);
		if (OriginalAspect) {
			SetWindowPos(WinHandle, HWND_TOPMOST, Resolution4Per3[1], 0, Resolution4Per3[0], Resolution[1], NULL);
		}
		else {
			SetWindowPos(WinHandle, HWND_DESKTOP, 0, 0, Resolution[0], Resolution[1], NULL);
		}

		return EXIT_SUCCESS;
	}

}

