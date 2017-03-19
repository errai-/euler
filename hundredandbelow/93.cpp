#include <iostream>
#include <cmath>
#include <cstdint>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <set>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::uint64_t;
using std::clock_t;
using std::set;

int noP(int *el, vector<int> &build){
  int sumVal = 0;
  int sumGrid[]={0,0,0,0};
  int pos = 0;
  int tmp=0;
  for (int i=0; i!=3; ++i){
    if (build[i]<2){
      if (tmp) sumGrid[pos++] = tmp;
      tmp = 0;
      sumGrid[pos++] = el[i];
    } else {
      if (build[i]==3){
        tmp = tmp ? tmp*el[i+1] : el[i]*el[i+1];
      } else {
        tmp = tmp ? tmp/el[i+1] : el[i]*el[i+1];
      }
    }
    if (tmp) sumGrid[pos] = tmp;
  }
  sumVal = sumGrid[3];
  for (int i=2; i!=-1; --i){
    if (build[i]<2){
      if (build[i]==0){
        sumVal 
      }
    }
  }
}

void evaluator(int *el, vector<int> &build, vector<int> &parenth, set<int> &res){
  int sumVal = 0;
  int sumGrid[]={0,0,0,0};
  if (parenth.size()==0){
  } else if (parenth.size()==2){

  } else if (parenth.size()==1){

  } else if (parenth.size()==4){

  }

  set.insert(sumVal);
}

// Parentheses
void stage3(int *el, vector<int> &build, set<int> &res){
  vector<int> par0; // no parentheses
  evaluator(el,build,par0,res);
  for (int i=0; i!=3; ++i){ // one pair of parentheses
    for (int j=i+2; j!=5; ++j){
      vector<int> par1;
      par1.push_back(i); par1.push_back(j);
      evaluator(el,build,par1,res);
    }
  }
  vector<int> par2; // two parentheses, no overlap
  par2.push_back(0);
  evaluator(el,build,par2,res);
  for (int i=0; i!=2; ++i){ // two parentheses, overlap
    for (int j=0; j!=2; ++j){
      vector<int> par3;
      par3.push_back(i); par3.push_back(i+3);
      par3.push_back(j); par3.push_back(j);
      evaluator(el,build,par3,res);
    }
  }
}

// Signs
void stage2(int *elements, vector<int> &build, set<int> &res){
  if ( build.size()<3 ){
    for (int i=0; i!=4; ++i){
      vector<int> nBuild(build);
      nBuild.push_back(i);
      stage2(elements,nBuild,res);
    }
  } else {
    stage3(elements,build,res);
  }
}

// returns the highest consecutive count
int consecution(int a,int b,int c,int d){
  int elements[]={a,b,c,d};
  set<int> resNos;
  do {
    vector<int> null;
    stage2(elements,null,resNos);
  } while ( std::next_permutation(elements,elements+4) );
  int consCount = 0, highCount = 0; int previous = 0;
  for (auto i = resNos.begin(); i != resNos.end(); ++i){
    if ( consCount!=0 && (*i-previous)!=1 ){
      if (highCount < consCount){
        highCount = consCount;
      }
      consCount = 0;
    } else {
      consCount++;
      previous = *i;
    }
  }
  return highCount;
}

int main(void){
  int best = 0;
  int bestNos[4];
  clock_t start = clock();
  for (a=0; a!=7; ++a){
    for (b=a+1; b!=8; ++b){
      for (c=b+1; c!=9; ++c){
        for (d=c+1; d!=10; ++d){
          int tmpCons = consecution(a,b,c,d);
          if (tmpCons>best){
            best = tmpCons;
            bestNos[0]=a; bestNos[1]=b; bestNos[2]=c; bestNos[3]=d;
          }
        }
      }
    }
  }

  cout << "Ans: " <<  << " Time: ";
  cout << (clock()-start)/((double)CLOCKS_PER_SEC) << "s" << endl;
  return 0;
}
