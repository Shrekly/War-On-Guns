#include "EnemyShip.h"
#include "../Core/Renderer/ConsoleColours.h"
#include "../Core/Maths/Vector2.h"
#include "../Core/Renderer/AnimatedSprite.h"

#include <Windows.h>

//ascii bounds
const int ENEMY_SPRITE_WIDTH = 11;
const int ENEMY_SPRITE_HEIGHT = 11;

//enemy sprite
CHAR_INFO EnemyShipSprite0[ENEMY_SPRITE_ANIMATION_FRAMES][ENEMY_SPRITE_WIDTH * ENEMY_SPRITE_HEIGHT] =
{
	{
		{ ' ' ,BACKGROUND_RED },{ ' ' ,BACKGROUND_RED },{ ' ' ,BACKGROUND_DARK_GREY } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_DARK_GREY } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_YELLOW },{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_DARK_GREY } ,{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_DARK_GREY } ,{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_RED },{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_DARK_GREY } ,{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY } ,{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_GREY } ,{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY } ,{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_GREY } ,{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY } ,{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY } ,{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY } ,{ ' ' ,BACKGROUND_GREY},{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY } ,{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK  },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_DARK_GREY } ,{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_DARK_GREY } ,{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
	},
	{
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_DARK_GREY } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_DARK_GREY } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_DARK_GREY } ,{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_DARK_GREY } ,{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_DARK_GREY } ,{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY } ,{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_GREY } ,{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY } ,{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_GREY } ,{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY } ,{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY } ,{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY } ,{ ' ' ,BACKGROUND_GREY},{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY } ,{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK  },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_DARK_GREY } ,{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_DARK_GREY } ,{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
	},
	{
		{ ' ' ,BACKGROUND_RED },{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_DARK_GREY } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_DARK_GREY } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_YELLOW },{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_DARK_GREY } ,{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_DARK_GREY } ,{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_RED },{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_DARK_GREY } ,{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY } ,{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_GREY } ,{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY } ,{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_GREY } ,{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY } ,{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY } ,{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY } ,{ ' ' ,BACKGROUND_GREY},{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY } ,{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK  },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_DARK_GREY } ,{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_DARK_GREY } ,{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
	},
	{
		{ ' ' ,BACKGROUND_RED },{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_DARK_GREY } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_DARK_GREY } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_YELLOW },{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_DARK_GREY } ,{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_DARK_GREY } ,{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_RED },{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_DARK_GREY } ,{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY } ,{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_GREY } ,{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY } ,{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_GREY } ,{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY } ,{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY } ,{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY } ,{ ' ' ,BACKGROUND_GREY},{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY } ,{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK  },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_DARK_GREY } ,{ ' ' ,BACKGROUND_GREY },{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_DARK_GREY } ,{ ' ' ,BACKGROUND_DARK_GREY },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
	},

};

const int MOVEMENT_AMOUNT = 4;
//constructor
EnemyShip::EnemyShip()
	:m_bInitialised(false)
	, m_AnimationTimer(0.0f)
	, m_Active(true)
	, m_ScoreValue(0)
	, m_FireRate(0)
	, m_checkif(false)
{
}
//destructor
EnemyShip::~EnemyShip()
{
}

//initialises all values and position of the ship
void EnemyShip::Initialise(Vector2& position, int fireRate, int sprite, int scoreValue, float initialTime)
{
	m_ScoreValue = scoreValue;
	m_AnimationTimer = initialTime;
	m_FireRate = fireRate;
	int SCREEN_HEIGHT = 96;

	AnimatedSprite::Initialise(&EnemyShipSprite0[0][0], Vector3(ENEMY_SPRITE_WIDTH, ENEMY_SPRITE_HEIGHT, ENEMY_SPRITE_ANIMATION_FRAMES));
	Vector2 startPosition(position.x - (AnimatedSprite::GetSize().x / 2), position.y - (AnimatedSprite::GetSize().y / 2));
	SetPosition(startPosition);

	m_bInitialised = true;

}

bool EnemyShip::Update(float deltaTime)
{
	if (!m_bInitialised || !m_Active)
		return false;

	//checks if .x position is less than two and kills enemy and sets a bool value to true
	if (GetPosition().x < -2)
	{
		m_checkif = true;
		Meow();
	}

	//makes the animation work together
	m_AnimationTimer += deltaTime;
	if (m_AnimationTimer >= 1.0f) 
	{
		if (GetAnimationFrame() == 2)
		{
			m_AnimationTimer -= 0.15f;
			SetAnimationFrame(3);
		}
		else if (GetAnimationFrame() == 3)
		{
			m_Active = false;
		}
		else
		{
			m_AnimationTimer -= 1.0f;
			SetAnimationFrame(GetAnimationFrame() == 0 ? 1 : 0);
		}

		return ShouldFire();
	}
	return false;
	
}

//calls the renderer
void EnemyShip::Render(ASCIIRenderer* pRenderer)
{
	if (!m_bInitialised || !m_Active)
		return;

	AnimatedSprite::Render(pRenderer);
}

//removes enemy ship
void EnemyShip::Meow()
{
	m_Active = false;
}

//gives a random chance for the ship to fire and will return a bool
bool EnemyShip::ShouldFire()
{
	bool shouldFire = false;
	int chance = rand() % 100;

	if (m_FireRate > chance)
	{
		shouldFire = true;
		
	}

	return shouldFire;
}

//decreases position on x axis causing it to move left towards playership
void EnemyShip::Approach()
{
	SetPosition(Vector2(GetPosition().x - 2, GetPosition().y));
}
