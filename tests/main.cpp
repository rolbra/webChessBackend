#include <iostream>

#include "testManager.hpp"

int main()
{
    TestManager testManager;

    std::cout << "Tests will be executed...\n" << std::endl;
    
    if( testManager.executeAll() == false )
    {
        std::cout << "Terminated with errors" << std::endl;
        return -1;
    }
    else
    {
        std::cout << "Terminated without errors" << std::endl;
        return 0;
    }
}