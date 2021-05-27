#include "CDashboard.h"
#include <iostream>

int main()
{
	CDashboard dashboard(std::cin, std::cout);

	while (!std::cin.eof() && !std::cin.fail())
	{
		std::cout << "> ";
		if (!dashboard.HandleCommand())
		{
			std::cout << "Unknown command\n";
		}
	}
	dashboard.PrintShapeWithMaxArea();
	dashboard.PrintShapeWithMinPerimeter();

	return 0;
}
