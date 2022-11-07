#include "lab_m1/Tema1/Duck.h"

// Constructor
void Duck::createDuck()
{
	// Create body
	this->body = Triangle::CreateTriangle("body", glm::vec3(0.0f, 0.0f, 0.0f), 80.0f, glm::vec3(0.0, 0.74f, 1.0f));

	// Create wingLeft
	this->wingLeft = Triangle::CreateTriangle("wingLeft", glm::vec3(0.0f, 0.0f, 0.0f), 50.0f, glm::vec3(0.0, 0.74f, 1.0f));

	// Create wingRight
	this->wingRight = Triangle::CreateTriangle("wingRight", glm::vec3(0.0f, 0.0f, 0.0f), 50.0f, glm::vec3(0.0, 0.74f, 1.0f));

	// Create head
	this->head = Circle::CreateCircle("head", glm::vec3(0.0f, 0.0f, 0.0f), 50.0f, 100.0f);

	// Create beak
	this->beak = Triangle::CreateTriangle("beak", glm::vec3(0.0f, 0.0f, 0.0f), 10.0f, glm::vec3(0.0, 0.74f, 1.0f));
}

// Getters
Mesh* Duck::getBody() {
	return body;
}

Mesh* Duck::getWingLeft() {
	return wingLeft;
}

Mesh* Duck::getWingRight() {
	return wingRight;
}

Mesh* Duck::getHead() {
	return head;
}

Mesh* Duck::getBeak() {
	return beak;
}

std::string Duck::getBodyString()
{
	return std::string("body");
}

std::string Duck::getWingLeftString()
{
	return std::string("wingLeft");
}

std::string Duck::getWingRightString()
{
	return std::string("wingRight");
}

std::string Duck::getHeadString()
{
	return std::string("head");
}

std::string Duck::getBeakString()
{
	return std::string("beak");
}

