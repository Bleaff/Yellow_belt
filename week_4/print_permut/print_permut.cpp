#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_ranges(const vector<int> &range)
{
	for(auto it : range)
	{
		cout << it << ' ';
	}
	cout << endl;
}
void fill_range(vector<int> &range, int n)
{
	for (int i = n; i >= 1; i--)
	{
		range.push_back(i);
	}
}	

int main()
{
	int n;
	cin >> n;
	vector<int> permut;
	fill_range(permut, n);
	do{
		print_ranges(permut);
	}
	while (next_permutation(begin(permut), end(permut), [](int a, int b){return a > b;}));
	return 0;
}

