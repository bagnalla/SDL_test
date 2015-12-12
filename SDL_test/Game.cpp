/*************************************************************************************

Program:			CS 4250 Assignment 1: Drone

Author:				Alexander Bagnall
Email:				ab667712@ohio.edu

Description:		Implementation file for the Game class.

Date:				September 28, 2015

*************************************************************************************/

#include "Game.h"
//#include "Angel.h"
#include "Drone.h"
#include "Bagnall.h"

using namespace glm;

namespace Bagnall
{
	GLuint Game::WindowSizeLoc;
	GLuint Game::ColorLoc;
	GLuint Game::PositionLoc;
	GLuint Game::RotationLoc;
	GLuint Game::CenterOfRotationLoc;
	GLuint Game::SecondRotationLoc;
	GLuint Game::SecondCenterOfRotationLoc;
	GLuint Game::TimeLoc;

	std::vector<vec4> Game::Vertices;

	vec2 Game::WindowSize;
	int Game::FrameTimeMs;

	float Game::RotorRotateRate = .025;
}
