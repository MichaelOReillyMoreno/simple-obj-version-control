#pragma once
#ifndef OBJ_RECORD_MANAGER
#define OBJ_RECORD_MANAGER

#include "Objs_utils.hpp"
#include "lua_util.hpp"

namespace Obj_version_control
{
	class Obj_record_manager
	{
	private:

		//lua utilities
		Lua_util lua_util;

		//obj utilities
		Obj_utils obj_utils;

		//prev version number
		int num_prev_version;

		//current version number
		unsigned int num_current_version;

	private:

		/// <summary>return the number of the last version</summary>
		/// <param name="file_name">File name</param>  
		/// <returns>number of the last version</returns>  
		int Get_num_prev_version(string & file_name);

	public:

		Obj_record_manager();

		/// <summary>registre the changes between two files</summary>
		/// <param name="current_file">current file name</param>
		/// <param name="original_file">original file name</param>
		void Register_changes(const char * current_file, const char * original_file);

		/// <summary>restore the file to an especific version version</summary>
		/// <param name="original_file">original file name</param>
		/// <param name="num_version">version number</param>
		void Restore_version(const char * original_file, int num_version);

		/// <summary>restore the file to the last version</summary>
		/// <param name="original_file">original file name</param>
		void Restore_last_version(const char * original_file);
	};
}
#endif