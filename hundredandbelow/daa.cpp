#include <iostream>
#include <cstdint>

template <typename T>
bool is_int64() { return false; }

template <>
bool is_int64<int64_t>() { return true; }

int main()
{
    std::cout << "int:\t" << is_int64<int>() << std::endl;
     std::cout << "int64_t:\t" << is_int64<int64_t>() << std::endl;
      std::cout << "long int:\t" << is_int64<long int>() << std::endl;
       std::cout << "long long int:\t" << is_int64<long long int>() << std::endl;

        return 0;
}
