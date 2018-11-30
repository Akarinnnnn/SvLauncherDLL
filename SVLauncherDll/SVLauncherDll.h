#include "stdafx.h"


#ifdef EXPORT
#define SVLAUNCHER_API __declspec(dllexport)
#else
#define SVLAUNCHER_API __declspec(dllimport)
#endif
/*
use struct<svarg> as CallSv(svarg a) paramitter,<svarg>is defined in SVLauncherDLL.h
if you can't create a struct which typed of <PROCESS_INFORMATION>,
you can use CallSvWithDefPI() instead.
*/

//still debugging

namespace SVLauncherDll
{
	__declspec(dllexport) typedef struct svarg
	{
		LPWSTR execfile = (wchar_t*)L".\\dontstarve_dedicated_server_nullrenderer.exe";
		LPWSTR cluster = (wchar_t*)L"Cluster_1";
		LPWSTR shard = (wchar_t*)L"Master";
		LPWSTR rootstroage = nullptr;
		LPWSTR conf_dir = nullptr;
		LPWSTR log_backup_dir = nullptr;
		LPWSTR Token = nullptr;
		LPWSTR CurDir = (wchar_t*)L"";
		bool offline = 1;
		char maxplayers = 4;
		char tickrate = 15;
		wchar_t* Con_Title = (wchar_t*)L"";

	};
	svarg Defaultarg;
	PROCESS_INFORMATION pi_thisSV;
	__declspec(dllexport) wchar_t* _cdecl getarg(svarg a);

	__declspec(dllexport) wchar_t* _cdecl GetCurDir(svarg a);

	__declspec(dllexport) PROCESS_INFORMATION* _cdecl _callsv(wchar_t CmdLine[500], wchar_t CurDir[MAX_PATH]);

	__declspec(dllexport) PROCESS_INFORMATION* _cdecl CallSv(svarg a);

	__declspec(dllexport) void _cdecl CallSvWithDefPI(svarg a);

	__declspec(dllexport) bool  _cdecl killsv(PROCESS_INFORMATION a);
}