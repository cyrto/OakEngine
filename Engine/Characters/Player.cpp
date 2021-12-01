#include "Player.h"
#include<Graphics/TextureManager.h>


Player::Player(Properties* props) : Character(props) {
	m_Row = 0;
	m_FrameCount = 5;
	m_AnimSpeed = 80;
} 




void Player::Draw()
{
	TextureManager::GetInstance()->DrawFrame(m_TextureID, m_Transfrom->X, m_Transfrom->Y, m_Width, m_Height, m_Row, m_Frame);
	//TextureManager::GetInstance()->Draw(m_TextureID, m_Transfrom->X, m_Transfrom->Y, m_Width, m_Height);
}

void Player::Update(float delteTime)
{
	m_Frame = (SDL_GetTicks() / m_AnimSpeed) % m_FrameCount;
	SDL_Log("%d", m_Frame);
}

void Player::Clean()
{
	TextureManager::GetInstance()->Clean();
}
