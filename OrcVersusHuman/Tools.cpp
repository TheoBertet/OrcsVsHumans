// Tools.cpp
// Author : Théo Bertet
// Description : This file contains all the methods for the tools methods used in all the code.
#include <random>
#include "Tools.h"

/// <summary>
/// Generate a random int betwen two values
/// </summary>
/// <param name="min">The minimum value for the random int</param>
/// <param name="max">The maximum value for the random int</param>
/// <returns>A random int between the min and max values</returns>
int Tools::Random(int min, int max)
{
	if (min > max)
	{
		min = min + max;
		max = min - max;
		min = min - max;
	}

	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(min, max);

	return dist(rng);
}
