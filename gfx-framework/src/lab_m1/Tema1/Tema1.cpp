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

    // For randomization
    srand(time(NULL));

    // Create list of spawnpoints
    for (int yPos = 25; yPos <= 100; yPos = yPos + 25) {
        for (int xPos = 125; xPos <= 900; xPos = xPos + 25) {
            my_duck_manager.getSpawnPoints().push_back(std::make_pair(xPos, yPos));
        }
    }

    // Set an initial random spawn point from the list
    int spawnPointIndex = rand() % my_duck_manager.getSpawnPoints().size();
    std::cout << spawnPointIndex << std::endl;
    my_duck_manager.setSpawnPoint(my_duck_manager.getSpawnPoints().at(spawnPointIndex));
   
    std::cout << my_duck_manager.getSpawnPoint().first << " " << my_duck_manager.getSpawnPoint().second << std::endl;
    // Add meshes
    my_duck_manager.createDuck(std::make_pair(my_duck_manager.getSpawnPoint().first, my_duck_manager.getSpawnPoint().second));
    my_duck_manager.getDuckAlive();
    AddMeshToList(my_duck_manager.getDuckAlive()->getBody());
    AddMeshToList(my_duck_manager.getDuckAlive()->getWingLeft());
    AddMeshToList(my_duck_manager.getDuckAlive()->getWingRight());
    AddMeshToList(my_duck_manager.getDuckAlive()->getHead());
    AddMeshToList(my_duck_manager.getDuckAlive()->getBeak());
    AddMeshToList(my_duck_manager.getDuckAlive()->getHitbox());

    // Create model matrix
    modelMatrix = glm::mat3 { 1 };

    // Wings movement
    angularStepIncreasing = true;

    // Set starting translation
    my_duck_manager.getDuckAlive()->setTranslateX(0);
    my_duck_manager.getDuckAlive()->setTranslateY(0);

    // Set random travelling angle between 25* and 135*, but not between 85 and 95
    // Also randomly (based if the result from rand is even or odd, go right or left
    int movingAngle = rand() % 110 + 25;
    while (movingAngle >= 85 && movingAngle <= 95) {
        movingAngle = rand() % 110 + 25;
    }
    my_duck_manager.getDuckAlive()->setTravellingAngle(movingAngle);
    std::cout << movingAngle;

    my_duck_manager.getDuckAlive()->setDuckAngle(my_duck_manager.getDuckAlive()->getTravellingAngle() + 135);
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
    // Calculate gravity center
    my_duck_manager.getDuckAlive()->setGravityCenter(std::make_pair(my_duck_manager.getSpawnPoint().first, my_duck_manager.getSpawnPoint().second));

    // Calculate translation
    my_duck_manager.getDuckAlive()->setTranslateX(my_duck_manager.getDuckAlive()->getTranslateX() + deltaTimeSeconds * my_duck_manager.getDuckAlive()->getSpeed() * cos(GameManager::myMath::degreesToRadians(my_duck_manager.getDuckAlive()->getTravellingAngle())));
    my_duck_manager.getDuckAlive()->setTranslateY(my_duck_manager.getDuckAlive()->getTranslateY() + deltaTimeSeconds * my_duck_manager.getDuckAlive()->getSpeed() * sin(GameManager::myMath::degreesToRadians(my_duck_manager.getDuckAlive()->getTravellingAngle())));

    // Check wall collisions
    if (my_duck_manager.getDuckAlive()->getTranslateX() + my_duck_manager.getDuckAlive()->getGravityCenter().first < 0 || my_duck_manager.getDuckAlive()->getTranslateX() + my_duck_manager.getDuckAlive()->getGravityCenter().first > resolution.x) {
        my_duck_manager.getDuckAlive()->setTravellingAngle(180 - my_duck_manager.getDuckAlive()->getTravellingAngle());
        my_duck_manager.getDuckAlive()->setDuckAngle(my_duck_manager.getDuckAlive()->getTravellingAngle() + 135);
    }
    else if (my_duck_manager.getDuckAlive()->getTranslateY() + my_duck_manager.getDuckAlive()->getGravityCenter().second < 0 || my_duck_manager.getDuckAlive()->getTranslateY() + my_duck_manager.getDuckAlive()->getGravityCenter().second > resolution.y) {
        my_duck_manager.getDuckAlive()->setTravellingAngle(-my_duck_manager.getDuckAlive()->getTravellingAngle());
        my_duck_manager.getDuckAlive()->setDuckAngle(my_duck_manager.getDuckAlive()->getTravellingAngle() + 135);
    }

    // Create body
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(my_duck_manager.getDuckAlive()->getTranslateX(), my_duck_manager.getDuckAlive()->getTranslateY());
    modelMatrix *= transform2D::Translate(my_duck_manager.getSpawnPoint().first, my_duck_manager.getSpawnPoint().second);
    modelMatrix *= transform2D::Translate(+my_duck_manager.getDuckAlive()->getGravityCenter().first - my_duck_manager.getSpawnPoint().first, my_duck_manager.getDuckAlive()->getGravityCenter().second - my_duck_manager.getSpawnPoint().second);
    modelMatrix *= transform2D::Rotate(GameManager::myMath::degreesToRadians(my_duck_manager.getDuckAlive()->getDuckAngle()));
    modelMatrix *= transform2D::Translate(-my_duck_manager.getDuckAlive()->getGravityCenter().first + my_duck_manager.getSpawnPoint().first, -my_duck_manager.getDuckAlive()->getGravityCenter().second + my_duck_manager.getSpawnPoint().second);
    RenderMesh2D(meshes[my_duck_manager.getDuckAlive()->getBodyString()], shaders["VertexColor"], modelMatrix);

    // Create head
    glm::mat3 body_part = modelMatrix;
    body_part *= transform2D::Scale(0.4f, 0.4f);
    body_part *= transform2D::Translate(my_duck_manager.getDuckAlive()->getHeadBodyOffset().first, my_duck_manager.getDuckAlive()->getHeadBodyOffset().second);
    RenderMesh2D(meshes[my_duck_manager.getDuckAlive()->getHeadString()], shaders["VertexColor"], body_part);

    // Wing rotation step
    if (angularStepIncreasing) {
        angularStep += deltaTimeSeconds;
        if (angularStep > 0.5)
            angularStepIncreasing = false;
    }
    else {
        angularStep -= deltaTimeSeconds;
        if (angularStep <= 0)
            angularStepIncreasing = true;
    }

    // Right wing
    body_part = modelMatrix;
    body_part *= transform2D::Translate(my_duck_manager.getDuckAlive()->getRightWingBodyOffset().first, my_duck_manager.getDuckAlive()->getRightWingBodyOffset().second);
    body_part *= transform2D::Translate(22.5, 22.5);
    body_part *= transform2D::Rotate(angularStep);
    body_part *= transform2D::Translate(-22.5, -22.5);
    RenderMesh2D(meshes[my_duck_manager.getDuckAlive()->getWingRightString()], shaders["VertexColor"], body_part);

    // Left wing
    body_part = modelMatrix;
    body_part *= transform2D::Translate(my_duck_manager.getDuckAlive()->getLeftWingBodyOffset().first, my_duck_manager.getDuckAlive()->getLeftWingBodyOffset().second);
    body_part *= transform2D::Translate(22.5, 22.5);
    body_part *= transform2D::Rotate(-angularStep);
    body_part *= transform2D::Translate(-22.5, -22.5);
    RenderMesh2D(meshes[my_duck_manager.getDuckAlive()->getWingLeftString()], shaders["VertexColor"], body_part);

    // Beak
    body_part = modelMatrix;
    body_part *= transform2D::Translate(my_duck_manager.getDuckAlive()->getBeakBodyOffset().first, my_duck_manager.getDuckAlive()->getBeakBodyOffset().second);
    RenderMesh2D(meshes[my_duck_manager.getDuckAlive()->getBeakString()], shaders["VertexColor"], body_part);

    // Hitbox
    body_part = modelMatrix;
    body_part *= transform2D::Translate(my_duck_manager.getDuckAlive()->getHitboxBodyOffset().first, my_duck_manager.getDuckAlive()->getHitboxBodyOffset().second);
    RenderMesh2D(meshes[my_duck_manager.getDuckAlive()->getHitboxString()], shaders["VertexColor"], body_part);
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