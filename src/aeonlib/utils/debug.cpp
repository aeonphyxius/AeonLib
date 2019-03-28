#include "debug.h"
#include "string.h"
#include "stdarg.h"
#include "stdlib.h"
#include <stdio.h>

namespace AeonLib
{
	// Show trace log messages (LOG_INFO, LOG_WARNING, LOG_ERROR, LOG_DEBUG)
	void Debug::Log(int msgType, const char *text, ...)
	{
		//#if defined(SUPPORT_TRACELOG)
		
		static char buffer[256];				
		int traceDebugMsgs = 0;

		//#if defined(SUPPORT_TRACELOG_DEBUG)
		traceDebugMsgs = 1;
		//#endif

		switch (msgType)
		{
			case LOG_INFO: strcpy(buffer, "INFO: "); break;
			case LOG_ERROR: strcpy(buffer, "ERROR: "); break;
			case LOG_WARNING: strcpy(buffer, "WARNING: "); break;
			case LOG_DEBUG: strcpy(buffer, "DEBUG: "); break;
			default: break;
		}

		strcat(buffer, text);
		strcat(buffer, "\n");

		va_list args;
		va_start(args, text);
		/*
	#if defined(PLATFORM_ANDROID)
		switch (msgType)
		{
		case LOG_INFO: __android_log_vprint(ANDROID_LOG_INFO, "raylib", buffer, args); break;
		case LOG_ERROR: __android_log_vprint(ANDROID_LOG_ERROR, "raylib", buffer, args); break;
		case LOG_WARNING: __android_log_vprint(ANDROID_LOG_WARN, "raylib", buffer, args); break;
		case LOG_DEBUG: if (traceDebugMsgs) __android_log_vprint(ANDROID_LOG_DEBUG, "raylib", buffer, args); break;
		default: break;
		}
	#else*/
		if ((msgType != LOG_DEBUG) || ((msgType == LOG_DEBUG) && (traceDebugMsgs))) 
			vprintf(buffer, args);
		
		//#endif		
		
		va_end(args);
		
		if (msgType == LOG_ERROR) exit(1);  // If LOG_ERROR message, exit program

	//#endif  // SUPPORT_TRACELOG
	}
}
