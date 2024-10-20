#include "PlayerShip.h"
#include "../Core/Maths/Vector2.h"
#include "../Core/Renderer/ConsoleColours.h"
#include <Windows.h>
//speed
const int MOVEMENT_SPEED = 2;
//sprite design
CHAR_INFO ShipSprite[] =
{
	{0, BACKGROUND_BLACK},{0, BACKGROUND_BLACK},{0, BACKGROUND_BLACK},{0, BACKGROUND_BLACK},{0, BACKGROUND_BLACK},{0, BACKGROUND_BLACK},{0, BACKGROUND_DARK_GREY},{0, BACKGROUND_GREY},
	{0, BACKGROUND_BLACK},{0, BACKGROUND_BLACK},{0, BACKGROUND_BLACK},{0, BACKGROUND_BLACK},{0, BACKGROUND_BLACK},{0, BACKGROUND_DARK_GREY},{0, BACKGROUND_GREY},{0, BACKGROUND_WHITE},
	{0, BACKGROUND_BLACK},{0, BACKGROUND_BLACK},{0, BACKGROUND_BLACK},{0, BACKGROUND_BLACK},{0, BACKGROUND_DARK_GREY},{0, BACKGROUND_GREY},{0, BACKGROUND_WHITE},{0, BACKGROUND_BLACK},
	{0, BACKGROUND_BLACK},{0, BACKGROUND_BLUE},{0, BACKGROUND_BLACK},{0, BACKGROUND_DARK_GREY},{0, BACKGROUND_GREY},{0, BACKGROUND_WHITE},{0, BACKGROUND_BLACK},{0, BACKGROUND_BLACK},
	{0, BACKGROUND_BLACK},{0, BACKGROUND_BLACK},{0, BACKGROUND_BLUE},{0, BACKGROUND_GREY},{0, BACKGROUND_WHITE},{0, BACKGROUND_BLACK},{0, BACKGROUND_BLACK},{0, BACKGROUND_BLACK},
	{0, BACKGROUND_BLACK},{0, BACKGROUND_TURQOISE},{0, BACKGROUND_SKYBLUE},{0, BACKGROUND_BLUE},{0, BACKGROUND_BLACK},{0, BACKGROUND_BLACK},{0, BACKGROUND_BLACK},{0, BACKGROUND_BLACK},
	{0, BACKGROUND_TURQOISE},{0, BACKGROUND_SKYBLUE},{0, BACKGROUND_TURQOISE},{0, BACKGROUND_BLACK},{0, BACKGROUND_BLUE},{0, BACKGROUND_BLACK},{0, BACKGROUND_BLACK},{0, BACKGROUND_BLACK},
	{0, BACKGROUND_BLACK},{0, BACKGROUND_TURQOISE},{0, BACKGROUND_BLACK},{0, BACKGROUND_BLACK},{0, BACKGROUND_BLACK},{0, BACKGROUND_BLACK},{0, BACKGROUND_BLACK},{0, BACKGROUND_BLACK}
};

//constructor
PlayerShip::PlayerShip()
	:m_UpKey(0)
	, m_DownKey(0)
	, m_bInitialised(false)
{
}

//destructor
PlayerShip::~PlayerShip()
{
}

//player movement
void PlayerShip::Initialise(Vector2& position, int upKey, int downKey)
{
	m_UpKey = upKey;
	m_DownKey = downKey;

	Sprite::Initialise(ShipSprite, Vector2(8, 8));

	Vector2 startPosition(3, 48);
	SetPosition(startPosition);

	m_bInitialised = true;
}
//update sprite
void PlayerShip::Update()
{
	if (!m_bInitialised)
		return;

	if (UpKeyPressed())
	{
		MoveUp();
	}
	if (DownKeyPressed())
	{
		MoveDown();
	}

}
//render sprite on screen
void PlayerShip::Render(ASCIIRenderer* pRenderer)
{
	if (!m_bInitialised)
		return;

	Sprite::Render(pRenderer);
}
//sets move up to work
void PlayerShip::MoveUp()
{
	SetPosition(Vector2(GetPosition().x, GetPosition().y - MOVEMENT_SPEED));

	//if position is less than 0 changes the direction of movement
	if (GetPosition().x < 0)
	{
		MoveDown();
	}
}
//sets move down to work
void PlayerShip::MoveDown()
{
	SetPosition(Vector2(GetPosition().x, GetPosition().y + MOVEMENT_SPEED));

	//if position is greather than screen width then it changes direction of movement
	if (GetPosition().x + GetSize().x > SCREEN_WIDTH)
	{
		MoveUp();
	}
}

bool PlayerShip::UpKeyPressed()
{//Checks if up key has been pressed
	return (GetKeyState(m_UpKey) < 0);
}

bool PlayerShip::DownKeyPressed()
{//Checks if down key has been pressed
	return (GetKeyState(m_DownKey) < 0);
}

void PlayerShip::Bounds() 
{
	// Checks if player goes off screen and teleports them to other side
	if (GetPosition().y > 90) 
	{
		SetPosition(Vector2(GetPosition().x, 6));
	}
	else 
	{
		SetPosition(Vector2(GetPosition().x, 90));
	}
}
