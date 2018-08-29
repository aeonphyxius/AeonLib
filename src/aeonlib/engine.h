#ifndef _ENGINE_H
#define _ENGINE_H

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

#include <assert.h>
#include <string>
#include <renderer.h>
#include <config.h>

namespace AeonLib
{
	class Engine;
	class EngineSingleton
	{
		NON_COPYABLE_CLASS(EngineSingleton);

	public:
		EngineSingleton() = delete;
		explicit EngineSingleton(Engine* engineInstance)
		{
			assert(s_Instance == nullptr);
			s_Instance = engineInstance;
		}

		~EngineSingleton() { s_Instance = nullptr; }

		static Engine* Instance() { assert(s_Instance != nullptr);  return s_Instance; }

	private:
		static Engine* s_Instance;
	};
	
	class Engine final : public EngineSingleton
    {
        	NON_COPYABLE_CLASS( Engine );
        public:
			explicit Engine(const std::string& configFileName);
	        ~Engine();
	        
	        const AeonLib::Config& Config() const { return m_Configuration; }
			AeonLib::Config& Config() { return m_Configuration; }
		
	        void Run();
	        
        private:
			Engine() = default;
			
			AeonLib::Config 	m_Configuration;
			AeonLib::Renderer 	m_Renderer;

		//void Update();
    };
}

#endif /* defined( _ENGINE_H )*/
