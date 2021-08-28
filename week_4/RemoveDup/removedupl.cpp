#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

template <typename T>
void RemoveDuplicates(vector<T>& elements)
{
	sort(begin(elements), end(elements));
	auto new_end = unique(begin(elements), end(elements));
	elements.erase(new_end, end(elements));
}

