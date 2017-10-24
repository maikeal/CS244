#ifndef SQUARES_H
#define SQUARES_H

#include <string>
#include <sstream>

namespace example
{
	class Square1
	{
	 public:
		//Class Fields
		//============
		int side;

		//Class Methods
		//=============

		//Default Constructor
		/*It delagates operations to
		another constructor by use of
		the initalization list which
		can only be implemented by
		constructors*/
		Square1() : Square1(1) {}

		//Overloaded Constructor
		Square1(int side)
		{
			/*To resolve ambiguity
			between the field and
			parameter, the this
			pointer is used. The this
			pointer is a pointer that
			references the class object*/
			this->side = side;
		}

		//Copy Constructor
		Square1(const Square1& other)
		{
			/*This copy constructor
			performs a shallow copy (or
			memberwise copy) which means
			each field is assigned the
			values by using simply using
			the assignment operator*/
			side = other.side;
		}

		//Assignment Operator
		Square1 operator=(const Square1& rhs)
		{
			/*First check to same if you
			are performing a self assignment*/
			if(this != &rhs)
			{
				this->side = rhs.side;
			}

			return *this;
		}

		//Destructor
		~Square1() {}

		int Perimeter()
		{
			return 4 * side;
		}

		string ToString()
		{
			stringstream out;
			out << side;
			return out.str();
		}
	};

	class Square2
	{
	 public:
		//Class Fields
		//============
		int* side;

		//Class Methods
		//=============

		//Default Constructor
		/*It delagates operations to
		another constructor by use of
		the initalization list which
		can only be implemented by
		constructors*/
		Square2() : Square2(1) {}

		//Overloaded Constructor
		Square2(int side)
		{
			this->side = new int;
			*(this->side) = side;
		}

		//Copy Constructor
		Square2(const Square2& other)
		{
			/*This copy constructor
			performs a deep copy
			which means it allocates new
			memory for its fields and
			then assign them the values of
			the other objects' fields. A
			deep copy is only needed whenever
			you have pointer fields.*/
			side = new int;
			*side = *(other.side);
		}

		//Assignment Operator
		Square2 operator=(const Square2& rhs)
		{
			if(this != &rhs)
			{
				*(this->side) = *(rhs.side);
			}

			return *this;
		}

		//Destructor
		~Square2()
		{
			if(side != NULL)
			{
				delete side;
				side = NULL;
			}
		}

		int Perimeter()
		{
			return 4 * (*side);
		}

		string ToString()
		{
			stringstream out;
			out << *side;
			return out.str();
		}
	};
}

#endif
