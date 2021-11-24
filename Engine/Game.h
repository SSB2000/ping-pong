/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"

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
	void DrawBall(int x, int y, int r);
	void player01(int x, int y, int length, int width);
	void GameBox(int start_x, int end_x, int start_y, int end_y);
	bool OverlapTest(int box0x, int box0y, int box1x, int box1y);
	bool contact(int xB, int yB, int xP, int yP);
	void GameNet();
	bool BallPlayerContact(int xBall, int yBall);
	void BallBoxWalls(int& xB, int& yB, int& xBS, int& yBS);
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	const int platformLength{ 60 };
	const int platformWidth{ 7 };
	const int xPosition{770 - 10};
	int yPosition{ 300 };
	const int xGameNet{ 400 };
	const int yGameNetStart{ 30 };
	const int yGameNetEnd{ 570 };
	const int platformSpeed{ 12 };
	const int xBoxLowerLimit{ 30 };
	const int xBoxUpperLimit{ 770 };
	const int yBoxLowerLimit{ 30 };
	const int yBoxUpperLimit{ 570 };
	int xBall{ xBoxLowerLimit + 1 };
	int yBall{ yBoxLowerLimit + 1 };
	int xBallSpeed{ 8 };
	int yBallSpeed{ 6 };
	int x1Ball{ xBoxLowerLimit };
	int y1Ball{ yBoxUpperLimit - 11};
	int x1BallSpeed{ 3 };
	int y1BallSpeed{ 2 };

	/********************************/
};