#define SDL_MAIN_HANDLED
#include"Core/Engine.h"
#include<map>
#include<string>
#include<filesystem>
#include<Timer/Timer.h>



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
		Timer::GetInstance()->Tick();
	}

	Engine::GetInstance()->Clean();
	return 0;
}