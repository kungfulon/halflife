#include "interface.h"
#include "IClientVGUI.h"

#include <vgui/isurface.h>

#include <vgui_controls\Controls.h>

using namespace vgui;

IClientVGUI *g_pClientVGUI;

class CClientVGUI : public IClientVGUI
{
public:
	virtual void Initialize(CreateInterfaceFn *factories, int count)
	{
		VGui_InitInterfacesList("NewClientUI", factories, count);

		g_pClientVGUI->Initialize(factories, count);
	}

	virtual void Start(void)
	{
		g_pClientVGUI->Start();
	}

	virtual void SetParent(int parent)
	{
		g_pClientVGUI->SetParent(parent);
	}

	virtual bool UseVGUI1(void)
	{
		surface()->DrawSetColor(255, 255, 255, 255);
		surface()->DrawFilledRect(0, 0, 200, 200);

		return g_pClientVGUI->UseVGUI1();
	}

	virtual void HideScoreBoard(void)
	{
		g_pClientVGUI->HideScoreBoard();
	}

	virtual void HideAllVGUIMenu(void)
	{
		g_pClientVGUI->HideAllVGUIMenu();
	}

	virtual void ActivateClientUI(void)
	{
		g_pClientVGUI->ActivateClientUI();
	}

	virtual void HideClientUI(void)
	{
		g_pClientVGUI->HideClientUI();
	}
};

EXPOSE_SINGLE_INTERFACE(CClientVGUI, IClientVGUI, CLIENTVGUI_INTERFACE_VERSION);
