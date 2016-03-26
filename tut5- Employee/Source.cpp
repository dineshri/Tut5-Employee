#include <iostream>
#include <string>

using namespace std;

int Employee::numberOfEmployees = 0; // initialisation of static variable globally

class Employee {
protected:
	string m_name;
	int Number;
	float m_salary;

public:
    Employee(string em_name, int num = 1, float em_salary = 1.00 ): m_name(em_name), Number(num), m_salary(em_salary) {  } // constructor of base class
	
	string name() {
		return m_name;}   // method name()

	int staffNumber() {
		return Number;}  // method staffNumber()

	float salary(){
		return m_salary;}

	static int numberOfEmployees; // declaration of static member

};

// derived classes starts here

class SalaryEmployee : public Employee {
public:
	SalaryEmployee(string em_name, int num = 1, float em_salary = 1.00) : Employee(em_name, num = 1, em_salary = 1.00){ } // default constructor
	float salary;

	const void setSalary(float m_salary) { // declared constant for a fixed salary
		salary = m_salary;
	}

};

class HourlyEmployee : public Employee {
public:
	HourlyEmployee(string em_name, int num = 1, float em_salary = 1.00) : Employee(em_name, num = 1, em_salary = 1.00){ } // default constructor
	float hourly_rate;
	int hours_worked;

	void setHourlyRate(float hrate){
		hourly_rate = hrate;
	}

	void setHoursWorked(int hworked){
		hours_worked = hworked;
	}
};

class CommissionEmployee : public Employee {
public:
	CommissionEmployee(string em_name, int num = 1, float em_salary = 1.00) : Employee(em_name, num = 1, em_salary = 1.00){ } // default constructor
	float base_salary;
	float rate;
	float rev;

	void setBaseSalary(float bsalary){
		base_salary = bsalary;
	}

	void setRate(float m_rate){
		rate = m_rate;
	}

	void setRevenue() {
		rev = rate / 100.00;  //  not exactly sure what to do with revenue??? 
	}
};


// testing 

int main() {
	SalaryEmployee Em1 ("Din", 1);
	HourlyEmployee Em2 ("Povz", 2);
	CommissionEmployee Em3 ("Dee", 3);

}