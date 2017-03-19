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

      Gruppe(){}

      void SetValues(int single){
         numbers[0] = single;
         member_count = 1;
      }

      void SetValues(int * previous, int amount, int addition){
         for (int i = 0; i < amount; i++){
            numbers[i] = previous[i];
         }
         member_count = amount + 1;
         numbers[amount] = addition;
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
   int number_of_primes = 500000;
   int iteration_count = 1101;
   Gruppe * first = new Gruppe[2048];
   Gruppe * second = new Gruppe[16384];
   Gruppe * third = new Gruppe[8192];
   Gruppe * fourth = new Gruppe[1024];
   int first_amount = 1;
   int second_amount = 0;
   int third_amount = 0;
   int fourth_amount = 0;
   int * primes = new int[number_of_primes];
   primes[0] = 3;
   int latest_prime = 3;
   first[0].SetValues(latest_prime);
   for (int i = 1; i < number_of_primes; i++){
      latest_prime = NextPrime(latest_prime, primes);
      primes[i] = latest_prime;
   }

   for (int i = 0; i < iteration_count; i++){
      latest_prime = primes[i];
      first[i].SetValues(latest_prime);
      for (int j = 0; j < first_amount; j++){
         if (first[j].IsCompatible(latest_prime, primes)){
            second[second_amount].SetValues(first[j].Members(), first[j].MemberAmount(), latest_prime);
            second_amount = second_amount + 1;
         }
      }
      first_amount = first_amount + 1;
      for (int j = 0; j < second_amount; j++){
         if (second[j].IsCompatible(latest_prime, primes)){
            third[third_amount].SetValues(second[j].Members(), second[j].MemberAmount(), latest_prime);
            third_amount = third_amount + 1;
         }
      }
      for (int j = 0; j < third_amount; j++){
         if (third[j].IsCompatible(latest_prime, primes)){
            fourth[fourth_amount].SetValues(third[j].Members(), third[j].MemberAmount(), latest_prime);
            fourth_amount = fourth_amount + 1;
         }
      }
      for (int j = 0; j < fourth_amount; j++){
         if (fourth[j].IsCompatible(latest_prime, primes)){
            std::cout << "Success, found sum " << fourth[j].CurrentSum() + latest_prime << "of values " << 
               fourth[j].Members()[0] << "," << fourth[j].Members()[1] << "," << fourth[j].Members()[2] << " " 
               << fourth[j].Members()[3] << " and " << latest_prime << "\n";
         }
      }
   }
   std::cout << first_amount << " " << second_amount << " " << third_amount << " " << fourth_amount << "\n";
   delete[] primes;
   delete[] first;
   delete[] second;
   delete[] third;
   delete[] fourth;
}
