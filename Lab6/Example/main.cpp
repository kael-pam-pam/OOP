#include "CObject.h"
#include "CFunctionCall.h"
#include "CMyException.h"
#include "CSomeClass.h"
#include <iostream>

void SayHello()
{
	CFunctionCall sayHello("SayHello()");
	std::cout << "HELLO!\n";
}

void Function2()
{
	CFunctionCall fn("Function2()");
	CObject obj4("obj4");
	CObject *pObj5 = new CObject("pObj5");
	std::cout << "Throwing an exception\n";
	throw CMyException();
}

void Function1()
{
	CFunctionCall fn("Function1()");
	CObject obj2("obj2");
	{
		CObject obj3("obj3");
	}
	Function2();
}

int main()
{
	CObject object1("object1");
	{
		CObject object2("object2");
		CObject object3("object3");
	}
	CObject object4("object4");
	CObject *pObject5 = new CObject("pObject5");
	std::cout << "\n\n";


	CFunctionCall main("main()");
	SayHello();
	std::cout << "\n\n";


	try
	{
		throw CMyException();
	}
	catch (const CMyException& e)
	{
		std::cout << "Caught CMyException. Copy # is " << e.GetCopyIndex() << "\n";
	}
	std::cout << "\n\n";


	CFunctionCall fn("main()");
	try
	{
		CObject obj1("obj1");
		Function1();
	}
	catch (const CMyException& e)
	{
		std::cout << "CMyException is caught. Copy #" << e.GetCopyIndex() << "\n";
	}
	std::cout << "\n\n";


	try
	{
		CSomeClass someObject(-1);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
	std::cout << "\n\n";


	return 0;
}


/*
	Контролируемый блок-функцию можно объявить не только в конструкторе, но и в любом методе класса или функции. 
	Например, для перехвата всех исключений нашего приложения можно записать следующий вариант функции main():

	int main(int argc, char * argv[])
	try
	{
		// тело функции main
		// ...
		return 0;
	}
	catch (std::exception const& e)
	{
		std::cout << "Error: " << e.what() << "\n";
		return 1;
	}
	catch (...)
	{
		std::cout << "Unknown exception has been caught\n";
		return 2;
	}
*/