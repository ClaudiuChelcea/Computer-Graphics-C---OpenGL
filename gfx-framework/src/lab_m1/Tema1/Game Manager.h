#ifndef __GAME_MANAGER_H
#define __GAME_MANAGER_H

#pragma once

#include <iostream>
#include "components/simple_scene.h"
#include "transform2D.h"
#include "lab_m1/Tema1/Duck.h"

namespace GameManager
{
	class DuckManager {
		private:
			Duck* my_duck = NULL;
			//glm::mat3 duck_StartingPosition{ 1 }; // the starting position of the duck

		public:
			// default constructor
			DuckManager() {}; 

			// create a duck (only one can exist at a time)
			void createDuck(std::pair<float, float> startingBodyPosition);

			// Getters
			Duck* getDuckAlive();

			// Setters
	};

	class myMath
	{
	public:
		static float degreesToRadians(float degrees) {
			int new_PI = acos(-1);
			return degrees * new_PI / 100;
		}

		static float radiansToDegrees(float radians) {
			return (180 / PI) * radians;
		}
	};
};

#endif // __GAME_MANAGER_H


