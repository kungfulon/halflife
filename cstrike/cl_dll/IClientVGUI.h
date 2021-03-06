#ifndef ICLIENTVGUI_H
#define ICLIENTVGUI_H

#ifdef _WIN32
#pragma once
#endif

class IClientVGUI : public IBaseInterface
{
public:
	virtual void Initialize(CreateInterfaceFn *factories, int count) = 0;
	virtual void Start(void) = 0;
	virtual void SetParent(int parent) = 0;
	virtual bool UseVGUI1(void) = 0;
	virtual void HideScoreBoard(void) = 0;
	virtual void HideAllVGUIMenu(void) = 0;
	virtual void ActivateClientUI(void) = 0;
	virtual void HideClientUI(void) = 0;
};

#define CLIENTVGUI_INTERFACE_VERSION "VClientVGUI001"

extern IClientVGUI *g_pClientVGUI;

#endif
