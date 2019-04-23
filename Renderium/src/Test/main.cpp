#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../RenderiumWindow/RenderiumWindow.h";
#include "../EngineLoop/EngineLoop.h"
#include "States/states.h"

int main() {

	RenderiumWindow rWindow("Sim1.0", 800, 600, false);

	SecondState* state = new SecondState();

	EngineLoop looper((EngineState*)state);
	looper.run();

}