/*************************************************************************************

Program:			CS 4250 Assignment 1: Drone

Author:				Alexander Bagnall
Email:				ab667712@ohio.edu

Description:		Implementation file for the Util class.

Date:				September 28, 2015

*************************************************************************************/

#include "Util.h"

using namespace glm;

namespace Bagnall
{
	mat4 Util::RotateX(float theta)
	{
		mat4 m;
		m[2][2] = m[1][1] = cos(theta);
		m[2][1] = sin(theta);
		m[1][2] = -m[2][1];
		return m;
	}

	mat4 Util::RotateY(float theta)
	{
		mat4 m;
		m[2][2] = m[0][0] = cos(theta);
		m[0][2] = sin(theta);
		m[2][0] = -m[0][2];
		return m;
	}

	mat4 Util::RotateZ(float theta)
	{
		mat4 m;
		m[0][0] = m[1][1] = cos(theta);
		m[1][0] = sin(theta);
		m[0][1] = -m[1][0];
		return m;
	}

	mat4 Util::identity()
	{
		mat4 m;
		// fill with zeroes
		for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			m[i][j] = 0.0;
		// diagonal = 1
		for (int i = 0; i < 4; i++)
			m[i][i] = 1.0;
		return m;
	}
}