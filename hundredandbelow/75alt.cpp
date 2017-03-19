#include <iostream>
#include <cmath>
#include <vector>
#include <cstdint>


int main(void)
{
   int maximum = 1500000; // Should be divisible by 12
   int * numbers = new int[maximum/2-1];
   uint64_t i,j,k,bandari;
   for (i = 0; i < maximum/2-1; i++){
      numbers[i] = 0;
   }
   int boundary = floor(maximum/(1+sqrt(2)));
   double tmp;
   uint64_t indicator;
   for (i = 1; i <= boundary; i++){
      if (i%100==1)
         std::cout << i << " " << bandari << std::endl;
      bandari = maximum*(maximum-2*i)/(2*(maximum-i));
      for (j = i; j <= bandari; j++){
         tmp = sqrt( pow(i,2.0)+pow(j,2.0) );
         if ( tmp == round(tmp) ){
            k = (int) tmp;
            k = k + i + j;
            if (k > maximum)
               break;
            numbers[k/2-2]++;
         }
      }
   }
   indicator = 0;
   for (i = 0; i < maximum/2 -1; i++){
      if (numbers[i] == 1)
         indicator++;
   }
   std::cout << indicator << std::endl;
   delete[] numbers;
   return 1;
}

