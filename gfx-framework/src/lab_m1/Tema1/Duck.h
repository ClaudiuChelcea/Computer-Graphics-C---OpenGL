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
	std::pair<float, float> leftWingBodyOffset{ 25.0f, 0.0f };

	// Wing Right
	Mesh* wingRight{ NULL }; // The right wing of the duck
	std::pair<float, float> rightWingBodyOffset{ 0.0f, 25.0f }; 

	// Head
	Mesh* head { NULL }; // The head of the duck
	std::pair<float, float> headBodyOffset{ -15.0f, -15.0f };

	// Beak
	Mesh* beak { NULL }; // The beak of the duck
	std::pair<float, float> beakBodyOffset{ -15.0f, -15.0f };
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
	std::pair<float, float> getLeftWingBodyOffset();

	// Wing Right
	Mesh* getWingRight();
	std::string getWingRightString();
	std::pair<float, float> getRightWingBodyOffset();

	// Head
	Mesh* getHead();
	std::string getHeadString();
	std::pair<float, float> getHeadBodyOffset();

	// Beak
	Mesh* getBeak();
	std::string getBeakString();
	std::pair<float, float> getBeakBodyOffset();
	
	/* Setters */
	// Body
	void setBodyPosition(std::pair<float, float> position);
	void setBodyRotation(float radians);
};

#endif // __DUCK_H
