#pragma once

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H



#include"IObject.h"
#include<Physics/Transform.h>
#include<SDL.h>


struct Properties {

public:

	Properties(std::string textureID, int x, int y,int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE) {
		X = x;
		Y = y;
		Flip = flip;
		Width = width;
		Height = height;
		TextureID = textureID;
	}
	std::string TextureID;
	int Width, Height;
	float X, Y;
	SDL_RendererFlip Flip;

};

class GameObject :public IObject {

public:
	GameObject(Properties* props):  m_Flip(props->Flip) ,
		m_TextureID(props->TextureID), m_Height(props->Height),
		m_Width(props->Width){
		m_Transfrom = new Transform(props->X, props->Y);
	}


	virtual ~GameObject() {}

	virtual void Draw() = 0;
	virtual void Update(float delteTime) = 0;
	virtual void Clean() = 0;

protected:
	Transform* m_Transfrom;
	int m_Width, m_Height;
	std::string m_TextureID;
	SDL_RendererFlip m_Flip;
};


#endif // !GAMEOBJECT_H