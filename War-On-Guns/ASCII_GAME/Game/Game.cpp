#include "Game.h"
#include <windows.h>
#include <iostream>
#include "../Core/Utils.h"
#include "../Core/Renderer/ASCIIRenderer.h"

const int SCREEN_WIDTH = 256;
const int SCREEN_HEIGHT = 96;

//gets all keys that will be used
#define VK_LEFT		0x25
#define VK_RIGHT	0x27
#define VK_SPACE	0x20      

#define VK_UP		0x26
#define VK_DOWN		0x28

//extra sprites
char* GameOverSprite = "        GGGGGGGGGGGGG               AAA               MMMMMMMM               MMMMMMMMEEEEEEEEEEEEEEEEEEEEEE          OOOOOOOOO     VVVVVVVV           VVVVVVVVEEEEEEEEEEEEEEEEEEEEEERRRRRRRRRRRRRRRRR        GGG::::::::::::G              A:::A              M:::::::M             M:::::::ME::::::::::::::::::::E        OO:::::::::OO   V::::::V           V::::::VE::::::::::::::::::::ER::::::::::::::::R     GG:::::::::::::::G             A:::::A             M::::::::M           M::::::::ME::::::::::::::::::::E      OO:::::::::::::OO V::::::V           V::::::VE::::::::::::::::::::ER::::::RRRRRR:::::R   G:::::GGGGGGGG::::G            A:::::::A            M:::::::::M         M:::::::::MEE::::::EEEEEEEEE::::E     O:::::::OOO:::::::OV::::::V           V::::::VEE::::::EEEEEEEEE::::ERR:::::R     R:::::R G:::::G       GGGGGG           A:::::::::A           M::::::::::M       M::::::::::M  E:::::E       EEEEEE     O::::::O   O::::::O V:::::V           V:::::V   E:::::E       EEEEEE  R::::R     R:::::RG:::::G                        A:::::A:::::A          M:::::::::::M     M:::::::::::M  E:::::E                  O:::::O     O:::::O  V:::::V         V:::::V    E:::::E               R::::R     R:::::RG:::::G                       A:::::A A:::::A         M:::::::M::::M   M::::M:::::::M  E::::::EEEEEEEEEE        O:::::O     O:::::O   V:::::V       V:::::V     E::::::EEEEEEEEEE     R::::RRRRRR:::::R G:::::G    GGGGGGGGGG        A:::::A   A:::::A        M::::::M M::::M M::::M M::::::M  E:::::::::::::::E        O:::::O     O:::::O    V:::::V     V:::::V      E:::::::::::::::E     R:::::::::::::RR  G:::::G    G::::::::G       A:::::A     A:::::A       M::::::M  M::::M::::M  M::::::M  E:::::::::::::::E        O:::::O     O:::::O     V:::::V   V:::::V       E:::::::::::::::E     R::::RRRRRR:::::R G:::::G    GGGGG::::G      A:::::AAAAAAAAA:::::A      M::::::M   M:::::::M   M::::::M  E::::::EEEEEEEEEE        O:::::O     O:::::O      V:::::V V:::::V        E::::::EEEEEEEEEE     R::::R     R:::::RG:::::G        G::::G     A:::::::::::::::::::::A     M::::::M    M:::::M    M::::::M  E:::::E                  O:::::O     O:::::O       V:::::V:::::V         E:::::E               R::::R     R:::::R G:::::G       G::::G    A:::::AAAAAAAAAAAAA:::::A    M::::::M     MMMMM     M::::::M  E:::::E       EEEEEE     O::::::O   O::::::O        V:::::::::V          E:::::E       EEEEEE  R::::R     R:::::R  G:::::GGGGGGGG::::G   A:::::A             A:::::A   M::::::M               M::::::MEE::::::EEEEEEEE:::::E     O:::::::OOO:::::::O         V:::::::V         EE::::::EEEEEEEE:::::ERR:::::R     R:::::R   GG:::::::::::::::G  A:::::A               A:::::A  M::::::M               M::::::ME::::::::::::::::::::E      OO:::::::::::::OO           V:::::V          E::::::::::::::::::::ER::::::R     R:::::R     GGG::::::GGG:::G A:::::A                 A:::::A M::::::M               M::::::ME::::::::::::::::::::E        OO:::::::::OO              V:::V           E::::::::::::::::::::ER::::::R     R:::::R        GGGGGG   GGGGAAAAAAA                   AAAAAAAMMMMMMMM               MMMMMMMMEEEEEEEEEEEEEEEEEEEEEE          OOOOOOOOO                 VVV            EEEEEEEEEEEEEEEEEEEEEERRRRRRRR     RRRRRRR";
char* YouWinSprite = "YYYYYYY       YYYYYYY     OOOOOOOOO     UUUUUUUU     UUUUUUUU     WWWWWWWW                           WWWWWWWWIIIIIIIIIINNNNNNNN        NNNNNNNNY:::::Y       Y:::::Y   OO:::::::::OO   U::::::U     U::::::U     W::::::W                           W::::::WI::::::::IN:::::::N       N::::::NY:::::Y       Y:::::Y OO:::::::::::::OO U::::::U     U::::::U     W::::::W                           W::::::WI::::::::IN::::::::N      N::::::NY::::::Y     Y::::::YO:::::::OOO:::::::OUU:::::U     U:::::UU     W::::::W                           W::::::WII::::::IIN:::::::::N     N::::::NYYY:::::Y   Y:::::YYYO::::::O   O::::::O U:::::U     U:::::U       W:::::W           WWWWW           W:::::W   I::::I  N::::::::::N    N::::::N   Y:::::Y Y:::::Y   O:::::O     O:::::O U:::::D     D:::::U        W:::::W         W:::::W         W:::::W    I::::I  N:::::::::::N   N::::::N    Y:::::Y:::::Y    O:::::O     O:::::O U:::::D     D:::::U         W:::::W       W:::::::W       W:::::W     I::::I  N:::::::N::::N  N::::::N     Y:::::::::Y     O:::::O     O:::::O U:::::D     D:::::U          W:::::W     W:::::::::W     W:::::W      I::::I  N::::::N N::::N N::::::N      Y:::::::Y      O:::::O     O:::::O U:::::D     D:::::U           W:::::W   W:::::W:::::W   W:::::W       I::::I  N::::::N  N::::N:::::::N       Y:::::Y       O:::::O     O:::::O U:::::D     D:::::U            W:::::W W:::::W W:::::W W:::::W        I::::I  N::::::N   N:::::::::::N       Y:::::Y       O:::::O     O:::::O U:::::D     D:::::U             W:::::W:::::W   W:::::W:::::W         I::::I  N::::::N    N::::::::::N       Y:::::Y       O::::::O   O::::::O U::::::U   U::::::U              W:::::::::W     W:::::::::W          I::::I  N::::::N     N:::::::::N       Y:::::Y       O:::::::OOO:::::::O U:::::::UUU:::::::U               W:::::::W       W:::::::W         II::::::IIN::::::N      N::::::::N    YYYY:::::YYYY     OO:::::::::::::OO   UU:::::::::::::UU                 W:::::W         W:::::W          I::::::::IN::::::N       N:::::::N    Y:::::::::::Y       OO:::::::::OO       UU:::::::::UU                    W:::W           W:::W           I::::::::IN::::::N        N::::::N    YYYYYYYYYYYYY         OOOOOOOOO           UUUUUUUUU                       WWW             WWW            IIIIIIIIIINNNNNNNN         NNNNNNN";

