#pragma once
#ifndef FILE_CHANGE
#define FILE_CHANGE

#include <string>
#include <vector>
using namespace std;

namespace Obj_version_control
{
	/// <summary>the type of change that is made</summary>
	enum TYPE_CHANGE { REPLACE, DELETE, ADD };

	/// <summary>Class that represent a change in a file</summary>
	class Obj_change 
	{

	private:

		TYPE_CHANGE type;

		unsigned int num_line; 

		string content;

	public:

		/// <summary>Class that represent a change in a file</summary>
		/// <param name="_type">type of change</param>  
		/// <param name="_num_line">line of the change</param>  
		/// <param name="_content">content of the change</param>  
		Obj_change(TYPE_CHANGE _type, unsigned int _num_line, string _content) : type(_type), num_line(_num_line), content(_content) {}

		/// <summary>Class that represent a change in a file, created from hg and sum files</summary>
		/// <param name="sum">text form sum file</param>  
		/// <param name="hg">text form hg file</param>  
		Obj_change(string & sum, string & hg) : content(sum) 
		{
			Deserialize_hg(hg);
		}

		/// <summary>Serialze the change in the file to writte it in the hg file</summary>
		/// <param name="sum">text form sum file</param>  
		/// <param name="hg">text form hg file</param>  
		inline string Get_hg_string() 
		{
			return Parse_type() + to_string(num_line);
		}

		/// <summary>convert the change in a string to print it in console</summary>
		/// <param name="file_name">File route</param>  
		/// <returns>vector of text lines</returns>  
		inline string To_string()
		{
			return Parse_type() + "> num line : " + to_string(num_line) + " content : " + content + " \n";
		}

		inline TYPE_CHANGE  &  Get_type() { return type; }
		inline unsigned int & Get_num_line() { return num_line; }
		inline string       & Get_content() { return content; }

	private:

		/// <summary>parse the change type in a string</summary>
		/// <returns>type in a string</returns> 
		string Parse_type();

		/// <summary>convert the hg string in two string splitted by "-"</summary>
		/// <param name="file_name">File route</param>  
		/// <returns>vector of text lines</returns>  
		const vector<string> explode(const string & s, const char& c);

		/// <summary>deserialize g content</summary>
		/// <param name="hg">hg content</param>  
		void Deserialize_hg(string & hg);
	};
}
#endif