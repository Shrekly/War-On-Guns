#pragma once
#ifndef _MISSILE_H
#define _MISSILE_H
#include "EnemyShip.h"
#include "../Core/Renderer/AnimatedSprite.h"
#include "../Core/Renderer/ASCIIRenderer.h"
#include "../Core/Renderer/Sprite.h"

class ASCIIRenderer;

const int MISSILE_SPEED = 2;

class Missile : public Sprite 
{
public:
	//constructor and destructor
	Missile();
	~Missile();

	//base functions
	void Initialise(Vector2& position, Vector2& velocity);
	void Update();
	void Render(ASCIIRenderer* pRenderer);
	//extra functions
	void Explode();

	void SetActive(bool active = true) { m_Active = active; };
	bool Active() { return m_Active; }

private:
	//variables
	Vector2 m_Velocity;

	bool m_bInitialised;
	bool m_Active;


};

#endif // !_MISSILE_H

