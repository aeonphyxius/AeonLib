#include "config.h"
#include "json/json.h"
#include <fstream>
#include "../utils/utils.h"
#include <assert.h>
using namespace AeonLib;

namespace AeonLib
{

    Config::Config(const std::string& configFileName) 
		: m_GameName("Aeon Game Test")		
		, m_Resolution{ 800u, 600u }
		, m_Fullscreen(false)		
    {   
		
		/*Json::Value config;
		OpenAndParseJsonFromFile(config, configFileName);
		LoadFromJson(config);*/
    }
    /*
    void Config::LoadFromJson(const Json::Value& serializer)
	{	
		m_GameName = serializer["game"]["gamename"].asString();
		m_Resolution[0] = serializer["graphics"]["resolution"][0].asUInt();
		m_Resolution[1] = serializer["graphics"]["resolution"][1].asUInt();
		m_Fullscreen = serializer["graphics"]["fullscreen"].asBool();
	}
	
	bool Config::OpenAndParseJsonFromFile(Json::Value& out, std::string filename)
 	{		
		Json::CharReaderBuilder builder;
		std::string errs;

		std::ifstream sceneFile(filename, std::ifstream::binary);
		
		bool result = Json::parseFromStream(builder, sceneFile, &out, &errs);

	 	if (result == false)
	 	{
			Utils::TraceLog(Utils::LOG_WARNING,"Error parsing %s\n", filename.c_str());
		 	Utils::TraceLog(Utils::LOG_WARNING,"%s\n", errs.c_str());
		 	assert(false);
	 	}

	 	return result;
 	}*/
}
