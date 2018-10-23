#ifndef _PRECOMPILED_H
#define _PRECOMPILED_H

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

//System wise includes
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <iostream>
#include <sstream>      // std::stringstream
#include <string>      // std::stringstream
#include <tchar.h>
#include <windows.h>
#include <math.h>
#include <memory>

//Project includes
#include <types/mathmodule.h>
#include <utils/utils.h>
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "types/types.h"
#include "utils/utils.h"
#include "utils/debug.h"

using namespace std;

#define NON_COPYABLE_CLASS(C) private: \
C( const C& ) = delete; \
C& operator=( const C& ) = delete


#endif /* defined( _PRECOMPILED_H )*/
