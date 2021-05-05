#include "Ccar.h"
#include "CDashboard.h"
#include <iostream>

int main()
{
	CCar car;

	CDashboard dashboard(car, std::cin, std::cout);

	while (!std::cin.eof() && !std::cin.fail())
	{
		std::cout << "> ";
		if (!dashboard.HandleCommand())
		{
			std::cout << "Unknown command!\n";
		}
	}
	return 0;
}