//constructor
Game::Game()
:m_pRenderer(NULL)
, m_GameState(E_GAME_STATE_MAIN_MENU)
, m_bInitialised(false)
, m_bExitApp(false)
, m_Score(0)
, m_MainMenuCounter(0)
, m_EndScreenCounter(0)
, m_lives(3)
, m_repeat(0)
{
}

//destructor
Game::~Game()
{
	SAFE_DELETE_PTR(m_pRenderer);
}

void Game::Initialise()
{
	//Calls all initialise functions
	InitialiseRenderer();

	InitialiseMainMenu();

	InitialiseGame();

	InitialiseEndScreens();

	m_bInitialised = true;
}

void Game::InitialiseRenderer()
{
	m_pRenderer = new ASCIIRenderer();

	m_pRenderer->Initialise(SCREEN_WIDTH, SCREEN_HEIGHT);
}

void Game::InitialiseMainMenu() 
{
	//initialses all sprite places on the screen and the pointer
	m_Title.SetSpriteID(0);
	m_Title.SetPosition(Vector2(39, 9));
	m_Title.Initialise(Vector2(SCREEN_WIDTH / 2, 30));

	m_PlayIcon.SetSpriteID(1);
	m_PlayIcon.SetPosition(Vector2(14, 6));
	m_PlayIcon.Initialise(Vector2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2));

	m_ExitIcon.SetSpriteID(2);
	m_ExitIcon.SetPosition(Vector2(14, 5));
	m_ExitIcon.Initialise(Vector2(SCREEN_WIDTH / 2, (m_PlayIcon.Sprite::GetPosition().y + m_PlayIcon.GetSize().y) + 3));

	m_Pointer.Initialise(Vector2(SCREEN_WIDTH / 2 + 20, SCREEN_HEIGHT / 2), VK_UP, VK_DOWN);
}

