/*************************************************************************************

Program:			CS 4250 Assignment 1: Drone

Author:				Alexander Bagnall
Email:				ab667712@ohio.edu

Description:		Interface file for the Triangle class. Triangle inherits from
					Polygon. It is a polygon with three vertices.

Date:				September 28, 2015

*************************************************************************************/

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Polygon.h"
#include "Util.h"

namespace Bagnall
{
	class Triangle : public Polygon
	{
	public:
		/**********************************************************************
		Function:		Triangle  constructor
		Purpose:		Initialize a Triangle object.
		Parameters:		vec4 v1, v2, v3	-	points of the triangle
		**********************************************************************/
		Triangle(glm::vec4 v1, glm::vec4 v2, glm::vec4 v3);

		/**********************************************************************
		Function:		Draw
		Purpose:		Draw the triangle.
		**********************************************************************/
		void Draw();

		/**********************************************************************
		Function:		Draw
		Purpose:		Draw the triangle.
		Parameters:		vec4 centerOfRotation	-	center of rotation
						mat4 rotation			-	rotation matrix
		**********************************************************************/
		void Draw(glm::vec4 centerOfRotation, glm::mat4 rotation = Util::identity());

	protected:
		/**********************************************************************
		Function:		createVertices
		Purpose:		Initialize vertices of the triangle.
		Parameters:		vec4 v1, v2, v3	-	points of the triangle
		**********************************************************************/
		void createVertices(glm::vec4 v1, glm::vec4 v2, glm::vec4 v3);

		/**********************************************************************
		Function:		computeCenterOfRotation
		Purpose:		Compute the center of rotation. For initialization.
		**********************************************************************/
		void computeCenterOfRotation();
	};
}

#endif
