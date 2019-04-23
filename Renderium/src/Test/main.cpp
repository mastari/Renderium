#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../Engine/EngineWindow/RenderiumWindow.h";
#include "../Engine/EngineLoop/EngineLoop.h"
#include "States/testState/testState.h"

int main() {
	RenderiumWindow rWindow("Particle Playground v0.1.2", 800, 600, true);

	TestState* beginState = new TestState();

	EngineLoop looper((EngineState*)beginState);
	looper.run();
}