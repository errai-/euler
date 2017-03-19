#include <iostream>
#include <cmath>

bool Tester(int start, int rule, int trie)
{
   int work_horse = rule-start;
   trie = trie - start;
   if (trie%work_horse == 0){
      return 1;
   }
   return 0;
}

int FindRule(int start, int rule, int digits)
{
   int diff = 0;
   int tmp;
   int trp;
   int tdp;
   int tmp_val = 0;
   int trp_val = 0;
   int tdp_val = 0;
   int work_horse = rule-start;
   for (int i = 0; i < digits; i++)
   {
      tmp = pow(10,i);
      trp = (rule%(10*tmp))/tmp;
      tdp = (start%(10*tmp))/tmp;
      tmp_val = trp-tdp;
      if (tmp_val < 0){
         return 0;
      }
      if (tmp_val > 0){
         if (!diff){
            diff = tmp_val;
            trp_val = trp;
            tdp_val = tdp;
         }else if (tmp_val != diff){
            return 0;
         }else if (trp_val != trp){
            return 0;
         }else if (tdp_val != tdp){
            return 0;
         }
      }
   }
   if (diff == 0){
      return 0;
   }
   return work_horse/diff;
}

// No. 2 is a "trivial" prime and is not included in primes
bool IsPrime(int trie, int * primes)
{
   int edge = sqrt(trie)+1;
   int i = 0;
   while (primes[i] < edge){
      if (!(trie%primes[i])){
         return 0;
      }
      i++;
   }
   return 1;
}

// current has to be an odd number
int NextPrime(int current, int * primes)
{
   while(1){
      current = current + 2;
      if (IsPrime(current, primes)){
         return current;
      }
   }
}

class Cumulation{
      int amount;
      // starter is always the smallest prime of the possible family
      int starter;
      // ruler determines the rule of a current family
      int ruler;
   public:
      Cumulation(){}
      ~Cumulation(){}

      Cumulation(int start, int rule)
      {
         starter = start;
         ruler = rule;
         amount = 2;
      }

      int Adder(int trie)
      {
         if (Tester(starter, ruler, trie)){
            amount++;
         }
         return amount;
      }

      int Starter()
      {
         return starter;
      }
};

int main(void)
{
   int digits = 6;
   int edge = pow(10,digits);
   int amount = 100 + 0.2*edge;
   int * primes = new int[amount];
   int start_index = 0;
   int end_index;
   int i = 0;
   int j;
   int tmpval;
   int summarum;
   int k;
   int a;
   int b;
   primes[0] = 3;
   while(primes[i] < edge){
      i++;
      primes[i] = NextPrime(primes[i-1],primes);
      if ( (!(start_index)) && (primes[i] > edge/10) ){
         start_index = i;
      }
   }
   end_index = i;
   for (i = start_index; i < end_index-1; i++){
      for (j = i+1; j < end_index; j++){
         tmpval = FindRule(primes[i], primes[j], digits);
         if (tmpval){
            summarum = 2;
            for (k = j+1; k < end_index; k++){
               if ( primes[k] > primes[i]+9*tmpval ){
                  break;
               }
               a = FindRule(primes[i],primes[k],digits);
               b = FindRule(primes[j],primes[k],digits);
               if ( a && b && (a==b) ){
                  summarum++;
               }
            }
            if (summarum == 8){
               std::cout << primes[i] << std::endl;
            }
         }
      }
      // std::cout << storage_size << " " << amount << std::endl;
   }
   return 1;
}

