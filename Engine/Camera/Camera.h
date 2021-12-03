#ifndef CAMERA_H
#define CAMERA_H

class Camera
{
public:
	inline static Camera* GetInstance() { return s_Instance = (s_Instance != nullptr) ? s_Instance : new Camera(); }

private:
	Camera();

	static Camera* s_Instance;
};



#endif // !CAMERA_H
