#include <iostream>
#include <cmath>
#include <vector>
#include <cstdint>




bool IsFitting(uint64_t troe, uint64_t other, uint64_t digits)
{
   uint64_t derp;
   uint64_t dorp;
   uint64_t oppi;
   std::vector<uint64_t> tramounts (10,0);
   std::vector<uint64_t> otamounts (10,0);
   for (uint64_t i = 0; i < 10; i++){
      tramounts[i] = 0;
      otamounts[i] = 0;
   }
   for (uint64_t i = 0; i < digits; i++){
      oppi = pow(10,i);
      derp = ( troe%(10*oppi) )/oppi;
      dorp = ( other%(10*oppi) )/oppi;
      tramounts[derp]++;
      otamounts[dorp]++;
   }
   for (uint64_t i = 0; i < 10; i++){
      if (tramounts[i] != otamounts[i]){
         return 0;
      }
   }
   return 1;
}


int main(void){
   uint64_t digits = 12;
   uint64_t wanted = 5;
   uint64_t start = ceil( cbrt( pow(10,digits-1) ) );
   uint64_t end = ceil( cbrt( pow(10,digits) ) );
   std::vector<uint64_t> values;
   std::vector<uint64_t> indices;
   uint64_t i;
   for (i = start; i < end; i++){
      values.push_back( pow(i,3) );
   }
   i = 0;
   uint64_t amount;
   uint64_t j;
   std::cout << values.size() << " " << values[0] << " " << values[1] << std::endl;
   while (values.size() > wanted - 1){
      amount = 1;
      for (j = 1; j < values.size(); j++){
         if (IsFitting(values[0],values[j],digits)){
            amount++;
            indices.push_back(j);
         }
      }
      if (amount == wanted){
         std::cout << values[0] << std::endl;
      }
      //for (i = 1; i <= indices.size(); i++){
      //   values.erase( values.begin()+indices[indices.size()-i] );
      //}
      values.erase( values.begin() );
      indices.clear();
   }
}

