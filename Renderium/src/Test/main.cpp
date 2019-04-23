#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../RenderiumWindow/RenderiumWindow.h";
#include "../EngineLoop/EngineLoop.h"
#include "States/states.h"

int main() {
	RenderiumWindow rWindow("Sim1.0", 800, 600, true);

	TestState* beginState = new TestState();

	EngineLoop looper((EngineState*)beginState);
	looper.run();
}