#include "Engine.h"
#include <iostream>;
#include <Physics/Vector2D.h>
#include <Physics/Transform.h>
#include <Object/GameObject.h>
#include <Characters/Player.h>
#include<Animation/Animation.h>
#include<Input/Input.h>
#include<Timer/Timer.h>
#include<Map/MapParser.h>


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

	// load tilemap
	if (!MapParser::GetInstance()->Load()) {
		std::cout << "Failed to load map" << std::endl;
		return false;
	}

	m_LevelMap = MapParser::GetInstance()->GetMap("level1");
	if (m_LevelMap == nullptr) {
		std::cout << "Failed to load map" << std::endl;
		return false;
	}

	// load texture
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
	float deltaTime = Timer::GetInstance()-> GetDeltaTime();
	m_LevelMap->Update();
	player->Update(deltaTime);
}

void Engine::Render()
{
	SDL_SetRenderDrawColor(m_Renderer, 124, 218, 254, 255);
	SDL_RenderClear(m_Renderer);

	m_LevelMap->Render();

	player->Draw();

	SDL_RenderPresent(m_Renderer);
}

void Engine::Events()
{
	Input::GetInstance()->Listen();
}
