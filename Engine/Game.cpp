/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	xBall += xBallSpeed;
	yBall += yBallSpeed;
	x1Ball += x1BallSpeed;
	y1Ball += y1BallSpeed;
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		yPosition -= platformSpeed;
		if ((yPosition) <= (yBoxLowerLimit + 1))
		{
			yPosition = (yBoxLowerLimit + 1);
		}
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		yPosition += platformSpeed;
		if ((yPosition + platformLength) >= (yBoxUpperLimit + 1))
		{
			yPosition = (yBoxUpperLimit - platformLength);
		}
	}
	BallBoxWalls(xBall, yBall, xBallSpeed, yBallSpeed);
	BallBoxWalls(x1Ball, y1Ball, x1BallSpeed, y1BallSpeed);

	if (BallPlayerContact(xBall, yBall))
	{
		xBallSpeed = -xBallSpeed;
	}
	if (BallPlayerContact(x1Ball, y1Ball))
	{
		x1BallSpeed = -x1BallSpeed;
	}
	
	
}

void Game::ComposeFrame()
{
	GameBox(xBoxLowerLimit, xBoxUpperLimit, yBoxLowerLimit, yBoxUpperLimit);
	GameNet();
	DrawBall(xBall, yBall, 255);
	DrawBall(x1Ball, y1Ball, 0);
	player01(xPosition, yPosition, platformLength, platformWidth);
}

void Game::GameNet()
{
	for (int i = yGameNetStart; i < yGameNetEnd; i++)
	{
		gfx.PutPixel(xGameNet, i, 250, 20, 0);
	}
}

bool Game::BallPlayerContact(int xBall, int yBall)
{
	if ((xBall + 11 >= xPosition) && ((yBall + 1)>= yPosition) && ((yBall + 11) <= (yPosition+platformLength)))
	{
		return true;
	}
	return false;
}

void Game::BallBoxWalls(int& xB, int& yB, int& xBS, int& yBS)
{
	if (xB + 10 >= xBoxUpperLimit)
	{
		xB = xBoxLowerLimit + 1;
	}
	if (xB <= xBoxLowerLimit)
	{
		xBS = -xBS;
	}
	if (yB + 10 >= yBoxUpperLimit)
	{
		yBS = -yBS;
	}
	if (yB <= yBoxLowerLimit)
	{
		yBS = -yBS;
	}
}

void Game::DrawBall(int x, int y, int r)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			gfx.PutPixel((i + x), (j + y), r, 255, 255);
		}
	}
}
void Game::player01(int x, int y, int length, int width)
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < length; j++)
		{
			gfx.PutPixel(i + x, j + y, 255, 255, 255);
		}
	}
}
void Game::GameBox(int start_x, int end_x, int start_y, int end_y)
{
	for (int i = start_x; i < end_x; i++)
	{
		gfx.PutPixel(i, start_y, 255, 0, 0);
		gfx.PutPixel(i, end_y, 255, 0, 0);
	}
	for (int i = start_y; i < end_y; i++)
	{
		gfx.PutPixel(start_x, i, 255, 0, 0);
		gfx.PutPixel(end_x, i, 255, 0, 0);
	}
}