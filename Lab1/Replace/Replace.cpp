#include <iostream>

int main(int argc, char* argv[])
{
	/*
		1) replace.exe <input file> <output file> <search string> <replace string>
		2) построчно
		3) длина искомой строки равна 0 = не будет замены
		4) замена строки «ма» на «мама» не должна приводить к зацикливанию
		5) замена подстроки «1231234» внутри текста «12312312345»
	*/

	std::cout << "Hello world!";
	return 0;
}