#ifndef CAMERA_H
#define CAMERA_H


#include<Physics/Point.h>
#include<Physics/Vector2D.h>
#include<SDL.h>
#include <Core/Engine.h>

class Camera
{
public:

	void Update(float deltaTime);
	inline SDL_Rect GetViewBox() { return m_ViewBox; }
	inline Vector2D GetPosition() { return m_Position; }
	inline void SetTarget(Point* target) { m_Target = target; }
	inline static Camera* GetInstance() { return s_Instance = (s_Instance != nullptr) ? s_Instance : new Camera(); }

private:
	Camera() {
		m_ViewBox = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };
	}


	Point* m_Target;
	Vector2D m_Position;

	SDL_Rect m_ViewBox;

	static Camera* s_Instance;
};

#endif // !CAMERA_H