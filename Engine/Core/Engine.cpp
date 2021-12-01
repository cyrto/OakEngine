#include "Engine.h"
#include <iostream>;
#include <Physics/Vector2D.h>
#include <Physics/Transform.h>
#include <Object/GameObject.h>
#include <Characters/Player.h>


Engine* Engine::s_Instance = nullptr;
Player* player = nullptr;

Engine::Engine(): 
	m_IsRunning(false), m_Window(nullptr), m_Renderer(nullptr){
}

bool Engine::Init()
{
	m_IsRunning = true;
	if (SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0) {
		SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
		return false;
	}


	// create window
	m_Window = SDL_CreateWindow("Odora Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	if (m_Window == nullptr) {
		SDL_Log("Failed to Create window using SDL: %s", SDL_GetError());
		return false;
	}

	//create renderer
	m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (m_Renderer == nullptr) {
		SDL_Log("Failed to Create renderer using SDL: %s", SDL_GetError());
		return false;
	}

	// load texture
	//bool success = TextureManager::GetInstance()->Load("planet", "D:/Program/VisualStudioProject/OdoraEngine/Assets/Images/planet.png");
	bool success = TextureManager::GetInstance()->Load("planet", "Assets/Images/planet.png");
	if (!success) {
		SDL_Log("Failed to Load texture: %s", SDL_GetError());
		return false;
	}

	//load player
	TextureManager::GetInstance()->Load("player", "Assets/Images/reading.png");
	player = new Player(new Properties("player", 0, 0, 60, 88));

	
	return true;
}

bool Engine::Clean()
{
	TextureManager::GetInstance()->Clean();
	SDL_DestroyRenderer(m_Renderer);
	SDL_DestroyWindow(m_Window);
	IMG_Quit();
	SDL_Quit();
	return false;
}

void Engine::Quit()
{
}

void Engine::Update()
{
	player->Update(0);
}

void Engine::Render()
{
	SDL_SetRenderDrawColor(m_Renderer, 124, 218, 254, 255);
	SDL_RenderClear(m_Renderer);

	//TextureManager::GetInstance()->Draw("planet", 100,100,300,300);

	player->Draw();

	SDL_RenderPresent(m_Renderer);
}

void Engine::Events()
{

	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		Quit();
		break;
	}
}
