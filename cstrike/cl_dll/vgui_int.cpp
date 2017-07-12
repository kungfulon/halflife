#include "interface.h"
#include "IClientVGUI.h"

#include <vgui/isurface.h>
#include <vgui/isystem.h>
#include <vgui/IVGui.h>

#include <vgui_controls\Controls.h>
#include <vgui_controls\Panel.h>
#include <vgui_controls\frame.h>

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

		m_pTestPanel = NULL;
		m_hNewScheme = scheme()->LoadSchemeFromFile("resource/SourceScheme.res", "SourceScheme");
	}

	virtual void SetParent(int parent)
	{
		g_pClientVGUI->SetParent(parent);

		m_pTestPanel = CREATE_PANEL(Frame, NULL, "XD");
		m_pTestPanel->SetParent(parent);
		m_pTestPanel->SetScheme(m_hNewScheme);
		m_pTestPanel->InvalidateLayout(false, true);
		m_pTestPanel->SetTitle(L"XDDDDDDDDDDDD", true);
		m_pTestPanel->SetPos(0, 0);
		m_pTestPanel->SetSize(200, 200);
		m_pTestPanel->Activate();
	}

	virtual bool UseVGUI1(void)
	{
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

private:
	Frame *m_pTestPanel;
	HScheme m_hNewScheme;
};

EXPOSE_SINGLE_INTERFACE(CClientVGUI, IClientVGUI, CLIENTVGUI_INTERFACE_VERSION);
