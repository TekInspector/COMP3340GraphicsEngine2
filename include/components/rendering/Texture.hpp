#pragma once

#include "components/abstract/IComponent.hpp"

#include <GL/glew.h>
#include <string>

struct Texture : public IComponent {
	GLuint id;
	std::string filePath;

	Texture(GLuint textureId, const std::string& path)
		: id(textureId), filePath(path)
	{}
};