#include "Tema2.h"

#include <vector>
#include <string>
#include <iostream>

using namespace std;
using namespace m1;

#define Z_FAR		(200.f)
#define Z_NEAR		(.01f)

/*
 *  To find out more about `FrameStart`, `Update`, `FrameEnd`
 *  and the order in which they are called, see `world.cpp`.
 */

Tema2::Tema2() {}
Tema2::~Tema2() {}

void Tema2::Init()
{
    srand(time(NULL));
    initialCamOX = 0;
    initialCamOY = 2;
    initialCamOZ = 3.5f;
    camera = new implement::Camera();
    camera->Set(glm::vec3(0, 2, 3.5f), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0));
    cam = new implement::Camera();

    points[0] = glm::vec3(0, 0, 0);
    points[1] = glm::vec3(-0.41, 0, 1.95);
    points[2] = glm::vec3(-1.18, 0, 3.77);
    points[3] = glm::vec3(-1.74, 0, 6.22);
    points[4] = glm::vec3(-2.3, 0, 7.9);
    points[5] = glm::vec3(-3.28, 0, 9.79);
    points[6] = glm::vec3(-3.98, 0, 11.75);
    points[7] = glm::vec3(-4.41, 0, 13.79);
    points[8] = glm::vec3(-4.27, 0, 15.96);
    points[9] = glm::vec3(-3.98, 0, 17.92);
    points[10] = glm::vec3(-3.56, 0, 20.51);
    points[11] = glm::vec3(-3.91, 0, 23.03);
    points[12] = glm::vec3(-5, 0, 25);
    points[13] = glm::vec3(-6.23, 0, 26.39);
    points[14] = glm::vec3(-7.77, 0, 27.23);
    points[15] = glm::vec3(-9.24, 0, 27.51);
    points[16] = glm::vec3(-11.2, 0, 27.16);
    points[17] = glm::vec3(-12.04, 0, 26.04);
    points[18] = glm::vec3(-13.16, 0, 24.99);
    points[19] = glm::vec3(-15, 0, 25);
    points[20] = glm::vec3(-16.66, 0, 26.32);
    points[21] = glm::vec3(-17.36, 0, 28.01);
    points[22] = glm::vec3(-17.5, 0, 30.32);
    points[23] = glm::vec3(-17.08, 0, 32.28);
    points[24] = glm::vec3(-16.38, 0, 34.52);
    points[25] = glm::vec3(-15.78, 0, 38.01);
    points[26] = glm::vec3(-15.89, 0, 40.98);
    points[27] = glm::vec3(-17.87, 0, 42.52);
    points[28] = glm::vec3(-20.4, 0, 43.4);
    points[29] = glm::vec3(-23.15, 0, 43.18);
    points[30] = glm::vec3(-25.57, 0, 42.19);
    points[31] = glm::vec3(-27.33, 0, 40.65);
    points[32] = glm::vec3(-29.2, 0, 38.23);
    points[33] = glm::vec3(-30.3, 0, 35.58);
    points[34] = glm::vec3(-30.85, 0, 33.93);
    points[35] = glm::vec3(-31.84, 0, 31.62);
    points[36] = glm::vec3(-34.71, 0, 30.63);
    points[37] = glm::vec3(-36.91, 0, 31.95);
    points[38] = glm::vec3(-38.67, 0, 33.82);
    points[39] = glm::vec3(-41.09, 0, 35.58);
    points[40] = glm::vec3(-43.51, 0, 36.57);
    points[41] = glm::vec3(-46.59, 0, 36.46);
    points[42] = glm::vec3(-48.13, 0, 34.7);
    points[43] = glm::vec3(-48.35, 0, 32.83);
    points[44] = glm::vec3(-47.47, 0, 30.08);
    points[45] = glm::vec3(-45.6, 0, 28.43);
    points[46] = glm::vec3(-43.95, 0, 26.67);
    points[47] = glm::vec3(-42.19, 0, 25.46);
    points[48] = glm::vec3(-39.99, 0, 24.47);
    points[49] = glm::vec3(-37.35, 0, 23.7);
    points[50] = glm::vec3(-34.27, 0, 22.93);
    points[51] = glm::vec3(-31.09, 0, 23.14);
    points[52] = glm::vec3(-28.54, 0, 21.61);
    points[53] = glm::vec3(-27.55, 0, 19.74);
    points[54] = glm::vec3(-27.55, 0, 17.97);
    points[55] = glm::vec3(-27.66, 0, 15.77);
    points[56] = glm::vec3(-27.99, 0, 14.01);
    points[57] = glm::vec3(-28.54, 0, 12.03);
    points[58] = glm::vec3(-27.11, 0, 10.05);
    points[59] = glm::vec3(-24.8, 0, 8.51);
    points[60] = glm::vec3(-22.6, 0, 7.63);
    points[61] = glm::vec3(-20.62, 0, 6.86);
    points[62] = glm::vec3(-18.31, 0, 6.42);
    points[63] = glm::vec3(-15.89, 0, 5.65);
    points[64] = glm::vec3(-13.35, 0, 4.88);
    points[65] = glm::vec3(-11.04, 0, 4.11);
    points[66] = glm::vec3(-9.06, 0, 3.23);
    points[67] = glm::vec3(-7.52, 0, 1.25);
    points[68] = glm::vec3(-5.65, 0, 0.37);
    points[69] = glm::vec3(-3.89, 0, -0.51);
    points[70] = glm::vec3(-1.13, 0, -1.71);
    
    //car
    {
        vector<VertexFormat> verticesCar
        {
            VertexFormat(myRectangle.getCorners()[0], glm::vec3(1.0f, 0.5f, 0.31f)),
            VertexFormat(myRectangle.getCorners()[1], glm::vec3(1.0f, 0.5f, 0.31f)),
            VertexFormat(myRectangle.getCorners()[2], glm::vec3(1.0f, 0.5f, 0.31f)),
            VertexFormat(myRectangle.getCorners()[3], glm::vec3(1.0f, 0.5f, 0.31f)),
            VertexFormat(myRectangle.getCorners()[4], glm::vec3(1.0f, 0.5f, 0.31f)),
            VertexFormat(myRectangle.getCorners()[5], glm::vec3(1.0f, 0.5f, 0.31f)),
            VertexFormat(myRectangle.getCorners()[6], glm::vec3(1.0f, 0.5f, 0.31f)),
            VertexFormat(myRectangle.getCorners()[7], glm::vec3(1.0f, 0.5f, 0.31f)),
        };

        vector<unsigned int> indicesCar =
        {
            0, 1, 2,
            2, 3, 7,
            2, 7, 6,
            1, 7, 3,
            1, 5, 7,
            6, 7, 4,
            7, 5, 4,
            0, 4, 1,
            1, 4, 5,
            2, 6, 4,
            0, 2, 4,
        };

        meshes["car"] = new Mesh("generated car");
        meshes["car"]->InitFromData(verticesCar, indicesCar);
    }

    // Enemy 1
    {
        vector<VertexFormat> verticesCar
        {
            VertexFormat(myRectangle.getCorners()[0], enemy_1.getColor()),
            VertexFormat(myRectangle.getCorners()[1], enemy_1.getColor()),
            VertexFormat(myRectangle.getCorners()[2], enemy_1.getColor()),
            VertexFormat(myRectangle.getCorners()[3], enemy_1.getColor()),
            VertexFormat(myRectangle.getCorners()[4], enemy_1.getColor()),
            VertexFormat(myRectangle.getCorners()[5], enemy_1.getColor()),
            VertexFormat(myRectangle.getCorners()[6], enemy_1.getColor()),
            VertexFormat(myRectangle.getCorners()[7], enemy_1.getColor()),

        };

        vector<unsigned int> indicesCar = enemy_1.getDefaultIndicesCar();
        meshes[enemy_1.getObjectName()] = new Mesh("First");
        meshes[enemy_1.getObjectName()]->InitFromData(verticesCar, indicesCar);
    }

    // Enemy 2
    {
        vector<VertexFormat> verticesCar
        {
            VertexFormat(myRectangle.getCorners()[0], enemy_2.getColor()),
            VertexFormat(myRectangle.getCorners()[1], enemy_2.getColor()),
            VertexFormat(myRectangle.getCorners()[2], enemy_2.getColor()),
            VertexFormat(myRectangle.getCorners()[3], enemy_2.getColor()),
            VertexFormat(myRectangle.getCorners()[4], enemy_2.getColor()),
            VertexFormat(myRectangle.getCorners()[5], enemy_2.getColor()),
            VertexFormat(myRectangle.getCorners()[6], enemy_2.getColor()),
            VertexFormat(myRectangle.getCorners()[7], enemy_2.getColor()),

        };

        vector<unsigned int> indicesCar = enemy_2.getDefaultIndicesCar();
        meshes[enemy_2.getObjectName()] = new Mesh("Second");
        meshes[enemy_2.getObjectName()]->InitFromData(verticesCar, indicesCar);
    }

    // Enemy 3
    {
        vector<VertexFormat> verticesCar
        {
            VertexFormat(myRectangle.getCorners()[0], enemy_3.getColor()),
            VertexFormat(myRectangle.getCorners()[1], enemy_3.getColor()),
            VertexFormat(myRectangle.getCorners()[2], enemy_3.getColor()),
            VertexFormat(myRectangle.getCorners()[3], enemy_3.getColor()),
            VertexFormat(myRectangle.getCorners()[4], enemy_3.getColor()),
            VertexFormat(myRectangle.getCorners()[5], enemy_3.getColor()),
            VertexFormat(myRectangle.getCorners()[6], enemy_3.getColor()),
            VertexFormat(myRectangle.getCorners()[7], enemy_3.getColor()),
        };

        vector<unsigned int> indicesCar = enemy_3.getDefaultIndicesCar();
        meshes[enemy_3.getObjectName()] = new Mesh("Third");
        meshes[enemy_3.getObjectName()]->InitFromData(verticesCar, indicesCar);
    }

   

    //ground
    {
        vector<VertexFormat> verticesGround
        {
            VertexFormat(glm::vec3(0, 0, 500), glm::vec3(0.68f, 1.0f, 0.68f)),
            VertexFormat(glm::vec3(500, 0, 500), glm::vec3(0.68f, 1.0f, 0.68f)),
            VertexFormat(glm::vec3(0, 0, 500), glm::vec3(0.68f, 1.0f, 0.68f)),
            VertexFormat(glm::vec3(500, 0, 500), glm::vec3(0.68f, 1.0f, 0.68f)),
            VertexFormat(glm::vec3(0, 0, 0), glm::vec3(0.68f, 1.0f, 0.68f)),
            VertexFormat(glm::vec3(500, 0, 0), glm::vec3(0.68f, 1.0f, 0.68f)),
            VertexFormat(glm::vec3(0, 0, 0), glm::vec3(0.68f, 1.0f, 0.68f)),
            VertexFormat(glm::vec3(500, 0, 0), glm::vec3(0.68f, 1.0f, 0.68f)),

        };

        vector<unsigned int> indicesGround =
        {
            0, 1, 2,
            1, 3, 2,
            2, 3, 7,
            2, 7, 6,
            1, 7, 3,
            1, 5, 7,
            6, 7, 4,
            7, 5, 4,
            0, 4, 1,
            1, 4, 5,
            2, 6, 4,
            0, 2, 4
        };

        meshes["ground"] = new Mesh("generated ground");
        meshes["ground"]->InitFromData(verticesGround, indicesGround);
    }

    //treeTop
    {
        vector<VertexFormat> vertices{
            VertexFormat(glm::vec3(0, 0, 1.5), glm::vec3(0.035f, 0.47f, 0.41f),glm::vec3(0, 1, 0),glm::vec2(1)),
            VertexFormat(glm::vec3(1.5, 0, 1.5), glm::vec3(0.035f, 0.47f, 0.41f),glm::vec3(0, 1, 0),glm::vec2(1)),
            VertexFormat(glm::vec3(0, 1.5, 1.5), glm::vec3(0.035f, 0.47f, 0.41f),glm::vec3(0, 1, 0),glm::vec2(1)),
            VertexFormat(glm::vec3(1.5, 1.5, 1.5), glm::vec3(0.035f, 0.47f, 0.41f),glm::vec3(0, 1, 0),glm::vec2(1)),
            VertexFormat(glm::vec3(0, 0, 0), glm::vec3(0.035f, 0.47f, 0.41f),glm::vec3(0, 1, 0),glm::vec2(1)),
            VertexFormat(glm::vec3(1.5, 0, 0), glm::vec3(0.035f, 0.47f, 0.41f),glm::vec3(0, 1, 0),glm::vec2(1)),
            VertexFormat(glm::vec3(0, 1.5, 0), glm::vec3(0.035f, 0.47f, 0.41f),glm::vec3(0, 1, 0),glm::vec2(1)),
            VertexFormat(glm::vec3(1.5, 1.5, 0), glm::vec3(0.035f, 0.47f, 0.41f),glm::vec3(0, 1, 0),glm::vec2(1)),
        };
        vector<unsigned int> indices = {
            0, 1, 2,
            2, 3, 7,
            2, 7, 6,
            1, 7, 3,
            1, 5, 7,
            6, 7, 4,
            7, 5, 4,
            0, 4, 1,
            1, 4, 5,
            2, 6, 4,
            0, 2, 4, };
        meshes["treeTop"] = new Mesh("generated treeTop");
        meshes["treeTop"]->InitFromData(vertices, indices);
    }


    //treeBottom
    {
        vector<VertexFormat> vertices{
            VertexFormat(glm::vec3(0, 0, 0.5), glm::vec3(0.82f, 0.41f, 0.11f),glm::vec3(0, 1, 0),glm::vec2(1)),
            VertexFormat(glm::vec3(0.5, 0, 0.5), glm::vec3(0.82f, 0.41f, 0.11f),glm::vec3(0, 1, 0),glm::vec2(1)),
            VertexFormat(glm::vec3(0, 1.5, 0.5),  glm::vec3(0.82f, 0.41f, 0.11f),glm::vec3(0, 1, 0),glm::vec2(1)),
            VertexFormat(glm::vec3(0.5, 1.5, 0.5),  glm::vec3(0.82f, 0.41f, 0.11f),glm::vec3(0, 1, 0),glm::vec2(1)),
            VertexFormat(glm::vec3(0, 0, 0),  glm::vec3(0.82f, 0.41f, 0.11f),glm::vec3(0, 1, 0),glm::vec2(1)),
            VertexFormat(glm::vec3(0.5, 0, 0),  glm::vec3(0.82f, 0.41f, 0.11f),glm::vec3(0, 1, 0),glm::vec2(1)),
            VertexFormat(glm::vec3(0, 1.5, 0),  glm::vec3(0.82f, 0.41f, 0.11f),glm::vec3(0, 1, 0),glm::vec2(1)),
            VertexFormat(glm::vec3(0.5, 1.5, 0),  glm::vec3(0.82f, 0.41f, 0.11f),glm::vec3(0, 1, 0),glm::vec2(1)), };
        vector<unsigned int> indices = {
            0, 1, 2,
            1, 3, 2,
            2, 3, 7,
            2, 7, 6,
            1, 7, 3,
            1, 5, 7,
            6, 7, 4,
            7, 5, 4,
            0, 4, 1,
            1, 4, 5,
            2, 6, 4,
            0, 2, 4, };
        meshes["treeBottom"] = new Mesh("generated treeBottom");
        meshes["treeBottom"]->InitFromData(vertices, indices);
    }

    projectionMatrix = glm::perspective(RADIANS(60), window->props.aspectRatio, 0.01f, 200.0f);
    glm::ivec2 resolution = window->GetResolution();
    miniViewport = Viewport(50, 50, resolution.x / 5.f, resolution.y / 5.f);

    for (int i = 0; i < 70; i++) {
        glm::vec3 D = points[i + 1] - points[i];
        glm::vec3 P = cross(D, UP);
        pointsRed[i] = points[i] + distRed * P;
        pointsBlue[i] = points[i] - distBlue * P;
        pointsRedOb1[i] = points[i] + distRedOb1 * P;
        pointsBlueOb1[i] = points[i] - distBlueOb1 * P;
    }

    glm::vec3 D = points[0] - points[70];
    glm::vec3 P = cross(D, UP);
    pointsRed[70] = points[70] + distRed * P;
    pointsBlue[70] = points[70] - distBlue * P;
  
    enemy_1.setStartIndex(rand() % 70);
    enemy_2.setStartIndex(rand() % 70);
    enemy_3.setStartIndex(rand() % 70);
}

