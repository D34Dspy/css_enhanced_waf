#include "glue.hpp"
#include "serverplugin.h"

ServerPlugin::ServerPlugin()
{
	load_allowed	 = false;
	m_pSourcemodGlue = new CSourcemodGlueInterface;
}