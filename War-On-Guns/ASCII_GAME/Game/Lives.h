#pragma once
#ifndef _LIVES_H
#define _LIVES_H

#include "../Core/Renderer/AnimatedSprite.h"

class ASCIIRenderer;

extern const int SCREEN_WIDTH;

const int LIVES_DIGITS = 3;
const int LIVES_WIDTH = 8;
const int LIVES_HEIGHT = 10;

class Lives : public AnimatedSprite 
{
public:
	//constructor and destructor
	Lives();
	~Lives();

	//base functions
	void Initialise(Vector2& position);
	void Render(ASCIIRenderer* pRenderer);
	void Update(float deltatime);

	//sets digit
	void SetDigitValue(int value);

private:
	//variables
	int m_bInitialised;

};
#endif