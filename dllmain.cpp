#include <Windows.h>
#include "Detours/detours.h"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
	return TRUE;
}

extern "C" __declspec(dllexport) void HookAttach(void** target, void* detour) {
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(target, detour);
	DetourTransactionCommit();
}

extern "C" __declspec(dllexport) void HookDetach(void** target, void* detour) {
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourDetach(target, detour);
	DetourTransactionCommit();
}