void Tema2::RenderScene(implement::Camera* camera) {

    modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Translate(-300, 0, -160);
    RenderMesh(meshes["ground"], shaders["VertexColor"], modelMatrix, camera);

      //calculate points for path
  
    for (int i = 0; i < 70; i++) {
        vector<VertexFormat> verticesPath{
          VertexFormat(glm::vec3(pointsRed[i].x, 0.1, pointsRed[i].z), glm::vec3(0.54f, 0.27f, 0.07f)),
          VertexFormat(glm::vec3(pointsBlue[i].x, 0.1, pointsBlue[i].z), glm::vec3(0.54f, 0.27f, 0.07f)),
          VertexFormat(glm::vec3(pointsRed[i + 1].x, 0.1, pointsRed[i + 1].z), glm::vec3(0.54f, 0.27f, 0.07f)),
          VertexFormat(glm::vec3(pointsBlue[i + 1].x, 0.1, pointsBlue[i + 1].z), glm::vec3(0.54f, 0.27f, 0.07f)),

        };
        vector<unsigned int> indicesPath = {
                0,1,3,
                0,3,2,
        };
        meshes["path"] = new Mesh("generated path");
        meshes["path"]->InitFromData(verticesPath, indicesPath);
        modelMatrix = glm::mat4(1);

        RenderMesh(meshes["path"], shaders["VertexColor"], modelMatrix, camera);

        if (i >= 0 && i <= 31) {
     
                modelMatrix = glm::mat4(1);
                modelMatrix *= transform3D::Translate(pointsBlue[i].x + 3, 0, pointsBlue[i].z + 8.1);
                RenderMesh(meshes["treeBottom"], shaders["VertexColor"], modelMatrix, camera);
                modelMatrix *= transform3D::Translate(-0.5, 1.53, -0.5);
                RenderMesh(meshes["treeTop"], shaders["VertexColor"], modelMatrix, camera);
                
                if (i > 1 &&  i <= 29) {
                    glm::mat4 modelMatrixCopy = glm::mat4(1);
                    modelMatrixCopy *= transform3D::Translate(pointsRed[i].x - 1.3, 0, pointsRed[i].z - 2);
                    RenderMesh(meshes["treeBottom"], shaders["VertexColor"], modelMatrixCopy, camera);
                    modelMatrixCopy *= transform3D::Translate(-0.5, 1.53, -0.5);
                    RenderMesh(meshes["treeTop"], shaders["VertexColor"], modelMatrixCopy, camera);
                }
        }
        else {

            if (i > 31 && i < 37) {
                glm::mat4 modelMatrixCopy = glm::mat4(1);
                modelMatrixCopy *= transform3D::Translate(pointsBlue[i].x - 2, 0, pointsBlue[i].z  + 3);
                RenderMesh(meshes["treeBottom"], shaders["VertexColor"], modelMatrixCopy, camera);
                modelMatrixCopy *= transform3D::Translate(-0.5, 1.53, -0.5);
                RenderMesh(meshes["treeTop"], shaders["VertexColor"], modelMatrixCopy, camera);

                modelMatrixCopy = glm::mat4(1);
                modelMatrixCopy *= transform3D::Translate(pointsRed[i].x + 4, 0, pointsRed[i].z);
                RenderMesh(meshes["treeBottom"], shaders["VertexColor"], modelMatrixCopy, camera);
                modelMatrixCopy *= transform3D::Translate(-0.5, 1.53, -0.5);
                RenderMesh(meshes["treeTop"], shaders["VertexColor"], modelMatrixCopy, camera);
            }

           if (i > 38 && i < 41) {
               glm::mat4 modelMatrixCopy = glm::mat4(1);
               modelMatrixCopy *= transform3D::Translate(pointsBlue[i].x + 6, 0, pointsBlue[i].z - 1);
               RenderMesh(meshes["treeBottom"], shaders["VertexColor"], modelMatrixCopy, camera);
               modelMatrixCopy *= transform3D::Translate(-0.5, 1.53, -0.5);
               RenderMesh(meshes["treeTop"], shaders["VertexColor"], modelMatrixCopy, camera);
           }
           if (i > 41 && i < 69) {
             
                glm::mat4 modelMatrixCopy = glm::mat4(1);
                modelMatrix *= transform3D::Translate(pointsBlue[i].x - 2, 0, pointsBlue[i].z - 3.5);
                RenderMesh(meshes["treeBottom"], shaders["VertexColor"], modelMatrix, camera);
                modelMatrix *= transform3D::Translate(-0.5, 1.53, -0.5);
                RenderMesh(meshes["treeTop"], shaders["VertexColor"], modelMatrix, camera);

                modelMatrixCopy = glm::mat4(1);
                modelMatrixCopy *= transform3D::Translate(pointsRed[i].x + 2.3, 0, pointsRed[i].z);
                RenderMesh(meshes["treeBottom"], shaders["VertexColor"], modelMatrixCopy, camera);
                modelMatrixCopy *= transform3D::Translate(-0.5, 1.53, -0.5);
                RenderMesh(meshes["treeTop"], shaders["VertexColor"], modelMatrixCopy, camera);
           }
        }


    }
    
    vector<VertexFormat> verticesPath{
          VertexFormat(glm::vec3(pointsRed[70].x, 0.1, pointsRed[70].z), glm::vec3(0.54f, 0.27f, 0.07f)),
          VertexFormat(glm::vec3(pointsBlue[70].x, 0.1, pointsBlue[70].z), glm::vec3(0.54f, 0.27f, 0.07f)),
          VertexFormat(glm::vec3(pointsRed[0].x, 0.1, pointsRed[0].z), glm::vec3(0.54f, 0.27f, 0.07f)),
          VertexFormat(glm::vec3(pointsBlue[0].x, 0.1, pointsBlue[0].z), glm::vec3(0.54f, 0.27f, 0.07f)),

    };
    vector<unsigned int> indicesPath = {
            0,1,3,
            0,3,2,
    };
    meshes["path"] = new Mesh("generated path");
    meshes["path"]->InitFromData(verticesPath, indicesPath);
    modelMatrix = glm::mat4(1);
    RenderMesh(meshes["path"], shaders["VertexColor"], modelMatrix, camera);
  

}

