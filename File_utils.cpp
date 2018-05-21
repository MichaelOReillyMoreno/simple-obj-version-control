
#include "File_utils.hpp"

namespace Obj_version_control
{
	void File_utils::Read_file(const std::string & file_name)
	{
		ifstream inFile;

		inFile.open(file_name);

		if (!inFile)
		{
			cout << "WARNING: Unable to open file : " << file_name;

		}

		string line;

		while (std::getline(inFile, line))
		{
			std::cout << line << std::endl;
		}

		inFile.close();
	}

	vector<string> File_utils::Get_file_content(const std::string & file_name)
	{
		ifstream inFile;
		vector<string> file_lines;

		inFile.open(file_name);

		if (!inFile)
		{
			cout << "WARNING: Unable to open file : " << file_name;

		}

		string line;

		while (std::getline(inFile, line))
		{
			file_lines.push_back(line);
		}

		inFile.close();

		return file_lines;
	}

	void File_utils::Create_file_sum(const std::string & file_name, vector<Obj_change> diff_files)
	{
		std::ofstream outfile(file_name);

		if (!outfile.is_open()) 
		{
			cout << "WARNING: Failed to create " << file_name << endl;
		}
		else 
		{
			cout << "File " << file_name << " create" << endl;

			for (Obj_change change : diff_files)
			{
				outfile << change.Get_content() << std::endl;
			}

			outfile.close();
		}
	}

	void File_utils::Create_file_hg(const std::string & file_name, vector<Obj_change> diff_files)
	{
		std::ofstream outfile(file_name);

		if (!outfile.is_open())
		{
			cout << "WARNING: Failed to create " << file_name << endl;
		}
		else
		{
			cout << "File " << file_name << " create" << endl;

			for (Obj_change change : diff_files)
			{
				outfile << change.Get_hg_string() << std::endl;
			}

			outfile.close();
		}
	}
	bool File_utils::Check_file_exist(const std::string & name)
	{
		struct stat buffer;
		return (stat(name.c_str(), &buffer) == 0);
	}
	void File_utils::Create_file(vector<string> & content, string name)
	{
		std::ofstream outfile(name);

		for (string s : content)
			outfile << s << std::endl;

		outfile.close();
	}
}