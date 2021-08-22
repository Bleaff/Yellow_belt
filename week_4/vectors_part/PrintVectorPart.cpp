#include <vector>
#include <iostream>

using namespace std;

void PrintVectorPart(const vector<int>& numbers)
{
  auto it = begin(numbers);
    while (it != end(numbers))
    {
      if (*it < 0)
        break;
      it ++;
    }
    while (it != begin(numbers))
    {
      it--;
      cout << *it << ' ';
    }
}
