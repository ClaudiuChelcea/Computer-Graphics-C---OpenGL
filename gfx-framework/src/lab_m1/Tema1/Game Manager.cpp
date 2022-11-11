#include "Game Manager.h"

using namespace GameManager;

/* Duck */
// create a duck (only one can exist at a time)
void DuckManager::createDuck(std::pair<float, float> startingBodyPosition)
{
	if (this->my_duck == NULL) {
		my_duck = new Duck();
		my_duck->createDuck();

		// Set starting coordinates
		my_duck->setBodyPosition(startingBodyPosition);
		my_duck->setBodyRotation(PI);
	}
	else {
		std::cerr << "Duck is already alive!\n";
	}
}

// Getters
Duck* DuckManager::getDuckAlive()
{
	return my_duck;
}

std::pair<int, int> DuckManager::getSpawnPoint()
{
	return spawnPoint;
}

std::vector<std::pair<int, int>>& DuckManager::getSpawnPoints()
{
	return spawnPoints;
}

// Setters
void DuckManager::setSpawnPoint(std::pair<int, int> _spawnPoint)
{
	spawnPoint.first = _spawnPoint.first;
	spawnPoint.second = _spawnPoint.second;
}


/* UI */

UI::UI()
{
	// Create ground
	this->ground = Rectangle::CreateRectangle("ground", glm::vec3(0.0f, 0.0f, 0.0f), 300.0f, 1280.0f, glm::vec3(0.2f, 0.98f, 0.59f), true);

	// Create sky
	this->sky = Rectangle::CreateRectangle("sky", glm::vec3(0.0f, 0.0f, 0.0f), 500.0f, 1280.0f, glm::vec3(0.0f, 1.0f, 1.0f), true);

	// Create life 1
	this->life1 = Circle::CreateCircle("life1", glm::vec3(0.0f, 0.0f, 0.0f), 30.0f, 100, glm::vec3(1.0f, 0.0f, 0.0f));

	// Create life 2
	this->life2 = Circle::CreateCircle("life2", glm::vec3(0.0f, 0.0f, 0.0f), 30.0f, 100, glm::vec3(1.0f, 0.0f, 0.0f));

	// Create life 3
	this->life3 = Circle::CreateCircle("life3", glm::vec3(0.0f, 0.0f, 0.0f), 30.0f, 100, glm::vec3(1.0f, 0.0f, 0.0f));

	// Create bullet 1
	this->bullet1 = Rectangle::CreateRectangle("bullet1", glm::vec3(0.0f, 0.0f, 0.0f), 50.0f, 25.0f, glm::vec3(0.0f, 0.0f, 0.0f), false);

	// Create bullet 2
	this->bullet2 = Rectangle::CreateRectangle("bullet2", glm::vec3(0.0f, 0.0f, 0.0f), 50.0f, 25.0f, glm::vec3(0.0f, 0.0f, 0.0f), false);

	// Create bullet 3
	this->bullet3 = Rectangle::CreateRectangle("bullet3", glm::vec3(0.0f, 0.0f, 0.0f), 50.0f, 25.0f, glm::vec3(0.0f, 0.0f, 0.0f), false);
}

// Ground
std::string UI::getGroundString()
{
	return "ground";
}

Mesh* UI::getGround()
{
	return ground;
}

// Sky
std::string UI::getSkyString()
{
	return "sky";
}

Mesh* UI::getSky()
{
	return sky;
}

// Lives
Mesh* UI::getLife1()
{
	return life1;
}

std::string UI::getLife1String()
{
	return "life1";
}

Mesh* UI::getLife2()
{
	return life2;
}

std::string UI::getLife2String()
{
	return "life2";
}

Mesh* UI::getLife3()
{
	return life3;
}

std::string UI::getLife3String()
{
	return "life3";
}

// Bullets
Mesh* UI::getBullet1()
{
	return bullet1;
}

std::string UI::getBullet1String()
{
	return "bullet1";
}

Mesh* UI::getBullet2()
{
	return bullet2;
}

std::string UI::getBullet2String()
{
	return "bullet2";
}

Mesh* UI::getBullet3()
{
	return bullet3;
}

std::string UI::getBullet3String()
{
	return "bullet3";
}