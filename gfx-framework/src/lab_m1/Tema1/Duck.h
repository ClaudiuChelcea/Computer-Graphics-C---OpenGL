#ifndef __DUCK_H
#define __DUCK_H

#pragma once

#include "lab_m1/Tema1/Triangle.h"
#include "lab_m1/Tema1/Circle.h"

class Duck {
private:
	// Body
	Mesh* body{ NULL }; // The body of the duck
	std::pair<float, float> bodyPos{ 0, 0 };
	float bodyRotation{ 0.0f };

	// Wing Left
	Mesh* wingLeft{ NULL }; // The left wing of the duck

	// Wing Right
	Mesh* wingRight{ NULL }; // The right wing of the duck

	// Head
	Mesh* head { NULL }; // The head of the duck

	// Beak
	Mesh* beak { NULL }; // The beak of the duck
public:
	// Constructor
	Duck() = default;

	// Create default duck
	void createDuck();

	/* Getters */
	// Body
	Mesh* getBody();
	std::string getBodyString();
	std::pair<float, float> getBodyPosition();
	float getBodyRotation();

	// Wing Left
	Mesh* getWingLeft();
	std::string getWingLeftString();

	// Wing Right
	Mesh* getWingRight();
	std::string getWingRightString();

	// Head
	Mesh* getHead();
	std::string getHeadString();

	// Beak
	Mesh* getBeak();
	std::string getBeakString();
	
	/* Setters */
	// Body
	void setBodyPosition(std::pair<float, float> position);
	void setBodyRotation(float radians);
};

#endif // __DUCK_H
