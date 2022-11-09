#ifndef __TEMA1_H_
#define __TEMA1_H_

#pragma once

#include <iostream>
#include <vector>

#include "components/simple_scene.h"
#include "lab_m1/Tema1/transform2D.h"
#include "lab_m1/Tema1/Game Manager.h"

namespace m1
{
    class Tema1 : public gfxc::SimpleScene
    {
    public:
        Tema1();
        ~Tema1();
        void Init() override;

    private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;
        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;

    protected:
        float angularStep; // wing rotation animation
        bool angularStepIncreasing = true; // used for angularStep
        glm::mat3 modelMatrix; // modelMatrix for rendering shapes
        GameManager::DuckManager my_duck_manager; // manage ducks
        glm::ivec2 resolution; // window resolution
        float directionX{ 0 }, directionY{ 0 };
    };
}   // namespace m1


#endif // __TEMA1_H_