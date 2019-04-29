#pragma once
#include "../EngineModel/EngineModel.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class EngineEntity {
public:
	EngineEntity();
	EngineEntity(EngineModel* model);
	glm::mat4 getTransform();
	EngineModel* getModel();
	void setPosition(glm::vec3 position);
	void setRotationX(float rotation);
	void setRotationY(float rotation);
	void setRotationZ(float rotation);
	void setScale(glm::vec3 scale);
private:
	EngineModel* model;
	glm::mat4 transform = glm::mat4(1.0);

	glm::vec3 position;
	float rotationX;
	float rotationY;
	float rotationZ;
	glm::vec3 scale;
};