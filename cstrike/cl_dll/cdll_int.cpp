#ifdef _WIN32
#include "winsani_in.h"
#include <windows.h>
#include "winsani_out.h"
#endif

#include "interface.h"

#include "wrect.h"
#include "cl_dll.h"

CSysModule *g_pClientDLL = nullptr;
void (*g_pF)(void *);
IBaseInterface *(*g_pCreateInterface)(const char *, int *);
cldll_func_t g_ClientDLLFuncs;
cl_enginefunc_t gEngfuncs;

bool LoadClientDLL()
{
	return ((g_pClientDLL = Sys_LoadModule("cstrike\\cl_dlls\\client_orig.dll")) != nullptr);
}

int Initialize(cl_enginefunc_t *pEnginefuncs, int iVersion)
{
	gEngfuncs = *pEnginefuncs;

	gEngfuncs.pfnClientCmd("echo \"XD\"");

	return g_ClientDLLFuncs.pInitFunc(pEnginefuncs, iVersion);
}

void *ClientFactory(void)
{
	return Sys_GetFactoryThis();
}

extern "C" EXPORT_FUNCTION void F(void *pv)
{
	if (!g_pClientDLL)
		if (!LoadClientDLL())
			return;

	if (!g_pF)
	{
		g_pF = (void(*)(void *))(Sys_GetProcAddress(g_pClientDLL, "F"));

		if (!g_pF)
			return;
	}

	g_pF(pv);

	cldll_func_t *pcldll_func = (cldll_func_t *)pv;

	memcpy(&g_ClientDLLFuncs, pcldll_func, sizeof(cldll_func_t));

	pcldll_func->pInitFunc = Initialize;
	pcldll_func->pClientFactory = ClientFactory;
}

IBaseInterface *CreateInterfaceLocal(const char *pName, int *pReturnCode);

#include "IClientVGUI.h"

extern "C" EXPORT_FUNCTION IBaseInterface *CreateInterface(const char *pName, int *pReturnCode)
{
	if (!g_pClientDLL)
		if (!LoadClientDLL())
			return NULL;

	if (!g_pCreateInterface)
	{
		g_pCreateInterface = (IBaseInterface *(*)(const char *, int *))(Sys_GetProcAddress(g_pClientDLL, "CreateInterface"));

		if (!g_pCreateInterface)
			return NULL;
	}

	if (!strcmp(pName, CLIENTVGUI_INTERFACE_VERSION))
	{
		g_pClientVGUI = (IClientVGUI *)g_pCreateInterface(pName, pReturnCode);

		return CreateInterfaceLocal(pName, pReturnCode);
	}

	return g_pCreateInterface(pName, pReturnCode);
}
