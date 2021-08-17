#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

// bool IsPalindrom(const string& str) {
//   int length = str.length();
//
//      for (int i = 0; i < (length / 2); i++)
//          if (str[i] != str[length - 1 - i])
//              return false;
//
//      return true;
// }

void TestPalindrom()
{
  string empty = "";
  string ch = "c";
  string wrong_pal1 = " level";
  string wrong_pal2 = "level ";
  string wrong_pal3 = " lev1el ";
  AssertEqual(IsPalindrom(empty), 1, "Empty string is a palindrom!");
  AssertEqual(IsPalindrom(ch), 1, "Character is a palindrom!");
  AssertEqual(IsPalindrom(wrong_pal1), 0, "String ' level' isn't a palindrom!");
  AssertEqual(IsPalindrom(wrong_pal2), 0, "String 'level ' isn't a palindrom!");
  AssertEqual(IsPalindrom(wrong_pal3), 0, "String 'lev1el' isn't a palindrom!");
  AssertEqual(IsPalindrom(" l eve l "), 1, "String ' l eve l ' is a palindrom!");
  AssertEqual(IsPalindrom("wasitacaroracatisaw"), 1, "String 'wasitacaroracatisaw' is a palindrom!");
  AssertEqual(IsPalindrom("nvf"), 0, "'nvf' is not a palindrom!");
  AssertEqual(IsPalindrom("c p c"), 1, "'c p c' is a palindrom!");
  AssertEqual(IsPalindrom("mevel"), 0, "'mevel' is not a palindrom!");
  AssertEqual(IsPalindrom("levem"), 0, "'levem' is not a palindrom!");
  Assert(IsPalindrom("  ABBA  "), "`  ABBA  ` is a palindrome");
}



int main() {
  TestRunner runner;
  runner.RunTest(TestPalindrom, "TestPalindrom");
  return 0;
}
