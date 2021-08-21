#include "phone_number.h"
#include <stdexcept>
#include <string>
#include <sstream>


using namespace std;

PhoneNumber::PhoneNumber(const string &international_number)
{
  istringstream inter(international_number);

  char First_ch = inter.get();
  getline(inter, country_code_, '-');
  getline(inter, city_code_, '-');
  getline(inter, local_number_);

  if (First_ch != '+' || country_code_.empty() || city_code_.empty() || local_number_.empty()) {
   throw invalid_argument("Phone number must begin with '+' symbol and contain 3 parts separated by '-' symbol: " + international_number);
    }
}


string PhoneNumber::GetCountryCode() const
{
  return country_code_;
}

string PhoneNumber::GetCityCode() const
{
  return city_code_;
}

string PhoneNumber::GetLocalNumber() const
{
  return local_number_;
}

string PhoneNumber::GetInternationalNumber() const
{
  return string("+" + country_code_ + "-" + city_code_ + "-" + local_number_);
}
