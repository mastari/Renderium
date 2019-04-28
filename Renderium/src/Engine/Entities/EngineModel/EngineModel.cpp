#include "EngineModel.h"

EngineModel::EngineModel() {

}

EngineModel::EngineModel(SizableArray vertices, Texture* texture, ShaderProgram* shader) {
	this->texture = texture;
	this->shader = shader;
	unsigned int VBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size, vertices.data, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

}

void EngineModel::bind() {
	glBindVertexArray(VAO);
	texture->bind();
	shader->use();
}

void EngineModel::unbind() {
	glBindVertexArray(0);
	texture->unbind();
	glUseProgram(0);
}

