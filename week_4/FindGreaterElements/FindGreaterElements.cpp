#include <set>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border)
{
  vector <T> result;
  auto stop = begin(elements);
  for(; stop != end(elements); stop++)
  {
    if (border <= *stop)
      break;
  }
  if (stop != end(elements) && *stop == border)
    stop++;
  for(; stop != end(elements); stop++)
  {
    result.push_back(*stop);
  }
  return result;
}
