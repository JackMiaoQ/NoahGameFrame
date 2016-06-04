// -------------------------------------------------------------------------
//    @FileName      :    NFWorldLogicPlugin.cpp
//    @Author           :    LvSheng.Huang
//    @Date             :    2012-07-14 08:51
//    @Module           :    NFWorldLogicPlugin
//
// -------------------------------------------------------------------------


#include "NFCWorldLogicModule.h"
#include "NFWorldLogicPlugin.h"
#include "NFCWSSwichServerModule.h"
#include "NFCTeamModule.h"

//
//

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
#if NF_PLATFORM == NF_PLATFORM_WIN
    SetConsoleTitle("NFWorldServer");
#endif // NF_PLATFORM
    CREATE_PLUGIN(pm, NFWorldLogicPlugin)
};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFWorldLogicPlugin)
};

//////////////////////////////////////////////////////////////////////////

const int NFWorldLogicPlugin::GetPluginVersion()
{
    return 0;
}

const std::string NFWorldLogicPlugin::GetPluginName()
{
    return GET_CLASS_NAME(NFWorldLogicPlugin);
}

void NFWorldLogicPlugin::Install()
{

	REGISTER_MODULE(pPluginManager, NFCWorldLogicModule)
	REGISTER_MODULE(pPluginManager, NFCWSSwichServerModule)
	REGISTER_MODULE(pPluginManager, NFCTeamModule)
}

void NFWorldLogicPlugin::Uninstall()
{
	UNREGISTER_MODULE(pPluginManager, NFCTeamModule)
	UNREGISTER_MODULE(pPluginManager, NFCWSSwichServerModule)
	UNREGISTER_MODULE(pPluginManager, NFCWorldLogicModule)
}
