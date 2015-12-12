#ifndef CALLBACKS_H
#define BALLBACKS_H

//#include "Angel.h"
#include "Game.h"

using namespace Bagnall;

extern "C" void display(void);

// Maintains the mapping from screen to world coordinates.
// TAKEN FROM CODE-EGS CHELBERG CS4250
extern "C" void myReshape(int w, int h);

int last_frame_time = 0;
int frame_counter = 0, frame_time_counter = 0, fps = 0;

void idle(void);

void mouseMotion(int x, int y);

void mouseClick(int button, int state, int x, int y);

void keyPress(unsigned char k, int x, int y);

#endif
