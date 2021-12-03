#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include <Animation/Animation.h>
#include <Physics/RigidBody.h>



class Player : public Character
{
public:
	Player(Properties* props);
	
	virtual void Draw();
	virtual void Update(float deltaTime);
	virtual void Clean();

private:
	Animation* m_Animation;
	RigidBody* m_RigidBody;
};




#endif // !PLAYER_H
