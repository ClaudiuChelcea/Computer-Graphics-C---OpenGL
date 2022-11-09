#include "lab_m1/Tema1/Duck.h"

// Constructor
void Duck::createDuck()
{
	// Create body
	this->body = Triangle::CreateTriangle("body", glm::vec3 (0.0f, 0.0f, 0.0f), 90.0f, glm::vec3(0.0, 0.74f, 1.0f));

	// Create wingLeft
	this->wingLeft = Triangle::CreateTriangle("wingLeft", glm::vec3(0.0f, 0.0f, 0.0f), 45.0f, glm::vec3(0.4f, 0.6f, 0.4f));

	// Create wingRight
	this->wingRight = Triangle::CreateTriangle("wingRight", glm::vec3(0.0f, 0.0f, 0.0f), 45.0f, glm::vec3(0.4f, 0.6f, 0.4f));

	// Create head
	this->head = Circle::CreateCircle("head", glm::vec3(0.0f, 0.0f, 0.0f), 50.0f, 100.0f, glm::vec3(0.8f, 0.1f, 0.9f));

	// Create beak
	this->beak = Triangle::CreateTriangle("beak", glm::vec3(0.0f, 0.0f, 0.0f), 15.0f, glm::vec3(0.6f, 0.3f, 0.8f));

	// Create hitbox
	this->hitbox = Rectangle::CreateRectangle("hitbox", glm::vec3(0.0f, 0.0f, 0.0f), 125.0f, 125.0f, glm::vec3(0.6f, 0.3f, 0.8f));

	// Calculate gravity center
	gravityCenter.first = (0 + 125) / 2;
	gravityCenter.second = (0 + 125) / 2;
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

std::pair<float, float> Duck::getLeftWingBodyOffset()
{
	return this->leftWingBodyOffset;
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

std::pair<float, float> Duck::getRightWingBodyOffset()
{
	return this->rightWingBodyOffset;
}

// Head
Mesh* Duck::getHead() {
	return head;
}

std::string Duck::getHeadString()
{
	return std::string("head");
}

std::pair<float, float> Duck::getHeadBodyOffset()
{
	return this->headBodyOffset;
}

// Beak
Mesh* Duck::getBeak() {
	return beak;
}

std::string Duck::getBeakString()
{
	return std::string("beak");
}

std::pair<float, float> Duck::getBeakBodyOffset()
{
	return this->beakBodyOffset;
}

// Hitbox
Mesh* Duck::getHitbox() {
	return hitbox;
}

std::string Duck::getHitboxString()
{
	return std::string("hitbox");
}

std::pair<float, float> Duck::getHitboxBodyOffset()
{
	return this->hitboxBodyOffset;
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

