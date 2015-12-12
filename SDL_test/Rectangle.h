/*************************************************************************************

Program:			CS 4250 Assignment 1: Drone

Author:				Alexander Bagnall
Email:				ab667712@ohio.edu

Description:		Interface file for the Rectangle class. Rectangle inherits from
					Polygon. It is a polygon with four vertices.

Date:				September 28, 2015

*************************************************************************************/

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Polygon.h"
#include "Util.h"

namespace Bagnall
{
	class Rectangle : public Polygon
	{
	public:
		/**********************************************************************
		Function:		Rectangle  constructor
		Purpose:		Initialize a Rectangle object.
		Parameters:		vec4 v1, v2, v3, 4	-	points of the rectangle
		**********************************************************************/
		Rectangle(glm::vec4 v1, glm::vec4 v2, glm::vec4 v3, glm::vec4 v4);

		/**********************************************************************
		Function:		Draw
		Purpose:		Draw the rectangle.
		**********************************************************************/
		void Draw();

		/**********************************************************************
		Function:		Draw
		Purpose:		Draw the rectangle.
		Parameters:		vec4 pos				-	position to draw at 
						vec4 centerOfRotation	-	center of rotation
						mat4 rotation			-	rotation matrix
		**********************************************************************/
		void Draw(glm::vec4 pos, glm::vec4 centerOfRotation, glm::mat4 rotation = Util::identity());

	private:
		/**********************************************************************
		Function:		createVertices
		Purpose:		Initialize vertices of the rectangle.
		Parameters:		vec4 v1, v2, v3, v4	-	points of the rectangle
		**********************************************************************/
		void createVertices(glm::vec4 v1, glm::vec4 v2, glm::vec4 v3, glm::vec4 v4);

		/**********************************************************************
		Function:		computeCenterOfRotation
		Purpose:		Compute the center of rotation. For initialization.
		**********************************************************************/
		void computeCenterOfRotation();
	};
}

#endif
