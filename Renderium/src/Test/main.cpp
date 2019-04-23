#include <iostream>

#include "../Engine/Engine.h"
#include "States/testState/testState.h"

int main() {
	RenderiumWindow rWindow("Particle Playground v0.0.1-Alpha", 800, 600, true);

	TestState* beginState = new TestState();

	EngineLoop looper((EngineState*)beginState);
	looper.run();
}