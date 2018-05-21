
#include "lua_util.hpp"



string Obj_version_control::Lua_util::Get_name_file_from_route(const char * route)
{

	state.doFile("../../lua_scripts/utils.lua");
	return state["get_name_file_from_route"](route);
}
