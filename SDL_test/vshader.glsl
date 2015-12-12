#version 150
#define M_PI 3.1415926535897932384626433832795

attribute vec4 vPosition;
varying vec4 fcolor;

uniform vec4 shapePosition;
uniform vec2 windowSize;
uniform vec4 vcolor;
uniform mat4 rotation;
uniform vec4 centerOfRotation;
uniform mat4 secondRotation;
uniform vec4 secondCenterOfRotation;
uniform float time;

const float scale = 100.0;

void main()
{
	vec4 temp_pos = rotation * (vPosition - centerOfRotation);
	
	if (secondRotation != mat4(1.0)) {
		
		temp_pos = secondRotation * (temp_pos - secondCenterOfRotation) + secondCenterOfRotation;
	}
	
	//vec2 windowScale = vec2(512.0 / windowSize.x, 512.0 / windowSize.y);
	
	//temp_pos.x = (temp_pos.x - scale/2) / (scale/2) * windowScale.x;
	//temp_pos.y = (temp_pos.y - scale/2) / (scale/2) * windowScale.y;
	//temp_pos.z = (temp_pos.z - scale/2) / (scale/2);
	//temp_pos.w = 1;
	//temp_pos += vec4(shapePosition.x * windowScale.x, shapePosition.y * windowScale.y, shapePosition.z, shapePosition.w) / (scale/2);
	
	
	temp_pos = shapePosition / (scale/2) + vec4((temp_pos.x - scale/2) / (scale/2), (temp_pos.y - scale/2) / (scale/2), (temp_pos.z - scale/2) / (scale/2), 1);
	//temp_pos = vec4(shapePosition.x / scaledWindowSize.x, shapePosition.y / scaledWindowSize.y, shapePosition.z, shapePosition.w) + vec4((temp_pos.x - scaledWindowSize.x/2) / (scaledWindowSize.x/2) / scaledWindowSize.x, (temp_pos.y - scaledWindowSize.y/2) / (scaledWindowSize.y/2) / scaledWindowSize.y, (temp_pos.z), 1);
	
	gl_Position = temp_pos;
	
	if (time != 0) {
		float scaled_time = time / 1000.0;
		fcolor = vec4((cos(scaled_time) + 1) / 2, (cos(scaled_time+1) + 1) / 2, (cos(scaled_time+2) + 1) / 2, 1);
	}
	else {
		fcolor = vcolor;
	}
}
