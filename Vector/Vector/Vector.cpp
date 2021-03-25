#include <iostream>
#include <vector>
#include "Vector.h"

//6 вариант
int main()
{
	std::vector<float> inputVector;

	if (!ParseVector(std::cin, inputVector))
	{
		std::cout << "Invalid input data or empty input" << std::endl;
		return 1;
	}

	if (inputVector.empty())
	{
		return 0;
	}

	// Multiple every vector element by max element and divide every vector element by min element
	ProcessVector(inputVector);
	
	// Vector sorting
	std::sort(inputVector.begin(), inputVector.end());

	// Copying vector to the output
	copy(inputVector.begin(), inputVector.end(), std::ostream_iterator<float>(std::cout, " "));

	return 0;
}