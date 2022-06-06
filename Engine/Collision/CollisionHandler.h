#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

#include<SDL.h>
#include<Map/TileLayer.h>


class CollisionHandler
{
public:
	bool CheckCollision(SDL_Rect a, SDL_Rect b);
	bool MapCollision(SDL_Rect a);

	inline static CollisionHandler* GetInstance() { return s_Instance = (s_Instance != nullptr) ? s_Instance : new CollisionHandler(); }


private:
	CollisionHandler();
	TileMap m_LayerTilemap;
	TileLayer* m_CollisionLayer;

	static CollisionHandler* s_Instance;
};
#endif // !COLLISIONHANDLER_H
