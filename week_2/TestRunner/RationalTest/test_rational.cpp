#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <utility>

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

template <class K, class V>
ostream& operator << (ostream& os, const pair<K, V>& m) {
  os << "(" << m.first << "," << m.second << ")";
  return os;
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

// class Rational {
// public:
//     Rational() {
//         // Реализуйте конструктор по умолчанию
//         p = 0;
//         q = 1;
//     }
//
//     Rational(int numerator, int denominator) {
//         // Реализуйте конструктор
//         int a = numerator, b = denominator, c = 0;
//         while (b != 0) {
//             c = a % b;
//             a = b;
//             b = c;
//         }
//
//         p = numerator / a;
//         if (denominator / a < 0)
//           {
//             p *= -1;
//             q = -(denominator / a);
//           }
//         else{
//           q = denominator / a;
//         }
//     }
//
//     int Numerator() const {
//         // Реализуйте этот метод
//         return p;
//     }
//
//     int Denominator() const {
//         // Реализуйте этот метод
//         return q;
//     }
//
// private:
//     // Добавьте поля
//     int p;
//     int q;
// };
//
// bool operator == (const Rational& lhs, const Rational& rhs) {
//     int a = lhs.Denominator(), b = rhs.Denominator(), c = 0;
//     while (b != 0) {
//         c = a % b;
//         a = b;
//         b = c;
//     }
//     int n = (lhs.Denominator() * rhs.Denominator()) / a;
//     int l = n / lhs.Denominator();
//     int r = n / rhs.Denominator();
//     return (lhs.Numerator() * l) == (rhs.Numerator() *r);
// }
//
// Rational operator + (const Rational& lhs, const Rational& rhs) {
//     int a = lhs.Denominator(), b = rhs.Denominator(), c = 0;
//     while (b != 0) {
//         c = a % b;
//         a = b;
//         b = c;
//     }
//     int n = (lhs.Denominator() * rhs.Denominator()) / a;
//     int l = n / lhs.Denominator();
//     int r = n / rhs.Denominator();
//     return Rational((lhs.Numerator() * l) + (rhs.Numerator() *r), n);
// }
//
// Rational operator - (const Rational& lhs, const Rational& rhs) {
//     int a = lhs.Denominator(), b = rhs.Denominator(), c = 0;
//     while (b != 0) {
//         c = a % b;
//         a = b;
//         b = c;
//     }
//     int n = (lhs.Denominator() * rhs.Denominator()) / a;
//     int l = n / lhs.Denominator();
//     int r = n / rhs.Denominator();
//     return Rational((lhs.Numerator() * l) - (rhs.Numerator() *r), n);
// }

void TestEmpty()
{
    Rational empty;
    pair<int, int> correct = make_pair(0,1);
    pair<int, int> test = make_pair(empty.Numerator(), empty.Denominator());
    AssertEqual(test, correct, "Empty rational must be equal 0/1");
}

void TestReduction()
{
  for (int i = 1; i < 16; i++) {
    Rational check_red(i,i*i);
    ostringstream hint;
    pair<int, int> correct	= make_pair(1,i);
    pair<int, int> test	= make_pair(check_red.Numerator(), check_red.Denominator());

    hint << "Wrong reduction! " << "Got: " << check_red.Numerator() << "/" << check_red.Denominator()
    << " while expected: " << correct.first << "/" << correct.second <<endl;
    AssertEqual(test, correct, hint.str());
  }
}

void TestNegative()
{

  for (size_t i = 1; i < 10; i++)
  {
    if (i % 2)
    {
      ostringstream hint;
      Rational check_red(-i,i*i);
      pair<int, int> correct	= make_pair(-1,i);
      pair<int, int> test	= make_pair(check_red.Numerator(), check_red.Denominator());
      hint << "Wrong sign! " << "Got: " << check_red.Numerator() << "/" << check_red.Denominator()
      << " while expected: " << correct.first << "/" << correct.second <<endl;
      AssertEqual(test, correct, hint.str());
    }
    else{
      Rational check_red(i,-i*i);
      pair<int, int> correct	= make_pair(-1,i);
      pair<int, int> test	= make_pair(check_red.Numerator(), check_red.Denominator());
      ostringstream hint;
      hint << "Wrong sign! " << "Got: " << check_red.Numerator() << "/" << check_red.Denominator()
      << " while expected: " << correct.first << "/" << correct.second <<endl;
      AssertEqual(test, correct, hint.str());

    }
  }
}

void TestPositive()
{
  ostringstream hint;
  for (size_t i = 1; i < 10; i++)
  {
    Rational check_red(-i,-i*i);
    pair<int, int> correct	= make_pair(1, i);
    pair<int, int> test	= make_pair(check_red.Numerator(), check_red.Denominator());
    hint << "Wrong sign! " << "Got: " << check_red.Numerator() << "/" << check_red.Denominator()
    << " while expected: " << correct.first << "/" << correct.second <<endl;
    AssertEqual(test, correct, hint.str());
  }
}

void TestNullDenominator()
{
  for (size_t i = 1; i < 10; i++)
  {
    if (i % 2)
    {
      Rational check_red(0, i*i);
      pair<int, int>correct	= make_pair(0, 1);
      pair<int, int>test	= make_pair(check_red.Numerator(), check_red.Denominator());
      ostringstream hint;
      hint << "Wrong denominator! " << "Got: " << check_red.Numerator() << "/" << check_red.Denominator()
      << " while expected: " << correct.first << "/" << correct.second <<endl;
      AssertEqual(test, correct, hint.str());
    }
    else{
      Rational check_red(0, -i*i);
      pair<int, int> correct	= make_pair(0, 1);
      pair<int, int> test	= make_pair(check_red.Numerator(), check_red.Denominator());
      ostringstream hint;
      hint << "Wrong denominator! " << "Got: " << check_red.Numerator() << "/" << check_red.Denominator()
      << " while expected: " << correct.first << "/" << correct.second <<endl;
      AssertEqual(test, correct, hint.str());
    }

  }
}

int main() {
  TestRunner runner;
  runner.RunTest(TestEmpty, "TestEmpty");
  runner.RunTest(TestReduction, "TestReduction");
  runner.RunTest(TestNegative, "TestNegative");
  runner.RunTest(TestPositive, "TestPositive");
  runner.RunTest(TestNullDenominator, "TestNullDenominator");
  return 0;
}
