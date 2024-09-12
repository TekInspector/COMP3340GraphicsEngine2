#pragma once

#include "IComponent.h"
#include <glm/glm.hpp>

#include <glm/gtc/matrix_transform.hpp>

class Transform : public IComponent {
public:
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;

    glm::mat4 model;

    Transform(Entity* parent) : IComponent(parent), position(0.0f), rotation(0.0f), scale(1.0f) {}

    void updateModelMatrix() {

        // Apply transformations in order: Scale -> Rotate -> Translate
        model = glm::translate(model, position);  // Translate to position
        model = glm::rotate(model, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));  // Rotate around X-axis
        model = glm::rotate(model, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));  // Rotate around Y-axis
        model = glm::rotate(model, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));  // Rotate around Z-axis
        model = glm::scale(model, scale);  // Apply scaling
    }

    glm::mat4 getModel() {
        return model;
    }
};