void Tema2::FrameStart()
{   
    // Set the color of the sky 
    float R = 255;
    float G = 192;
    float B = 203;
    glClearColor((float)R/255, (float)G/255, (float)B/255, 1);
    glClear(GL_COLOR_BUFFER_BIT);
}


void Tema2::Update(float deltaTimeSeconds)
{
    glClear(GL_DEPTH_BUFFER_BIT);
    glm::ivec2 resolution = window->GetResolution();

    // --------------------------------------------------------- MAIN VIEWPORT ---------------------------------------------------------
    glViewport(0, 0, resolution.x, resolution.y);
    projectionMatrix = glm::perspective(RADIANS(60), window->props.aspectRatio, 0.01f, 200.0f);

    // Camera
    RenderScene(camera);
    camera->Set(glm::vec3(0, 2, 3.5f), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0));

    modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Translate(translateX, translateY, translateZ);
    camera->MoveForward(-translateZ);
    camera->TranslateRight(translateX);

    modelMatrix *= transform3D::Translate(0, 0.3, 0);
    modelMatrix *= transform3D::Translate(0.5, 0, 0);
    modelMatrix *= transform3D::RotateOY(rotation_angle_OY);
    modelMatrix *= transform3D::Translate(-0.5, 0, 0);

    camera->MoveForward(initialCamOZ);
    camera->RotateFirstPerson_OY(rotation_angle_OY);
    camera->MoveForward(-initialCamOZ);
    RenderMesh(meshes["car"], shaders["VertexColor"], modelMatrix, camera);
    
    // First enemy
    enemy_1.carMovement(modelMatrix, points);
    RenderMesh(meshes[enemy_1.getObjectName()], shaders["VertexColor"], modelMatrix, camera);

    // Second enemy
    enemy_2.carMovement(modelMatrix, points);
    RenderMesh(meshes[enemy_2.getObjectName()], shaders["VertexColor"], modelMatrix, camera);

    // Third enemy
    enemy_3.carMovement(modelMatrix, points);
    RenderMesh(meshes[enemy_3.getObjectName()], shaders["VertexColor"], modelMatrix, camera);


    glClear(GL_DEPTH_BUFFER_BIT);
    glViewport(miniViewport.x, miniViewport.y, miniViewport.width, miniViewport.height);

    // --------------------------------------------------------- MINIMAP ---------------------------------------------------------
    cam->Set(glm::vec3(translateX, 30, translateZ), glm::vec3(translateX, 0, translateZ), glm::vec3(-1, 0, -1));

    RenderScene(cam);

    modelMatrix = glm::mat4(1);

    modelMatrix *= transform3D::Translate(translateX, translateY, translateZ);

    modelMatrix *= transform3D::Translate(0, 0.3, 0);
    modelMatrix *= transform3D::Translate(0.5, 0, 0);
    modelMatrix *= transform3D::RotateOY(rotation_angle_OY);
    modelMatrix *= transform3D::Translate(-0.5, 0, 0);

    RenderMesh(meshes["car"], shaders["VertexColor"], modelMatrix, cam);

    // First enemy
    enemy_1.carMovement(modelMatrix, points);
    RenderMesh(meshes[enemy_1.getObjectName()], shaders["VertexColor"], modelMatrix, camera);

    // Second enemy
    enemy_2.carMovement(modelMatrix, points);
    RenderMesh(meshes[enemy_2.getObjectName()], shaders["VertexColor"], modelMatrix, camera);

    // Third enemy
    enemy_3.carMovement(modelMatrix, points);
    RenderMesh(meshes[enemy_3.getObjectName()], shaders["VertexColor"], modelMatrix, camera);

}

