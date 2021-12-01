#pragma once

#ifndef Transform_H
#define Transform_H


#include<iostream>
#include"Vector2D.h"

class Transform
{
public:
	float X, Y;
public:
	Transform(float x = 0, float y = 0) : X(x), Y(y) {};
	void Log(std::string msg = "") {
		std::cout << msg << "(X Y) = (" << X << " " << Y << ")" << std::endl;
	}
private:
	inline void TranslateX(float x) { X += x; }
	inline void TranslateY(float y) { Y += y; }
	inline void TranslateX(Vector2D v) { X += v.X; Y += v.Y;}

};



#endif // !Transform_H
