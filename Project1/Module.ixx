#include <iostream>
#include <string>
using namespace std;
double Add(double num1, double num2) {
	double answer = num1 + num2;
	return answer;
}
double Subtract(double num1, double num2) {
	double answer = num1 - num2;
	return answer;
}
double Multiply(double num1, double num2) {
	double answer = num1 * num2;
	return answer;
}
double Divide(double num1, double num2) {
	double answer = num1 / num2;
	return answer;
}
double Exponent(double num1, double num2) {
	double answer = pow(num1, num2);
	return answer;
}
double Root(double num1 , double num2) {
	double answer = pow(num1, 1.0 / num2);
	return answer;
}


int main() {
	int userInput = 0;
	double num1 = 0;
	double num2 = 0;
	double answer = 0;
	int next = 0;
	int answerValid = 0;
	string op[99] = { 
	"Addition", "Subtraction", "Multiplication", "Division",
	"Exponent", "Root"
	};

	//user interface

	do {
		std::cout << "Calculator\n\tAddition:1\n\tSubtraction:2\n\tMultiplication:3\n\tDivision:4\n\tExponent:5\n\tRoot:6\n";
		std::cin >> userInput;
		if (userInput < 1 || userInput > 6) {
			std::cout << "Invalid input\n";
			std::cout << "Press 1 to restart.\n";
			continue;
		}
		else {
			std::cout << "You entered " << userInput << "\n" << op[userInput - 1] << "\n" << "Enter 2 numbers\n";
		}
		std::cin >> num1 >> num2;

		//Calculate

		if (userInput == 1) {
			answer = Add(num1, num2);
		} else if (userInput == 2) {
			answer = Subtract(num1, num2);
		} else if (userInput == 3) {
			answer = Multiply(num1, num2);
		} else if (userInput == 4) {
			if (num2 == 0) {
				std::cout << "Can not divide by 0.\n";
				answerValid = 1;
			} else {
				answer = Divide(num1, num2);
			}
		} else if (userInput == 5) {
			if (num2 == 0) {
				answer = 1;
			} else {
				answer = Exponent(num1, num2);
			}
		} else if (userInput == 6) {
			if (num2 == 0) {
				std::cout << "Can not root by 0.\n";
				answerValid = 1;
			} else {
				answer = Root(num1, num2);
			}
		} else {
			std::cout << "Wrong Number!\n";
			return 1;
		}
		if (answerValid == 0) {
			std::cout << answer << "\n";
		}
		//Loop / End Program
		
		std::cout << "Press 1 to restart.\n";
	} while ((std::cin >> next) && (next == 1));
	std::cout << "Exiting Calculator...\n";
	return 0;
}