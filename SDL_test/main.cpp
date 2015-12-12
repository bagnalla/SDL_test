#define VEC2_SIZE 8
#define vec4_SIZE 12
#define VEC4_SIZE 16
#define _CRT_SECURE_NO_DEPRECATE
#define GLUT_DISABLE_ATEXIT_HACK

#define BUFFER_OFFSET(offset)   ((GLvoid*) (offset))

//#include "Angel.h"
#include "Bagnall.h"
#include "Game.h"
#include "Box.h"
#include "Rectangle.h"
#include "Drone.h"
#include "Util.h"
//#include "GLFunctions.h"
#include "InitShader.h"
#include <SDL/SDL.h>
#include <vector>
#include <iostream>

using namespace Bagnall;
using namespace glm;

GLuint buffer;
GLuint vao;

SDL_Window *window;
SDL_GLContext glcontext;

Drone *drone;

int last_frame_time = 0;
int frame_counter = 0, frame_time_counter = 0, fps = 0;

void init(void)
{
	drone = new Drone(glm::vec4(50, 50, 50, 1), 40);

	// Create a vertex array object
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec4)*Game::Vertices.size(), &Game::Vertices[0], GL_STATIC_DRAW);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);

	// Load shaders and use the resulting shader program
	GLuint program = InitShader("vshader.glsl", "fshader.glsl");
	glUseProgram(program);

	// Initialize attributes from the vertex shader
	Game::WindowSizeLoc = glGetUniformLocation(program, "windowSize");
	if (Game::WindowSizeLoc == -1) {
		std::cerr << "Unable to find windowSize parameter" << std::endl;
	}
	Game::ColorLoc = glGetUniformLocation(program, "vcolor");
	if (Game::ColorLoc == -1) {
		std::cerr << "Unable to find colorLoc parameter" << std::endl;
	}
	Game::PositionLoc = glGetUniformLocation(program, "shapePosition");
	if (Game::PositionLoc == -1) {
		std::cerr << "Unable to find positionLoc parameter" << std::endl;
	}
	Game::RotationLoc = glGetUniformLocation(program, "rotation");
	if (Game::RotationLoc == -1) {
		std::cerr << "Unable to find rotationLoc parameter" << std::endl;
	}
	Game::CenterOfRotationLoc = glGetUniformLocation(program, "centerOfRotation");
	if (Game::CenterOfRotationLoc == -1) {
		std::cerr << "Unable to find centerOfRotationLoc parameter" << std::endl;
	}
	Game::SecondRotationLoc = glGetUniformLocation(program, "secondRotation");
	if (Game::RotationLoc == -1) {
		std::cerr << "Unable to find secondRotationLoc parameter" << std::endl;
	}
	Game::SecondCenterOfRotationLoc = glGetUniformLocation(program, "secondCenterOfRotation");
	if (Game::CenterOfRotationLoc == -1) {
		std::cerr << "Unable to find secondCenterOfRotationLoc parameter" << std::endl;
	}
	Game::TimeLoc = glGetUniformLocation(program, "time");
	if (Game::TimeLoc == -1) {
		std::cerr << "Unable to find timeLoc parameter" << std::endl;
	}
	GLuint vPositionLoc = glGetAttribLocation(program, "vPosition");
	glEnableVertexAttribArray(vPositionLoc);
	glVertexAttribPointer(vPositionLoc, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	glEnable(GL_DEPTH_TEST);

	//glClearColor(1.0, 1.0, 1.0, 1.0); // white background
	glClearColor(0.5, 0.5, 0.5, 1.0);

	// initialize second rotation to identity
	glUniformMatrix4fv(Game::SecondRotationLoc, 1, 0, value_ptr(Util::identity()));
}

//----------------------------------------------------------------------------

extern "C" void display(void)
{
	//glClearColor(static_cast<float>(rand()) / RAND_MAX, static_cast<float>(rand()) / RAND_MAX, static_cast<float>(rand()) / RAND_MAX, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);     // clear the window
	//glClear(GL_COLOR_BUFFER_BIT);

	// draw drone
	drone->Draw();

	//SDL_UpdateWindowSurface(window);
	SDL_GL_SwapWindow(window);
	glFlush();
	//SDL_GL_SwapWindow(window);
}

