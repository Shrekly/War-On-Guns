#ifndef _ScoreDisplay_H_
#define _ScoreDisplay_H_

#include "../../Core/Renderer/AnimatedSprite.h"

class ASCIIRenderer;

extern const int SCREEN_WIDTH;

const int NUM_DIGITS = 10;
const int DIGIT_WIDTH = 8;
const int DIGIT_HEIGHT = 10;


class ScoreDisplay : public AnimatedSprite
{
public:
	//constructor and destructor
	ScoreDisplay();
	~ScoreDisplay();

	//base functions
	void Initialise(Vector2& position);
	void Update(float deltaTime);
	void Render(ASCIIRenderer* pRenderer);

	//sets digit
	void SetDigitValue(int value);

private:
	//variables
	bool m_bInitialised;

};

#endif
