#pragma once

#ifndef ENGINE_H
#define ENGINE_H

#include<SDL.h>
#include<SDL_image.h>
#include<Graphics/TextureManager.h>
#include<Map/GameMap.h>


#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 640



class Engine {

public:

	static Engine* GetInstance() {
		return s_Instance = (s_Instance != nullptr) ? s_Instance : new Engine();
	}

	bool Init();
	bool Clean();
	void Quit();
	void Update();
	void Render();
	void Events();

	inline bool IsRunning() {
		return m_IsRunning;
	}

	inline SDL_Renderer* GetRender() {
		return m_Renderer;
	}

private:
	Engine();
	bool m_IsRunning;

	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;

	static Engine* s_Instance;
	GameMap* m_LevelMap;
};

#endif // !ENGINE_H
