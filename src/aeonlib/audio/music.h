#ifndef _MUSIC_H
#define _MUSIC_H

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
#include "precompiled.h"

namespace AeonLib
{
    class Music
    {
    public:
        static const int InfiniteLoop = -1;
        static const int NoLoop = 0;

        Music();
        explicit Music( const std::string& musicFileName );
        ~Music();

        void Load( const std::string& musicFileName );
        void Unload();
        bool IsLoaded() const { return true; /*m_MusicInternal != nullptr;*/ }

        void Play( const int loops = InfiniteLoop );
    private:
    	
    	int	 			m_loops;
    	
        std::string 	m_FileName;        
      //  Mix_Music* m_MusicInternal;
    };
}
#endif /* defined( _MUSIC_H )*/
