## Begin of Page
A Simple Mod thats allow some modifications on Screen Size of this Game.

![Bv1.0](https://raw.githubusercontent.com/CoffeeLoader/GGX2-FIX/main/Screenshot/Bv1.0.png)

## How to Install on Windows
* Configure the game for Window Mode using Config.exe inside game folder.
* Download the newer [Release](https://github.com/CoffeeLoader/GGX2-FIX/releases).
* Extract DDRAW.dll inside game folder.
* Enjoy.

## How to Install on Linux (Lutris+Wine+D3D8to9+DXVK)
* Download [D3D8to9](https://github.com/crosire/d3d8to9/releases) and move d3d8.dll to game folder.
* Download [DXVK](https://github.com/doitsujin/dxvk/releases/tag/v2.1), extract and move d3d9.dll inside x32 to game folder.
* Install Lutris and open config.exe using Wine to configure game to Window Mode.
* On Lutris, add game to List, configure Resolution and Disable DXVK on Config of this game. We already installed it manually.
* Still on Lutris, search for Wine Configuration, go to Libraries and manual add ddraw to list.
* Edit and set "Native then Embedded", finish the configuration.
* Enjoy.

## How to Build and Compile on Windows

### To Build
* Be sure you have Cmake.
* Download this Repository or Clone using Git Bash.
* Open CMD or PowerShell and point to Repository Folder.
* cmake CMakeLists.txt

### To Compile
* Be sure you have Visual Studio 2022 or newer.
* Open GGX2WinMod.sln file.
* Change Debug to Release.
* CTRL + SHIFT + B to Compile.


## Version 1.0
Allows only stretch window to resolution screen like a Windowed Borderless Mode.

# Credits to folowing projects.

[WRAP_DLL](https://github.com/mavenlin/wrap_dll)
Used to Create a DLL Wrapper.
