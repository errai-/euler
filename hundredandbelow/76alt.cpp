#include <iostream>
#include <cmath>
#include <vector>
#include <cstdint>
#include <stdio.h>
#include <gmp.h>

void Partition( int N, mpz_t * partitions ){
   mpz_t partition;
   mpz_init_set_str(partition, "0",10);
   int tmplo,tmphi;
   for ( int i = 1; i<=N; i++ ){
      tmphi = N-(i*(3*i-1))/2;
      tmplo = N-(i*(3*i+1))/2;
      if (tmphi < 0)
         break;
      if (partitions[ tmphi ] == 0)
         Partition( tmphi, partitions );
      if (tmplo >= 0){
         if (partitions[ tmplo ] == 0)
            Partition( tmplo, partitions );
         partition += pow( -1, i+1 )*( partitions[ tmplo ] + partitions[ tmphi ] );
      }else{
         partition += pow( -1, i+1 )*partitions[ tmphi ];
      }
   }
   partitions[N] = partition;
}

int main(void)
{
   int maximum = 58;
   mpz_t Max = 10000;
   mpz_t * partitions = new mpz_t[maximum+1];
   mpz_t i;
   for (i=0; i<=maximum; i++)
      mpz_init_setpartitions[i] = 0;
   partitions[0] = 1;
   partitions[1] = 1;
   Partition( maximum, partitions );
   for (i=maximum+1; i < Max; i++){
      Partition( i, partitions );
      std::cout << partitions[i] << std::endl;
      if ( partitions[i]%1000000==0 )
         break;
   }
   std::cout << i << std::endl;
   return 1;
}

