#include "UI.h"
#include <iostream>

#ifdef _WINDLL

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
    if (fdwReason == DLL_PROCESS_ATTACH)
    {
        DisableThreadLibraryCalls(hinstDLL);
        CreateThread(nullptr, NULL, (LPTHREAD_START_ROUTINE)UI::Render, nullptr, NULL, nullptr);
        return TRUE;
    }

    return TRUE;
}

#else



int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nShowCmd)
{
    //Auto hide or show console window depeneding on release/debug build.
    #if defined _DEBUG
        //Debug Build
        AllocConsole();
        #pragma warning(disable: 4996)  //Allowing 4996 for console
        freopen("conin$", "r", stdin);
        freopen("conout$", "w", stdout);
        freopen("conout$", "w", stderr);
        #pragma warning(default: 4996)

    #else
        //Release Build
    #endif

    UI::Render();

    return 0;
}

#endif