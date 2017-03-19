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

int PrimeInd(int trie, int * primes)
{
   int i = 0;
   while (primes[i] <= trie){
      i++;
   }
   return i-1;
}

bool InPrimes(int trie, int * primes)
{
   if (primes[PrimeInd(trie,primes)+1]==trie){
      return 1;
   }else{
      return 0;
   }
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

int PrimeSums( int remaining, int maxind, int * primes ){
   int count = 0;
   if ( (remaining==2) || (remaining==0) ){
      count = 1;
   }else if ( InPrimes( remaining, primes ) ){
      if ( InPrimes( remaining-2, primes ) )
         count++;
      count++;
   }else{
      int i = maxind;
      while ( primes[i] > remaining )
         i--;
      while ( i >= 0 ){
         count += PrimeSums( remaining - primes[i], i, primes );
         i--;
      }
   }
   return count;
}

int main(void)
{
   int maximum = 1000; // Should be divisible by 12
   int prime_amount = 1.3*maximum/log(maximum);
   int * primes = new int[prime_amount];
   int i = 1;
   int greatest=0;
   int amount=0;
   int tmp;
   primes[0] = 2;
   primes[1] = 3;
   while(primes[i] < maximum){
      i++;
      primes[i] = NextPrime(primes[i-1],primes);
   }
   prime_amount = i;
   for (int i = 10; i < maximum; i++){
      tmp = PrimeSums( i, PrimeInd(i,primes), primes);
      if (tmp > greatest){
         greatest = tmp;
         amount = i;
      }
      if (greatest > 5000) break;
   }
   std::cout << amount << " " << greatest << std::endl;
   return 1;
}

