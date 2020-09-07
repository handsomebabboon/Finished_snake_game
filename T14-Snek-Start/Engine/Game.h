#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Board.h"
#include "Snake.h"
#include <random>
#include "goal.h"
class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
    Board brd;
    Location start_loc = { 2,2 };
    Snake snek;
    Location delta_loc = { 1,0 };
	std::mt19937 rng;
	Goal goal;
    int frametimer = 0;
    int static constexpr frameperiod = 10;
    bool IsOver = false;
	/********************************/
};