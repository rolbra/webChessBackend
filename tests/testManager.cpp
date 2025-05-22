#include "testManager.hpp"
#include <iostream>

TestManager::TestManager()
{

}

bool TestManager::executeAll()
{
    for( int i=0; i<0; i++ )
    {
        //execute testfunction
        if( false )
            this->allSuccessful = false;
    }

    std::cout << "all tests terminated" << std::endl;

    return this->allSuccessful;
}