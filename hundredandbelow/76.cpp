#include <iostream>
#include <cmath>
#include <vector>
#include <cstdint>


uint64_t Leveler( int level, int N ){
   uint64_t counter = 0;
   if (level > 2){
      for (int i = N; i > 0; i--){
         counter += Leveler( level - 1, i );
      }
   }else if (level == 2){
      counter = N*(N+1)/2;
   }else{
      counter = N;
   }
   return counter;
}

uint64_t Naive( int N, int limit, uint64_t * slots ){
   uint64_t counter = 0;
   int i,j,upper,standard,level;
   if ( N==1 )
      return 1;
   if ( (limit >= N) && (slots[N-1] != 0) )
      return slots[N-1];
   for (i = 1; i <= limit; i++){
      standard = N-i;
      counter += Naive( standard, i, slots );
   }
   return counter;
}

int main(void)
{
   int maximum = 100;
   uint64_t counter;
   int i,j,upper,standard,level;
   uint64_t * slots = new uint64_t[maximum];
   for (int i=0; i<maximum; i++)
      slots[i] = 0;
   slots[0] = 1;
   for (i = 2; i <= maximum; i++){
      counter = 1;
      upper = floor(i/2);
      for (j = 1; j <= upper; j++){
         counter += slots[j-1];
      }
      for (j = upper+1; j < i; j++){
         standard = i-j;
         counter += Naive( j, standard, slots );
         //counter += Leveler( level, slots[standard-1] );
      }
      slots[i-1] = counter;
   }
   std::cout << slots[ maximum - 1]-1 << std::endl;
   //std::cout << Naive( maximum, maximum-1 ) << std::endl;
   return 1;
}