void Tema2::RenderMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix, implement::Camera* cam)
{
    if (!mesh || !shader || !shader->program)
        return;

    // Render an object using the specified shader and the specified position
    shader->Use();
    glUniformMatrix4fv(shader->loc_view_matrix, 1, GL_FALSE, glm::value_ptr(cam->GetViewMatrix()));
    glUniformMatrix4fv(shader->loc_projection_matrix, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
    glUniformMatrix4fv(shader->loc_model_matrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));

    mesh->Render();
}


double Tema2::CalculateArea(glm::vec3 A, glm::vec3 B, glm::vec3 C) {
    glm::vec3 ab = glm::vec3(B.x - A.x, 0, B.z - A.z);
    glm::vec3 ac = glm::vec3(C.x - A.x, 0, C.z - A.z);
    double cross_prod = double(ab.x * ac.z - ab.z * ac.x);
    return abs(cross_prod) / 2;
}

bool Tema2::InsideTriangle(glm::vec3 A, glm::vec3 B, glm::vec3 C, glm::vec3 P) {
    double area = CalculateArea(A, B, C);
    double areaSum = 0;
    double epsilon = 0.001;
    areaSum = areaSum + CalculateArea(A, B, P);
    areaSum = areaSum + CalculateArea(A, C, P);
    areaSum = areaSum + CalculateArea(B, C, P);
 
    if (abs(area - areaSum) <= epsilon) {
        return true;
    }
    return false;
}

