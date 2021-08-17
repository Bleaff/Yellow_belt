#include "sum_reverse_sort.h"
#include <iostream>

using namespace std;

int main()
{
  string check;
  vector<int> v = {1,9,2,8,3,7,4,6,5,9,0,0,0,0};
  Sort(v);
  for (auto it : v)
    cout << it << " ";
  cout << endl << "___________________";
  check = Reverse("ABCD");
  cout << check <<  endl << "__________\n" << Sum (3,8);


  return (0);
}
