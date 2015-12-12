/*************************************************************************************

Program:			CS 4250 Assignment 1: Drone

Author:				Alexander Bagnall
Email:				ab667712@ohio.edu

Description:		Interface file for the Util class. It is just a container for 
					static utility functions. It currently only contains some matrix
					generator functions that are based on the ones in the Angel code.

Date:				September 28, 2015

*************************************************************************************/

#ifndef UTIL_H
#define UTIL_H

//#include "Angel.h"
#include "Bagnall.h"

namespace Bagnall
{
	class Util
	{
	public:
		/**********************************************************************
		Function:		RotateX
		Purpose:		Create a rotation matrix for rotation about the X axis.
		Parameters:		float theta	-	amount to rotate in radians
		**********************************************************************/
		static glm::mat4 RotateX(float theta);

		/**********************************************************************
		Function:		RotateY
		Purpose:		Create a rotation matrix for rotation about the Y axis.
		Parameters:		float theta	-	amount to rotate in radians
		**********************************************************************/
		static glm::mat4 RotateY(float theta);

		/**********************************************************************
		Function:		RotateZ
		Purpose:		Create a rotation matrix for rotation about the Z axis.
		Parameters:		float theta	-	amount to rotate in radians
		**********************************************************************/
		static glm::mat4 RotateZ(float theta);

		/**********************************************************************
		Function:		identity
		Purpose:		Returns an instance of the 4x4 identity matrix.
		**********************************************************************/
		static glm::mat4 identity();
	};
}

#endif
