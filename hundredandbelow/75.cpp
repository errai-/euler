#include <iostream>
#include <cmath>
#include <vector>
#include <cstdint>

int main(void)
{
   int maximum = 1500000;
   uint64_t i,j,k,counter,upper,lower,totalcount;
   double tmp;
   totalcount = 0;
   // Looping over values of L
   for (i =1; i < maximum/2; i++){
      counter = 0; // counts the feasible triangles per loop
      j = 2*i;
      tmp = floor(0.5*( j + 1/j ));
      upper = (int) tmp;
      tmp = ceil(j/(1+sqrt(2)));
      lower = (int) tmp;
      // Looping over values of c
      for (k = lower; k <= upper; k++){
         tmp = 0.5*(j-k) - 0.5*sqrt(2*pow(k,2.0)-pow(j-k,2.0));
         if ((tmp == round(tmp))&&tmp!=0)
            counter++;
         if (counter > 1){
            break;
         }
      }
      if (i%10000==0)
         std::cout << j << std::endl;
      if (counter==1)
         totalcount++;
   }
   std::cout << totalcount << std::endl;
}

