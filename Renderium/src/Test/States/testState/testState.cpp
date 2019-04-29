#include "testState.h"

void TestState::init() {
	float vertices[] = {
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
	};
	ourShader = ShaderProgram("src/Test/States/testState/vertex.glsl", "src/Test/States/testState/fragment.glsl");
	SizableArray arr = SizableArray(vertices, sizeof(vertices));
	myModel = EngineModel(arr, new Texture("src/Test/States/testState/wall.jpg", GL_REPEAT, GL_LINEAR), &ourShader);

	myEntity = EngineEntity(&myModel);

	myEntity.setScale(glm::vec3(1, 1, sca));

	glEnable(GL_DEPTH_TEST);
}
void TestState::input() { // Time of last frame

}

void TestState::update(double deltaTime) {
	float cameraSpeed = 5.f * deltaTime; // adjust accordingly
	GLFWwindow* window = ContextDevice::getContext();
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(ContextDevice::getContext(), true);
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		cameraPos += cameraSpeed * cameraFront;
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		cameraPos -= cameraSpeed * cameraFront;
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
	rot += deltaTime*2;
	sca -= deltaTime * 7;
}

void TestState::render(GLFWwindow* context) {
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// bind Texture

	view = glm::mat4(1);
	projection = glm::mat4(1);
	projection = glm::perspective(glm::radians(45.0f), (float)ContextDevice::getScreenWidth() / ContextDevice::getScreenHeight(), 0.1f, 100.0f);

	glm::mat4 view = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
	float radius = 10.0f;
	float camX = sin(glfwGetTime()) * radius;
	float camZ = cos(glfwGetTime()) * radius;

	myEntity.getModel()->bind();

	myEntity.setRotationZ(rot);
	myEntity.setScale(glm::vec3(sqrt(abs(sca)), sqrt(abs(sca)), sqrt(abs(sca/2))));

	glm::mat4 model = myEntity.getTransform();
	view = glm::lookAt(cameraPos, glm::vec3(0.0f, 0.0f, 0.0f) + cameraFront, cameraUp);
	ourShader.setMat4("model", model);
	ourShader.setMat4("view", view);
	ourShader.setMat4("projection", projection);

	glDrawArrays(GL_TRIANGLES, 0, 36);
}