#include <iostream>
#include <random>
using namespace std;
int main()
{
  std::random_device rd;
  std::default_random_engine gen = std::default_random_engine(rd());
  std::uniform_int_distribution<int> dis(1,10);
  for (int i=0; i<10; ++i)
      std::cout << dis(gen) << " ";

  std::cout << std::endl;

  return 0;
}