bool Tema2::InsidePath(glm::vec3 P) {
    bool out = false;
    for (int i = 0; i < 70; i++) {
     
        if (InsideTriangle(pointsRed[i], pointsBlue[i], pointsRed[i + 1], P) == true) {
            out = true;
       
        }

        if (InsideTriangle(pointsRed[i], pointsBlue[i + 1], pointsBlue[i], P) == true) {

            out = true;
        }

        if (InsideTriangle(pointsRed[i], pointsBlue[i + 1], pointsRed[i + 1], P) == true) {
            out = true;

        }

        if (InsideTriangle(pointsRed[i+1], pointsBlue[i + 1], pointsBlue[i], P) == true) {

            out = true;
        }
    }

    if (InsideTriangle(pointsRed[70], pointsBlue[70], pointsBlue[0], P) == true) {
        out = true;
    }

    if (InsideTriangle(pointsRed[70], pointsBlue[0], pointsRed[0], P) == true) {
        out = true;
    }
   
    return out;
}

void Tema2::OnInputUpdate(float deltaTime, int mods)
{
    float speed = 10.0f;
    float offset = 0.25f;
    float speed_teleporter_reducer = 2.0f;
    if (!window->MouseHold(GLFW_MOUSE_BUTTON_RIGHT))
    {
        if (window->KeyHold(GLFW_KEY_W)) {
            
            trZ -= (speed / speed_teleporter_reducer) * cos(rotation_angle_OY) * deltaTime;
            trX -= (speed / speed_teleporter_reducer) * sin(rotation_angle_OY) * deltaTime;
          
            glm::vec3 var = glm::vec3(trX + offset * 2, 0, trZ + offset );
           if (InsidePath(var) == true) {
               translateZ = trZ;
               translateX = trX;
           }
        }

        if (window->KeyHold(GLFW_KEY_A)) {
            if (window->KeyHold(GLFW_KEY_W)) {
                rotation_angle_OY += deltaTime;
            }
            else if (window->KeyHold(GLFW_KEY_S)) {
                rotation_angle_OY -= deltaTime;
            }
            else {
                rotation_angle_OY += deltaTime;
            }
        }

        if (window->KeyHold(GLFW_KEY_S)) {
            trZ += (speed / speed_teleporter_reducer) * cos(rotation_angle_OY) * deltaTime;
            trX += (speed / speed_teleporter_reducer) * sin(rotation_angle_OY) * deltaTime;

            glm::vec3 var = glm::vec3(trX + offset * 2
                , 0, trZ + offset);
            if (InsidePath(var) == true) {
                translateZ = trZ;
                translateX = trX;
            }
        }

        if (window->KeyHold(GLFW_KEY_D)) {
            if (window->KeyHold(GLFW_KEY_W)) {
                rotation_angle_OY -= deltaTime;
            }
            else if (window->KeyHold(GLFW_KEY_S)) {
                rotation_angle_OY += deltaTime;
            }
            else {
                rotation_angle_OY -= deltaTime;
            }

        }
    }

    if (window->MouseHold(GLFW_MOUSE_BUTTON_RIGHT))
    {
        float cameraSpeed = 2.0f;

        if (window->KeyHold(GLFW_KEY_W)) {
            camera->MoveForward(deltaTime * cameraSpeed);
        }

        if (window->KeyHold(GLFW_KEY_A)) {
            camera->TranslateRight(-deltaTime * cameraSpeed);
        }

        if (window->KeyHold(GLFW_KEY_S)) {
            camera->MoveForward(-deltaTime * cameraSpeed);
        }

        if (window->KeyHold(GLFW_KEY_D)) {
            camera->TranslateRight(deltaTime * cameraSpeed);
        }

        if (window->KeyHold(GLFW_KEY_Q)) {
            camera->TranslateUpward(-deltaTime * cameraSpeed);
        }
        if (window->KeyHold(GLFW_KEY_E)) {
            camera->TranslateUpward(deltaTime * cameraSpeed);
        }
    }



}


