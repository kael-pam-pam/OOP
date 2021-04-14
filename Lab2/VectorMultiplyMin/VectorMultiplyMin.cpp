#include "VectorOfFloat.h"

int main()
{
	std::vector<float> vect = GetVectorOfFloatFromStream(std::cin);
	PrintVectorOfFloatToStream(std::cout, SortVectorOfFloat(MultiplyVectorOfFloatByMinElement(vect)));
}