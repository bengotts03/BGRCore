#include <glad/glad.h>
#include "Camera.h"
#include "Input.h"
#include "AppTime.h"
#include <GLFW/glfw3.h>
#include <glm/gtx/rotate_vector.hpp>

namespace BGRCore {
    Camera::Camera(BGAppCore::Window* window, int width, int height, glm::vec3 pos) : _window(window),
        _viewWidth(width), _viewHeight(height), Position(pos) {
    }

    void Camera::SendMatrixData(Shader& shader, const char* uniform) {
        shader.SetMat4(uniform, CameraMatrix);
    }

    void Camera::UpdateMatrix(float FOV, float nearPane, float farPane) {
        glm::mat4 view = glm::mat4(1.0f);
        glm::mat4 projection = glm::mat4(1.0f);

        view = GetView();
        projection = GetProjection();

        CameraMatrix = projection * view;
    }

    void Camera::RefreshViewport(int width, int height) {
        _viewWidth = static_cast<float>(width);
        _viewHeight = static_cast<float>(height);
    }

    float Camera::GetFOV() {
        return _fov;
    }

    void Camera::SetFOV(float fov) {
        _fov = fov;
    }

    float Camera::GetNearPane() {
        return _nearPane;
    }

    void Camera::SetNearPane(float nearPane) {
        _nearPane = nearPane;
    }

    float Camera::GetFarPane() {
        return _farPane;
    }

    void Camera::SetFarPane(float farPane) {
        _farPane = farPane;
    }
}