void Game::InitialiseGame()
{
	//Initialises the playership spawn and the enemy army spawn
	m_PlayerShip.Initialise(Vector2(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 8), VK_UP, VK_DOWN);
	m_Army.Initialise(this);
	//Initialises the missile spawn and sets the active to false
	m_Missile.Initialise(Vector2(m_PlayerShip.GetPosition().x + (m_PlayerShip.GetSize().x * 0.5f), m_PlayerShip.GetPosition().y - 2), Vector2(0, -MISSILE_SPEED));
	m_Missile.SetActive(false);

	//initialses a array for the score digits which can individually update
	for (int i = 0; i < 4; i++)
	{
		m_ScoreDigit[i].Initialise(Vector2(220 + (i * 10), 7));
	}
	//Initialises the lives on the screen
	m_Lives_Left.Initialise(Vector2(250, 90));
}

void Game::InitialiseEndScreens()
{
	//End Game Screen
	Vector2 gameOverTitleSize(200, 16);
	m_GameOverTitle.Initialise(GameOverSprite, FOREGROUND_WHITE, gameOverTitleSize);

	Vector2 gameOverPosition(25, 37);
	m_GameOverTitle.SetPosition(gameOverPosition);


	Vector2 youWinTitleSize(143, 16);
	m_YouWinTitle.Initialise(YouWinSprite, FOREGROUND_WHITE, youWinTitleSize);

	Vector2 youWinPosition(53, 37);
	m_YouWinTitle.SetPosition(youWinPosition);
}

void Game::Run()
{
	//code will only run when the app isn't exited
	while (!m_bExitApp)
	{
		//calls the update subroutine
		Update();
		//calls the render subroutine
		Render();
		//tells the code to not run for 30ms
		Sleep(30);
	}
}

void Game::Update()
{
	//checks if the escape button is currently pressed and if it is exits the game
	if (GetKeyState(VK_ESCAPE) < 0)
	{
		m_bExitApp = true;
		return;
	}
	//this case statement checks which game state the game is currently in
	switch (m_GameState)
	{

	case E_GAME_STATE_MAIN_MENU: // add 2
	{
		//calls update main menu subroutine
		UpdateMainMenu();
	}
	break;

	case E_GAME_STATE_IN_GAME:
		//calls update game subroutine
		UpdateGame();
		break;
	case E_GAME_STATE_LOSE_GAME:
		//If the player loses the game by pressing the space bar they get sent back to the main menu
		if (GetKeyState(VK_SPACE) < 0)
		{
			m_GameState = E_GAME_STATE_MAIN_MENU;
		}
		break;
	case E_GAME_STATE_WIN_GAME:
		//this code is repeated if the player wins allowing them to return to the main menu
		if (GetKeyState(VK_SPACE) < 0)
		{
			m_GameState = E_GAME_STATE_MAIN_MENU;
		}
		break;
	default:
		break;
	}
}

