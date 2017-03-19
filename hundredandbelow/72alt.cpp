#include <iostream>
#include <cmath>
#include <vector>
#include <cstdint>


//std::vector<int> Divisors(int number, int * primes){
//   std::vector<int> factors;
//   int i = 0;
//   int indicator = 0;
//   while (number%2 == 0){
//      if (i = 0){
//         factors.push_back(2);
//         factors.push_back(0);
//         i += 3;
//      }
//      factors[1]++;
//      number /= 2;
//   }
//   while (i<sqrt(number)){
//      indicator = 1;
//      while (number%i == 0){
//         if (indicator){
//            factors.push_back(i);
//            factors.push_back(0);
//            indicator = 0;
//         }
//         factors[factors.size()-1]++;
//         number /= i;
//      }
//      i += 2;
//   }
//   if (number != 1){
//      factors.push_back(number);
//      factors.push_back(1);
//   }
//   std::vector<int> permutations;
//   for (i = 0; i<factors.size()/2; i++){
//      factors[2*i+1]++;
//      for (indicator = i; indicator<factors.size()/2; indicator++){
//         while( factors[2*j

std::vector<int> Divisors(int number){
   std::vector<int> factors;
   int tmp = number/2+1;
   for (int i = 2; i < tmp; i++){
      if ( number%i==0 )
         factors.push_back(i);
   }
   return factors;
}

int main(void)
{
   int maximum = 1000000; // Should be divisible by 2
   int prime_amount = 1.3*maximum/log(maximum);
   int i = 0;
   int j,k,indicator,tmp;
   prime_amount = i;
   int * status = new int[maximum-1];
   
   uint64_t sum_states = 0; // For divisors bigger than 2, there exists at least 2 new fractions
   std::vector<int> factors;
   for (i = 0; i < maximum-1; i++){
      if (i%5000==0)
         std::cout << i << std::endl;
      factors = Divisors(i+2);
      tmp = i+1;
      for (j = 0; j < factors.size(); j++){
         tmp -= status[factors[j]-2];
      }
      sum_states += tmp;
      status[i]=tmp;
   }
   std::cout << sum_states << std::endl;
   delete[] status;
   return 1;
}

