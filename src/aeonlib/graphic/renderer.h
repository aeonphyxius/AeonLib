#ifndef AEON_LIB_H_
#define AEON_LIB_H_

/****************************************************************************
Copyright (c) 2017 Alejandro Santiago Varela

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

#include "utils/utils.h"
#include "types/types.h"
#include "precompiled.h"

struct GLFWwindow;

namespace AeonLib
{
	class Renderer
	{
		NON_COPYABLE_CLASS( Renderer );
		
		public:
			enum class RenderLayer : int
		{
			Layer_0 = 0,
			Layer_1,
			Layer_2,
			Layer_4,
			Layer_6,
			Layer_7,
			Layer_8,
			Layer_9,
			Layer_Max
		};
		
		Renderer();
        virtual ~Renderer();
        
        void InitWindow();
		void InitWindow(const int windowWidth, const int windowHeight, bool fullscreen, const std::string& windowName);
		static void GameLoop();

		static void AddShader(int shader_type, const char * shader_code);
		
		bool WindowShouldClose();
		void Clear();
		void SwapBuffers();
		/*static void InitTimer(void);
		static void InitGraphicsDevice(int width, int height);
		static double GetTime(void);
		static void SetTargetFPS(int fps);
		static int GetFPS(void);
		float GetFrameTime(void);*/

	
	protected:
        //void ClearRenderBuffer();
        //void WindowResized( const int windowWidth, const int windowHeight );

		int m_WindowWidth;
		int m_WindowHeight;
		bool m_IsFullScreen;
		const char * m_WindowTitle;				// Window text title...		
		GLFWwindow * m_Window;					// window reference
        
	private:

		static const char * m_window_title;					// Window text title...		
		static GLFWwindow * m_window;							// window reference
		
		//static Vector2 mousePosition;						// Mouse position on screen

															// Display size-related data
		//static unsigned int displayWidth, displayHeight; // Display width and height (monitor, device-screen, LCD, ...)
		static int screenWidth, screenHeight;		     // Screen width and height (used render area)
		//static int renderWidth, renderHeight;				// Framebuffer width and height (render area, including black bars if required)
		/*static int renderOffsetX = 0;               // Offset X from render area (must be divided by 2)
		static int renderOffsetY = 0;               // Offset Y from render area (must be divided by 2)
		static bool fullscreen = false;             // Fullscreen mode (useful only for PLATFORM_DESKTOP)
		static Matrix downscaleView;                // Matrix to downscale view (in case screen size bigger than display size)
		
		static double currentTime, previousTime;    // Used to track timmings
		static double updateTime, drawTime;         // Time measures for update and draw
		static double frameTime = 0.0;              // Time measure for one frame
		static double targetTime = 0.0;             // Desired time for one frame, if 0 not applied*/

		static unsigned int shaderProgram;

	};

}
#endif  // AEON_LIB_H_
