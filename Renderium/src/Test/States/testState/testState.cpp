#include "testState.h"

void TestState::init() {
	ourShader = new ShaderProgram("src/Test/States/testState/vertex.glsl", "src/Test/States/testState/fragment.glsl");
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	
	glBindVertexArray(VAO);
}

void TestState::input() {
	if (glfwGetKey(ContextDevice::getContext(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(ContextDevice::getContext(), true);
}

void TestState::update() {

}

void TestState::render(GLFWwindow* context) {
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	// be sure to activate the shader before any calls to glUniform
	ourShader->use();

	// update shader uniform
	float timeValue = glfwGetTime();
	float greenValue = sin(timeValue) / 2.0f + 0.5f;
	ourShader->setFloat("ourColor", greenValue);

	// render the triangle
	glDrawArrays(GL_TRIANGLES, 0, 3);
}