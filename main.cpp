#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include "Payroll.h"

using namespace std;

// I can't figure out how to use the stringstream example posted in blackboard to loop 3 times.

int _tmain(int argc, _TCHAR* argv[])
{
	enum paymentMethod { Hourly = 72, Salary = 83 };
	string first_name, last_name;
	int reg_hours, ot_hours, total_hours, i = 0;
	double hourly_pay_rate, salary, gross_pay;
	char c;

	for (int i = 0; i < 3; i++)
	{
		cout << "Please enter your first name: ";
		cin >> first_name;
		cout << "Please enter your last name: ";
		cin >> last_name;
		cout << "Please designate your method of payment." << endl;
		cout << "H = Hourly" << endl;
		cout << "S = Salary" << endl;
		cin >> c;
		cout << endl;
		while (!(int(c) == 72 || (int(c) == 83)))
		{
			cout << "Error: You entered an incorrect character. Please try again." << endl;
			cout << "Please designate your method of payment." << endl;
			cout << "H = Hourly" << endl;
			cout << "S = Salary" << endl;
			cin >> c;
			cout << endl;
		}

		if (int(c) == 72)
		{
			cout << "Hourly Employee Verified" << endl;
			cout << endl;
			cout << "How many total hours did you work? ";
			cin >> total_hours;
			cout << endl;
			while ((total_hours <= 0) || (total_hours >= 60))
			{
				cout << "Error: Please enter a value greater than 0 and less than 60." << endl;
				cin >> total_hours;
				cout << endl;
			}

			cout << "What is your hourly pay rate? ";
			cin >> hourly_pay_rate;
			cout << endl;
			while ((hourly_pay_rate <= 0) || (hourly_pay_rate >= 50))
			{
				cout << "Error: Please enter a value greater than 0 and less than 50." << endl;
				cin >> hourly_pay_rate;
				cout << endl;
			}

			reg_hours = get_reg_hours(total_hours);
			ot_hours = get_ot_hours(total_hours);
			gross_pay = get_gross_pay(reg_hours, ot_hours, hourly_pay_rate);
		}


		else if (int(c) == 83)
		{
			cout << "Salaried Employee Verified" << endl;
			cout << endl;
			cout << "What is your yearly salary? ";
			cin >> salary;
			cout << endl;
			while ((salary < 20000) || (salary > 100000))
			{
				cout << "Error: Please enter a value of at least 20,000 with a maximum of 100,000." << endl;
				cin >> salary;
				cout << endl;
			}

			gross_pay = get_gross_pay(salary);
		}

		if (int(c) == 72)
		{
			cout << right << setw(16) << "Name: " << setw(8) << first_name << " " << last_name;
			show_check_hourly(gross_pay, reg_hours, ot_hours);
		}

		else if (int(c) == 83)
		{
			cout << right << setw(16) << "Name: " << setw(8) << first_name << " " << last_name;
			show_check_salary(gross_pay);
		}

		else
			cout << "Invalid entry." << endl;
	}

	return 0;
}
