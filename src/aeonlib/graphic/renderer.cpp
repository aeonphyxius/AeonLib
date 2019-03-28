#include "precompiled.h"
#include "renderer.h"
#include "fragmentShader.h"
#include "vertexShader.h"

using namespace AeonLib;

int			Renderer::screenWidth, Renderer::screenHeight;		     // Screen width and height (used render area)
GLFWwindow  *Renderer::m_window;
GLuint		Renderer::shaderProgram;
namespace AeonLib
{
	Renderer::Renderer()
        : m_WindowWidth( 800 )
        , m_WindowHeight( 600 )
        , m_IsFullScreen(false)
        , m_WindowTitle( "OpenGL Window" )
		, m_Window( NULL )		
		//, m_ViewTransform(Transform3::identity())
		//, m_VisualListDirty(false)
	{	 

    }

    Renderer::~Renderer()
    {

    }
    
	void Renderer::InitWindow()
	{
		InitWindow(m_WindowWidth,m_WindowHeight,m_IsFullScreen,m_WindowTitle);
	}
    
	void Renderer::InitWindow( const int windowWidth, const int windowHeight, bool fullscreen, const std::string& windowTitle )
	{	
		Debug::Log(Debug::LOG_INFO, "Initializing AeonLib (%d.%d.%d)" , Utils::V1, Utils::V2,Utils::V3 );

		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
		
		m_window = glfwCreateWindow(windowWidth, windowHeight, windowTitle.c_str(),nullptr, nullptr);
		
		glfwGetFramebufferSize(m_window, &m_WindowWidth, &m_WindowHeight);

		if (nullptr == m_window)		
		{
			Debug::Log(Debug::LOG_INFO, "An error ocurred while initializing the OpenGL window");
			glfwTerminate();
			return;
		}

		glfwMakeContextCurrent(m_window);

		glewExperimental = true;

		if (GLEW_OK != glewInit())
		{
			Debug::Log(Debug::LOG_INFO, "An error ocurred while initializing GLEW");
			return;
		}

		Debug::Log(Debug::LOG_INFO, "GLEW Initialized correctly");

		glViewport(0, 0, m_WindowWidth, m_WindowHeight);
		shaderProgram = glCreateProgram();

		//AddShader(GL_VERTEX_SHADER, VERTEX_SHADER);
		AddShader(GL_FRAGMENT_SHADER, FRAGMENT_SHADER);		
	}
	
	bool Renderer::WindowShouldClose()
	{
		return glfwWindowShouldClose(m_window);
	}
	
	void Renderer::Clear()
	{
		glfwPollEvents();
	
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}
	
	void Renderer::SwapBuffers()
	{
		glfwSwapBuffers(m_window);
	}
	
