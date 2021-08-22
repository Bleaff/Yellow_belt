#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> SplitIntoWords(const string& s)
{
  vector <string> result;
  auto iter = begin(s);
  // проматываемся до первого символа
  while (iter != end(s))
  {
    string to_push;
    if (*iter != ' ')
    {
      auto end_word = find_if(iter, end(s), [](char ch){return (ch == ' ');});
      for (;iter != end_word; iter++)
      {
        to_push += *iter;
      }
      result.push_back(to_push);
    }
    else
    {
      iter++;
    }
  }
  return (result);
}

// int main() {
//   string s = "C Cpp Java Python";
//
//   vector<string> words = SplitIntoWords(s);
//   cout << words.size() << " ";
//   for (auto it = begin(words); it != end(words); ++it) {
//     if (it != begin(words)) {
//       cout << "/";
//     }
//     cout << *it;
//   }
//   cout << endl;
//
//   return 0;
// }