//// Maintains the mapping from screen to world coordinates.
//// TAKEN FROM CODE-EGS CHELBERG CS4250 OHIO UNIVERSITY
//// glutReshapeFunc
//extern "C" void myReshape(int w, int h)
//{
//	glViewport(0, 0, w, h);
//	Game::WindowSize = vec2(w, h);
//	glUniform2f(Game::WindowSizeLoc, w, h);       // Pass the window size
//	// size
//	glutPostRedisplay();
//}
//
//// glutIdleFunc
bool holdingMouseClick = false;
int idle()
{
	// calculate milliseconds elapsed since last call
	int current_time = SDL_GetTicks();
	Game::FrameTimeMs = current_time - last_frame_time;
	last_frame_time = current_time;

	SDL_Event ev;
	while (SDL_PollEvent(&ev))
	{
		if (ev.type == SDL_QUIT)
		{
			return 1;
		}
		else if (ev.type == SDL_KEYDOWN)
		{
			switch (ev.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				return 1;
				break;
			case SDLK_q:
				drone->RotateX(Game::FrameTimeMs * -.01);
				break;
			case SDLK_w:
				drone->RotateX(Game::FrameTimeMs * .01);
				break;
			case SDLK_a:
				drone->RotateY(Game::FrameTimeMs * -.01);
				break;
			case SDLK_s:
				drone->RotateY(Game::FrameTimeMs * .01);
				break;
			case SDLK_z:
				drone->RotateZ(Game::FrameTimeMs * -.01);
				break;
			case SDLK_x:
				drone->RotateZ(Game::FrameTimeMs * .01);
				break;
			case SDLK_MINUS:
			case SDLK_UNDERSCORE:
				Game::RotorRotateRate -= .001;
				break;
			case SDLK_EQUALS:
			case SDLK_PLUS:
				Game::RotorRotateRate += .001;
				break;
			}
		}
		else if (ev.type == SDL_MOUSEBUTTONDOWN)
		{
			holdingMouseClick = true;
		}
		else if (ev.type == SDL_MOUSEBUTTONUP)
		{
			holdingMouseClick = false;
		}
		else if (ev.type == SDL_MOUSEMOTION)
		{/*
			if (holdingMouseClick)
			{
				float normal_x = 1 + (ev.motion.x - (Game::WindowSize.x)) / (float)Game::WindowSize.x;
				float normal_y = 1 + (y - (Game::WindowSize.y)) / (float)Game::WindowSize.y;
			}*/
			//ev.motion.x
		}
	}

	if (holdingMouseClick)
	{
		int w, h;
		SDL_GetWindowSize(window, &w, &h);

		int x, y;
		SDL_GetMouseState(&x, &y);
		float normal_x = 1 + (x - w) / (float)w;
		float normal_y = 1 + (y - h) / (float)h;

		//vec2 windowScale = vec2(512.0 / w, 512.0 / h);

		float world_x = normal_x * 100;// / windowScale.x;
		float world_y = 100 - normal_y * 100;// / windowScale.y;

		drone->SetPosition(glm::vec4(world_x, world_y, drone->GetPosition().z, 1));
	}

	// increment frame counter, update fps once per second
	frame_counter++;
	frame_time_counter += Game::FrameTimeMs;
	if (frame_time_counter >= 1000)
	{
		fps = frame_counter;
		frame_counter = frame_time_counter = 0;
		std::cout << fps << std::endl;
		//std::cout << Game::WindowSize.x << " " << Game::WindowSize.y << std::endl;
	}

	// update drone
	drone->Update();

	return 0;
}

// glutMotionFunc
extern "C" void mouseMotion(int x, int y)
{
	// convert to between -1 to 1
	float normal_x = 1 + (x - (Game::WindowSize.x)) / (float)Game::WindowSize.x;
	float normal_y = 1 + (y - (Game::WindowSize.y)) / (float)Game::WindowSize.y;

	// this window scale stuff doesn't work right
	vec2 windowScale = vec2(512.0 / Game::WindowSize.x, 512.0 / Game::WindowSize.y);

	// convert to world coordinates
	float world_x = normal_x * 100 / windowScale.x;// *(Game::WindowSize.x / 100) + Game::WindowSize.x;
	float world_y = 100 - normal_y * 100 / windowScale.y;// *(Game::WindowSize.y / 100) + Game::WindowSize.y;

	// set position of drone
	drone->SetPosition(glm::vec4(world_x, world_y, drone->GetPosition().z, 1));
}

