#pragma once
#include "../Texture/Texture.h"
#include "../../../Renderium/ShaderProgram/ShaderProgram.h"
#include "../../../Utilities/Utilities.h"

class EngineModel {
public:
	EngineModel();
	EngineModel(SizableArray arr, Texture* texture, ShaderProgram* shader);
	void bind();
	void unbind();

private:
	Texture* texture;
	ShaderProgram* shader;
	unsigned int VAO;

};