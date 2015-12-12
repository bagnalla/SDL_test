/*************************************************************************************

Program:			CS 4250 Assignment 1: Drone

Author:				Alexander Bagnall
Email:				ab667712@ohio.edu

Description:		Implementation file for the Rectangle class.

Date:				September 28, 2015

*************************************************************************************/

#include "Rectangle.h"

using namespace glm;

namespace Bagnall
{
	/**********************************************************************
		PUBLIC
	**********************************************************************/
	
	Rectangle::Rectangle(vec4 v1, vec4 v2, vec4 v3, vec4 v4)
	{
		vertexCount = 4;
		createVertices(v1, v2, v3, v4);
		addVerticesToGlobalVertices();
		computeCenterOfRotation();
	}

	void Rectangle::Draw()
	{
		Draw(position, this->centerOfRotation);
	}
	void Rectangle::Draw(vec4 pos, vec4 centerOfRotation, mat4 rotation)
	{
		glUniformMatrix4fv(Game::RotationLoc, 1, 0, value_ptr(rotation));
		glUniform4fv(Game::PositionLoc, 1, value_ptr(pos));
		glUniform4fv(Game::CenterOfRotationLoc, 1, value_ptr(centerOfRotation));
		glDrawArrays(GL_TRIANGLE_STRIP, globalVertexOffset, 4);
	}

	/**********************************************************************
		PRIVATE
	**********************************************************************/

	void Rectangle::createVertices(vec4 v1, vec4 v2, vec4 v3, vec4 v4)
	{
		vertices = new vec4[vertexCount];
		vertices[0] = v1;
		vertices[1] = v2;
		vertices[2] = v4;
		vertices[3] = v3;
	}

	void Rectangle::computeCenterOfRotation()
	{
		centerOfRotation = (vertices[0] + vertices[1] + vertices[2] + vertices[3]) / 4.0f;
	}
}