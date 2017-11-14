//Team: <Team Name>
//Author: <Names>
//Creation: <Date>
#ifndef NAME_H
#define NAME_H

#include "Archive.h"

namespace lab3
{
	class Name
	{
		private:
		std::string firstName;
		std::string lastName;
		
		public:
		Name();
		Name(std::string,std::string);
		Name(const Name&);
		Name& operator=(const Name&);
		~Name() {}
		std::string& GetFirstName();
		std::string& GetLastName();
		void SetFirstName(const std::string&);
		void SetLastName(const std::string&);
		std::string ToString() const;
		friend std::ostream& operator<<(std::ostream&,const Name&);
	};
}

#endif 