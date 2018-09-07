#include <iostream>
#include <limits>

int main()
{
  int N[] = {0,0,0};

  if ( std::numeric_limits<long int>::digits==63 &&
    std::numeric_limits<int>::digits==31 &&
    std::numeric_limits<unsigned int>::digits==32 )
  {
    for (long int i = -0xffffffff; i ; --i)
    {
      N[i] = 1;
    }
  }
  else
  {  
    N[1]=1;
  }

  std::cout << N[0] <<N [1] << N[2];
}