#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../../../Engine/Engine.h"
#include "../../../Utilities/Utilities.h"

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
	int shaderProgram;

	float vertices[12] = {
	 0.5f,  0.5f, 0.0f,  // top right
	 0.5f, -0.5f, 0.0f,  // bottom right
	-0.5f, -0.5f, 0.0f,  // bottom left
	-0.5f,  0.5f, 0.0f   // top left 
	};
	unsigned int indices[6] = {  // note that we start from 0!
		0, 1, 3,  // first Triangle
		1, 2, 3   // second Triangle
	};
	unsigned int VBO, VAO, EBO;

};