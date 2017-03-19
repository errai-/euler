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

class Gruppe {
      int * numbers = new int[5];
      int member_count;
   public:

      Gruppe(int single){
         numbers[0] = single;
      }

      Gruppe(int * previous, int amount, int addition){
         for (int i = 0; i < amount; i++){
            numbers[i] = previous[i];
         }
      }

      bool IsCompatible(int, int *);
      int CurrentSum();
      int * Members(){
         return numbers;
      }
      int MemberAmount(){
         return member_count;
      }
};

bool Gruppe::IsCompatible(int trie, int * primes){
   int exponent;
   int permutation;
   int const_exponent = log10(trie)+1;
   for (int i = 0; i < member_count; i++){
      permutation = numbers[i]*pow(10, const_exponent)+trie;
      if (!IsPrime(permutation, primes)){
         return 0;
      }
      exponent = log10(numbers[i])+1;
      permutation = numbers[i]+pow(10, exponent)*trie;
      if (!IsPrime(permutation, primes)){
         return 0;
      }
   }
   return 1;
}

int Gruppe::CurrentSum(){
   int sum_storage = 0;
   for (int i = 0; i < member_count; i++){
      sum_storage = sum_storage + numbers[i];
   }
   return sum_storage;
}



int main(){
   int number_of_primes = 30;
   int * primes = new int[number_of_primes];
   primes[0] = 3;
   int latest_prime = 3;
   
   for (int i = 1; i < number_of_primes; i++){
      latest_prime = NextPrime(latest_prime, primes);
      std::cout << latest_prime << std::endl;
      primes[i+1] = latest_prime;
   }

   //Gruppe foo1 = Gruppe(3);
   //std::cout << foo1.IsCompatible(7, primes) << foo1.IsCompatible(9, primes) << std::endl;
   //Gruppe foo2 = Gruppe(foo1.Members(), foo1.MemberAmount(), 7);
   //std::cout << foo2.IsCompatible(109, primes) << foo2.IsCompatible(7, primes) << std::endl;

   delete[] primes;
}
