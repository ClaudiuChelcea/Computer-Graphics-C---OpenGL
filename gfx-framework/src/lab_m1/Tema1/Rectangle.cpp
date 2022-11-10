#include "Rectangle.h"

/**
 * Create a rectangle shape
 * @param rectangle_name name given to object
 * @param Corner the corner of the object to start drawing from
 * @param heoght the height of the rectangle
 * @param length the lenght of one side of the rectangle
 * @param color the color used for the rectangle
 * @result A rectangle mesh
 */
Mesh* Rectangle::CreateRectangle(const std::string& rectangle_name, glm::vec3 Corner, float height, float length, glm::vec3 color)
{
    // Create mesh
    Mesh* rectangle = new Mesh(rectangle_name);

    // Set vertices
    std::vector<VertexFormat> vertices =
    {
        VertexFormat(Corner, glm::vec3(0,1,0)),
        VertexFormat(Corner + glm::vec3(length, 0, 0), glm::vec3(0,1,0)),
        VertexFormat(Corner + glm::vec3(length, height, 0), glm::vec3(0,1,0)),
        VertexFormat(Corner + glm::vec3(0, height, 0), glm::vec3(0,1,0))
    };

    std::vector<unsigned int> indices;
    for (int i = 0; i < vertices.size(); ++i) {
        indices.push_back(i);
    }

    // Draw rectangle
    rectangle->SetDrawMode(GL_LINE_LOOP);
    rectangle->InitFromData(vertices, indices);

    return rectangle;
}
