#include "EngineEntity.h"


EngineEntity::EngineEntity() {}
EngineEntity::EngineEntity(EngineModel* model) {
	this->model = model;
	position = glm::vec3(0, 0, 0);
	rotationX = 0.f;
	rotationY = 0.f;
	rotationZ = 0.f;
	scale = glm::vec3(1, 1, 1);
}

void EngineEntity::setPosition(glm::vec3 position) {
	this->position = position;
}
void EngineEntity::setRotationX(float rotation) {
	this->rotationX = rotation;
}
void EngineEntity::setRotationY(float rotation) {
	this->rotationY = rotation;
}
void EngineEntity::setRotationZ(float rotation) {
	this->rotationZ = rotation;
}
void EngineEntity::setScale(glm::vec3 scale) {
	this->scale = scale;
}

glm::mat4 EngineEntity::getTransform() {
	transform = glm::mat4(1.0);
	transform = glm::translate(transform, position);
	transform = glm::rotate(transform, glm::radians(rotationX), glm::vec3(1.0f, 0.0f, 0.0f));
	transform = glm::rotate(transform, glm::radians(rotationY), glm::vec3(0.0f, 1.0f, 0.0f));
	transform = glm::rotate(transform, glm::radians(rotationZ), glm::vec3(0.0f, 0.0f, 1.0f));
	transform = glm::scale(transform, scale);
	return transform;
}

EngineModel* EngineEntity::getModel() {
	return model;
}