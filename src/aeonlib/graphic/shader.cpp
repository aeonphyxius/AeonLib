#include "shader.h"

namespace aeonlib
{
    Shader::Shader()
    {
        Shader("","");
    }

    Shader::Shader( const char * t_vertex_file, const char * t_frag_file ):
        m_vertex_file ( t_vertex_file ),
        m_frag_file ( t_frag_file )
    {
        // 1. Retrieve the vertex/fragment source code from filePath
        std::string vertex_code;
        std::string fragment_code;

        std::ifstream vShaderFile;
        std::ifstream fShaderFile;
        
        // ensures ifstream objects can throw exceptions:
        vShaderFile.exceptions ( std::ifstream::badbit );
        fShaderFile.exceptions ( std::ifstream::badbit );
        try
        {
            // Open files
            vShaderFile.open( m_vertex_file );
            fShaderFile.open( m_frag_file );
            std::stringstream vShaderStream, fShaderStream;
            // Read file's buffer contents into streams
            vShaderStream << vShaderFile.rdbuf( );
            fShaderStream << fShaderFile.rdbuf( );
            // close file handlers
            vShaderFile.close( );
            fShaderFile.close( );
            // Convert stream into string
            vertex_code = vShaderStream.str( );
            fragment_code = fShaderStream.str( );
        }
        catch ( std::ifstream::failure e )
        {
            std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
        }
        const GLchar *vShaderCode = vertex_code.c_str( );
        const GLchar *fShaderCode = fragment_code.c_str( );
        // 2. Compile shaders
        GLuint vertex, fragment;
        GLint success;
        GLchar infoLog[512];
        // Vertex Shader
        vertex = glCreateShader( GL_VERTEX_SHADER );
        glShaderSource( vertex, 1, &vShaderCode, NULL );
        glCompileShader( vertex );
        // Print compile errors if any
        glGetShaderiv( vertex, GL_COMPILE_STATUS, &success );
        if ( !success )
        {
            glGetShaderInfoLog( vertex, 512, NULL, infoLog );
            std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        }
        // Fragment Shader
        fragment = glCreateShader( GL_FRAGMENT_SHADER );
        glShaderSource( fragment, 1, &fShaderCode, NULL );
        glCompileShader( fragment );
        // Print compile errors if any
        glGetShaderiv( fragment, GL_COMPILE_STATUS, &success );
        if ( !success )
        {
            glGetShaderInfoLog( fragment, 512, NULL, infoLog );
            std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
        }
        // Shader Program
        this->m_program = glCreateProgram( );
        glAttachShader( this->m_program, vertex );
        glAttachShader( this->m_program, fragment );
        glLinkProgram( this->m_program );
        // Print linking errors if any
        glGetProgramiv( this->m_program, GL_LINK_STATUS, &success );
        if (!success)
        {
            glGetProgramInfoLog( this->m_program, 512, NULL, infoLog );
            std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        }
        // Delete the shaders as they're linked into our program now and no longer necessery
        glDeleteShader( vertex );
        glDeleteShader( fragment );
    }   
}
