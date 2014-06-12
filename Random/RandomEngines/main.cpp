#include <iostream>
#include <map>
#include <random>

int main(){
    //trying out random engines, testing dice roll distributions to make sure they're working
    
    std::random_device rd;
    std::mersenne_twister_engine<uint_fast32_t,
  32,624,397,31,0x9908b0df,11,0xffffffff,7,0x9d2c5680,15,0xefc60000,18,1812433253> gen(rd()); //AKA std::mt19937
    std::uniform_int_distribution<> dis(1,6);
    std::map<int, double> results;
    
    const int times = 1000000;
    
    for (int i = 0; i != times; ++i)
        results[dis(gen)-1]++;
        
    for (int i = 0; i != 6; ++i)
        std::cout << results[i] / times * 100 << "%" << std::endl;
}