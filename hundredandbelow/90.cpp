#include <iostream>
#include <cmath>
#include <cstdint>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <set>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::uint64_t;
using std::set;
using std::sort;

int counter = 0;

struct Die{
  int die[6];
  Die(vector<int> init){
    for (int i=0; i!=6; ++i){
      die[i]=init[i];
    }
  }
  bool operator==(const Die &right) const{
    for (int i=0; i!=6; ++i){
      if (die[i]!=right.die[i]) break;
      if (i==9) return true;
    }
    return false;
  }

  bool operator<(const Die &right) const{
    for (int i=0; i!=6; ++i){
      if (die[i]!=right.die[i]) break;
      if (i==0) return true;
    }
    return false;
  }

  size_t operator()() const{
    size_t tmp = 0;
    for (int i=0; i!=6; ++i){
      tmp += die[i]*(size_t(pow( 10, i )));
    }
    return tmp;
  }

  friend std::ostream& operator<<(std::ostream& out, const Die& d); // output
};

std::ostream& operator<<(std::ostream& out, const Die& d) // output
{
  out << d.die[0] << d.die[1] << d.die[2] << d.die[3] << d.die[4] << d.die[5];
  return out;
}

void finisher(const vector<int> &die1, const vector<int> &die2,set<size_t> 
  &allowedPairs){
  vector<int> final1(die1),final2(die2);
  sort(final1.begin(),final1.end());
  sort(final2.begin(),final2.end());
  Die d1(final1);
  Die d2(final2);
  size_t no1 = d1();
  size_t no2 = d2();
  if (no1==no2) counter++;
  size_t store;
  if (no1>no2){ store = no1*pow(10,6)+no2;
  } else { store = no2*pow(10,6)+no1; }
  cout << store << endl;
  allowedPairs.insert(store);
}

void innerDie(const vector<int> &die1, const vector<int> &die2, const vector<int> &missing,
  set<size_t> &allowedPairs){
  if (die2.size()==6) {finisher(die1,die2,allowedPairs); return;}
  for (size_t i = 0; i!=missing.size(); ++i){
    vector<int> newDie(die2);
    vector<int> newMiss;
    newDie.push_back(missing[i]);
    for (size_t j = 0; j!=missing.size(); ++j){
      if (i==j) continue;
      newMiss.push_back(missing[j]);
    }
    innerDie(die1,newDie,newMiss,allowedPairs);
  }
}

void outerDie(const vector<int> &die1, const vector<int> &die2, const vector<int> &missing1, const vector<int> &missing2, set<size_t> &allowedPairs){
  if (die1.size()==6) {innerDie(die1,die2,missing2,allowedPairs); return;}
  for (size_t i = 0; i!=missing1.size(); ++i){
    vector<int> newDie(die1);
    vector<int> newMiss;
    newDie.push_back(missing1[i]);
    for (size_t j = 0; j!=missing1.size(); ++j){
      if (i==j) continue;
      newMiss.push_back(missing1[j]);
    }
    outerDie(newDie,die2,newMiss,missing2,allowedPairs);
  }
}

void DieLoop(vector<int> &die1Tmpl, vector<int> &die2Tmpl, set<size_t> &allowedPairs){
  vector<int> missing1, missing2;
  for (int i=0; i!=10; ++i){
    for (size_t j=0; j!=die1Tmpl.size(); ++j){
      if (i==die1Tmpl[j]) break;
      if (j==die1Tmpl.size()-1) missing1.push_back(i);
    }
    for (size_t j=0; j!=die2Tmpl.size(); ++j){
      if (i==die2Tmpl[j]) break;
      if (j==die2Tmpl.size()-1) missing2.push_back(i);
    }
  }
  outerDie(die1Tmpl,die2Tmpl,missing1,missing2,allowedPairs);
}


int main(void){
  int first[2]={2,5};
  set<size_t> allowedPairs;
  for (int twoFive=0; twoFive!=2; ++twoFive){
    for (int four=0; four!=2; ++four){    
      for (int eight=0; eight!=2; ++eight){
        for (int sixNine=0; sixNine!=12; ++sixNine){
          vector<int> die1, die2;
          die1.push_back(0); die2.push_back(1);
          die1.push_back(first[twoFive%2]); die2.push_back(first[(twoFive+1)%2]);
          if (four==0){die1.push_back(4); die2.push_back(0);
          }else{die2.push_back(4);}
          if (eight==0){die2.push_back(8); die1.push_back(1);
          }else{die1.push_back(8);}
          if (sixNine==0){die2.push_back(6);die1.push_back(3);
          }else if (sixNine==1){die2.push_back(9);die1.push_back(3);
          }else if (sixNine==2){die1.push_back(6);die2.push_back(3);
          }else if (sixNine==3){die1.push_back(9);die2.push_back(3);
          }else if (sixNine==4){die1.push_back(6);die1.push_back(3);die2.push_back(6);
          }else if (sixNine==5){die1.push_back(6);die2.push_back(3);die2.push_back(6);
          }else if (sixNine==6){die1.push_back(9);die1.push_back(3);die2.push_back(9);
          }else if (sixNine==7){die1.push_back(9);die2.push_back(3);die2.push_back(9);
          }else if (sixNine==8){die1.push_back(6);die1.push_back(3);die2.push_back(9);
          }else if (sixNine==9){die1.push_back(6);die2.push_back(3);die2.push_back(9);
          }else if (sixNine==10){die1.push_back(9);die1.push_back(3);die2.push_back(6);
          }else if (sixNine==11){die1.push_back(9);die2.push_back(3);die2.push_back(6);}
          if (sixNine<4){
            if (sixNine<2){
              bool four=true, one=true;
              for (size_t i=0; i!=die1.size(); ++i){
                if (die1[i]==4) four=false;
                if (die1[i]==1) one=false;
              }
              if (four) die1.push_back(4);
              if (one) die1.push_back(1);
            } else {
              bool four=true, zero=true;
              for (size_t i=0; i!=die2.size(); ++i){
                if (die2[i]==4) four=false;
                if (die2[i]==0) zero=false;
              }
              if (four) die2.push_back(4);
              if (zero) die2.push_back(0);
            }
          }
          if (die1.size()>6 || die2.size()>6) continue;
          DieLoop(die1,die2,allowedPairs);
        }
      }
    }
  }

  cout << counter << " " << allowedPairs.size() << endl;
  return 0;
}
