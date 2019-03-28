#include "engine.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace AeonLib
{
    Engine* s_Instance = nullptr;


	Engine::Engine(const std::string& configFileName)
		: EngineSingleton(this)
		, m_Renderer()
		, m_Configuration(configFileName)
		//, m_GameController()
		
        //, m_Audio()
	{
		//SDL_Init(SDL_INIT_EVERYTHING);
	}

    Engine::~Engine()
    {    
 		/*for (auto scene : m_ScenesToActivate)
 		{
 			scene->CleanUp();
 		}

		for (auto scene : m_ActiveScenes)
		{
			scene->DeInitialize();
			scene->CleanUp();
		}

		for (auto scene : m_ScenesToDeactivate)
		{
			scene->DeInitialize();
			scene->CleanUp();
		}

        m_GameController.DeInitialize();
        m_Audio.DeInitialize();
        m_Renderer.DeInitialize();   
		*/
        //SDL_Quit();
    }    
    
	void Engine::Run()
	{
		m_Renderer.InitWindow
			((int)Config().GetResolutionWidth(), 
			(int)Config().GetResolutionHeight(), 
			Config().GetFullScreen(), 
			Config().GetGameName());
		

		while (!m_Renderer.WindowShouldClose())
		{
			m_Renderer.Clear();
			m_Renderer.SwapBuffers();
			
	
			// Draw our first triangle
			/*glUseProgram(shaderProgram);
			glBindVertexArray(VAO);
			glDrawArrays(GL_TRIANGLES, 0, 3);
			glBindVertexArray(0);*/
	
			//glfwSwapBuffers(window);
		}
		
		/*while (!GameController().GetIsQuit())
		{
			Update();
		}*/
	
	}
}
