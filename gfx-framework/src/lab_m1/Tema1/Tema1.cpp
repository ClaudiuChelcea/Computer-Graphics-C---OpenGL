#include "Tema1.h"

using namespace std;
using namespace m1;

Tema1::Tema1() = default;
Tema1::~Tema1() = default;

void Tema1::Init()
{
    // Set window
    glm::ivec2 resolution = window->GetResolution();
    auto camera = GetSceneCamera();
    camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
    camera->SetPosition(glm::vec3(0, 0, 50));
    camera->SetRotation(glm::vec3(0, 0, 0));
    camera->Update();
    GetCameraInput()->SetActive(false);

    glm::vec3 corner = glm::vec3(0, 0, 0);

    // Initialize angularStep
    angularStep = 0;

    // Create model matrix
    modelMatrix = glm::mat3(1);

    // Add meshes
    my_duck.createDuck();
    AddMeshToList(my_duck.getBody());
    AddMeshToList(my_duck.getWingLeft());
    AddMeshToList(my_duck.getWingRight());
    AddMeshToList(my_duck.getHead());
    AddMeshToList(my_duck.getBeak());
}

void Tema1::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();
    
    // Sets the screen area where to draw
    glViewport(0, 0, resolution.x, resolution.y);
}

int positionX = 32;
int speedX = 2;
int positionY = 32;
int speedY = 1;
int ballSize = 8;


void Tema1::Update(float deltaTimeSeconds)
{

    // Update horizontal position
    positionX = positionX + speedX;


    // If the ball reaches the left side of the screen
    if (positionX < 0) {
        // Go right
        speedX = 1;
    }


    // If the ball reaches the right side of the screen
    if (positionX > 1280 - ballSize) {
        // Go left
        speedX = -1;
    }


    // Update vertical position
    positionY = positionY + speedY;


    // If the ball reaches the top side of the screen
    if (positionY < 0) {
        // Go down
        speedY = 1;
    }


    // If the ball reaches the bottom side of the screen
    if (positionY > 920 - ballSize) {
        // Go up
        speedY = -1;
    }

    angularStep += deltaTimeSeconds;
    if (angularStep > 0.7) {
        angularStep = 0;
    }

    modelMatrix = glm::mat3(1);
    modelMatrix = transform2D::Translate(positionX, positionY);
    RenderMesh2D(meshes[my_duck.getBodyString()], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(240, 215);
    modelMatrix *= transform2D::Rotate(-1);
    modelMatrix *= transform2D::Rotate(angularStep);
    RenderMesh2D(meshes[my_duck.getWingLeftString()], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(153, 233);
    modelMatrix *= transform2D::Rotate(-1);
    modelMatrix *= transform2D::Translate(+50, +50);
    modelMatrix *= transform2D::Rotate(-angularStep);
    modelMatrix *= transform2D::Translate(-50, -50);
    RenderMesh2D(meshes[my_duck.getWingRightString()], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(240, 245);
    modelMatrix *= transform2D::Scale(0.3, 0.3);
    RenderMesh2D(meshes[my_duck.getHeadString()], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(263, 258);
    modelMatrix *= transform2D::Rotate(-2.7);
    RenderMesh2D(meshes[my_duck.getBeakString()], shaders["VertexColor"], modelMatrix);
}

void Tema1::FrameEnd()
{
}

void Tema1::OnInputUpdate(float deltaTime, int mods)
{
}


void Tema1::OnKeyPress(int key, int mods)
{
}


void Tema1::OnKeyRelease(int key, int mods)
{
}


void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
}


void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
}


void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
}


void Tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void Tema1::OnWindowResize(int width, int height)
{
}
