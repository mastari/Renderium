#pragma once

#include "../../Engine/OpenGL/OpenGL.h"
#include "../../Utilities/Utilities.h"
#include <iostream>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class ShaderProgram {
public:
	ShaderProgram();
	ShaderProgram(std::string vs, std::string fs);
	unsigned int getID();
	void use();
	void setBool(const char* name, bool value) const;
	void setInt(const char* name, int value) const;
	void setFloat(const char* name, float value) const;
	void setVec4(const char* name, float v1, float v2, float v3, float v4) const;
	void setMat4(const char* name, glm::mat4 &m);

private:
	unsigned int ID;

	void checkCompileErrors(unsigned int shader, std::string type);
};