/*************************************************************************************

Program:			CS 4250 Assignment 1: Drone

Author:				Alexander Bagnall
Email:				ab667712@ohio.edu

Description:		Implementation file for the Object3D class.

Date:				September 28, 2015

*************************************************************************************/

#include "Object3D.h"
#include "Util.h"

using namespace glm;

namespace Bagnall
{
	/**********************************************************************
		PUBLIC
	**********************************************************************/

	Object3D::Object3D()
	{
		rotX = rotY = rotZ = 0;
	}
	Object3D::~Object3D() { delete[] polygons; }

	void Object3D::RotateX(float x)
	{
		rotX += x;
	}
	void Object3D::RotateY(float y)
	{
		rotY += y;
	}
	void Object3D::RotateZ(float z)
	{
		rotZ += z;
	}

	vec4 Object3D::GetPosition() { return position; }
	void Object3D::SetPosition(vec4 pos)
	{
		position = pos;
		for (int i = 0; i < polygonCount; i++)
		{
			polygons[i]->position = pos;
		}
	}

	void Object3D::Translate(vec4 translation)
	{
		SetPosition(position + translation);
	}

	vec4 Object3D::GetColor() { return color; }
	void Object3D::SetColor(vec4 c) { color = c; }

	vec4 Object3D::GetCenterOfRotation() { return centerOfRotation; }

	/**********************************************************************
		PROTECTED
	**********************************************************************/

	mat4 Object3D::computeRotation()
	{
		return Util::RotateX(rotX) * Util::RotateY(rotY) * Util::RotateZ(rotZ);
	}

	void Object3D::computeCenterOfRotation()
	{
		vec4 sum;
		for (int i = 0; i < polygonCount; i++)
		{
			sum += polygons[i]->GetCenterOfRotation();
		}
		centerOfRotation = sum / (float)polygonCount;
	}
}