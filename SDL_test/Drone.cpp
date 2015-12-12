/*************************************************************************************

Program:			CS 4250 Assignment 1: Drone

Author:				Alexander Bagnall
Email:				ab667712@ohio.edu

Description:		Implementation file for the Drone class.

Date:				September 28, 2015

*************************************************************************************/

#include "Drone.h"
#include "Util.h"

using namespace glm;

namespace Bagnall
{
	/**********************************************************************
	PUBLIC
	**********************************************************************/

	Drone::Drone(glm::vec4 pos, int sz)
	{
		size = sz;
		init();
		computeCenterOfRotation();
		SetPosition(pos);
	}
	Drone::~Drone() { delete body; delete[] rotors; }

	void Drone::Update()
	{
		for (int i = 0; i < 4; i++)
		{
			rotors[i]->RotateZ(Game::FrameTimeMs * Game::RotorRotateRate);
		}
	}

	void Drone::Draw()
	{
		glUniformMatrix4fv(Game::SecondRotationLoc, 1, 0, value_ptr(computeRotation()));
		glUniform4fv(Game::SecondCenterOfRotationLoc, 1, value_ptr(vec4()));
		body->Draw(position);
		for (int i = 0; i < 4; i++)
		{
			glUniform4fv(Game::SecondCenterOfRotationLoc, 1, value_ptr(-rotorOffsets[i]));
			rotors[i]->Draw(position + rotorOffsets[i]);
		}
	}

	vec4 Drone::GetPosition() { return position; }
	void Drone::SetPosition(vec4 pos)
	{
		position = pos;
	}

	void Drone::RotateX(float x) { rotX += x; }
	void Drone::RotateY(float y) { rotY += y; }
	void Drone::RotateZ(float z) { rotZ += z; }

	/**********************************************************************
	PRIVATE
	**********************************************************************/

	void Drone::init()
	{
		body = new Box(vec4(), size, size, size / 4);
		body->SetColor(vec4(0.0, 0.0, 0.0, 1.0));
		body->trippy = true;
		rotors = new Box*[4];
		rotorOffsets = new vec4[4];

		float rotorWidth = size / 2.0;
		float rotorHeight = size / 20.0;
		float rotorDepth = size / 15.0;
		for (int i = 0; i < 4; i++)
		{
			rotors[i] = new Box(vec4(), rotorWidth, rotorHeight, rotorDepth);
			rotors[i]->SetColor(vec4(1, 1, 1, 1));
			rotors[i]->trippy = true;
			rotors[i]->timeOffset = (i + 1) * 500;
		}
		rotorOffsets[0] = vec4(-size / 2, -size / 2, -size / 6, 1);
		rotorOffsets[1] = vec4(-size / 2, size / 2, -size / 6, 1);
		rotorOffsets[2] = vec4(size / 2, size / 2, -size / 6, 1);
		rotorOffsets[3] = vec4(size / 2, -size / 2, -size / 6, 1);
	}

	mat4 Drone::computeRotation()
	{
		return Util::RotateX(rotX) * Util::RotateY(rotY) * Util::RotateZ(rotZ);
	}

	void Drone::computeCenterOfRotation()
	{
		centerOfRotation = body->GetCenterOfRotation();
	}
}
