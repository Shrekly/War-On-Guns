#include "Missile.h"
#include "../Core/Renderer/ConsoleColours.h"

//player missile sprite
CHAR_INFO MissileSprite[] =
{
	{0, BACKGROUND_WHITE}, {0, BACKGROUND_WHITE}, {0, BACKGROUND_WHITE}, {0, BACKGROUND_RED}
};

//enemy missile sprite
CHAR_INFO EnemyMissileSprite[] =
{
	{ ' ', BACKGROUND_YELLOW },
	{ ' ', BACKGROUND_YELLOW },
	{ ' ', BACKGROUND_YELLOW },
};

//constructor
Missile::Missile()
	:m_bInitialised(false)
	, m_Active(true)
{
}

//destructor
Missile::~Missile()
{
}

//initialises all variables
void Missile::Initialise(Vector2& position, Vector2& velocity)
{
	m_Velocity = velocity;

	Sprite::Initialise(m_Velocity.y < 0.0f ? MissileSprite : EnemyMissileSprite, Vector2(4, 1));

	Vector2 startPosition(position.x - (Sprite::GetSize().x / 2), position.y - (Sprite::GetSize().y / 2));
	SetPosition(startPosition);

	m_bInitialised = true;
}

//moves the missile forward every time called
void Missile::Update()
{
	if (!m_bInitialised || !m_Active)
		return;

	SetPosition(Vector2(GetPosition().x + 4, GetPosition().y ));
}

//renders the missiles in the ascii renderer
void Missile::Render(ASCIIRenderer* pRenderer)
{
	if (!m_bInitialised || !m_Active)
		return;

	Sprite::Render(pRenderer);
}

//when explorded it sets it to not active
void Missile::Explode()
{
	m_Active = false;
}