#pragma once

#ifndef _EnemyArmy_H
#define _EnemyArmy_H

#include "EnemyShip.h"
#include "../Core/Maths/Vector2.h"
#include "Missile.h"


const int NUM_INVADERS_PER_ROW = 50;
const int NUM_ROWS_OF_INVADERS = 1;
const int TOP_OF_PLAY_SCREEN = 15;

class Game;
class ASCIIRenderer;


class EnemyArmy
{
public:
	//constructor and destructor
	EnemyArmy();
	~EnemyArmy();

	//base functions
	void Initialise(Game* pGame);
	void Update();
	void Render(ASCIIRenderer* pRenderer);

	void Approach();

	//other public functions
	bool Collides(Sprite& otherSprite);
	int GetScore() { int value = m_ScoreAdd; m_ScoreAdd = 0; return value; }
	int EnemiesRemaining();
	void KillAll();
	void SetFalse();

	//lives code
	bool Landed();
	bool checking;

private:
	//variables
	bool m_bInitialised;
	bool m_Aproaching;
	float m_UpdateTimer;
	Game* m_pGame;
	EnemyShip m_EnemyShip[NUM_ROWS_OF_INVADERS][NUM_INVADERS_PER_ROW];
	int m_ScoreAdd;
	int EnemiesKilled;
	float m_AnimationTimer;
	bool m_Landed;
};

#endif