/*************************************************************************************

Program:			CS 4250 Assignment 1: Drone

Author:				Alexander Bagnall
Email:				ab667712@ohio.edu

Description:		Implementation file for the Triangle class.

Date:				September 28, 2015

*************************************************************************************/

#include "Triangle.h"

using namespace glm;

namespace Bagnall
{
	/**********************************************************************
		PUBLIC
	**********************************************************************/

	Triangle::Triangle(vec4 v1, vec4 v2, vec4 v3)
	{
		vertexCount = 3;
		createVertices(v1, v2, v3);
		addVerticesToGlobalVertices();
		computeCenterOfRotation();
	}

	void Triangle::Draw()
	{
		Draw(this->centerOfRotation);
	}
	void Triangle::Draw(vec4 centerOfRotation, mat4 rotation)
	{
		glUniformMatrix4fv(Game::RotationLoc, 1, 0, value_ptr(rotation));
		glUniform4fv(Game::PositionLoc, 1, value_ptr(position));
		glUniform4fv(Game::CenterOfRotationLoc, 1, value_ptr(centerOfRotation));
		glDrawArrays(GL_TRIANGLES, globalVertexOffset, 3);
	}

	/**********************************************************************
		PRIVATE
	**********************************************************************/

	void Triangle::createVertices(vec4 v1, vec4 v2, vec4 v3)
	{
		vertices = new vec4[vertexCount];// { v1, v2, v3 };
		vertices[0] = v1;
		vertices[1] = v2;
		vertices[2] = v3;
	}

	void Triangle::computeCenterOfRotation()
	{
		centerOfRotation = (vertices[0] + vertices[1] + vertices[2]) / 3.0f;
	}
}
