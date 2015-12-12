/*************************************************************************************

Program:			CS 4250 Assignment 1: Drone

Author:				Alexander Bagnall
Email:				ab667712@ohio.edu

Description:		Interface file for the Game class. This is basically just a
					container for global variables of the program.

Date:				September 28, 2015

*************************************************************************************/

#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Bagnall.h"
//#include "Angel.h"

namespace Bagnall
{
	class Game
	{
	public:
		static GLuint WindowSizeLoc; // location of windowSize in vshader
		static GLuint ColorLoc; // location of color in vshader
		static GLuint PositionLoc; // location of shapePosition in vshader
		static GLuint RotationLoc; // location of rotation in vshader
		static GLuint CenterOfRotationLoc; // location of centerOfRotation in vshader
		static GLuint SecondRotationLoc; // location of secondRotation in vshader
		static GLuint SecondCenterOfRotationLoc; // location of secondCenterOfRotation in vshader
		static GLuint TimeLoc; // location of time in vshader

		static std::vector<glm::vec4> Vertices; // global vertices array

		static glm::vec2 WindowSize; // size of window x, y
		static int FrameTimeMs; // elapsed milliseconds since previous frame

		static float RotorRotateRate; // rate at which the drone rotors rotate
	};
}

#endif
