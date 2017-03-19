#include <iostream>
#include <cmath>
#include <vector>

// This function expects that the given number is not divisible by 2
bool IsPrime(int prime_candidate, int * primes)
{
   int border = sqrt(prime_candidate);
   int i = 0;
   while (primes[i] <= border){
       if (prime_candidate%primes[i]==0){
           return 0;
       }
       i++;
   }
   return 1;
}


int NextPrime(int current_prime, int * primes)
{
   int runner = current_prime;
   while(1){
      runner = runner + 2;
      if ( IsPrime(runner, primes) ){
          return runner;
      }
   }
}


bool IsPermutation(int number, int phi){
   int digits = log10(number);
   std::vector<int> numbers (10,0);
   for (int i = 0; i<digits; i++){
      numbers[ number%10 ]++;
      numbers[ phi%10 ]--;
      number/=10;
      phi/=10;
   }
   for (int i = 0; i<10; i++){
      if (numbers[i]!=0) return 0;
   }
   return 1;
}

std::vector<int> Factorize(int number, int * primes){
   int looper = 0;
   std::vector<int> factors;
   while(1){
      if (primes[looper]>number)
         break;
      if (number%primes[looper]==0){
         if (primes[looper]<1200){
            return std::vector<int> (1,1);
         }
         factors.push_back(primes[looper]);
      }
      looper++;
   }
   if (factors.size() == 1)
      return std::vector<int> (1,1);
   return factors;
}

int main(){
   int maximum_number = 10000000;
   int prime_amount = 1.3*maximum_number/log(maximum_number);
   int * primes = new int[prime_amount];

   // Look for the primes needed, except for 2
   primes[0] = 3;
   int latest_prime = 3;
   for (int i = 1; i < prime_amount; i++){
      latest_prime = NextPrime(latest_prime, primes);
      primes[i] = latest_prime;
      if (latest_prime > maximum_number){
         prime_amount = i;
         break;
      }
   }
   std::vector<int> facotors;
   int phi, m, o;
   double indicator;
   indicator = maximum_number;
   m = 0;
   for (int i = 0; i < prime_amount; i++){
      if (primes[i]<1325)
         continue;
      for (int j = i+1; j < prime_amount; j++){
         o = primes[i]*primes[j];
         if ((o>10000000)||(o<0)){
            break;
         }
         phi = o-primes[i]-primes[j]+1;
         if (IsPermutation(o,phi)){
            std::cout << o << " " << phi << " " << (1.0*o)/phi << " " << m << std::endl;
            if ( ( (double) o)/phi < indicator) {m = o; indicator = ( (double) o)/phi;}
         }
      }
   }
   std::cout << o << std::endl;
   delete[] primes;
}
