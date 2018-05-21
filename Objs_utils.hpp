#pragma once
#ifndef OBJ_DIFFS
#define OBJ_DIFFS

#include "Obj_splitted.hpp"

namespace Obj_version_control
{
	// class that represent some utils to process objs
	class Obj_utils
	{

	public:

		/// <summary>Get difs between two files</summary>
		/// <param name="prev_obj">prev version of the obj</param>  
		/// <param name="current_obj">current version of the obj</param> 
		/// <returns>vector of changes found</returns>  
		vector<Obj_change> Get_diffs(Obj_splitted & prev_obj, Obj_splitted & current_obj);

		/// <summary>restore the obj to a prev version</summary>
		/// <param name="num_prev_version">obj num version</param>  
		/// <param name="original_file">route to original file</param> 
		/// <returns>vector of lines to compose the restored obj</returns>  
		vector<string> Get_prev_version_obj(unsigned int num_prev_version, const char * original_file, string & file_name);

		/// <summary>restore the obj a desire version</summary>
		/// <param name="obj_restored">obj that is going to be restores</param>  
		/// <param name="sum">sum file to apply changes</param> 
		/// <param name="hg">hg file to apply changes</param> 
		/// <returns>vector of lines to compose the restored obj</returns>  
		void Restore_obj(vector<string> & obj_restored, vector<string> & sum, vector<string> & hg);
	};
}
#endif