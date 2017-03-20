
CXX:=g++
CXXFLAGS:=-std=c++11 -g -Wall -Wextra -Werror -Wno-error=unused-parameter \
 -Wno-error=unused-function -Wno-error=unknown-pragmas -march=native -O3 -pedantic -m64

main: main.cpp
	$(CXX) $(CXXFLAGS) -I. -Wl,-rpath=$(PWD) -L. main.cpp -o $@

