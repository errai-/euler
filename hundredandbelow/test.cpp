#include <iostream>
#include <cmath>
#include <vector>
#include <cstdint>
#include <stdio.h>
#include <gmp.h>

int main(void)
{
   mpz_t partition;
   mpz_t portition;
   mpz_init_set_str(partition, "3",10);
   mpz_init_set_str(portition, "11",10);
   mpz_add(partition, partition, portition);
   char fug[100];
   mpz_get_str(fug, 10, partition);
   std::cout << fug << std::endl;
}
   
