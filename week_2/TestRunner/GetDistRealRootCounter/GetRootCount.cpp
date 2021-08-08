#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include<random>

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

int GetDistinctRealRootCount(double a, double b, double c) {
  return 2;
}

void RootCount()
{
  for (size_t i = 0; i < 200; i++) {
    int rootcount = GetDistinctRealRootCount(i / 2 , i * 9, i);
    Assert((rootcount >= 0 && rootcount <= 2), "Root count more than 2 or less than 0!");
  }
}

void OneRootTest()
{
  std::random_device rd;
  std::mt19937 mersenne(rd());
  for (size_t i = 0; i < 200; i++) {
    stringstream hint;
    int b = mersenne() * 2, c = b * b;
    int rootcount = GetDistinctRealRootCount(1, b, c);
    hint << "Root count not equal 1, position: " << "x^2 " << b << "x +" << c;
    AssertEqual(rootcount, 1, hint.str());
    stringstream hint1;
    b = (-1) * mersenne() * 2, c = b * b;
    rootcount = GetDistinctRealRootCount(1, b, c);
    hint1 << "Root count not equal 1, position: " << "x^2 " << b << "x +" << c;
    AssertEqual(rootcount, 1, hint1.str());
  }
}

int main() {
  TestRunner runner;
  runner.RunTest(RootCount, "RootCount");
  runner.RunTest(OneRootTest,"OneRootTest");
  return 0;
}
