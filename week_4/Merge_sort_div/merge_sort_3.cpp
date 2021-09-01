#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end)
{
  if (range_end - range_begin < 2)
    return ;
  else
  {
    vector<typename RandomIt::value_type> elements(range_begin, range_end);
    auto it_f = begin(elements) + elements.size()/3;
    auto it_s = it_f + elements.size()/3;
    MergeSort(begin(elements), it_f);
    MergeSort(it_f, it_s);
    MergeSort(it_s, end(elements));
    vector<typename RandomIt::value_type> elements_sorted;
    merge(begin(elements), it_f, it_f, it_s, back_inserter(elements_sorted));
    merge(begin(elements_sorted), end(elements_sorted), it_s, end(elements), range_begin);
  }
}

// int main() {
//   vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, 8};
//   MergeSort(begin(v), end(v));
//   for (int x : v) {
//     cout << x << " ";
//   }
//   cout << endl;
//   return 0;
// }
