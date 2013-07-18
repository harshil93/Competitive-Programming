#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <sys/time.h>

#define MOD 10000007
int main() {
    timeval a;
    timeval b;
    int64_t temp,temp1;
    srand(time(NULL));
    gettimeofday(&a, 0);
    for (int i = 0; i < 10000000; ++i)
    {
    	temp1 = rand();
    	temp = temp1*temp;
    }
    gettimeofday(&b, 0);

    std::cout << "difference in seconds: " << (b.tv_sec - a.tv_sec) << std::endl;
    std::cout << "difference: in useconds " << (b.tv_usec - a.tv_usec) << std::endl;
    return 0;
}