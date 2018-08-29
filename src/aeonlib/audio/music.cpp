#include "music.h"
#include <assert.h>

namespace AeonLib
{
    Music::Music()
        : m_FileName( "Undefined music" )
        //, m_MusicInternal( nullptr )
    {
    }

    Music::Music( const std::string& musicFileName )
        : m_FileName( musicFileName )
        //, m_MusicInternal( nullptr )
    {
        Load( musicFileName );
    }

    Music::~Music()
    {
        if ( IsLoaded() )
        {
            Unload();
        }
    }

    void Music::Load( const std::string& musicFileName )
    {
        /*m_MusicInternal = Mix_LoadMUS( musicFileName.c_str() );
        if ( m_MusicInternal == nullptr )
        {
            WARNING( "Cannot load music: %s. Error: %s", musicFileName.c_str(), SDL_GetError() );
        }*/
    }

    void Music::Unload()
    {
        //Mix_FreeMusic( m_MusicInternal );
        //m_MusicInternal = nullptr;
        m_FileName = "Undefined music";
    }

    void Music::Play( const int loops )
    {
        assert( IsLoaded() );
        /*const int ret = Mix_PlayMusic( m_MusicInternal, loops );
        if ( ret == -1 )
        {
            WARNING( "Cannot play music: %s. Error: %s", m_FileName.c_str(), SDL_GetError() );
        }*/
    }
}
