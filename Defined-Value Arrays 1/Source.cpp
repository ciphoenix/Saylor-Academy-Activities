#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int year;
int DaysInMonths[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
string MonthNames[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

bool isLeapYear(int year);
void displayName(int month);
void buildArray(int year);



int main()
{
	cout << "Enter a Year: ";
	cin >> year;
	string remark = isLeapYear(year) ? "It's a Leap Year\n" : "It's not a Leap Year\n";
	cout << remark;

	buildArray(year);

	displayName(year);

	return 0;

}


bool isLeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0 && year % 100 == 0))
	{
		return true;
	}
	return false;
}

void buildArray(int year)
{
	if (isLeapYear(year) == true)
		DaysInMonths[1] = 29;

	else if (isLeapYear(year) == false)
		DaysInMonths[1] = 28;
}

void displayName(int year)
{
	int index = 1;

	while (index >= 1 && index <= 12)
	{
		cout << "Enter Month Number: ";
		cin >> index;

		if (index < 1 || index > 12) //Eror Handling
		{
			cout << "Invalid Month Number. Program is exiting...";
			break;
		}

		index -= 1;
		cout << "The Month is " << MonthNames[index] << " and it has " << DaysInMonths[index] << " days." << endl;
		index += 1;
	}


}