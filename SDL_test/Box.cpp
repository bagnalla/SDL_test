/*************************************************************************************

Program:			CS 4250 Assignment 1: Drone

Author:				Alexander Bagnall
Email:				ab667712@ohio.edu

Description:		Implementation file for the Box class.

Date:				September 28, 2015

*************************************************************************************/

#include "Box.h"
#include "Bagnall.h"

using namespace glm;

namespace Bagnall
{
	/**********************************************************************
		PUBLIC
	**********************************************************************/

	Box::Box(vec4 pos, float w, float h, float d) : width(w), height(h), depth(d)
	{
		trippy = false;
		timeOffset = 0;
		createPolygons();
		computeCenterOfRotation();

		SetPosition(pos);
	}

	void Box::Draw()
	{
		Draw(position);
	}

	void Box::Draw(vec4 pos)
	{
		glUniform4fv(Game::ColorLoc, 1, glm::value_ptr(color));

		for (int i = 0; i < polygonCount; i++)
		{
			//glUniform4fv(Game::ColorLoc, 1, colors[i]);
			glUniform1f(Game::TimeLoc, trippy ? SDL_GetTicks() + i * 200 + timeOffset : 0);
			polygons[i]->Draw(pos, centerOfRotation, computeRotation());
		}
	}

	/**********************************************************************
		PRIVATE
	**********************************************************************/

	void Box::createPolygons()
	{
		polygonCount = 6;
		polygons = new Polygon*[polygonCount];

		polygons[0] = new Bagnall::Rectangle(vec4(), vec4(0, height, 0, 1), vec4(width, height, 0, 1), vec4(width, 0, 0, 1));
		polygons[1] = new Bagnall::Rectangle(vec4(), vec4(0, 0, depth, 1), vec4(0, height, depth, 1), vec4(0, height, 0, 1));
		polygons[2] = new Bagnall::Rectangle(vec4(), vec4(width, 0, 0, 1), vec4(width, 0, depth, 1), vec4(0, 0, depth, 1));
		polygons[3] = new Bagnall::Rectangle(vec4(0, height, 0, 1), vec4(0, height, depth, 1), vec4(width, height, depth, 1), vec4(width, height, 0, 1));
		polygons[4] = new Bagnall::Rectangle(vec4(width, 0, 0, 1), vec4(width, height, 0, 1), vec4(width, height, depth, 1), vec4(width, 0, depth, 1));
		polygons[5] = new Bagnall::Rectangle(vec4(0, 0, depth, 1), vec4(width, 0, depth, 1), vec4(width, height, depth, 1), vec4(0, height, depth, 1));
	}
}