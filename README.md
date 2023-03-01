## Begin of Page
A Simple Mod thats allow some modifications on Screen Size of this Game.

![Av1.1](https://raw.githubusercontent.com/CoffeeLoader/GGX2-FIX/main/Screenshot/Av1.1.png)

## How to Install on Windows
* Be sure you have .Net Framework 3.5 working.
* Configure the game for Window Mode using Config.exe inside game folder.
* Download the newer [Release](https://github.com/CoffeeLoader/GGX2-FIX/releases).
* Extract DDRAW.dll, Background.exe and Background.png inside game folder.
* Enjoy.

## How to Install on Linux (Lutris+Wine+D3D8to9+DXVK)
* Download [D3D8to9](https://github.com/crosire/d3d8to9/releases) and move d3d8.dll to game folder.
* Download [DXVK](https://github.com/doitsujin/dxvk/releases/tag/v2.1), extract and move d3d9.dll inside x32 to game folder.
* Download [GGX2 FIX v1.0](https://github.com/CoffeeLoader/GGX2-FIX/releases/tag/v1.0), extract and move DDRAW.dll to game folder.
* Install Lutris and open "config.exe" using "Wine" to configure game to Window Mode.
* Add game to Lutris, configure Resolution and Disable DXVK on Config of this game.
* Search for Wine Configuration on Lutris, go to Libraries and manual add " ddraw " to list.
* Edit and set "Native then Embedded", finish the configuration.
* Enjoy.

## How to Build and Compile on Windows

### To Build
* Be sure you have Cmake.
* Download this Repository or Clone using Git Bash.
* Open CMD or PowerShell and point to Repository Folder.
* cmake CMakeLists.txt

### To Compile
* Be sure you have Visual Studio 2022 or newer with C++ Content.
* Open GGX2WinMod.sln file.
* Change Debug to Release.
* CTRL + SHIFT + B to Compile.

### To Compile Background
* Be sure you have Visual Studio 2022 or newer with C# and .Net Framework Content.
* Open Background.sln file.
* Change Debug to Release.
* CTRL + SHIFT + B to Compile.

## Version 1.0
* Allows only stretch window to resolution screen like a Windowed Borderless Mode.
## Version 1.1
* Now the game will open respecting the Aspect Ratio 4/3.
* You can customize the Background with some image with name Background.png inside game folder.
* Secret Characters Unlocked (Tested on GOG Version)
## Version 1.2
* Added [Settings](https://github.com/CoffeeLoader/GGX2-FIX/blob/main/Settings.ini) File to customize this Mod

# Credits to folowing projects.

* [WRAP_DLL](https://github.com/mavenlin/wrap_dll) Used to Create a DLL Wrapper.
* [EDIT_MEMORY](https://github.com/call-042PE/edit-memory) Some Functions to Memory Modifier.
* [mINI](https://github.com/pulzed/mINI) The library for the INI File Manager
