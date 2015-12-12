/*************************************************************************************

Program:			CS 4250 Assignment 1: Drone

Author:				Alexander Bagnall
Email:				ab667712@ohio.edu

Description:		Interface file for the Polygon class. Polygon is an abstract
					class which represents a polygon comprised of vertices.

Date:				September 28, 2015

*************************************************************************************/

#ifndef POLYGON_H
#define POLYGON_H

//#include "Angel.h"
#include "Game.h"
#include "Bagnall.h"

namespace Bagnall
{
	class Polygon
	{
	public:
		/**********************************************************************
		Function:		Polygon default constructor
		Purpose:		Initialize a Polygon object.
		**********************************************************************/
		Polygon() { }

		/**********************************************************************
		Function:		Polygon  destructor
		Purpose:		Handle cleanup.
		**********************************************************************/
		~Polygon() { delete[] vertices; }

		/**********************************************************************
		Function:		Draw (virtual)
		Purpose:		Draw the polygon.
		**********************************************************************/
		virtual void Draw() = 0;

		/**********************************************************************
		Function:		Draw (virtual)
		Purpose:		Draw the polygon.
		Parameters:		vec4 pos				-	position to draw at
						vec4 centerOfRotation	-	center of rotation
						mat4 rotation			-	rotation matrix
		**********************************************************************/
		virtual void Draw(glm::vec4 position, glm::vec4 centerOfRotation, glm::mat4 rotation) = 0;

		/**********************************************************************
		Function:		GetCenterOfRotation
		Purpose:		return a copy of centerOfRotation
		**********************************************************************/
		glm::vec4 GetCenterOfRotation() { return centerOfRotation; }

		glm::vec4 position; // position of polygon

	protected:
		glm::vec4 *vertices; // vertices (object space)
		int vertexCount; // number of vertices
		int globalVertexOffset; // starting index in the global vertices array

		glm::vec4 centerOfRotation; // center of rotation

		/**********************************************************************
		Function:		addVerticesToGlobalVertices
		Purpose:		Add vertices to global vertices array. Called during
						initialization after computing the vertices.
		**********************************************************************/
		void addVerticesToGlobalVertices();
	};
}

#endif
