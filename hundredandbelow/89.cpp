#include <iostream>
#include <cmath>
#include <cstdint>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::uint64_t;
using std::map;

int numerify(string number, map<char,int> &order){
  int arabic = 0;
  int largestSeen = 1;
  for (auto i = number.rbegin(); i != number.rend(); ++i){
    int inspVal = order[*i];
    if ( inspVal < largestSeen ){
      arabic -= inspVal;
    }else{
      arabic += inspVal;
      largestSeen = inspVal;
    }
  }
  return arabic;
}

void romanizeTens( string &tens, int &arabic, int mode ){
  const char tags[10] = "XVICLXMDC";
  if (arabic%10==9){
    tens.push_back(tags[mode]);
    tens.push_back(tags[mode+2]);
    arabic -= 9;
  } else if (arabic%5==4){
    tens.push_back(tags[mode+1]);
    tens.push_back(tags[mode+2]);
    arabic -= 4;
  } else {
    for (int i = 0; i != (arabic%5); ++i){
      tens.push_back(tags[mode+2]);
    }
    arabic -= arabic%5;
    if ( (arabic%10) ){
      tens.push_back(tags[mode+1]);
      arabic-=5;
    }
  }
}

string superRomanize( int arabic ){
  string dummy; // A roman numeral is constructed in reverse order
  
  romanizeTens( dummy, arabic, 0 );
  arabic /= 10;
  romanizeTens( dummy, arabic, 3 );
  arabic /= 10;
  romanizeTens( dummy, arabic, 6 );
  arabic /= 10;
  for (int i=0; i!= arabic; ++i){
    dummy.push_back('M');
  }
  string returnDummy(dummy.rbegin(),dummy.rend());
  return returnDummy;
}

int main(void){
  std::fstream readFile("p089_roman.txt");
  string storage;
  readFile >> storage;

  map<char,int> order;
  order['I'] = 1; order['V']=5; order['X']=10; order['L']=50; 
  order['C']=100; order['D']=500; order['M']=1000;
  
  int spare = 0;
  while (storage != ""){
    int arabic = numerify(storage,order);
    string reRomanized = superRomanize(arabic);
    spare += storage.size() - reRomanized.size();
    storage.clear();
    readFile >> storage;
  }
  readFile.close();
  cout << spare << endl;
  return 0;
}
