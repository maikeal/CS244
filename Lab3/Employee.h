//Team: <Team Name>
//Author: <Names>
//Creation: <Date>
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Archive.h"

namespace lab3
{
	class Employee
	{
		private:
		Name name;
		Address address;
		int employeeId;
		double salary;
		static int nextId;
		
		public:
		Employee();
		Employee(const Name&,const Address&,double);
		Employee(const Employee&);
		Employee& operator=(const Employee&);
		~Employee() {}
		int GetEmployeeId();
		Name& GetName();
		Address& GetAddress();
		static int GetNextId();
		double GetSalary();
		void SetName(const Name&);
		void SetAddress(const Address&);
		void SetSalary(double);
		std::string ToString() const;
		friend std::ostream& operator<<(std::ostream&,const Employee&);
	};
	
	int Employee::nextId = 1;
}

#endif 