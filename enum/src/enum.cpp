#include <iostream>

enum Abc
{
    A = 4,
    B = 8,
    C = 12,
    D = 15
};

int main()
{
    int v1 = 15;
    Abc v2 = static_cast< Abc >( v1 );

    switch ( v2 )
    {
        case A:
            std::cout<<"A"<<std::endl;
            break;
        case B:
            std::cout<<"B"<<std::endl;
            break;
        case C:
            std::cout<<"C"<<std::endl;
            break;
        default :
            if ( v2 >= D )
                std::cout<<"bigger than D"<<std::endl;
            else
                std::cout<<"no match found"<<std::endl;
    }
}

