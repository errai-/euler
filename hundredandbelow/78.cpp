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
      if ( mpz_get_ui( partitions[ tmphi ]) == 0)
         Partition( tmphi, partitions );
      if (tmplo >= 0){
         if ( mpz_get_ui(partitions[ tmplo ]) == 0)
            Partition( tmplo, partitions );
         if ( i%2 == 1 ){
             mpz_add( partition, partition, partitions[ tmplo ]);
         }else{
             mpz_sub( partition, partition, partitions[ tmplo ]);
         }
      }
      if ( i%2 == 1 ){
         mpz_add( partition, partition, partitions[ tmphi ] );
      }else{
         mpz_sub( partition, partition, partitions[ tmphi ] );
      }
   }
   mpz_add( partitions[N], partitions[N], partition );
}

bool LastZeros( mpz_t tester ){
   int size = mpz_sizeinbase( tester, 10 );
   if (size < 6)
      return 0;
   char values[size+2];
   mpz_get_str( values, 10, tester );
   if ( (values[size-1]=='0') && (values[size-2]=='0') && (values[size-3]=='0') && (values[size-4]=='0') && (values[size-5]=='0') && (values[size-6]=='0') )
      return 1;
   return 0;
}

int main(void)
{
   uint64_t maximum = 58;
   uint64_t Max = 1000000;
   mpz_t * partitions = new mpz_t[Max+1];
   uint64_t i;
   mpz_init_set_str(partitions[0], "1",10);
   mpz_init_set_str(partitions[1], "1",10);
   for (i=2; i<=Max; i++)
      mpz_init_set_str(partitions[i], "0",10);
   Partition( maximum, partitions );
   for (i=maximum+1; i < Max; i++){
      Partition( i, partitions );
      if ( LastZeros( partitions[i] ) )
         break;
   }
   std::cout << i << std::endl;
   return 1;
}

