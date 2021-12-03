#include "Player.h"
#include<Graphics/TextureManager.h>
#include<Input/Input.h>
#include<Physics/RigidBody.h>


Player::Player(Properties* props) : Character(props) {

	m_RigidBody = new RigidBody();
	m_Animation = new Animation();
	m_Animation->SetProps(props->TextureID, 0, 5, 80, SDL_FLIP_HORIZONTAL);
} 

void Player::Draw()
{
	m_Animation->Draw(m_Transfrom->X, m_Transfrom->Y, m_Width, m_Height);
}

void Player::Update(float deltaTime)
{
	m_RigidBody->Update(deltaTime);

	m_RigidBody->RemoveForce();

	if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_D)) {
		m_RigidBody->AddForceX(FORWARD * 5);
	}
	if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_A)) {
		m_RigidBody->AddForceX(BACKWARD * 5);
	}
	m_Transfrom->TranslateX(m_RigidBody->Position().X);
	m_Animation->Update();
}

void Player::Clean()
{
	TextureManager::GetInstance()->Clean();
}
