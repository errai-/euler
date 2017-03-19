#include <iostream>
#include <cmath>
#include <vector>
#include <cstdint>


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

std::vector<int> Factorize(int number, int * primes){
   int i = 0;
   std::vector<int> factors;
   while (primes[i]<number){
      if (number%primes[i]==0){
         factors.push_back(primes[i]);
      }
      i++;
   }
   return factors;
}

int main(void)
{
   int maximum = 12000; // Should be divisible by 12
   int prime_amount = 1.3*maximum/log(maximum);
   int * primes = new int[prime_amount];
   int i = 0;
   int j,k,indicator,tmp;
   primes[0] = 3;
   while(primes[i] < maximum){
      i++;
      primes[i] = NextPrime(primes[i-1],primes);
   }
   prime_amount = i;

   uint64_t sum_states = 0; // For divisors bigger than 2, there exists at least 2 new fractions
   std::vector<int> factors;
   // Parilliset d
   for (i = 1; i<=maximum/2; i++){
      if (i%1000==0) std::cout << i << std::endl;
      factors = Factorize(2*i,primes);
      for (j = 0; j<i; j++){
         indicator = 1;
         tmp = 2*j+1;
         for (k = 0; k<factors.size(); k++){
            if (factors[k]>tmp)
               break;
            if ( tmp%factors[k]==0 ){
               indicator = 0;
               break;
            }
         }
         if ((indicator)&&( ( (2.0*j+1)/(2*i)>1.0/3) && ( (2.0*j+1)/(2*i)<1.0/2) ) ) {
            sum_states++;
         }
      }
   }
   // Parittomat d
   for (i = 1; i<maximum/2; i++){
      factors = Factorize(2*i+1,primes);
      if (i%2000==0) std::cout << i << std::endl;
      for (j = 1; j < 2*i+1; j++){
         indicator = 1;
         for (k = 0; k<factors.size(); k++){
            if (factors[k]>j)
               break;
            if ( j%factors[k]==0 ){
               indicator = 0;
               break;
            }
         }
         if ((indicator)&&( (j/(2.0*i+1)>1.0/3) && (j/(2.0*i+1)<1.0/2) ) ){
            sum_states++;
         }
      }
   }
   std::cout << sum_states << std::endl;
   return 1;
}

