#include "lab_m1/Tema1/Duck.h"

// Constructor
void Duck::createDuck()
{
	// Create body
	this->body = Triangle::CreateTriangle("body", glm::vec3 (0.0f, 0.0f, 0.0f), 80.0f, glm::vec3(0.0, 0.74f, 1.0f));

	// Create wingLeft
	this->wingLeft = Triangle::CreateTriangle("wingLeft", glm::vec3(0.0f, 0.0f, 0.0f), 50.0f, glm::vec3(0.0, 0.74f, 1.0f));

	// Create wingRight
	this->wingRight = Triangle::CreateTriangle("wingRight", glm::vec3(0.0f, 0.0f, 0.0f), 50.0f, glm::vec3(0.0, 0.74f, 1.0f));

	// Create head
	this->head = Circle::CreateCircle("head", glm::vec3(0.0f, 0.0f, 0.0f), 50.0f, 100.0f);

	// Create beak
	this->beak = Triangle::CreateTriangle("beak", glm::vec3(0.0f, 0.0f, 0.0f), 10.0f, glm::vec3(0.0, 0.74f, 1.0f));
}

/* Getters */
// Body
Mesh* Duck::getBody() {
	return body;
}

std::string Duck::getBodyString()
{
	return std::string("body");
}

std::pair<float, float> Duck::getBodyPosition()
{
	return bodyPos;
}

float Duck::getBodyRotation() {
	return this->bodyRotation;
}

// Wing Left
Mesh* Duck::getWingLeft() {
	return wingLeft;
}

std::string Duck::getWingLeftString()
{
	return std::string("wingLeft");
}

// Wing Right
Mesh* Duck::getWingRight() {
	return wingRight;
}

std::string Duck::getWingRightString()
{
	return std::string("wingRight");
}

// Head
Mesh* Duck::getHead() {
	return head;
}

std::string Duck::getHeadString()
{
	return std::string("head");
}

// Beak
Mesh* Duck::getBeak() {
	return beak;
}

std::string Duck::getBeakString()
{
	return std::string("beak");
}

/* Setters */
// Body
void Duck::setBodyPosition(std::pair<float, float> position)
{
	this->bodyPos.first = position.first;
	this->bodyPos.second = position.second;
}

void Duck::setBodyRotation(float radians)
{
	this->bodyRotation = radians;
}

