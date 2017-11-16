#include <iostream>
#include <string>
using namespace std;

void first (int k)
{
if (k==5)
throw k;
}
void second(double t)
{
if (t<0)
throw "Negative";
}
void third (string u)
{
if (u.length() > 3 )
throw u;
}
void fourth(char a)
{
if(a=='a')
throw 0.2;
}

int main()
{
try
{
  first(5);
  second(37.0);
  third("Hello");
  fourth('A');
}
catch (int)
{
cerr << "First\n";
}
catch (const char*)
{
cerr << "Second\n";
}
catch (string)
{
cerr << "Third\n";
}
catch (double)
{
cerr << "Fourth\n";
}
catch (...)
{
cerr << "None\n";
throw;
}
return 0;
}
