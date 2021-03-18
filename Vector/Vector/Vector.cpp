#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <optional>

bool ParseVector(std::istream& inStrm, std::vector<float>& vec)
{
	std::string str;

	while (inStrm >> str)
	{
		std::istringstream strm(str);
		float num;
		if (strm >> num)
		{
			vec.push_back(num);
		}
		else
		{
			return false;
		}
	}

	return !vec.empty();
}

bool ProcessVector(std::vector<float>& vec)
{
	auto max = std::max_element(std::begin(vec), std::end(vec));
	auto min = std::min_element(std::begin(vec), std::end(vec));

	std::for_each(vec.begin(), vec.end(), [](auto max, auto min) { ; };

	return true;
}

//6 вариант
int main()
{
	

	return 0;
}