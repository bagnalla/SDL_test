/*************************************************************************************

Program:			CS 4250 Assignment 1: Drone

Author:				Alexander Bagnall
Email:				ab667712@ohio.edu

Description:		Interface file for the Object3D class. Object3D is an abstract
					class which represents an object comprised of polygons.

Date:				September 28, 2015

*************************************************************************************/

#ifndef OBJECT3D_H
#define OBJECT3D_H

//#include "Angel.h"
#include <vector>
#include "Polygon.h"

namespace Bagnall
{
	class Object3D
	{
	public:
		/**********************************************************************
		Function:		Object3D default constructor
		Purpose:		Initialize a Object3D object.
		**********************************************************************/
		Object3D();

		/**********************************************************************
		Function:		Object3D  destructor
		Purpose:		Handle cleanup.
		**********************************************************************/
		~Object3D();

		/**********************************************************************
		Function:		RotateX
		Purpose:		Apply rotation about the x axis.
		Parameters:		float x	-	amount to rotate by in degrees
		**********************************************************************/
		void RotateX(float x);

		/**********************************************************************
		Function:		RotateY
		Purpose:		Apply rotation about the y axis.
		Parameters:		float y	-	amount to rotate by in degrees
		**********************************************************************/
		void RotateY(float y);

		/**********************************************************************
		Function:		RotateZ
		Purpose:		Apply rotation about the z axis.
		Parameters:		float z	-	amount to rotate by in degrees
		**********************************************************************/
		void RotateZ(float z);

		/**********************************************************************
		Function:		GetPosition
		Purpose:		Return position.
		**********************************************************************/
		glm::vec4 GetPosition();

		/**********************************************************************
		Function:		SetPosition
		Purpose:		Set position value.
		Parameters:		vec4 pos	-	new position
		**********************************************************************/
		void SetPosition(glm::vec4 pos);

		/**********************************************************************
		Function:		Translate
		Purpose:		Apply a translation to the object.
		Parameters:		vec4 translation	-	vector to translate by
		**********************************************************************/
		void Translate(glm::vec4 translation);

		/**********************************************************************
		Function:		GetColor
		Purpose:		Return color.
		**********************************************************************/
		glm::vec4 GetColor();

		/**********************************************************************
		Function:		SetColor
		Purpose:		Set color value.
		Parameters:		vec4 c	-	new color
		**********************************************************************/
		void SetColor(glm::vec4 c);

		/**********************************************************************
		Function:		GetCenterOfRotation
		Purpose:		Return centerOfRotation.
		**********************************************************************/
		glm::vec4 GetCenterOfRotation();

	protected:
		glm::vec4 position; // position of object
		float rotX, rotY, rotZ; // rotation values for each axis
		glm::vec4 centerOfRotation; // center of rotation
		glm::vec4 color; // color of object
		Polygon **polygons; // array of polygons
		int polygonCount; // number of polygons

		/**********************************************************************
		Function:		computeRotation
		Purpose:		Return the rotation matrix formed from the three
						rotation values.
		**********************************************************************/
		glm::mat4 computeRotation();

		/**********************************************************************
		Function:		createPolygons (virtual)
		Purpose:		Create array of polygons which comprise the object.
		**********************************************************************/
		virtual void createPolygons() = 0;

		/**********************************************************************
		Function:		computeCenterOfRotation
		Purpose:		Compute the center of rotation. For initialization.
		**********************************************************************/
		void computeCenterOfRotation();
	};
}

#endif