void Tema2::OnKeyPress(int key, int mods)
{
    // Add key press event
    if (key == GLFW_KEY_T)
    {
        renderCameraTarget = !renderCameraTarget;
    }

    if (window->KeyHold(GLFW_KEY_O)) {
        float  orthoLeft = -50;
        float  orthoRight = 50;
        float  orthoUp = 4;
        float  orthoDown = -2;
        projectionMatrix = glm::ortho(orthoLeft, orthoRight, orthoDown, orthoUp, Z_NEAR, Z_FAR);

    }
}




void Tema2::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    // Add mouse move event

    if (window->MouseHold(GLFW_MOUSE_BUTTON_RIGHT))
    {
        float sensivityOX = 0.001f;
        float sensivityOY = 0.001f;

        if (window->GetSpecialKeyState() == 0) {
            renderCameraTarget = false;
            // TODO(student): Rotate the camera in first-person mode around
            // OX and OY using `deltaX` and `deltaY`. Use the sensitivity
            // variables for setting up the rotation speed.
            camera->RotateFirstPerson_OX(-2 * sensivityOX * deltaY);
            camera->RotateFirstPerson_OY(-2 * sensivityOY * deltaX);

        }

        if (window->GetSpecialKeyState() & GLFW_MOD_CONTROL) {
            renderCameraTarget = true;
            // TODO(student): Rotate the camera in third-person mode around
            // OX and OY using `deltaX` and `deltaY`. Use the sensitivity
            // variables for setting up the rotation speed.
            camera->RotateThirdPerson_OX(-2 * sensivityOX * deltaY);
            camera->RotateThirdPerson_OY(-2 * sensivityOY * deltaX);

        }
    }

}

// N/A
void Tema2::OnKeyRelease(int key, int mods)
{
}


void Tema2::FrameEnd()
{
}

void Tema2::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
}

void Tema2::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
}

void Tema2::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}

void Tema2::OnWindowResize(int width, int height)
{
}