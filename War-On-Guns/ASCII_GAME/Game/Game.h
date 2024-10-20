#ifndef _GAME_H_
#define _GAME_H

//get all the .h files from the file system
#include "GameStates.h"
#include "../Game/EnemyArmy.h"
#include "EnemyShip.h"
#include "Menu.h"
#include "PlayerShip.h"
#include "../Core/Renderer/Sprite.h"
#include "../Game/Missile.h"
#include "../Game/GameObjects/ScoreDisplay.h"
#include "Lives.h"
#include <vector>

class ASCIIRenderer;

class Game
{
public:
	Game();
	~Game();

	void Initialise();
	void Run();

	void AddEnemyMissile(Missile* pMissile);

private:

	//Functions
	void InitialiseRenderer();
	void InitialiseGame();
	void InitialiseEndScreens();

	void InitialiseMainMenu();
	void UpdateMainMenu();
	void RenderMainMenu();

	void Update();
	void UpdateGame();

	void UpdateEnemyMissiles();
	void RenderEnemyMissiles();
	
	void Render();
	void RenderGame();

	void UpdateMissile();
	void FireMissile();

	void RenderScore();
	void UpdateScoreDisplay();

	void UpdateLives();

	void RenderWinScreen();
	void RenderLoseScreen();
	void CheckWinConditions();
	void UpdateEndGameScreens();

	void Repeat();

	//Variables
	ASCIIRenderer* m_pRenderer;
	E_GAME_STATE m_GameState;

	bool m_bInitialised;
	bool m_bExitApp;

	int m_Score;
	int m_lives;
	int m_repeat;

	PlayerShip m_PlayerShip;
	
	MenuIcon m_Title;
	MenuIcon m_PlayIcon;
	MenuIcon m_ExitIcon;
	Pointer m_Pointer;

	EnemyShip m_EnemyShip;
	EnemyArmy m_Army;
	
	Missile m_Missile;
	std::vector<Missile*> m_EnemyMissiles;

	ScoreDisplay m_ScoreDigit[4];
	Lives m_Lives_Left;

	Sprite m_GameTitle;

	Sprite m_GameOverTitle;
	int m_EndScreenCounter;
	

	Sprite m_YouWinTitle;

	int m_MainMenuCounter = 0;

	
};


#endif
