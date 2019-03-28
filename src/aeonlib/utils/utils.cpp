#include "utils.h"
#include "string.h"
#include "utils/debug.h"
#include <stdio.h>
#include <math.h>
#include <fstream>
#include <sstream>

using namespace AeonLib;

namespace AeonLib
{
	std::string Utils::loadFile(const char *t_file)
	{
		// 1. Retrieve the vertex/fragment source code from filePath
		std::string file_data;
		
		std::ifstream file_stream;
		
		// ensures ifstream objects can throw exceptions:
		file_stream.exceptions(std::ifstream::badbit);
		
		try
		{
			// Open files
			file_stream.open(t_file);
			
			std::stringstream ss_stream;
			// Read file's buffer contents into streams
			ss_stream << file_stream.rdbuf();
			
			// close file handlers
			file_stream.close();
			
			// Convert stream into string
			file_data = ss_stream.str();			
		}
		catch (std::ifstream::failure e)
		{
			Debug::Log(Debug::LOG_ERROR, "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" );
		}
		
		return file_data;
	}

	bool Utils::cmpf(float f1, float f2, float episilon)
	{
		return (fabs(f1 - f2) < episilon);
	}
}
