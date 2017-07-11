//========= Copyright © 1996-2005, Valve Corporation, All rights reserved. ============//
//
// Purpose: An application framework 
//
// $Revision: $
// $NoKeywords: $
//=============================================================================//

#ifndef IAPPSYSTEM_H
#define IAPPSYSTEM_H

#ifdef _WIN32
#pragma once
#endif

#include "interface.h"


//-----------------------------------------------------------------------------
// Client systems are singleton objects in the client codebase responsible for
// various tasks
// The order in which the client systems appear in this list are the
// order in which they are initialized and updated. They are shut down in
// reverse order from which they are initialized.
//-----------------------------------------------------------------------------

enum InitReturnVal_t
{
	INIT_FAILED = 0,
	INIT_OK,

	INIT_LAST_VAL,
};


class IAppSystem
{

};

#endif // IAPPSYSTEM_H

