#include <iostream>
int main()
{
    int sum, value;
    sum = value = 0;
    std::cout<<"Input ints to get sum or others to quit"<<std::endl;
    while(std::cin>>value)
        sum += value;
    std::cout<<"Sum is : "<<sum<<std::endl;
    
    return 0;
}