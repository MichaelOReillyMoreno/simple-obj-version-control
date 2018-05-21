#pragma once
#ifndef FILE_UTILS
#define FILE_UTILS

#include <iostream>
#include <fstream>

#include "Obj_change.hpp"

namespace Obj_version_control
{
	class File_utils
	{
	public:

		/// <summary>Reads a file </summary>
		/// <param name="file_name">File route</param>  
		static void Read_file(const std::string & file_name);

		/// <summary>Reads a file and converts it into a vector of text lines</summary>
		/// <param name="file_name">File route</param>  
		/// <returns>vector of text lines</returns>  
		static vector<string> Get_file_content(const std::string & file_name);

		/// <summary>Generate a new sum file </summary>
		/// <param name="file_name">File name</param>  
		/// <param name="diff_files">differences between the current and the old file</param>  
		static void Create_file_sum(const std::string & file_name, vector<Obj_change> diff_files);

		/// <summary>Generate a new hg file </summary>
		/// <param name="file_name">File name</param>  
		/// <param name="diff_files">differences between the current and the old file</param>  
		static void Create_file_hg (const std::string & file_name, vector<Obj_change> diff_files);

		/// <summary>Check if a file exist</summary>
		/// <param name="file_name">File name</param>  
		static bool Check_file_exist(const std::string& name);

		/// <summary>Create a new file</summary>
		/// <param name="content">content to writte in the file</param>  
		/// <param name="name">File name</param>  
		static void Create_file(vector<string> & content, string name);
	};
}
#endif