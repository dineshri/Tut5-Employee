#include <iostream>
#include <string>

using namespace std;

int Employee::numberOfEmployees = 0; // initialisation of static variable globally

class Employee {
protected:
	string m_name;
	int Number;

public:
    Employee(string em_name, int num = 1): m_name(em_name), Number(num){  } // constructor of base class
	
	string name() {
		return m_name;}   // method name()

	int staffNumber() {
		return Number;}  // method staffNumber()

	virtual float salary() = 0; // pure virtual function for salary to be modified in derived classes

	static int numberOfEmployees; // declaration of static member

};

// derived classes starts here

class SalaryEmployee : public Employee {
public:
	SalaryEmployee(string em_name, int num = 1) : Employee(em_name, num = 1){ } // default constructor
	float salary;

	const void setSalary(float m_salary) { // declared constant for a fixed salary
		salary = m_salary;
	}

	float salary(){
		return salary;
	}

};

class HourlyEmployee : public Employee {
public:
	HourlyEmployee(string em_name, int num = 1) : Employee(em_name, num = 1){ } // default constructor
	float hourly_rate;
	int hours_worked;

	void setHourlyRate(float hrate){
		hourly_rate = hrate;
	}

	void setHoursWorked(int hworked){
		hours_worked = hworked;
	}

	float salary(){
		return (hourly_rate * hours_worked);
	}
};

class CommissionEmployee : public Employee {
public:
	CommissionEmployee(string em_name, int num = 1) : Employee(em_name, num = 1){ } // default constructor
	float base_salary;
	float rate;
	float revenue;

	void setBaseSalary(float bsalary){
		base_salary = bsalary;
	}

	void setRate(float m_rate){
		rate = m_rate;
	}

	void setRevenue(float rev) {
		revenue = rev;  //  not exactly sure what to do with revenue??? 
	}

	float salary(){
		return (base_salary + (rate * revenue));
	}
};


// testing 

int main() {
	SalaryEmployee Em1 ("Din", 1);
	HourlyEmployee Em2 ("Povz", 2);
	CommissionEmployee Em3 ("Dee", 3);

}