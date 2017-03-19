#include <iostream>
#include <cmath>
#include <vector>
#include <cstdint>
#include <algorithm>

uint64_t Factorial( uint64_t number ){
   uint64_t product = 1;
   while (number > 1){
      product *= number;
      number--;
   }
   return product;
}

uint64_t Next( uint64_t number ){
   int digits = log10(number)+1;
   int sum = 0;
   for (int i = 0; i < digits; i++){
      sum += Factorial( number%10 );
      number /= 10;
   }
   return sum;
}

int main(void)
{
   int maximum = 1000000; // Should be divisible by 12
   int i,j,k,indicator;
   uint64_t tmp;
   std::vector<uint64_t> factors (1,1);
   int total = 0;
   for (i =3; i < maximum; i++){
      indicator = 1;
      factors.clear();
      tmp = i;
      k = 0;
      factors.push_back(i);
      while (indicator){
         tmp = Next(tmp);
         k++;
         for (j=0; j<factors.size(); j++){
            if (factors[j]==tmp){
               indicator = 0;
               break;
            }
         }
         factors.push_back(tmp);
      }
      if (k == 60)
         total++;
      if (i%1000)
         std::cout << i << std::endl;
   }
   std::cout << total << std::endl;
   return 1;
}

