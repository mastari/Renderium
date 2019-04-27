#include "Texture.h"

Texture::Texture() {

}

Texture::Texture(const char* path, int wrapmethod, int filtermethod) {
	glGenTextures(1, &ID);
	bind();

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapmethod);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapmethod);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filtermethod);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filtermethod);

	unsigned char* data = stbi_load(path, &width, &height, &nrChannels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);
	unbind();
}  

void Texture::bind() {
	glBindTexture(GL_TEXTURE_2D, ID);
}
void Texture::unbind() {
	glBindTexture(GL_TEXTURE_2D, 0);
}
unsigned int Texture::getID() {
	return ID;
}

