/*************************************************************************************

Program:			CS 4250 Assignment 1: Drone

Author:				Alexander Bagnall
Email:				ab667712@ohio.edu

Description:		Implementation file for the Polygon class.

Date:				September 28, 2015

*************************************************************************************/

#include "Polygon.h"

namespace Bagnall
{
	/**********************************************************************
		PRIVATE
	**********************************************************************/

	void Polygon::addVerticesToGlobalVertices()
	{
		globalVertexOffset = Game::Vertices.size();

		for (int i = 0; i < vertexCount; i++)
			Game::Vertices.push_back(vertices[i]);
	}
}
