#include <windows.h>
#include <stdio.h>
#include "hook_macro.h"

HINSTANCE mHinst = 0, mHinstDLL = 0;

UINT_PTR mProcs[22] = {0};

LPCSTR mImportNames[] = {
  "AcquireDDThreadLock",
  "CompleteCreateSysmemSurface",
  "D3DParseUnknownCommand",
  "DDGetAttachedSurfaceLcl",
  "DDInternalLock",
  "DDInternalUnlock",
  "DSoundHelp",
  "DirectDrawCreate",
  "DirectDrawCreateClipper",
  "DirectDrawCreateEx",
  "DirectDrawEnumerateA",
  "DirectDrawEnumerateExA",
  "DirectDrawEnumerateExW",
  "DirectDrawEnumerateW",
  "DllCanUnloadNow",
  "DllGetClassObject",
  "GetDDSurfaceLocal",
  "GetOLEThunkData",
  "GetSurfaceFromDC",
  "RegisterSpecialCase",
  "ReleaseDDThreadLock",
  "SetAppCompatData",
};

#ifndef _DEBUG
inline void log_info(const char* info) {
}
#else
FILE* debug;
inline void log_info(const char* info) {
  fprintf(debug, "%s\n", info);
  fflush(debug);
}
#endif

#include "empty.h"

inline void _hook_setup() {
#ifdef ACQUIREDDTHREADLOCK
  AcquireDDThreadLock_real = (AcquireDDThreadLock_ptr)mProcs[0];
  mProcs[0] = (UINT_PTR)&AcquireDDThreadLock_fake;
#endif
#ifdef COMPLETECREATESYSMEMSURFACE
  CompleteCreateSysmemSurface_real = (CompleteCreateSysmemSurface_ptr)mProcs[1];
  mProcs[1] = (UINT_PTR)&CompleteCreateSysmemSurface_fake;
#endif
#ifdef D3DPARSEUNKNOWNCOMMAND
  D3DParseUnknownCommand_real = (D3DParseUnknownCommand_ptr)mProcs[2];
  mProcs[2] = (UINT_PTR)&D3DParseUnknownCommand_fake;
#endif
#ifdef DDGETATTACHEDSURFACELCL
  DDGetAttachedSurfaceLcl_real = (DDGetAttachedSurfaceLcl_ptr)mProcs[3];
  mProcs[3] = (UINT_PTR)&DDGetAttachedSurfaceLcl_fake;
#endif
#ifdef DDINTERNALLOCK
  DDInternalLock_real = (DDInternalLock_ptr)mProcs[4];
  mProcs[4] = (UINT_PTR)&DDInternalLock_fake;
#endif
#ifdef DDINTERNALUNLOCK
  DDInternalUnlock_real = (DDInternalUnlock_ptr)mProcs[5];
  mProcs[5] = (UINT_PTR)&DDInternalUnlock_fake;
#endif
#ifdef DSOUNDHELP
  DSoundHelp_real = (DSoundHelp_ptr)mProcs[6];
  mProcs[6] = (UINT_PTR)&DSoundHelp_fake;
#endif
#ifdef DIRECTDRAWCREATE
  DirectDrawCreate_real = (DirectDrawCreate_ptr)mProcs[7];
  mProcs[7] = (UINT_PTR)&DirectDrawCreate_fake;
#endif
#ifdef DIRECTDRAWCREATECLIPPER
  DirectDrawCreateClipper_real = (DirectDrawCreateClipper_ptr)mProcs[8];
  mProcs[8] = (UINT_PTR)&DirectDrawCreateClipper_fake;
#endif
#ifdef DIRECTDRAWCREATEEX
  DirectDrawCreateEx_real = (DirectDrawCreateEx_ptr)mProcs[9];
  mProcs[9] = (UINT_PTR)&DirectDrawCreateEx_fake;
#endif
#ifdef DIRECTDRAWENUMERATEA
  DirectDrawEnumerateA_real = (DirectDrawEnumerateA_ptr)mProcs[10];
  mProcs[10] = (UINT_PTR)&DirectDrawEnumerateA_fake;
#endif
#ifdef DIRECTDRAWENUMERATEEXA
  DirectDrawEnumerateExA_real = (DirectDrawEnumerateExA_ptr)mProcs[11];
  mProcs[11] = (UINT_PTR)&DirectDrawEnumerateExA_fake;
#endif
#ifdef DIRECTDRAWENUMERATEEXW
  DirectDrawEnumerateExW_real = (DirectDrawEnumerateExW_ptr)mProcs[12];
  mProcs[12] = (UINT_PTR)&DirectDrawEnumerateExW_fake;
#endif
#ifdef DIRECTDRAWENUMERATEW
  DirectDrawEnumerateW_real = (DirectDrawEnumerateW_ptr)mProcs[13];
  mProcs[13] = (UINT_PTR)&DirectDrawEnumerateW_fake;
#endif
#ifdef DLLCANUNLOADNOW
  DllCanUnloadNow_real = (DllCanUnloadNow_ptr)mProcs[14];
  mProcs[14] = (UINT_PTR)&DllCanUnloadNow_fake;
#endif
#ifdef DLLGETCLASSOBJECT
  DllGetClassObject_real = (DllGetClassObject_ptr)mProcs[15];
  mProcs[15] = (UINT_PTR)&DllGetClassObject_fake;
#endif
#ifdef GETDDSURFACELOCAL
  GetDDSurfaceLocal_real = (GetDDSurfaceLocal_ptr)mProcs[16];
  mProcs[16] = (UINT_PTR)&GetDDSurfaceLocal_fake;
#endif
#ifdef GETOLETHUNKDATA
  GetOLEThunkData_real = (GetOLEThunkData_ptr)mProcs[17];
  mProcs[17] = (UINT_PTR)&GetOLEThunkData_fake;
#endif
#ifdef GETSURFACEFROMDC
  GetSurfaceFromDC_real = (GetSurfaceFromDC_ptr)mProcs[18];
  mProcs[18] = (UINT_PTR)&GetSurfaceFromDC_fake;
#endif
#ifdef REGISTERSPECIALCASE
  RegisterSpecialCase_real = (RegisterSpecialCase_ptr)mProcs[19];
  mProcs[19] = (UINT_PTR)&RegisterSpecialCase_fake;
#endif
#ifdef RELEASEDDTHREADLOCK
  ReleaseDDThreadLock_real = (ReleaseDDThreadLock_ptr)mProcs[20];
  mProcs[20] = (UINT_PTR)&ReleaseDDThreadLock_fake;
#endif
#ifdef SETAPPCOMPATDATA
  SetAppCompatData_real = (SetAppCompatData_ptr)mProcs[21];
  mProcs[21] = (UINT_PTR)&SetAppCompatData_fake;
#endif
}