// glutMouseFunc
extern "C" void mouseClick(int button, int state, int x, int y)
{
	mouseMotion(x, y);
}

// glutKeyboardFunc
extern "C" void keyPress(unsigned char k, int x, int y)
{
	switch (k)
	{
		// change rotation rate of rotors
	case '-':
	case '_':
		Game::RotorRotateRate -= .001;
		break;
	case '=':
	case '+':
		Game::RotorRotateRate += .001;
		break;
		// ROTATE DRONE
	case 'q':
	case 'Q':
		drone->RotateX(Game::FrameTimeMs * -.01);
		break;
	case 'w':
	case 'W':
		drone->RotateX(Game::FrameTimeMs * .01);
		break;
	case 'a':
	case 'A':
		drone->RotateY(Game::FrameTimeMs * -.01);
		break;
	case 's':
	case 'S':
		drone->RotateY(Game::FrameTimeMs * .01);
		break;
	case 'z':
	case 'Z':
		drone->RotateZ(Game::FrameTimeMs * -.01);
		break;
	case 'x':
	case 'X':
		drone->RotateZ(Game::FrameTimeMs * .01);
		break;
		// EXIT
	case 033:
		exit(EXIT_SUCCESS);
		break;
	}
}

//int main(int argc, char **argv)
//{
//	glutInit(&argc, argv);
//	//glutInitDisplayMode(GLUT_RGBA);
//	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
//	glutInitWindowSize(512, 512);
//
//	glutCreateWindow("Drone");
//	glewInit();
//
//	init();
//
//	glutDisplayFunc(display);
//	glutMouseFunc(mouseClick);
//	glutIdleFunc(idle);
//	glutReshapeFunc(myReshape);
//	glutKeyboardFunc(keyPress);
//	glutMotionFunc(mouseMotion);
//
//	glutMainLoop();
//	system("pause");
//	return 0;
//}

#include "SDL/SDL.h"
#include <string>
#include <exception>

class InitError : public std::exception {
public:
	InitError();
	InitError(const std::string&);
	virtual ~InitError() throw();
	virtual const char* what() const throw();
private:
	std::string msg;
};

InitError::InitError() :
	exception(), msg(SDL_GetError()) {}
InitError::InitError(const std::string& m) :
	exception(), msg(m) {}
InitError::~InitError() throw() {}
const char* InitError::what() const throw() {
	return msg.c_str();
}

class SDL {
public:
	SDL(Uint32 flags = 0) throw(InitError);
	virtual ~SDL();
};

SDL::SDL(Uint32 flags) throw(InitError) {
	if (SDL_Init(flags) != 0)
		throw InitError();
}

SDL::~SDL() {
	SDL_Quit();
}

/* ... */

#include <iostream>

int main(int argc, char **argv) {
	try {
		SDL sdl(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO);

		window = SDL_CreateWindow(
			"SDL2/OpenGL Demo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480,
			SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

		// Create an OpenGL context associated with the window.
		glcontext = SDL_GL_CreateContext(window);

		SDL_GL_MakeCurrent(window, glcontext);

		//SDL_GL_SetSwapInterval(0);

		//glewExperimental = GL_TRUE;
		glewInit();

		//SDL_GL_LoadLibrary((glFunc)procAddress);

		init();

		/*glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		SDL_GL_SwapWindow(window);*/

		std::cout << "all systems are go bro\n";

		while (1)
		{
			if (idle())
				break;
			display();
		}

		SDL_GL_DeleteContext(glcontext);
		return 0;
	}

	catch (const InitError& err) {
		std::cerr
			<< "Error while initializing SDL:  "
			<< err.what() << std::endl;
	}

	system("pause");
	return 1;
}