void Game::UpdateGame() 
{
	//calls the update function for both playership and army
	m_PlayerShip.Update();
	m_Army.Update();

	//checks whether the playership is past a certain point and then calls the 
	if (m_PlayerShip.GetPosition().y < 0 || m_PlayerShip.GetPosition().y > SCREEN_HEIGHT)
	{
		m_PlayerShip.Bounds();
	}
	//checks whetehr space has been pressed and if there is not a missile active calls fire missile
	if (GetKeyState(VK_SPACE) < 0) 
	{
		if (!m_Missile.Active()) 
		{
			FireMissile();
		}
	}

	//calls alls the update functions and win conditions
	UpdateMissile();

	UpdateLives();
	
	UpdateEnemyMissiles();
	
	UpdateScoreDisplay();
	
	CheckWinConditions();
}

void Game::Render()
{
	//call this first
	m_pRenderer->ClearScreen();	

	//checks which game state it is in and calls the correct render function
	switch (m_GameState)
	{
	case E_GAME_STATE_MAIN_MENU: // add 2
	{
		RenderMainMenu();
		break;
	}

	case E_GAME_STATE_IN_GAME:
	{
		RenderGame();
		break;
	}

	case E_GAME_STATE_WIN_GAME:
	{
		RenderWinScreen();
		break;
	}

	case E_GAME_STATE_LOSE_GAME:
	{
		RenderLoseScreen();
		break;
	}
	default:
		break;
	}

	//call this last
	m_pRenderer->Render();
}

void Game::RenderGame() 
{
	//calls the render functions from the classes and calls the render enemy missile and score subroutines
	m_PlayerShip.Render(m_pRenderer);

	m_Army.Render(m_pRenderer);

	m_EnemyShip.Render(m_pRenderer);	

	m_Missile.Render(m_pRenderer);

	m_Lives_Left.Render(m_pRenderer);

	RenderEnemyMissiles();

	RenderScore();
}

void Game::UpdateMainMenu() 
{
	//checks whether the VK_Return button has been pressed 
	if (GetKeyState(VK_RETURN) < 0)
	{
		if (m_Pointer.GetPosition().y == SCREEN_HEIGHT / 2 - 2)  // if y position is same as play, start the game
		{
			m_GameState = E_GAME_STATE_IN_GAME;
		}
		else // if not, close the game
		{
			m_bExitApp = true;
			return;
		}
	}
	//calls the update function for these functions making sure they can run
	m_Title.Update();
	
	m_PlayIcon.Update();
	
	m_ExitIcon.Update();
	
	m_Pointer.Update();
}

void Game::RenderMainMenu() 
{
	//calls the render function so that these show up on the screen
	m_Title.Render(m_pRenderer);

	m_PlayIcon.Render(m_pRenderer);

	m_ExitIcon.Render(m_pRenderer);

	m_Pointer.Render(m_pRenderer);
}

void Game::RenderScore() 
{
	//calls every digit of the score display in the renderer so that it properly gets the next digit
	for (int i = 0; i < 4; i++)
	{
		m_ScoreDigit[i].Render(m_pRenderer);
	}
}

void Game::RenderWinScreen()
{
	//Calls the win screen
	m_YouWinTitle.Render(m_pRenderer);
}

void Game::RenderLoseScreen()
{
	//calls the game over title
	m_GameOverTitle.Render(m_pRenderer);
}

void Game::FireMissile()
{
	//sets the position of the missile by using the position of the playershp on x and y and then sets the missile to active
	m_Missile.SetPosition((m_PlayerShip.GetPosition().x + 5) + (m_PlayerShip.GetSize().x * 0.5f), m_PlayerShip.GetPosition().y - 0.5);
	m_Missile.SetActive();
}

void Game::UpdateMissile()
{
	//calsl the missile update function
	m_Missile.Update();

	//checks whether the missile has gone off the screen and calls explode which destroys the missile
	if (m_Missile.GetPosition().y < 0 || m_Missile.GetPosition().x > SCREEN_WIDTH)
	{
		m_Missile.Explode();
	}

	//checks whether the missile is active and it is colliding with an object
	if (m_Missile.Active() && m_Army.Collides(m_Missile))
	{
		//gets the score and increases it by a value and then kills the missile by calling .explode
		m_Score += m_Army.GetScore();
		m_Missile.Explode();
	}

}

