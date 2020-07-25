#include <unordered_map>
#include <cstdio>
#include <omp.h>
#include <iostream>

int main(int argc, char *argv[])
{
  std::unordered_map<unsigned,std::string> map{
    {200505,"2.5"},{200805,"3.0"},{201107,"3.1"},{201307,"4.0"},{201511,"4.5"}};
  std::cout<<"We have OpenMP "<< _OPENMP;
  return 0;
}