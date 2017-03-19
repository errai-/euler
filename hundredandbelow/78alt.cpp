#include <iostream>
#include <cmath>
#include <vector>
#include <cstdint>

void Partition( int N, uint64_t * partitions ){
   int64_t partition = 0;
   int64_t tmplo,tmphi;
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
   uint64_t Max = 1000;
   uint64_t * partitions = new uint64_t[Max+1];
   uint64_t i;
   for (i=0; i<=maximum; i++)
      partitions[i]=0;
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

