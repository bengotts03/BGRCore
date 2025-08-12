#pragma once

#define GLM_ENABLE_EXPERIMENTAL

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/vector_angle.hpp>

#include "Window.h"
#include "Shader.h"

namespace BGRCore {
    class Camera {
    public:
        Camera(BGAppCore::Window* window, int width, int height, glm::vec3 pos);
        virtual ~Camera() = default;

        // Sends matrix data to the vertex shader
        virtual void SendMatrixData(Shader& shader, const char* uniform);
        // Updates the cameras matrix
        virtual void UpdateMatrix(float FOV, float nearPane, float farPane);

        virtual glm::mat4 GetView();
        virtual glm::mat4 GetProjection();

        void RefreshViewport(int width, int height);

        float GetFOV();
        void SetFOV(float fov);

        float GetNearPane();
        void SetNearPane(float nearPane);

        float GetFarPane();
        void SetFarPane(float farPane);

        glm::mat4 CameraMatrix = glm::mat4(1);
        glm::vec3 Position = glm::vec3(0.0f, 0.0f, 0.0f);
        glm::vec3 Direction = glm::vec3(0.0f, 0.0f, -1.0f);
        glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);
    protected:
        float _viewWidth;
        float _viewHeight;

        float _fov = 90.0f;
        float _nearPane = 0.01f;
        float _farPane = 100.0f;

        BGAppCore::Window* _window;
    };
}