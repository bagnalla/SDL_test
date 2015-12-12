//#include "callbacks.h"
//
//extern "C" void display(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);     // clear the window
//
//	Game::drone->Draw();
//
//	glutSwapBuffers();
//	glFlush();
//}
//
//// Maintains the mapping from screen to world coordinates.
//// TAKEN FROM CODE-EGS CHELBERG CS4250
//extern "C" void myReshape(int w, int h)
//{
//	glViewport(0, 0, w, h);
//	Game::WindowSize = vec2(h, w);
//	glUniform2f(Game::WindowSizeLoc, w, h);       // Pass the window size
//	// size
//	glutPostRedisplay();
//}
//
//void idle(void)
//{
//	int current_time = glutGet(GLUT_ELAPSED_TIME);
//	Game::FrameTimeMs = current_time - last_frame_time;
//	last_frame_time = current_time;
//
//	frame_counter++;
//	frame_time_counter += Game::FrameTimeMs;
//	if (frame_time_counter >= 1000)
//	{
//		fps = frame_counter;
//		frame_counter = frame_time_counter = 0;
//		std::cout << fps << std::endl;
//	}
//
//	Game::drone->Update();
//
//	glutPostRedisplay();
//}
//
//void mouseMotion(int x, int y)
//{
//	float normal_x = (x - (Game::WindowSize.x)) / (float)Game::WindowSize.x;
//	float normal_y = (y - (Game::WindowSize.y)) / (float)Game::WindowSize.y;
//
//	float world_x = (normal_x + 1) * 100;
//	float world_y = 100 - (normal_y + 1) * 100;
//
//	Game::drone->SetPosition(vec4(world_x, world_y, Game::drone->GetPosition().z, 1));
//}
//
//void mouseClick(int button, int state, int x, int y)
//{
//	mouseMotion(x, y);
//}
//
//void keyPress(unsigned char k, int x, int y)
//{
//	switch (k)
//	{
//	case 'q':
//		Game::drone->RotateX(Game::FrameTimeMs * -1);
//		break;
//	case 'w':
//		Game::drone->RotateX(Game::FrameTimeMs * 1);
//		break;
//	case 'a':
//		Game::drone->RotateY(Game::FrameTimeMs * -1);
//		break;
//	case 's':
//		Game::drone->RotateY(Game::FrameTimeMs * 1);
//		break;
//	case 'z':
//		Game::drone->RotateZ(Game::FrameTimeMs * -1);
//		break;
//	case 'x':
//		Game::drone->RotateZ(Game::FrameTimeMs * 1);
//		break;
//	}
//}
