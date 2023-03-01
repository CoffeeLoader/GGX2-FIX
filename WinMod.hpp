
// Developed by Coffee Loader
// https://github.com/CoffeeLoader

#include "Memory.hpp"
Memory m;

#include "ini.h"
mINI::INIFile file("Settings.ini");
mINI::INIStructure ini;
bool IsRead = file.read(ini);

namespace WinMod {

	HWND WinHandle{ 0 };

	const bool NoBorderless = ini["Window"]["NoBorderless"] == "False" ? false : true;
	const bool Background = ini["Window"]["Background"] == "False" ? false : true;
	const bool KeepAspectRatio = ini["Window"]["KeepAspectRatio"] == "False" ? false : true;
	const bool TopMost = ini["Window"]["TopMost"] == "False" ? false : true;
	const bool Debug = ini["Extras"]["Debug"] == "True" ? true : false;
	const bool Unlock = ini["Extras"]["UnlockCharacters"] == "False" ? false : true;

	uintptr_t Resolution[2]{ 
		ini["Window"]["AutoResolution"] == "False" ? std::stoi(ini["Window"]["ResX"]) : GetSystemMetrics(SM_CXSCREEN),
		ini["Window"]["AutoResolution"] == "False" ? std::stoi(ini["Window"]["ResY"]) : GetSystemMetrics(SM_CYSCREEN) 
	};

	uintptr_t Resolution4Per3[2]{ Resolution[1] / 3 * 4, (Resolution[0] - Resolution4Per3[0]) / 2 };

	int main() {

		if (Debug) {AllocConsole(); FILE* Console = freopen("CONOUT$", "w", stdout);}

		for (size_t i = 0; i < 60; i++) {
			WinHandle = FindWindowA("GUILTYGEAR X2 #RELOAD", NULL);
			if (WinHandle) {
				break;
			}
			if (i >= 60) {
				return EXIT_SUCCESS;
			}
			Sleep(16);
		}

		if (Background) {system("start Background.exe");}
		if (NoBorderless) {SetWindowLongA(WinHandle, GWL_STYLE, 0x14000000);}

		if (KeepAspectRatio) {
			SetWindowPos(WinHandle, TopMost ? HWND_TOPMOST:HWND_TOP, Resolution4Per3[1], 0, 
				Resolution4Per3[0], Resolution[1], NULL);
		}
		else {
			SetWindowPos(WinHandle, TopMost ? HWND_TOPMOST:HWND_TOP, 0, 0, 
				Resolution[0], Resolution[1], NULL);
		}
		
		if (Unlock) {
			GetWindowThreadProcessId(WinHandle, &m.PID);
			m.PHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, m.PID);
			uintptr_t GGX2Module = m.GetModule("ggx2.exe");
			m.MemWrite(GGX2Module + 0x20147F, 0x0101, 2);
		}

		for (size_t i = 0; i < 60; i++) {
			BringWindowToTop(WinHandle);
			SetForegroundWindow(WinHandle);
			Sleep(16);
		}

		return EXIT_SUCCESS;
	}

}

