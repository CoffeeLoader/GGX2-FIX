
// Developed by Coffee Loader
// https://github.com/CoffeeLoader

#include <string>
#include <vector>
#include <psapi.h>

class Memory {
public:

	DWORD PID = 0;
	HANDLE PHandle = 0;

    uintptr_t GetModule(std::string ModuleName) {
        HMODULE hMods[1024];
        DWORD cbNeeded;
        if (EnumProcessModules(PHandle, hMods, sizeof(hMods), &cbNeeded)) {
            for (unsigned int i = 0; i < (cbNeeded / sizeof(HMODULE)); i++) {
                TCHAR szModName[MAX_PATH];
                if (GetModuleBaseName(PHandle, hMods[i], szModName, sizeof(szModName) / sizeof(TCHAR))) {
                    if ((std::string)szModName == ModuleName) {
                        return (uintptr_t)hMods[i];
                    }
                }
            }
        }
        return 0;
    }

	template <typename Type = unsigned int>
	Type MemRead(uintptr_t Address, size_t Size = sizeof(Type)) {
		Type TEMP = 0;
		ReadProcessMemory(PHandle, (LPCVOID)Address, &TEMP, Size, 0);
		return TEMP;
	}

	template <typename Type = unsigned int>
	void MemWrite(uintptr_t Address, Type Value, size_t Size = sizeof(Type)) {
		WriteProcessMemory(PHandle, (LPVOID)Address, &Value, Size, 0);
	}
};