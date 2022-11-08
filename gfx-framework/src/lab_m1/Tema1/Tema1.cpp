#include "Tema1.h"

using namespace std;
using namespace m1;

Tema1::Tema1() = default;
Tema1::~Tema1() = default;

void Tema1::Init()
{
    // Set window
    resolution = window->GetResolution();
    auto camera = GetSceneCamera();
    camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
    camera->SetPosition(glm::vec3(0, 0, 50));
    camera->SetRotation(glm::vec3(0, 0, 0));
    camera->Update();
    GetCameraInput()->SetActive(false);

    // Initialize angularStep
    angularStep = 0;

    // Add meshes
    my_duck_manager.createDuck(std::make_pair(100.0f, 100.0f));
    my_duck_manager.getDuckAlive();
    AddMeshToList(my_duck_manager.getDuckAlive()->getBody());
    AddMeshToList(my_duck_manager.getDuckAlive()->getWingLeft());
    AddMeshToList(my_duck_manager.getDuckAlive()->getWingRight());
    AddMeshToList(my_duck_manager.getDuckAlive()->getHead());
    AddMeshToList(my_duck_manager.getDuckAlive()->getBeak());

    // Create model matrix
    modelMatrix = glm::mat3 { 1 };

    // Wings movement
    angularStepIncreasing = true;
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

void Tema1::Update(float deltaTimeSeconds)
{
    
    /* Calculate horizontal position */
    // If the bird reaches the left side of the screen
    if (my_duck_manager.getDuckAlive()->getBodyPosition().first + my_duck_manager.getDuckAlive()->getDuckWidth().first < 0) {
        // Go right
        my_duck_manager.getDuckAlive()->setXSpeed(-my_duck_manager.getDuckAlive()->getXSpeed());
    }

    // If the bird reaches the right side of the screen
    if (my_duck_manager.getDuckAlive()->getBodyPosition().first > resolution.x - my_duck_manager.getDuckAlive()->getDuckWidth().second) {
        // Go left
        my_duck_manager.getDuckAlive()->setXSpeed(-my_duck_manager.getDuckAlive()->getXSpeed());
    }

    /* Calculate vertical position */
    // If the bird reaches the bottom of the screen
    if (my_duck_manager.getDuckAlive()->getBodyPosition().second + my_duck_manager.getDuckAlive()->getDuckHeight().first < 0) {
        // Go up
        my_duck_manager.getDuckAlive()->setYSpeed(-my_duck_manager.getDuckAlive()->getYSpeed());
    }

    // If the bird reaches the top of the screen
    if (my_duck_manager.getDuckAlive()->getBodyPosition().second > resolution.y - my_duck_manager.getDuckAlive()->getDuckHeight().second) {
        // Go down
        my_duck_manager.getDuckAlive()->setYSpeed(-my_duck_manager.getDuckAlive()->getYSpeed());
    }



    //my_duck.getPositionOfBody() = glm::mat3(1);
    //modelMatrix = transform2D::Translate(positionX, positionY);
    // 
    // 
    
    // Update position
    my_duck_manager.getDuckAlive()->setBodyPosition(
        std::make_pair(
            my_duck_manager.getDuckAlive()->getBodyPosition().first + my_duck_manager.getDuckAlive()->getXSpeed(),
            my_duck_manager.getDuckAlive()->getBodyPosition().second + my_duck_manager.getDuckAlive()->getYSpeed()));

    // Render body
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(my_duck_manager.getDuckAlive()->getBodyPosition().first, my_duck_manager.getDuckAlive()->getBodyPosition().second);
    modelMatrix *= transform2D::Rotate(my_duck_manager.getDuckAlive()->getBodyRotation());
    RenderMesh2D(meshes[my_duck_manager.getDuckAlive()->getBodyString()], shaders["VertexColor"], modelMatrix);
  
    // Wing rotation step
    if (angularStepIncreasing) {
        angularStep += deltaTimeSeconds;
        if (angularStep > 0.8)
            angularStepIncreasing = false;
    }
    else {
       angularStep -= deltaTimeSeconds;
       if (angularStep <= 0)
           angularStepIncreasing = true;
    }

    // Render left wing
    modelMatrix *= transform2D::Translate(my_duck_manager.getDuckAlive()->getLeftWingBodyOffset().first, my_duck_manager.getDuckAlive()->getLeftWingBodyOffset().second);
    modelMatrix *= transform2D::Rotate(1.65 * my_duck_manager.getDuckAlive()->getBodyRotation());
    modelMatrix *= transform2D::Rotate(angularStep);
    RenderMesh2D(meshes[my_duck_manager.getDuckAlive()->getWingLeftString()], shaders["VertexColor"], modelMatrix);

    // Render right wing
    // Redo body
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(my_duck_manager.getDuckAlive()->getBodyPosition().first, my_duck_manager.getDuckAlive()->getBodyPosition().second);
    modelMatrix *= transform2D::Rotate(my_duck_manager.getDuckAlive()->getBodyRotation());
    // Now add wing
    modelMatrix *= transform2D::Translate(my_duck_manager.getDuckAlive()->getRightWingBodyOffset().first, my_duck_manager.getDuckAlive()->getRightWingBodyOffset().second);
    modelMatrix *= transform2D::Rotate(my_duck_manager.getDuckAlive()->getBodyRotation() / 3);
    modelMatrix *= transform2D::Rotate(-angularStep);
    RenderMesh2D(meshes[my_duck_manager.getDuckAlive()->getWingRightString()], shaders["VertexColor"], modelMatrix);

    // Render head
    // Redo body
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(my_duck_manager.getDuckAlive()->getBodyPosition().first, my_duck_manager.getDuckAlive()->getBodyPosition().second);
    modelMatrix *= transform2D::Rotate(my_duck_manager.getDuckAlive()->getBodyRotation());
    // Now add head
    modelMatrix *= transform2D::Translate(my_duck_manager.getDuckAlive()->getHeadBodyOffset().first, my_duck_manager.getDuckAlive()->getHeadBodyOffset().second);
    modelMatrix *= transform2D::Scale(0.40f, 0.40f);
    RenderMesh2D(meshes[my_duck_manager.getDuckAlive()->getHeadString()], shaders["VertexColor"], modelMatrix);

    // Render beak
    // Redo body
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(my_duck_manager.getDuckAlive()->getBodyPosition().first, my_duck_manager.getDuckAlive()->getBodyPosition().second);
    // Now add beak
    modelMatrix *= transform2D::Translate(my_duck_manager.getDuckAlive()->getBeakBodyOffset().first, my_duck_manager.getDuckAlive()->getBeakBodyOffset().second);
    modelMatrix *= transform2D::Rotate(PI);
    RenderMesh2D(meshes[my_duck_manager.getDuckAlive()->getBeakString()], shaders["VertexColor"], modelMatrix);
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
