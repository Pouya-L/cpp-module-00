#include <iostream>
#include <string>

int	main()
{
	int	Number = 42;
	int	Number_2 = 0;
	int	Sum = 0;
	int	Diff = 0;
	int	Retry = 0;
	std::string Op_code;

	std::cout << "Hello world" << std::endl;
	std::cout << Number << std::endl;
	std::cout << "What is your favorite number? ";
	std::cin >> Number;
	if (Number % 2)
		std::cout << "Your number: " << Number << " is an odd number" << std::endl;
	else
		std::cout << "Your number: " << Number << " is an even number" << std::endl;
	std::cout << "Give me another number? ";
	std::cin >> Number_2;
	Sum = Number + Number_2;
	Diff = Number - Number_2;
	do
	{
		std::cout << "What operation would you like to do between these two numbers? ";
		std::cin >> Op_code;
		if (Op_code == "+")
		{
			std::cout << "The sum of the numbers is " << Sum << std::endl;
			Retry = 0;
		}
		else if (Op_code.compare("-") == 0)
		{
			std::cout << "The subtraction of the second number from the first one is " << Diff << std::endl;
			Retry = 0;
		}
		else if (Op_code == "*")
		{
			std::cout << "The multiplication of the numbers is " << (Number * Number_2) << std::endl;
			Retry = 0;
		}
		else if (Op_code == "/")
		{
			std::cout << "The division of the first number by the second number is " << (Number / Number_2) << std::endl;
			Retry = 0;
		}
		else
		{
			std::cout << "Not acceptable operation use '+, -, *, or /'" <<  std::endl;
			Retry = 1;
		}
	} while (Retry != 0);
	return (0);
}
