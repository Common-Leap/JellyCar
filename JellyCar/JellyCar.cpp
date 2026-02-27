#include <Andromeda/System/GameManager.h>
#include <Andromeda/System/GameLoader.h>
#include <Andromeda/Audio/AudioManager.h>
#include <Andromeda/Utils/Logger.h>
#include "JellyGameManager.h"
#include "Utils/AudioHelper.h"

using namespace Andromeda::System;


#include <iostream>
#include <cstdlib>

// Overloading Global new operator
//void* operator new(size_t sz)
//{
//    void* m = malloc(sz);
//    std::cout << "User Defined :: Operator new" << std::endl;
//
//    return m;
//}
//// Overloading Global delete operator
//void operator delete(void* m)
//{
//    std::cout << "User Defined :: Operator delete" << std::endl;
//    free(m);
//}
// Overloading Global new[] operator
//void* operator new[](size_t sz)
//{
//    std::cout << "User Defined :: Operator new []" << std::endl;
//    void* m = malloc(sz);
//    return m;
//}
//// Overloading Global delete[] operator
//void operator delete[](void* m)
//{
//    std::cout << "User Defined :: Operator delete[]" << std::endl;
//    free(m);
//}

int _newlib_heap_size_user = 128 * 1024 * 1024;

int main(int argc, char *argv[])
{
	JellyGameManager* jellyGame = new JellyGameManager();
	GameLoader* loader = GameLoader::Create(jellyGame);

	loader->Run();

	Andromeda::Utils::Logger::Instance()->Log("Main: begin audio shutdown\n");
	AudioHelper::Shutdown();
	Andromeda::Utils::Logger::Instance()->Log("Main: audio shutdown complete\n");

	Andromeda::Audio::AudioManager::Shutdown();
	Andromeda::Utils::Logger::Instance()->Log("Main: audio manager shutdown complete\n");

	Andromeda::Utils::Logger::Instance()->Log("Main: return to standard libnx exit\n");
	return 0;
}
