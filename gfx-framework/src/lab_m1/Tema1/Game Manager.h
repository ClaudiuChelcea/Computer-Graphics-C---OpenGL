#ifndef __GAME_MANAGER_H
#define __GAME_MANAGER_H

#pragma once

#include <iostream>
#include "components/simple_scene.h"
#include "transform2D.h"
#include "Duck.h"

namespace GameManager
{
	class DuckManager {
		private:
			Duck* my_duck = NULL;
			std::pair<int, int> spawnPoint{ 0, 0 };
			std::vector<std::pair<int, int>> spawnPoints;

		public:
			// default constructor
			DuckManager() {}; 

			// create a duck (only one can exist at a time)
			void createDuck(std::pair<float, float> startingBodyPosition);

			// Getters
			Duck* getDuckAlive();
			std::pair<int, int> getSpawnPoint();
			std::vector<std::pair<int, int>>& getSpawnPoints();

			// Setters
			void setSpawnPoint(std::pair<int, int> _spawnPoint = { 0, 0 });
	};

	class myMath
	{
		public:
			static float degreesToRadians(float degrees) {
				return degrees * PI / 180;
			}

			static float radiansToDegrees(float radians) {
				return (180 / PI) * radians;
			}
	};

	class UI
	{
		private:
			// Ground
			Mesh* ground;

		public:
	};
};

#endif // __GAME_MANAGER_H


