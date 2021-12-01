#pragma once

#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#endif // !TEXTUREMANAGER_H


#include"Core/Engine.h"
#include <string>
#include <map>
#include <SDL.h>
#include <SDL_image.h>

class TextureManager
{
public:
	static TextureManager* GetInstance() {
		if (s_Instance == nullptr) {
			s_Instance = new TextureManager();
		}
		return s_Instance;
	}

	bool Load(std::string id, std::string filename);
	void Drop(std::string id);
	void Clean();

	void Draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void DrawFrame(std::string id, int x, int y, int width, int height, int row, int frame, SDL_RendererFlip flip = SDL_FLIP_NONE);


private:
	static TextureManager* s_Instance;
	std::map<std::string, SDL_Texture*> m_TextureMap;
	TextureManager();
};

