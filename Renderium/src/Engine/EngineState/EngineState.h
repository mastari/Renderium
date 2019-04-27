#pragma once
#include "../../ContextDevice/ContextDevice.h"
#include "../../Renderium/ShaderProgram/ShaderProgram.h"
#include "../../Engine/Entities/Entities.h"

class EngineState {
public:
	virtual void init() = 0;
	virtual void input() = 0;
	virtual void update(double deltaTime) = 0;
	virtual void render(GLFWwindow* window) = 0;
};