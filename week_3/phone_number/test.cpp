#include "phone_number.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector <PhoneNumber> numbers;
  for (size_t i = 0; i < 10; i++) {
    try{
      string number_int;
      cin >> number_int;
      PhoneNumber number(number_int);
      numbers.push_back(number);
      cout << i <<".international number:" << number.GetInternationalNumber() << ", country_code:" << number.GetCountryCode()
      << ", city code:" << number.GetCityCode() << ", local_number:" << number.GetLocalNumber() << endl;
    }
    catch (invalid_argument &ina)
    {
      cout << ina.what() << endl;
    }
  }
  return 0;
}
