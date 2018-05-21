#pragma once
#ifndef LUA_UTIL
#define LUA_UTIL

#include <LuaState.h>
#include<string>


#include <LuaState.h>

using namespace std;

namespace Obj_version_control
{
	class Lua_util
	{

	private:

		lua::State state;

	public:

		/// <summary>Gets the name of the file from a route</summary>
		/// <param name="route">File route</param>  
		/// <returns>file name</returns>  
		std::string Get_name_file_from_route(const char * route);

	};
}
#endif