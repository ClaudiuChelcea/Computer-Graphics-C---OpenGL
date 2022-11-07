#ifndef __DUCK_H
#define __DUCK_H

#pragma once

#include "lab_m1/Tema1/Triangle.h"
#include "lab_m1/Tema1/Circle.h"

class Duck {
private:
	Mesh* body{ NULL }; // The body of the duck
	Mesh* wingLeft{ NULL }; // The left wing of the duck
	Mesh* wingRight{ NULL }; // The right wing of the duck
	Mesh* head { NULL }; // The head of the duck
	Mesh* beak { NULL }; // The beak of the duck
public:
	// Constructor
	Duck() = default;
	void createDuck();

	// Getters
	Mesh* getBody();
	std::string getBodyString();
	Mesh* getWingLeft();
	std::string getWingLeftString();
	Mesh* getWingRight();
	std::string getWingRightString();
	Mesh* getHead();
	std::string getHeadString();
	Mesh* getBeak();
	std::string getBeakString();
};

#endif // __DUCK_H
