#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "Name.h"
#include "Address.h"
#include "Employee.h"
using namespace lab3;
	
bool NameTest()
{
	Name n1, n2("John","Doe"), n3("Gh0st","Walker"), n4(n2);
	std::stringstream out;

	if(n1.GetFirstName() != "" && n1.GetLastName() != "")
		return false;
	if(n2.GetFirstName() != "John" && n2.GetLastName() != "Doe")
		return false;
	if(n3.GetFirstName() == "Gh0st")
		return false;
	if(n4.GetFirstName() != n2.GetFirstName() && n4.GetLastName() != n2.GetLastName())
		return false;
	
	n3 = n2;
	
	if(n3.GetFirstName() != n2.GetFirstName() && n3.GetLastName() != n2.GetLastName())
		return false;
	
	n1.SetFirstName("Peter");
	n1.SetFirstName("P3ter");
	n1.SetLastName("Parker");
	n1.SetLastName("P@rk3r");
	
	if(n1.GetFirstName() != "Peter" && n1.GetLastName() != "Parker")
		return false;
	if(n1.ToString() != "Peter Parker")
		return false;
	
	out << n1;
	
	if(n1.ToString() != out.str())
		return false;
	
	return true;	
}

bool AddressTest()
{	
	Address n1, n2("1638 Bedford Ave","Brooklyn","NY","11225"), 
	n3("1150 Carroll St","Br0nx","New Jersey","A1323"), n4(n2);
	std::stringstream out;

	if(n1.GetStreet() != "" && n1.GetCity() != "" && n1.GetState() != "NY"
		&& n1.GetZipcode() != "11111")
		return false;
	if(n2.GetStreet() != "1638 Bedford Ave" && n2.GetCity() != "Brooklyn"
		&& n2.GetState() != "NY" && n2.GetZipcode() != "11225")
		return false;
	if(n3.GetCity() == "Br0nx" && n3.GetState() == "New Jersey" 
		&& n3.GetZipcode() == "A1323")
		return false;
	if(n4.GetStreet() != n2.GetStreet() && n4.GetCity() != n2.GetCity()
		&& n4.GetState() != n2.GetState() && n4.GetZipcode() != n2.GetZipcode())
		return false;
	
	n3 = n2;
	
	if(n3.GetStreet() != n2.GetStreet() && n3.GetCity() != n2.GetCity()
		&& n3.GetState() != n2.GetState() && n3.GetZipcode() != n2.GetZipcode())
		return false;
		
	n1.SetStreet("1600 West St");
	n1.SetCity("Bronkdale");
	n1.SetCity("Br0nkD@ale");
	n1.SetState("NJ");
	n1.SetState("New Jersey");
	n1.SetZipcode("10021");
	n1.SetZipcode("33239-2442");
	
	if(n1.GetStreet() != "1600 West St" && n1.GetCity() != "Bronkdale" 
		&& n1.GetState() != "NJ" && n1.GetZipcode() != "10021")
		return false;
	if(n1.ToString() != "1600 West St\nBronkdale,NJ 10021")
		return false;
	
	out << n1;
	
	if(n1.ToString() != out.str())
		return false;

	return true;
}

bool equalName(Name n1,Name n2)
{
	bool result = (n1.GetFirstName() == n2.GetFirstName());
	result = result && (n1.GetLastName() == n2.GetLastName());
	
	return result;
}

bool equalAddress(Address n1,Address n2)
{
	bool result = (n1.GetStreet() == n2.GetStreet());
	result = result && (n1.GetCity() == n2.GetCity());
	result = result && (n1.GetState() == n2.GetState());
	result = result && (n1.GetZipcode() == n2.GetZipcode());
	
	return result;
}

bool EmployeeTest()
{
	Name v1("John","Doe"), v2("Mary","Jones");
	Address a1("3 Elm St","New York","NY","66600"), a2("22 East Ave","Bronx","NY","11332");
	Employee n1, n2(v1,a1,12000),n3(v1,a1,1000), n4(n2);
	std::stringstream out;

	if(Employee::GetNextId() < 4)
		return false;

	if(!equalName(n1.GetName(),Name()) && !equalAddress(n1.GetAddress(),Address()) && n1.GetSalary() != 6000)
		return false;
	if(!equalName(n2.GetName(),v1) && !equalAddress(n2.GetAddress(),a1) && n2.GetSalary() != 12000)
		return false;
	if(n3.GetSalary() == 1000)
		return false;
	if(!equalName(n4.GetName(),n2.GetName()) && !equalAddress(n4.GetAddress(),n2.GetAddress())
		&& n4.GetEmployeeId() != n2.GetEmployeeId() && n4.GetSalary() != n2.GetSalary())
		return false;
	
	n3 = n2;
	
	if(!equalName(n3.GetName(),n2.GetName()) && !equalAddress(n3.GetAddress(),n2.GetAddress())
		&& n3.GetEmployeeId() != n2.GetEmployeeId() && n3.GetSalary() != n2.GetSalary())
		return false;
		
	n1.SetName(v2);
	n1.SetAddress(a2);
	n1.SetSalary(53000);
	n1.SetSalary(4000);
	
	if(!equalName(n1.GetName(),v2) && !equalAddress(n1.GetAddress(),a2) && n1.GetSalary() != 53000)
		return false;
	
	std::string result = "Mary Jones " + std::to_string(n1.GetEmployeeId()) +  "\n22 East Ave\nBronx,NY 11332\n53000.00";
	
	if(n1.ToString() != result)
		return false;
	
	out.str("");
	
	out << n1;
	
	if(n1.ToString() != out.str())
		return false;
	
	return true;
}

bool Tester()
{
	bool(*func[3])() = { &NameTest, &AddressTest, &EmployeeTest}, result = true, hold;
		
	std::string functions[3] = { "Name", "Address", "Employee"};
	for (int i = 0; i < 3; i += 1)
	{
		std::cout << functions[i] << " Test ";
		hold = func[i]();
		std::cout << ((hold) ? ("has passed.\n") : ("has failed.\n"));
		if (!hold)
		{
			result = false;
		}
		std::cout << std::boolalpha;
		std::cout << func[i]() << " " << "\n";
	}

	std::cout << "\n";
	return result;
}

#endif 