	void Renderer::AddShader(int shader_type, const char * shader_code)
	{
		GLuint shader = glCreateShader(shader_type);
		//glShaderSource(shader, 1, &shader_code, nullptr);
		glShaderSource(shader, 1, &shader_code, NULL);
		glCompileShader(shader);
	
		GLint success;
		GLchar info[512];
	
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	
		if (!success)
		{
			//glGetShaderInfoLog(shader, GL_COMPILE_STATUS, nullptr, info);
			glGetShaderInfoLog(shader, GL_COMPILE_STATUS, NULL, info);
			Debug::Log(Debug::LOG_INFO, "Buidling shader error: ", info);
		}
		glAttachShader(shaderProgram, shader);
	
		glAttachShader(shaderProgram, shader);
		glLinkProgram(shaderProgram);
	
		glGetProgramiv(shaderProgram, GL_COMPILE_STATUS, &success);
	
		if (!success)
		{
			//glGetProgramInfoLog(shader, GL_COMPILE_STATUS, nullptr, info);
			glGetProgramInfoLog(shader, GL_COMPILE_STATUS, NULL, info);
			Debug::Log(Debug::LOG_INFO, "Linking shader program: failed - ", info);
			return;
		}
	
		glDeleteShader(shader);
		Debug::Log(Debug::LOG_INFO, "Buidling vertex shader: success");
	
	}
	
	
	void Renderer::GameLoop()
	{
		/*
		// Set up vertex data (and buffer(s)) and attribute pointers
		GLfloat vertices[] =
		{
			-0.5f, -0.5f, 0.0f, // Left
			0.5f, -0.5f, 0.0f, // Right
			0.0f,  0.5f, 0.0f  // Top
		};
	
		GLuint VBO, VAO;
	
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		// Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
		glBindVertexArray(VAO);
	
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid *)0);
		glEnableVertexAttribArray(0);
	
		glBindBuffer(GL_ARRAY_BUFFER, 0); // Note that this is allowed, the call to glVertexAttribPointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind
	
		glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)
	
	
		while (!glfwWindowShouldClose(window))
		{
			glfwPollEvents();
	
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
	
			// Draw our first triangle
			glUseProgram(shaderProgram);
			glBindVertexArray(VAO);
			glDrawArrays(GL_TRIANGLES, 0, 3);
			glBindVertexArray(0);
	
			glfwSwapBuffers(window);
		}
	
		// Properly de-allocate all resources once they've outlived their purpose
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
	
		// Terminate GLFW, clearing any resources allocated by GLFW.
		glfwTerminate();
		*/
	
	}
	//
	////#if defined(PLATFORM_DESKTOP) || defined(PLATFORM_RPI) || defined(PLATFORM_WEB)
	//// Initialize window and OpenGL context
	//void AeonCore::InitWindow(int width, int height, const char *title)
	//{
	//	Utils::TraceLog(Utils::LOG_INFO, "Initializing raylib (v1.8.0)");
	//
	//	// Store window title (could be useful...)
	//	window_title = title;
	//
	//	// Init graphics device (display device and OpenGL context)
	//	InitGraphicsDevice(width, height);
	//
	//#if defined(SUPPORT_DEFAULT_FONT)
	//	// Load default font
	//	// NOTE: External function (defined in module: text)
	//	LoadDefaultFont();
	//#endif
	//
	//	// Init hi-res timer
	//	InitTimer();
	//
	//#if defined(PLATFORM_RPI)
	//	// Init raw input system
	//	InitMouse();        // Mouse init
	//	InitTouch();        // Touch init
	//	InitKeyboard();     // Keyboard init
	//	InitGamepad();      // Gamepad init
	//#endif
	//
	//#if defined(PLATFORM_WEB)
	//	emscripten_set_fullscreenchange_callback(0, 0, 1, EmscriptenFullscreenChangeCallback);
	//
	//	// Support keyboard events
	//	emscripten_set_keypress_callback("#canvas", NULL, 1, EmscriptenKeyboardCallback);
	//
	//	// Support mouse events
	//	emscripten_set_click_callback("#canvas", NULL, 1, EmscriptenMouseCallback);
	//
	//	// Support touch events
	//	emscripten_set_touchstart_callback("#canvas", NULL, 1, EmscriptenTouchCallback);
	//	emscripten_set_touchend_callback("#canvas", NULL, 1, EmscriptenTouchCallback);
	//	emscripten_set_touchmove_callback("#canvas", NULL, 1, EmscriptenTouchCallback);
	//	emscripten_set_touchcancel_callback("#canvas", NULL, 1, EmscriptenTouchCallback);
	//	//emscripten_set_touchstart_callback(0, NULL, 1, Emscripten_HandleTouch);
	//	//emscripten_set_touchend_callback("#canvas", data, 0, Emscripten_HandleTouch);
	//
	//	// Support gamepad events (not provided by GLFW3 on emscripten)
	//	emscripten_set_gamepadconnected_callback(NULL, 1, EmscriptenGamepadCallback);
	//	emscripten_set_gamepaddisconnected_callback(NULL, 1, EmscriptenGamepadCallback);
	//#endif
	//
	//	mousePosition.x = (float) screenWidth / 2.0f;
	//	mousePosition.y = (float) screenHeight / 2.0f;
	//
	//	// raylib logo appearing animation (if enabled)
	///*	if (showLogo)
	//	{*/
	//		SetTargetFPS(60);
	//		//LogoAnimation();
	//	//}
	//}
	//
	//// Set target FPS (maximum)
	//void AeonCore::SetTargetFPS(int fps)
	//{
	//	if (fps < 1) targetTime = 0.0;
	//	else targetTime = 1.0 / (double)fps;
	//
	//	Utils::TraceLog(Utils::LOG_INFO, "Target time per frame: %02.03f milliseconds", (float)targetTime * 1000);
	//}
	//
	//// Returns current FPS
	//int AeonCore::GetFPS(void)
	//{
	//	return (int)(1.0f / GetFrameTime());
	//}
	//float AeonCore::GetFrameTime(void)
	//{
	//	// NOTE: We round value to milliseconds
	//	return (float)frameTime;
	//}
	//
	//// Initialize hi-resolution timer
	//void AeonCore::InitTimer(void)
	//{
	//	srand(time(NULL));              // Initialize random seed
	//
	//#if !defined(SUPPORT_BUSY_WAIT_LOOP) && defined(_WIN32)
	//	timeBeginPeriod(1);             // Setup high-resolution timer to 1ms (granularity of 1-2 ms)
	//#endif
	//
	//#if defined(PLATFORM_ANDROID) || defined(PLATFORM_RPI)
	//	struct timespec now;
	//
	//	if (clock_gettime(CLOCK_MONOTONIC, &now) == 0)  // Success
	//	{
	//		baseTime = (uint64_t)now.tv_sec * 1000000000LLU + (uint64_t)now.tv_nsec;
	//	}
	//	else TraceLog(LOG_WARNING, "No hi-resolution timer available");
	//#endif
	//
	//	previousTime = GetTime();       // Get time as double
	//}
	//
	//// Get current time measure (in seconds) since InitTimer()
	//double AeonCore::GetTime(void)
	//{
	//#if defined(PLATFORM_DESKTOP) || defined(PLATFORM_WEB)
	//	return glfwGetTime();
	//#endif
	//
	//#if defined(PLATFORM_ANDROID) || defined(PLATFORM_RPI)
	//	struct timespec ts;
	//	clock_gettime(CLOCK_MONOTONIC, &ts);
	//	uint64_t time = (uint64_t)ts.tv_sec * 1000000000LLU + (uint64_t)ts.tv_nsec;
	//
	//	return (double)(time - baseTime)*1e-9;
	//#endif
	//}
	//
	//void AeonCore::InitGraphicsDevice(int width, int height)
	//{
	//	screenWidth = width;        // User desired width
	//	screenHeight = height;      // User desired height
	//
	//								// NOTE: Framebuffer (render area - renderWidth, renderHeight) could include black bars...
	//								// ...in top-down or left-right to match display aspect ratio (no weird scalings)
	//
	//								// Downscale matrix is required in case desired screen area is bigger than display area
	//	downscaleView = MatrixIdentity();
	//
	//#if defined(PLATFORM_DESKTOP) || defined(PLATFORM_WEB)
	//		glfwSetErrorCallback(ErrorCallback);
	//
	//		if (!glfwInit()) Utils::TraceLog(Utils::LOG_ERROR, "Failed to initialize GLFW");
	//
	//		// NOTE: Getting video modes is not implemented in emscripten GLFW3 version
	//#if defined(PLATFORM_DESKTOP)
	//		// Find monitor resolution
	//		const GLFWvidmode *mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	//
	//		displayWidth = mode->width;
	//		displayHeight = mode->height;
	//
	//		// Screen size security check
	//		if (screenWidth <= 0) screenWidth = displayWidth;
	//		if (screenHeight <= 0) screenHeight = displayHeight;
	//#endif  // defined(PLATFORM_DESKTOP)
	//
	//#if defined(PLATFORM_WEB)
	//		displayWidth = screenWidth;
	//		displayHeight = screenHeight;
	//#endif  // defined(PLATFORM_WEB)
	//
	//		glfwDefaultWindowHints();                       // Set default windows hints
	//
	//														// Check some Window creation flags
	//		if (configFlags & FLAG_WINDOW_RESIZABLE) glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);   // Resizable window
	//		else glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);  // Avoid window being resizable
	//
	//		if (configFlags & FLAG_WINDOW_DECORATED) glfwWindowHint(GLFW_DECORATED, GL_TRUE);   // Border and buttons on Window
	//
	//		if (configFlags & FLAG_WINDOW_TRANSPARENT)
	//		{
	//			// TODO: Enable transparent window (not ready yet on GLFW 3.2)
	//		}
	//
	//		if (configFlags & FLAG_MSAA_4X_HINT)
	//		{
	//			glfwWindowHint(GLFW_SAMPLES, 4);            // Enables multisampling x4 (MSAA), default is 0
	//			Utils::TraceLog(Utils::LOG_INFO, "Trying to enable MSAA x4");
	//		}
	//
	//		//glfwWindowHint(GLFW_RED_BITS, 8);             // Framebuffer red color component bits
	//		//glfwWindowHint(GLFW_DEPTH_BITS, 16);          // Depthbuffer bits (24 by default)
	//		//glfwWindowHint(GLFW_REFRESH_RATE, 0);         // Refresh rate for fullscreen window
	//		//glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);    // Default OpenGL API to use. Alternative: GLFW_OPENGL_ES_API
	//		//glfwWindowHint(GLFW_AUX_BUFFERS, 0);          // Number of auxiliar buffers
	//
	//		// NOTE: When asking for an OpenGL context version, most drivers provide highest supported version
	//		// with forward compatibility to older OpenGL versions.
	//		// For example, if using OpenGL 1.1, driver can provide a 4.3 context forward compatible.
	//
	//		// Check selection OpenGL version
	//		if (rlGetVersion() == OPENGL_21)
	//		{
	//			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);        // Choose OpenGL major version (just hint)
	//			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);        // Choose OpenGL minor version (just hint)
	//		}
	//		else if (rlGetVersion() == OPENGL_33)
	//		{
	//			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);        // Choose OpenGL major version (just hint)
	//			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);        // Choose OpenGL minor version (just hint)
	//			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // Profiles Hint: Only 3.3 and above!
	//																		   // Other values: GLFW_OPENGL_ANY_PROFILE, GLFW_OPENGL_COMPAT_PROFILE
	//#if defined(__APPLE__)
	//			glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);  // OSX Requires
	//#else
	//			glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_FALSE); // Fordward Compatibility Hint: Only 3.3 and above!
	//#endif
	//																  //glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
	//		}
	//
	//		if (fullscreen)
	//		{
	//			// Obtain recommended displayWidth/displayHeight from a valid videomode for the monitor
	//			int count;
	//			const GLFWvidmode *modes = glfwGetVideoModes(glfwGetPrimaryMonitor(), &count);
	//
	//			// Get closest videomode to desired screenWidth/screenHeight
	//			for (int i = 0; i < count; i++)
	//			{
	//				if (modes[i].width >= screenWidth)
	//				{
	//					if (modes[i].height >= screenHeight)
	//					{
	//						displayWidth = modes[i].width;
	//						displayHeight = modes[i].height;
	//						break;
	//					}
	//				}
	//			}
	//
	//			Utils::TraceLog(Utils::LOG_WARNING, "Closest fullscreen videomode: %i x %i", displayWidth, displayHeight);
	//
	//			// NOTE: ISSUE: Closest videomode could not match monitor aspect-ratio, for example,
	//			// for a desired screen size of 800x450 (16:9), closest supported videomode is 800x600 (4:3),
	//			// framebuffer is rendered correctly but once displayed on a 16:9 monitor, it gets stretched
	//			// by the sides to fit all monitor space...
	//
	//			// At this point we need to manage render size vs screen size
	//			// NOTE: This function uses and modifies global module variables:
	//			//       screenWidth/screenHeight - renderWidth/renderHeight - downscaleView
	//			SetupFramebufferSize(displayWidth, displayHeight);
	//
	//			window = glfwCreateWindow(displayWidth, displayHeight, window_title, glfwGetPrimaryMonitor(), NULL);
	//
	//			// NOTE: Full-screen change, not working properly...
	//			//glfwSetWindowMonitor(window, glfwGetPrimaryMonitor(), 0, 0, screenWidth, screenHeight, GLFW_DONT_CARE);
	//		}
	//		else
	//		{
	//			// No-fullscreen window creation
	//			window = glfwCreateWindow(screenWidth, screenHeight, window_title, NULL, NULL);
	//
	//#if defined(PLATFORM_DESKTOP)
	//			// Center window on screen
	//			int windowPosX = displayWidth / 2 - screenWidth / 2;
	//			int windowPosY = displayHeight / 2 - screenHeight / 2;
	//
	//			if (windowPosX < 0) windowPosX = 0;
	//			if (windowPosY < 0) windowPosY = 0;
	//
	//			glfwSetWindowPos(window, windowPosX, windowPosY);
	//#endif
	//			renderWidth = screenWidth;
	//			renderHeight = screenHeight;
	//		}
	//
	//		if (!window)
	//		{
	//			glfwTerminate();
	//			Utils::TraceLog(Utils::LOG_ERROR, "GLFW Failed to initialize Window");
	//		}
	//		else
	//		{
	//			Utils::TraceLog(Utils::LOG_INFO, "Display device initialized successfully");
	//#if defined(PLATFORM_DESKTOP)
	//			Utils::TraceLog(Utils::LOG_INFO, "Display size: %i x %i", displayWidth, displayHeight);
	//#endif
	//			Utils::TraceLog(Utils::LOG_INFO, "Render size: %i x %i", renderWidth, renderHeight);
	//			Utils::TraceLog(Utils::LOG_INFO, "Screen size: %i x %i", screenWidth, screenHeight);
	//			Utils::TraceLog(Utils::LOG_INFO, "Viewport offsets: %i, %i", renderOffsetX, renderOffsetY);
	//		}
	//
	//		glfwSetWindowSizeCallback(window, WindowSizeCallback);      // NOTE: Resizing not allowed by default!
	//		glfwSetCursorEnterCallback(window, CursorEnterCallback);
	//		glfwSetKeyCallback(window, KeyCallback);
	//		glfwSetMouseButtonCallback(window, MouseButtonCallback);
	//		glfwSetCursorPosCallback(window, MouseCursorPosCallback);   // Track mouse position changes
	//		glfwSetCharCallback(window, CharCallback);
	//		glfwSetScrollCallback(window, ScrollCallback);
	//		glfwSetWindowIconifyCallback(window, WindowIconifyCallback);
	//#if defined(PLATFORM_DESKTOP)
	//		glfwSetDropCallback(window, WindowDropCallback);
	//#endif
	//
	//		glfwMakeContextCurrent(window);
	//
	//		// Try to disable GPU V-Sync by default, set framerate using SetTargetFPS()
	//		// NOTE: V-Sync can be enabled by graphic driver configuration
	//		glfwSwapInterval(0);
	//
	//#if defined(PLATFORM_DESKTOP)
	//		// Load OpenGL 3.3 extensions
	//		// NOTE: GLFW loader function is passed as parameter
	//		rlLoadExtensions(glfwGetProcAddress);
	//#endif
	//
	//		// Try to enable GPU V-Sync, so frames are limited to screen refresh rate (60Hz -> 60 FPS)
	//		// NOTE: V-Sync can be enabled by graphic driver configuration
	//		if (configFlags & FLAG_VSYNC_HINT)
	//		{
	//			glfwSwapInterval(1);
	//			Utils::TraceLog(Utils::LOG_INFO, "Trying to enable VSYNC");
	//		}
	//#endif // defined(PLATFORM_DESKTOP) || defined(PLATFORM_WEB)
	//
	//#if defined(PLATFORM_ANDROID) || defined(PLATFORM_RPI)
	//		fullscreen = true;
	//
	//		// Screen size security check
	//		if (screenWidth <= 0) screenWidth = displayWidth;
	//		if (screenHeight <= 0) screenHeight = displayHeight;
	//
	//#if defined(PLATFORM_RPI)
	//		bcm_host_init();
	//
	//		DISPMANX_ELEMENT_HANDLE_T dispmanElement;
	//		DISPMANX_DISPLAY_HANDLE_T dispmanDisplay;
	//		DISPMANX_UPDATE_HANDLE_T dispmanUpdate;
	//
	//		VC_RECT_T dstRect;
	//		VC_RECT_T srcRect;
	//#endif
	//
	//		EGLint samples = 0;
	//		EGLint sampleBuffer = 0;
	//		if (configFlags & FLAG_MSAA_4X_HINT)
	//		{
	//			samples = 4;
	//			sampleBuffer = 1;
	//			TraceLog(LOG_INFO, "Trying to enable MSAA x4");
	//		}
	//
	//		const EGLint framebufferAttribs[] =
	//		{
	//			EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,     // Type of context support -> Required on RPI?
	//														 //EGL_SURFACE_TYPE, EGL_WINDOW_BIT,          // Don't use it on Android!
	//														 EGL_RED_SIZE, 8,            // RED color bit depth (alternative: 5)
	//														 EGL_GREEN_SIZE, 8,          // GREEN color bit depth (alternative: 6)
	//														 EGL_BLUE_SIZE, 8,           // BLUE color bit depth (alternative: 5)
	//																					 //EGL_ALPHA_SIZE, 8,        // ALPHA bit depth (required for transparent framebuffer)
	//																					 //EGL_TRANSPARENT_TYPE, EGL_NONE, // Request transparent framebuffer (EGL_TRANSPARENT_RGB does not work on RPI)
	//																					 EGL_DEPTH_SIZE, 16,         // Depth buffer size (Required to use Depth testing!)
	//																												 //EGL_STENCIL_SIZE, 8,      // Stencil buffer size
	//																												 EGL_SAMPLE_BUFFERS, sampleBuffer,    // Activate MSAA
	//																												 EGL_SAMPLES, samples,       // 4x Antialiasing if activated (Free on MALI GPUs)
	//																												 EGL_NONE
	//		};
	//
	//		EGLint contextAttribs[] =
	//		{
	//			EGL_CONTEXT_CLIENT_VERSION, 2,
	//			EGL_NONE
	//		};
	//
	//		EGLint numConfigs;
	//
	//		// Get an EGL display connection
	//		display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
	//
	//		// Initialize the EGL display connection
	//		eglInitialize(display, NULL, NULL);
	//
	//		// Get an appropriate EGL framebuffer configuration
	//		eglChooseConfig(display, framebufferAttribs, &config, 1, &numConfigs);
	//
	//		// Set rendering API
	//		eglBindAPI(EGL_OPENGL_ES_API);
	//
	//		// Create an EGL rendering context
	//		context = eglCreateContext(display, config, EGL_NO_CONTEXT, contextAttribs);
	//
	//		// Create an EGL window surface
	//		//---------------------------------------------------------------------------------
	//#if defined(PLATFORM_ANDROID)
	//		EGLint displayFormat;
	//
	//		displayWidth = ANativeWindow_getWidth(app->window);
	//		displayHeight = ANativeWindow_getHeight(app->window);
	//
	//		// EGL_NATIVE_VISUAL_ID is an attribute of the EGLConfig that is guaranteed to be accepted by ANativeWindow_setBuffersGeometry()
	//		// As soon as we picked a EGLConfig, we can safely reconfigure the ANativeWindow buffers to match, using EGL_NATIVE_VISUAL_ID
	//		eglGetConfigAttrib(display, config, EGL_NATIVE_VISUAL_ID, &displayFormat);
	//
	//		// At this point we need to manage render size vs screen size
	//		// NOTE: This function use and modify global module variables: screenWidth/screenHeight and renderWidth/renderHeight and downscaleView
	//		SetupFramebufferSize(displayWidth, displayHeight);
	//
	//		ANativeWindow_setBuffersGeometry(app->window, renderWidth, renderHeight, displayFormat);
	//		//ANativeWindow_setBuffersGeometry(app->window, 0, 0, displayFormat);       // Force use of native display size
	//
	//		surface = eglCreateWindowSurface(display, config, app->window, NULL);
	//#endif  // defined(PLATFORM_ANDROID)
	//
	//#if defined(PLATFORM_RPI)
	//		graphics_get_display_size(0, &displayWidth, &displayHeight);
	//
	//		// At this point we need to manage render size vs screen size
	//		// NOTE: This function use and modify global module variables: screenWidth/screenHeight and renderWidth/renderHeight and downscaleView
	//		SetupFramebufferSize(displayWidth, displayHeight);
	//
	//		dstRect.x = 0;
	//		dstRect.y = 0;
	//		dstRect.width = displayWidth;
	//		dstRect.height = displayHeight;
	//
	//		srcRect.x = 0;
	//		srcRect.y = 0;
	//		srcRect.width = renderWidth << 16;
	//		srcRect.height = renderHeight << 16;
	//
	//		// NOTE: RPI dispmanx windowing system takes care of srcRec scaling to dstRec by hardware (no cost)
	//		// Take care that renderWidth/renderHeight fit on displayWidth/displayHeight aspect ratio
	//
	//		VC_DISPMANX_ALPHA_T alpha;
	//		alpha.flags = DISPMANX_FLAGS_ALPHA_FIXED_ALL_PIXELS;
	//		alpha.opacity = 255;    // Set transparency level for framebuffer, requires EGLAttrib: EGL_TRANSPARENT_TYPE
	//		alpha.mask = 0;
	//
	//		dispmanDisplay = vc_dispmanx_display_open(0);   // LCD
	//		dispmanUpdate = vc_dispmanx_update_start(0);
	//
	//		dispmanElement = vc_dispmanx_element_add(dispmanUpdate, dispmanDisplay, 0/*layer*/, &dstRect, 0/*src*/,
	//			&srcRect, DISPMANX_PROTECTION_NONE, &alpha, 0/*clamp*/, DISPMANX_NO_ROTATE);
	//
	//		nativeWindow.element = dispmanElement;
	//		nativeWindow.width = renderWidth;
	//		nativeWindow.height = renderHeight;
	//		vc_dispmanx_update_submit_sync(dispmanUpdate);
	//
	//		surface = eglCreateWindowSurface(display, config, &nativeWindow, NULL);
	//		//---------------------------------------------------------------------------------
	//#endif  // defined(PLATFORM_RPI)
	//		// There must be at least one frame displayed before the buffers are swapped
	//		//eglSwapInterval(display, 1);
	//
	//		if (eglMakeCurrent(display, surface, surface, context) == EGL_FALSE)
	//		{
	//			TraceLog(LOG_ERROR, "Unable to attach EGL rendering context to EGL surface");
	//		}
	//		else
	//		{
	//			// Grab the width and height of the surface
	//			//eglQuerySurface(display, surface, EGL_WIDTH, &renderWidth);
	//			//eglQuerySurface(display, surface, EGL_HEIGHT, &renderHeight);
	//
	//			TraceLog(LOG_INFO, "Display device initialized successfully");
	//			TraceLog(LOG_INFO, "Display size: %i x %i", displayWidth, displayHeight);
	//			TraceLog(LOG_INFO, "Render size: %i x %i", renderWidth, renderHeight);
	//			TraceLog(LOG_INFO, "Screen size: %i x %i", screenWidth, screenHeight);
	//			TraceLog(LOG_INFO, "Viewport offsets: %i, %i", renderOffsetX, renderOffsetY);
	//		}
	//#endif // defined(PLATFORM_ANDROID) || defined(PLATFORM_RPI)
	//
	//		// Initialize OpenGL context (states and resources)
	//		// NOTE: screenWidth and screenHeight not used, just stored as globals
	//		rlglInit(screenWidth, screenHeight);
	//
	//		// Setup default viewport
	//		SetupViewport();
	//
	//		// Initialize internal projection and modelview matrices
	//		// NOTE: Default to orthographic projection mode with top-left corner at (0,0)
	//		rlMatrixMode(RL_PROJECTION);                // Switch to PROJECTION matrix
	//		rlLoadIdentity();                           // Reset current matrix (PROJECTION)
	//		rlOrtho(0, renderWidth - renderOffsetX, renderHeight - renderOffsetY, 0, 0.0f, 1.0f);
	//		rlMatrixMode(RL_MODELVIEW);                 // Switch back to MODELVIEW matrix
	//		rlLoadIdentity();                           // Reset current matrix (MODELVIEW)
	//
	//		ClearBackground(RAYWHITE);      // Default background color for raylib games :P
	//
	//#if defined(PLATFORM_ANDROID)
	//		windowReady = true;             // IMPORTANT!
	//#endif
	//	}
}
