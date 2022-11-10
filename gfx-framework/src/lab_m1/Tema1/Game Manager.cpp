#include "Game Manager.h"

using namespace GameManager;

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

std::pair<int, int> DuckManager::getSpawnPoint() {
	return spawnPoint;
}

std::vector<std::pair<int, int>>& DuckManager::getSpawnPoints() {
	return spawnPoints;
}

// Setters
void DuckManager::setSpawnPoint(std::pair<int, int> _spawnPoint) {
	spawnPoint.first = _spawnPoint.first;
	spawnPoint.second = _spawnPoint.second;
}