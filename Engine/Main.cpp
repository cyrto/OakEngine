#include"Core/Engine.h"

#include<map>
#include<string>
#include<filesystem>

int main(int argc, char** argv) {

	

	bool success = Engine::GetInstance()->Init();
	if (!success) {
		SDL_Log("init error: %s", SDL_GetError());
		return 0;
	}

	while (Engine::GetInstance()->IsRunning())
	{
		Engine::GetInstance()->Events();
		Engine::GetInstance()->Update();
		Engine::GetInstance()->Render();
	}

	Engine::GetInstance()->Clean();
	return 0;
}