#include "VectorOfFloat.h"

int main()
{
	std::vector<float> vect = GetVectorOfFloatFromStream(std::cin);
	MultiplyVectorOfFloatByMinElement(vect);
	std::sort(vect.begin(), vect.end());
	PrintVectorOfFloatToStream(std::cout, vect);
}