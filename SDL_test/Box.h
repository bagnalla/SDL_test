/*************************************************************************************

Program:			CS 4250 Assignment 1: Drone

Author:				Alexander Bagnall
Email:				ab667712@ohio.edu

Description:		Interface file for the Box class. Box inherits from Object3D
					and is comprised of six Rectangle objects. When the trippy flag
					is set, the color of the box changes over time.

Date:				September 28, 2015

*************************************************************************************/

#ifndef BOX_H
#define BOX_H

#include "Object3D.h"
#include "Game.h"
#include "Rectangle.h"

namespace Bagnall
{
	class Box : public Object3D
	{
	public:
		bool trippy; // trippy flag
		int timeOffset; // time offset

		/**********************************************************************
		Function:		Rectangle  constructor
		Purpose:		Initialize a Rectangle object.
		Parameters:		vec4 v1, v2, v3, 4	-	points of the rectangle
		**********************************************************************/
		Box(glm::vec4 pos, float w, float h, float d);

		/**********************************************************************
		Function:		GetWidth
		Purpose:		Return width of the box.
		**********************************************************************/
		float GetWidth() { return width; }

		/**********************************************************************
		Function:		GetHeight
		Purpose:		Return height of the box.
		**********************************************************************/
		float GetHeight() { return height; }

		/**********************************************************************
		Function:		GetDepth
		Purpose:		Return depth of the box.
		**********************************************************************/
		float GetDepth() { return depth; }

		/**********************************************************************
		Function:		Draw
		Purpose:		Draw the box.
		**********************************************************************/
		void Draw();

		/**********************************************************************
		Function:		Draw
		Purpose:		Draw the box.
		Parameters:		vec4 pos	-	position offset
		**********************************************************************/
		void Draw(glm::vec4 pos);
	private:
		float width; // width of the box
		float height; // height of the box
		float depth; // depth of the box

		/**********************************************************************
		Function:		createPolygons
		Purpose:		Called during initialization to create the polygon
						objects which comprise the box.
		**********************************************************************/
		void createPolygons();
	};
}

#endif
