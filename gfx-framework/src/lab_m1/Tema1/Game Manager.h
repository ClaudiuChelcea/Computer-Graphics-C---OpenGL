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
};

#endif // __GAME_MANAGER_H


