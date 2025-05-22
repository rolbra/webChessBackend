#include <iostream>


int main()
{
    bool allSuccessful;

    std::cout << "Tests will be executed...\n" << std::endl;
    
    //allSuccessful = testManager.executeTests();

    if( allSuccessful == false )
        return -1;
    else
        return 0;
}