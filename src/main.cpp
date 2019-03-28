<<<<<<< HEAD
// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include "engine.h"
#include <memory>

using namespace AeonLib;

int main( void )
{	
	std::unique_ptr<Engine> engine(new Engine(""));
	
	engine->Run();
	//std::unique_ptr<Renderer> renderer (new Renderer());
	
	//renderer->InitWindow(800, 600,false, "My First window using aeonlib !!!");
	//Renderer::GameLoop();
	
	return 0;
}


=======
// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include "engine.h"
#include <memory>

using namespace AeonLib;

int main( void )
{	
	std::unique_ptr<Engine> engine(new Engine(""));
	
	engine->Run();
	//std::unique_ptr<Renderer> renderer (new Renderer());
	
	//renderer->InitWindow(800, 600,false, "My First window using aeonlib !!!");
	//Renderer::GameLoop();
	
	return 0;
}
>>>>>>> b3fe3d510207ab84b0b6f91a65f82a27061171ae
