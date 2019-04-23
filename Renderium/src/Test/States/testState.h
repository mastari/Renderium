#pragma once
#include "../../EngineState/EngineState.h"

class TestState : virtual EngineState {
private:
	//All states require override:
	void init();
	void input();
	void update();
	void render(GLFWwindow* window);
	//State specific necessities go here:
	//ChemicalEntities array[] = ChemicalUtils::RandomHydrogenIsotopes();
	//You get the idea



};