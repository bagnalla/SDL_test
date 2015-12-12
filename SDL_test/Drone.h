#ifndef DRONE_H
#define DRONE_H

#include "Box.h"
#include "Bagnall.h"

namespace Bagnall
{
	class Drone
	{
	public:
		/**********************************************************************
		Function:		Object3D constructor
		Purpose:		Initialize a Object3D object.
		Parameters:		vec4 pos	-	initial position of the drone
		int size	-	size value
		**********************************************************************/
		Drone(glm::vec4 pos, int size);

		/**********************************************************************
		Function:		Object3D destructor
		Purpose:		Cleanup.
		**********************************************************************/
		~Drone();

		/**********************************************************************
		Function:		Update
		Purpose:		Perform any update logic for the drone and it's
		components.
		**********************************************************************/
		void Update();

		/**********************************************************************
		Function:		Draw
		Purpose:		Draw the drone.
		**********************************************************************/
		void Draw();

		/**********************************************************************
		Function:		GetPosition
		Purpose:		Return position
		**********************************************************************/
		glm::vec4 GetPosition();

		/**********************************************************************
		Function:		SetPosition
		Purpose:		Set position value.
		Parameters:		vec4 pos	-	new position value
		**********************************************************************/
		void SetPosition(glm::vec4 pos);

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

	private:
		glm::vec4 position; // position of drone
		int size; // size value
		Box *body; // body Box object
		Box **rotors; // rotor Box objects
		glm::vec4 *rotorOffsets; // position of rotors relative to drone
		float rotX, rotY, rotZ; // rotation values
		glm::vec4 centerOfRotation; // center of rotation for the drone

		/**********************************************************************
		Function:		init
		Purpose:		Called during initialization to create the body and
		rotor objects.
		**********************************************************************/
		void init();

		/**********************************************************************
		Function:		computeRotation
		Purpose:		Return the rotation matrix formed from the three
		rotation values.
		**********************************************************************/
		glm::mat4 computeRotation();

		/**********************************************************************
		Function:		computeCenterOfRotation
		Purpose:		Compute the center of rotation. For initialization.
		**********************************************************************/
		void computeCenterOfRotation();
	};
}

#endif
