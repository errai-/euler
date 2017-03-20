
CXX:=g++
CXXFLAGS:=-std=c++11 -g -Wall -Wextra -Werror -Wno-error=unused-parameter \
 -Wno-error=unused-function -Wno-error=unknown-pragmas -march=native -O3 -pedantic -m64

main: Next.h main.cpp
	$(CXX) -I. -Wl,-rpath=$(PWD) -L. Next.h main.cpp -o $@