void Game::UpdateEnemyMissiles()
{
	//updates every missile so that all the missiles work
	for (int i = 0; i < m_EnemyMissiles.size(); i++)
	{
		m_EnemyMissiles[i]->Update();
	}

	//goes through all the missile.size to make sure every missile has been gone through
	for (int i = 0; i < m_EnemyMissiles.size(); i++)
	{
		//checks whether the missile is active and has collided with the playership
		if (m_EnemyMissiles[i]->Active() && m_EnemyMissiles[i]->Collides(m_PlayerShip))
		{
			//hit the player amd explodes
			m_EnemyMissiles[i]->Explode();
			
		}
		//if missile goes off of the screen the missile gets killed
		if (m_EnemyMissiles[i]->Active() && m_EnemyMissiles[i]->GetPosition().x < 0)
		{
			m_lives--;
			m_EnemyMissiles[i]->Explode();
		}
	}
}

void Game::CheckWinConditions()
{
	//Checks whether enemies remains and if there aren't then it goes to a win state 
	if (m_Army.EnemiesRemaining() <= 0 && m_Army.checking == false)
	{
		//player wins so the stats reset and if player presses space they are taken to the main menu
		m_repeat++;
		m_GameState = E_GAME_STATE_WIN_GAME;
		Repeat();
	}
	else if (m_Army.Landed())
	{
		//player loses lives
		m_lives--;
	}
}

void Game::UpdateEndGameScreens()
{
	//increases end screen counter
	m_EndScreenCounter++;

	//checks if the variable is under 90 and if it is resets it to 0 and exits the app
	if (m_EndScreenCounter > 90)
	{
		m_EndScreenCounter = 0;
		m_bExitApp = true;
	}
}

void Game::RenderEnemyMissiles()
{
	//goes through every missile and renders them
	for (int i = 0; i < m_EnemyMissiles.size(); i++)
	{
		m_EnemyMissiles[i]->Render(m_pRenderer);
	}
}

void Game::AddEnemyMissile(Missile* pMissile)
{
	//adds some pushback to the missile
	m_EnemyMissiles.push_back(pMissile);
}

void Game::UpdateScoreDisplay()
{
	//goes through all of the score digits and updates them
	for (int i = 0; i < 4; i++)
	{
		m_ScoreDigit[i].Update(0.0f);
	}
	
	//initialise array
	int ScoreValues[4];

	//uses array space to update the score display and then connect them to a value in the set digit value
	ScoreValues[3] = m_Score > 9999 ? 9 : m_Score % 10;
	ScoreValues[2] = m_Score > 9999 ? 9 : m_Score / 10 % 10;
	ScoreValues[1] = m_Score > 9999 ? 9 : m_Score / 100 % 10;
	ScoreValues[0] = m_Score > 9999 ? 9 : m_Score / 1000 % 10;

	m_ScoreDigit[0].SetDigitValue(ScoreValues[0]);
	m_ScoreDigit[1].SetDigitValue(ScoreValues[1]);
	m_ScoreDigit[2].SetDigitValue(ScoreValues[2]);
	m_ScoreDigit[3].SetDigitValue(ScoreValues[3]);
}

void Game::UpdateLives() 
{
	//checks whether the lives variable is zero and then sets the game state to the lose game
	switch (m_lives) 
	{
	case 2:
		m_Lives_Left.SetDigitValue(m_lives);
		break;
	case 1:
		m_Lives_Left.SetDigitValue(m_lives);
		break;
	case 0:
		m_repeat++;
		m_GameState = E_GAME_STATE_LOSE_GAME;
		Repeat();
		break;
	default:
		break;
	}
}

void Game::Repeat() 
{
	//if the game gets repeated the lives variable and repeat is changed back to their base values 
	if (m_repeat > 1)
	{
		m_pRenderer->ClearScreen();
		m_Score = 0;
		m_lives = 3;
		m_repeat = 0;
	}
}
