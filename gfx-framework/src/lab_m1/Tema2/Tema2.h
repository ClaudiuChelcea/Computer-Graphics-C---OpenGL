#pragma once

#include "components/simple_scene.h"
#include "Camera.h"

namespace m1
{
    class Tema2 : public gfxc::SimpleScene
    {
    public:
        Tema2();
        ~Tema2();

        bool isOrtho = false;

        void Init() override;
        struct ViewportArea
        {
            ViewportArea() : x(0), y(0), width(1), height(1) {}
            ViewportArea(int x, int y, int width, int height)
                : x(x), y(y), width(width), height(height) {}
            int x;
            int y;
            int width;
            int height;
        };

    private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;

        void RenderMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix, implement::Camera* cam);


        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;
        void RenderScene(implement::Camera* camera);
        double CalculateArea(glm::vec3 A, glm::vec3 B, glm::vec3 C);
        bool InsideTriangle(glm::vec3 A, glm::vec3 B, glm::vec3 C, glm::vec3 P);
        bool InsidePath(glm::vec3 P);
       
    protected:
        glm::vec3 points[71];
        glm::vec3 pointsRed[71];
        glm::vec3 pointsBlue[71];
        glm::vec3 pointsRedOb1[71];
        glm::vec3 pointsBlueOb1[71];
        glm::vec3 carCenter = glm::vec3(0.25, 0, 0.25);
        float distRed = 0.5, distBlue = 1;
        float distRedOb1 = 0.4, distBlueOb1 = 0.9;
        glm::vec3 UP = glm::vec3(0, 1, 0);
        implement::Camera* camera, * cam;
        float rotation_angle_OY = 0;
        float rotation_obstacle = 0;
        glm::mat4 projectionMatrix;
        glm::mat4 projectionMat;
        bool renderCameraTarget;
        float initialCamOX = 0, initialCamOY = 0, initialCamOZ = 0;
        float translateX = 0, translateY = 0, translateZ = 0, trX = 0, trZ = 0;
        GLfloat fov;
        float orthoRight = 8.0f, orthoUp = 4.5f, orthoDown = -4.5f, orthoLeft = -8.0f;
        bool projectionType;
        glm::mat4 modelMatrix = glm::mat4(1);
        ViewportArea miniViewportArea;
        bool isOrto = false;
        glm::vec3 posObs1;
        glm::vec3 posObs2;
        glm::vec3 posObs3;
        float trOb1X = 0, trOb1Y = 0;
        float tx = 0, ty = 0;
        int indOb1 = 0, indOb2 = 0, indOb3 = 0;
    };
} 