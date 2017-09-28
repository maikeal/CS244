#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  fstream file;
  file.open("test.txt",fstream::out);
  char letter = 'A';

  for (;letter <= 'Z'; letter++)
  {
    file << letter << " ";
  }

  file.close();
  return 0;
}
