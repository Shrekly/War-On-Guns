#pragma once

#ifndef _PlayerShip_H_
#define _PlayerShip_H_

#include "../Core/Renderer/Sprite.h"

class ASCIIRenderer;
//variable declaration
extern const int SCREEN_WIDTH;

class PlayerShip : public Sprite
{
public:
	//constructor and destructor
	PlayerShip();
	~PlayerShip();

	//base functions
	void Initialise(Vector2& position, int leftKey, int rightKey);
	void Update();
	void Render(ASCIIRenderer* pRenderer);
	void Bounds();

private:
	//movement
	void MoveUp();
	void MoveDown();

	//keys
	int m_UpKey;
	int m_DownKey;

	//checking
	bool UpKeyPressed();
	bool DownKeyPressed();

	bool m_bInitialised;

};

#endif
