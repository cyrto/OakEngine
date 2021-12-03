#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "Vector2D.h"


#define UNI_MASS 1.0f
#define GRAVITY 9.8f

#define FORWARD  1
#define BACKWARD  -1
#define UPWARD  1
#define DOWNWARD  -1



class RigidBody
{
public:
	RigidBody() {
		m_Mass = UNI_MASS;
		m_Gravity = GRAVITY;
	}

	inline void SetMass(float mass) { m_Mass = mass; }
	inline void SetGravity(float gravity) { m_Gravity = gravity; }

	inline void AddForce(Vector2D f) { m_Force = f; }
	inline void AddForceX(float fx) { m_Force.X = fx; }
	inline void AddForceY(float fy) { m_Force.Y = fy; }
	inline void RemoveForce() { m_Force = Vector2D(0, 0); }

	inline void AddFriction(Vector2D f) { m_Friction = f; }
	inline void RemoveFriction() { m_Friction = Vector2D(0, 0); }

	inline float Mass() { return m_Mass; }
	inline Vector2D Position() { return m_Position; }
	inline Vector2D Velocity() { return m_Velocity; }
	inline Vector2D Accelaration() { return m_Accelaration; }

	void Update(float deltaTime) {
		m_Accelaration.X = (m_Force.X + m_Friction.X) / m_Mass;
		m_Accelaration.Y = m_Gravity + m_Force.Y / m_Mass;
		m_Velocity = m_Accelaration * deltaTime;
		m_Position = m_Velocity * deltaTime;
	}

private:
	float m_Mass;
	float m_Gravity;

	Vector2D m_Force;
	Vector2D m_Friction;

	Vector2D m_Position;
	Vector2D m_Velocity;

	Vector2D m_Accelaration;



};


#endif // !RIGIDBODY_H
