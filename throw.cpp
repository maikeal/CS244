#include <iostream>
#include <string>
using namespace std;

int main()
{
double x,y;
cin >>x>>y;

try
{
if (y==0)
throw "Cannot divide by zero";
cout << x/y;
}
catch(int e)
{
throw;
}
catch(const char*e)
{
cout << e <<"\n";
}
return 0;
}
