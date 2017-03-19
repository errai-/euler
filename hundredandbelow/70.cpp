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

// class Gruppe {
//       int * numbers = new int[5];
//       int member_count;
//    public:
//  
//       Gruppe(){}
//  
//       void SetValues(int single){
//          numbers[0] = single;
//          member_count = 1;
//       }
//  
//       void SetValues(int * previous, int amount, int addition){
//          for (int i = 0; i < amount; i++){
//             numbers[i] = previous[i];
//          }
//          member_count = amount + 1;
//          numbers[amount] = addition;
//       }
//  
//       bool IsCompatible(int, int *);
//       int CurrentSum();
//       int * Members(){
//          return numbers;
//       }
//       int MemberAmount(){
//          return member_count;
//}}     }
//  ;
//B
// ool Gruppe::IsCompatible(int trie, int * primes){
// int exponent;
// int permutation;
// int const_exponent = log10(trie)+1;
// for (int i = 0; i < member_count; i++){
//    permutation = numbers[i]*pow(10, const_exponent)+trie;
//    if (!IsPrime(permutation, primes)){
//       return 0;
//    }
//    exponent = log10(numbers[i])+1;
//    permutation = numbers[i]+pow(10, exponent)*trie;
//    if (!IsPrime(permutation, primes)){
//       return 0;
//      }
//   }
//}  return 1;
//
//Ii
//  nt Gruppe::CurrentSum(){
//    int sum_storage = 0;
//    for (int i = 0; i < member_count; i++){
//       sum_storage = sum_storage + numbers[i];
//    }
//}}  return sum_storage;

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
         if (primes[looper]<2500){
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
         prime_amount = i+1;
         break;
      }
   }

   int phi, m, o, indicator;

//   for (int n = 0; n < prime_amount; n++){
//      m = primes[n];
//      if (m>sqrt(10000000))
//         break;
//      o = 1;
//      indicator = 0;
//      while ((o*m<maximum_number) && (o*m>0)){
//         o *= m;
//         indicator++;
//      }
//      phi = o - indicator;
//      if (IsPermutation(o,phi))
//         std::cout << o << " " << phi << std::endl;
//   }
   std::vector<int> factors;
   for (int n = 1; n < maximum_number/2; n++){
      phi = 2;
      if (n%100000==0) std::cout << 2*n+1 << std::endl;
      factors = Factorize(2*n+1, primes);
      if ((factors.size()>0) && (factors[0]==1))
         continue;
      for (m = 3; m < 2*n+1; m++){
         indicator = 1;
         for (o = 0; o < factors.size(); o++){
            if (factors[o]> m)
               break;
            if ((m)%factors[o]==0){
               indicator = 0;
               break;
            }
         }
         if (indicator){
            phi++;
         }
      }
      if (IsPermutation(2*n+1,phi))
         std::cout << 2*n+1 << " " << phi << " " << phi/(2*n+1.0) << std::endl;
   }
   delete[] primes;
}
