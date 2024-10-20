#include "EnemyArmy.h"
#include "../Core/Maths/Vector2.h"
#include "Game.h"
#include "Windows.h"

float deltaTime = 1.0f / 30.0f;

const int ENEMY_SPACING_X = 45; // allows for a maximum of 5 enemies on screen

//constructor
EnemyArmy::EnemyArmy()
	:m_UpdateTimer(0.0f)
	, m_pGame(NULL)
	, m_AnimationTimer(0.0f)
	, m_ScoreAdd(0)
	, checking(false)
{

}
//destructor
EnemyArmy::~EnemyArmy()
{
}

// for loops initialise 50 enemies. Random number generator used to set y coordinate. 
void EnemyArmy::Initialise(Game* pGame)
{
	m_pGame = pGame;
	deltaTime = 1.0f / 10.0f;
	m_Aproaching = true;
	for (int i = 0; i < NUM_ROWS_OF_INVADERS; i++)
	{
		for (int j = 0; j < NUM_INVADERS_PER_ROW; j++)
		{
			int Rand = rand() % (SCREEN_HEIGHT - 3);
			m_EnemyShip[i][j].Initialise(Vector2(256 + (ENEMY_SPACING_X + j * (17 + ENEMY_SPACING_X)), Rand), 5, i, (NUM_ROWS_OF_INVADERS - i) * 200);
		}

	}
}

void EnemyArmy::Update()
{
	//update enemy movement
	m_UpdateTimer += deltaTime;

	if (m_UpdateTimer >= 1.0f)
	{
		for (int i = 0; i < NUM_ROWS_OF_INVADERS; i++)
		{
			for (int j = 0; j < NUM_INVADERS_PER_ROW; j++)
			{
				m_EnemyShip[i][j].Approach();
			}
		}
	}
	//checks all the ships and updates their missiles
	for (int i = 0; i < NUM_ROWS_OF_INVADERS; i++)
	{
		for (int j = 0; j < NUM_INVADERS_PER_ROW; j++)
		{
			if (m_EnemyShip[i][j].Update(deltaTime))
			{
				Missile* pMissile = new Missile();
				pMissile->Initialise(Vector2(m_EnemyShip[i][j].GetPosition().x + (m_EnemyShip[i][j].GetSize().x / 2.0f), m_EnemyShip[i][j].GetPosition().y + 1), Vector2(0, MISSILE_SPEED));
				m_pGame->AddEnemyMissile(pMissile);
			}
		}
	}
}

//checks position of each active enemy ship. If the x position is 0, it will destroy the ship and set landed to true. 
bool EnemyArmy::Landed()
{
	m_Landed = false;
	for (int i = 0; i < NUM_ROWS_OF_INVADERS; i++)
	{
		for (int j = 0; j < NUM_INVADERS_PER_ROW; j++)
		{
			if (m_EnemyShip[i][j].GetPosition().x == 0 && m_EnemyShip[i][j].Active() == true)
			{
				m_Landed = true;
				m_EnemyShip[i][j].Meow();
			}
		}
	}

	return m_Landed;
}
//when called resets m_landed to false
void EnemyArmy::SetFalse()
{
	m_Landed = false;
}
//Calls the renderer for all of the ships
void EnemyArmy::Render(ASCIIRenderer* pRenderer)
{
	for (int i = 0; i < NUM_ROWS_OF_INVADERS; i++)
	{
		for (int j = 0; j < NUM_INVADERS_PER_ROW; j++)
		{
			m_EnemyShip[i][j].Render(pRenderer);
		}
	}
}

//checks for colisions. If it has collided, it will add to the score and remove the applicable ship
bool EnemyArmy::Collides(Sprite& otherSprite)
{
	bool collides = false;
	for (int i = 0; i < NUM_ROWS_OF_INVADERS; i++)
	{
		for (int j = 0; j < NUM_INVADERS_PER_ROW; j++)
		{
			if (m_EnemyShip[i][j].Active() && otherSprite.Collides(m_EnemyShip[i][j].GetCurrentSprite()))
			{
				collides = true;
				m_ScoreAdd += m_EnemyShip[i][j].GetScoreValue();
				m_EnemyShip[i][j].Meow();
			}
		}
	}

	return collides;
}

//kills all of the enemies
void EnemyArmy::KillAll()
{
	for (int i = 0; i < NUM_ROWS_OF_INVADERS; i++)
	{
		for (int j = 0; j < NUM_INVADERS_PER_ROW; j++)
		{
			checking = true;
			m_EnemyShip[i][j].Meow();
		}
	}
}

//used to check win conditions. 
int EnemyArmy::EnemiesRemaining()
{
	int activeEnemies = 0;
	for (int i = 0; i < NUM_ROWS_OF_INVADERS; i++)
	{
		for (int j = 0; j < NUM_INVADERS_PER_ROW; j++)
		{
			if (m_EnemyShip[i][j].Active())
			{
				activeEnemies++;
			}
		}
	}

	return activeEnemies;
}