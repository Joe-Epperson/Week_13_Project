// Joe Epperson, IV
// jee4cf@umsystem.edu
// Lab13
// 4/19/2021

#include <iostream>
#include <vector>
using namespace std;

// Function declarations
int factorial_r(int usrInput);
int fibonacci_r(int usrInput);
bool is_prime_r(int value, int usrInput);
int sum_r(int list[], int list_size);
void output_reverse_list_r(int list[], int list_size);

int main() {

	//cout << factorial_r(5);
	//cout << fibonacci_r(22);
	//cout << is_prime_r(90, 2);
	//const int list_size = 5;
	//int list[list_size];
	//list[0] = 1;
	//list[1] = 2;
	//list[2] = 8;
	//list[3] = 9;
	//list[4] = 8;
	//cout << sum_r(list, list_size);
	//output_reverse_list_r(list, list_size);

	int usrValue;
	bool primeVal;
	const int list_size = 5;
	int list[list_size];

	//Getting the value that the user input
	cout << "Enter an integer" << endl;
	cin >> usrValue;
	cout << endl;

	// Using that value to find the factorial and the fibonacci value
	cout << usrValue << "! = " << factorial_r(usrValue) << endl << endl;
	cout << "fibonacci(" << usrValue << ") = " << fibonacci_r(usrValue) << endl << endl;

	// Finding out if a user entered value is prime
	cout << "Enter a number to see if it is a prime number: " << endl;
	cin >> usrValue;
	cout << endl;
	
	primeVal = is_prime_r(usrValue, 2);
	// If is_prime_r returns true, the if-else will output that it is prime, if not it will output it is not prime
	if (primeVal)
	{
		cout << usrValue << " is a prime number." << endl << endl;
	}
	else
	{
		cout << usrValue << " is not a prime number." << endl << endl;
	}


	cout << "Next we will enter 5 values into an array" << endl;

	// Filling the array
	for (int i = 0; i < list_size; ++i)
	{
		cout << "Enter a value for index " << i << endl;
		cin >> list[i];
	}
	cout << endl;

	//Using the user entered array and list size to calculate the sum and output it backwards
	cout << "The sum of all of the values is " << sum_r(list, list_size) << endl << endl;
	cout << "The list output in reverse is:" << endl;
	output_reverse_list_r(list, list_size);
	cout << endl;


	return 0;
}

// Function definitions
int factorial_r(int usrInput)
{
	if (usrInput == 0)
	{
		return 1;
	}
	else
	{
		return (usrInput * factorial_r(usrInput - 1));
	}
}

int fibonacci_r(int usrInput)
{
	if (usrInput == 0)
	{
		return 0;
	}
	else if (usrInput == 1)
	{
		return 1;
	}
	else
	{
		return (fibonacci_r(usrInput - 1) + fibonacci_r(usrInput - 2));
	}
}

bool is_prime_r(int value, int usrInput)
{
	if (usrInput > sqrt(value))
	{
		return true;
	}
	else if ((value % usrInput) == 0)
	{
		return false;
	}
	is_prime_r(value, usrInput + 1);
}

int sum_r(int list[], int list_size)
{
	if (list_size == 0)
	{
		return 0;
	}
	else
	{
		return (list[list_size - 1] + (sum_r(list, list_size - 1)));
	}
}

void output_reverse_list_r(int list[], int list_size)
{
	if (list_size > 1)
	{
		cout << list[list_size - 1] << " ";
	}
	else if (list_size == 0)
	{
		cout << list[0];
	}
	if (list_size > 0)
	{
		output_reverse_list_r(list, list_size - 1);
	}
}