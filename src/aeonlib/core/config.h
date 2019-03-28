#ifndef _CONFIG_H
#define _CONFIG_H


/****************************************************************************
Copyright (c) 2018 Alejandro Santiago Varela

http://www.aeonphyxius.com

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#include <vector>
#include "json/forwards.h"


namespace AeonLib
{
    class Config
    {
    public:    	
        explicit Config(const std::string& configFileName);
		virtual ~Config() = default;
		
		unsigned int GetResolutionWidth() const { return m_Resolution[0]; }
		unsigned int GetResolutionHeight() const { return m_Resolution[1]; }
		bool GetFullScreen() const { return m_Fullscreen; }
		const std::string& GetGameName() const { return m_GameName; }
		
    private:
		Config() = default;
		//void LoadFromJson(const Json::Value& serializer);
		//bool OpenAndParseJsonFromFile(Json::Value& out, std::string filename);
		
		std::string 	m_GameName;		
		unsigned int 	m_Resolution[2];		
		bool 			m_Fullscreen;	
    };
}
#endif /* defined( _CONFIG_H )*/

