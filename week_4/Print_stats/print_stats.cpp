#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void PrintStats(vector<Person> persons)
{
  vector<Person> ans_states;
  cout << "Median age = " <<ComputeMedianAge(begin(persons),
   end(persons)) << endl;

   copy_if(persons.begin(), persons.end(), back_inserter(ans_states),
   [](Person per){return per.gender == Gender::FEMALE;});
  cout << "Median age for females = " << ComputeMedianAge(ans_states.begin(), ans_states.end()) <<endl;
  ans_states.clear();

  copy_if(persons.begin(), persons.end(), back_inserter(ans_states),
  [](Person per){return per.gender == Gender::MALE;});
  cout << "Median age for males = " << ComputeMedianAge(ans_states.begin(), ans_states.end()) <<endl;
  ans_states.clear();

    copy_if(persons.begin(), persons.end(), back_inserter(ans_states),
    [](Person per){return (per.gender == Gender::FEMALE && per.is_employed == 1);});
   cout << "Median age for employed females = " << ComputeMedianAge(ans_states.begin(), ans_states.end()) <<endl;
   ans_states.clear();

   copy_if(persons.begin(), persons.end(), back_inserter(ans_states),
   [](Person per){return (per.gender == Gender::FEMALE && per.is_employed == 0);});
  cout << "Median age for unemployed females = " << ComputeMedianAge(ans_states.begin(), ans_states.end()) <<endl;
  ans_states.clear();

  copy_if(persons.begin(), persons.end(), back_inserter(ans_states),
  [](Person per){return (per.gender == Gender::MALE && per.is_employed == 1);});
 cout << "Median age for employed males = " << ComputeMedianAge(ans_states.begin(), ans_states.end()) <<endl;
 ans_states.clear();

 copy_if(persons.begin(), persons.end(), back_inserter(ans_states),
 [](Person per){return (per.gender == Gender::MALE && per.is_employed == 0);});
cout << "Median age for unemployed males = " << ComputeMedianAge(ans_states.begin(), ans_states.end()) <<endl;
ans_states.clear();
}
