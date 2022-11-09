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
	std::pair<int, int> duckWidth{ -85, 40 }; // LEFT AND RIGHT
	std::pair<int, int> duckHeight{ -85, 40 }; // LEFT AND RIGHT

	// Wing Left
	Mesh* wingLeft{ NULL }; // The left wing of the duck
	std::pair<float, float> leftWingBodyOffset{ 25.0f, 5.0f };

	// Wing Right
	Mesh* wingRight{ NULL }; // The right wing of the duck
	std::pair<float, float> rightWingBodyOffset{ 5.0f, 25.0f };

	// Head
	Mesh* head { NULL }; // The head of the duck
	std::pair<float, float> headBodyOffset{ -15.0f, -15.0f };

	// Beak
	Mesh* beak { NULL }; // The beak of the duck
	std::pair<float, float> beakBodyOffset{ -35.0f, -35.0f };

	// Speed
	float xSpeed{ 10.0f };
	float ySpeed{ 10.0f };

	// Direction
	float travellingAngle{ 45.0f };
	float translateX{ 0.0f };
	float translateY{ 0.0f };

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
	std::pair<int,int> getDuckWidth() { return duckWidth; }
	std::pair<int, int> getDuckHeight() { return duckHeight; }

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

	// Speed
	float getXSpeed() { return xSpeed; }
	float getYSpeed() { return ySpeed; }

	// Direction
	float getTravellingAngle() { return travellingAngle; }
	float getTranslateX() { return translateX; }
	float getTranslateY() { return translateY; }
	
	/* Setters */
	// Body
	void setBodyPosition(std::pair<float, float> position);
	void setBodyRotation(float radians);

	// Speed
	void setXSpeed(float _xSpeed) { xSpeed = _xSpeed; }
	void setYSpeed(float _ySpeed) { ySpeed = _ySpeed; }

	// Direction
	void setTravellingAngle(float _travellingAngle) {travellingAngle = _travellingAngle; }
	void setTranslateX(float _translateX) { translateX = _translateX; }
	void setTranslateY(float _translateY) { translateY = _translateY; }
};

#endif // __DUCK_H
