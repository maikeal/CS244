//Team: <Team Name>
//Author: <Names>
//Creation: <Date>
#ifndef ADDRESS_H
#define ADDRESS_H

#include "Archive.h"

namespace lab3
{
	class Address
	{
		private:
		std::string street;
		std::string city;
		std::string state;
		std::string zipcode;
		
		public:
		Address();
		Address(std::string,std::string,std::string,std::string);
		Address(const Address&);
		Address& operator=(const Address&);
		~Address() {}
		std::string& GetStreet(); 
		std::string& GetCity();
		std::string& GetState(); 
		std::string& GetZipcode();
		void SetStreet(const std::string&);
		void SetCity(const std::string&);
		void SetState(const std::string&);
		void SetZipcode(const std::string&);
		std::string ToString() const; 
		friend std::ostream& operator<<(std::ostream&,const Address&);
	};
}

#endif 