#include "Math.h"
#include <algorithm>
#include <random>
#include <iostream>

float Math::Range(float value, float minValue, float maxValue) {
	return std::max(minValue, std::min(value, maxValue));
}

float Math::RandomNumber(float min, float max)
{
    std::random_device rd;  // Obtain a random number from hardware
    std::mt19937 gen(rd());  // Seed the generator
    std::uniform_real_distribution<float> dis(min, max);  // Define the range of the random number

    return dis(gen);
}