#include "WinMod.hpp"
HANDLE MyThread{ 0 };

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
  
  if (!MyThread) {
      MyThread = CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)WinMod::main, NULL, NULL, NULL);
  }

  mHinst = hinstDLL;
  if (fdwReason == DLL_PROCESS_ATTACH) {
    char path[MAX_PATH];
    GetSystemDirectoryA(path, MAX_PATH);
    strcat_s(path, "\\ddraw.dll");
    mHinstDLL = LoadLibraryA(path);
    if (!mHinstDLL) {
      return FALSE;
    }
    for (int i = 0; i < 22; ++i) {
      mProcs[i] = (UINT_PTR)GetProcAddress(mHinstDLL, mImportNames[i]);
    }
    _hook_setup();
#ifdef _DEBUG
    debug = fopen("./debug.log", "a");
#endif
  } else if (fdwReason == DLL_PROCESS_DETACH) {
#ifdef _DEBUG
    fclose(debug);
#endif
    system("taskkill /F /IM Background.exe");
    FreeLibrary(mHinstDLL);
  }
  return TRUE;
}

extern "C" __declspec(naked) void __stdcall AcquireDDThreadLock_wrapper(){
#ifdef _DEBUG
  log_info("calling AcquireDDThreadLock");
#endif
  __asm{jmp mProcs[0 * 4]}
}
extern "C" __declspec(naked) void __stdcall CompleteCreateSysmemSurface_wrapper(){
#ifdef _DEBUG
  log_info("calling CompleteCreateSysmemSurface");
#endif
  __asm{jmp mProcs[1 * 4]}
}
extern "C" __declspec(naked) void __stdcall D3DParseUnknownCommand_wrapper(){
#ifdef _DEBUG
  log_info("calling D3DParseUnknownCommand");
#endif
  __asm{jmp mProcs[2 * 4]}
}
extern "C" __declspec(naked) void __stdcall DDGetAttachedSurfaceLcl_wrapper(){
#ifdef _DEBUG
  log_info("calling DDGetAttachedSurfaceLcl");
#endif
  __asm{jmp mProcs[3 * 4]}
}
extern "C" __declspec(naked) void __stdcall DDInternalLock_wrapper(){
#ifdef _DEBUG
  log_info("calling DDInternalLock");
#endif
  __asm{jmp mProcs[4 * 4]}
}
extern "C" __declspec(naked) void __stdcall DDInternalUnlock_wrapper(){
#ifdef _DEBUG
  log_info("calling DDInternalUnlock");
#endif
  __asm{jmp mProcs[5 * 4]}
}
extern "C" __declspec(naked) void __stdcall DSoundHelp_wrapper(){
#ifdef _DEBUG
  log_info("calling DSoundHelp");
#endif
  __asm{jmp mProcs[6 * 4]}
}
extern "C" __declspec(naked) void __stdcall DirectDrawCreate_wrapper(){
#ifdef _DEBUG
  log_info("calling DirectDrawCreate");
#endif
  __asm{jmp mProcs[7 * 4]}
}
extern "C" __declspec(naked) void __stdcall DirectDrawCreateClipper_wrapper(){
#ifdef _DEBUG
  log_info("calling DirectDrawCreateClipper");
#endif
  __asm{jmp mProcs[8 * 4]}
}
extern "C" __declspec(naked) void __stdcall DirectDrawCreateEx_wrapper(){
#ifdef _DEBUG
  log_info("calling DirectDrawCreateEx");
#endif
  __asm{jmp mProcs[9 * 4]}
}
extern "C" __declspec(naked) void __stdcall DirectDrawEnumerateA_wrapper(){
#ifdef _DEBUG
  log_info("calling DirectDrawEnumerateA");
#endif
  __asm{jmp mProcs[10 * 4]}
}
extern "C" __declspec(naked) void __stdcall DirectDrawEnumerateExA_wrapper(){
#ifdef _DEBUG
  log_info("calling DirectDrawEnumerateExA");
#endif
  __asm{jmp mProcs[11 * 4]}
}
extern "C" __declspec(naked) void __stdcall DirectDrawEnumerateExW_wrapper(){
#ifdef _DEBUG
  log_info("calling DirectDrawEnumerateExW");
#endif
  __asm{jmp mProcs[12 * 4]}
}
extern "C" __declspec(naked) void __stdcall DirectDrawEnumerateW_wrapper(){
#ifdef _DEBUG
  log_info("calling DirectDrawEnumerateW");
#endif
  __asm{jmp mProcs[13 * 4]}
}
extern "C" __declspec(naked) void __stdcall DllCanUnloadNow_wrapper(){
#ifdef _DEBUG
  log_info("calling DllCanUnloadNow");
#endif
  __asm{jmp mProcs[14 * 4]}
}
extern "C" __declspec(naked) void __stdcall DllGetClassObject_wrapper(){
#ifdef _DEBUG
  log_info("calling DllGetClassObject");
#endif
  __asm{jmp mProcs[15 * 4]}
}
extern "C" __declspec(naked) void __stdcall GetDDSurfaceLocal_wrapper(){
#ifdef _DEBUG
  log_info("calling GetDDSurfaceLocal");
#endif
  __asm{jmp mProcs[16 * 4]}
}
extern "C" __declspec(naked) void __stdcall GetOLEThunkData_wrapper(){
#ifdef _DEBUG
  log_info("calling GetOLEThunkData");
#endif
  __asm{jmp mProcs[17 * 4]}
}
extern "C" __declspec(naked) void __stdcall GetSurfaceFromDC_wrapper(){
#ifdef _DEBUG
  log_info("calling GetSurfaceFromDC");
#endif
  __asm{jmp mProcs[18 * 4]}
}
extern "C" __declspec(naked) void __stdcall RegisterSpecialCase_wrapper(){
#ifdef _DEBUG
  log_info("calling RegisterSpecialCase");
#endif
  __asm{jmp mProcs[19 * 4]}
}
extern "C" __declspec(naked) void __stdcall ReleaseDDThreadLock_wrapper(){
#ifdef _DEBUG
  log_info("calling ReleaseDDThreadLock");
#endif
  __asm{jmp mProcs[20 * 4]}
}
extern "C" __declspec(naked) void __stdcall SetAppCompatData_wrapper(){
#ifdef _DEBUG
  log_info("calling SetAppCompatData");
#endif
  __asm{jmp mProcs[21 * 4]}
}
