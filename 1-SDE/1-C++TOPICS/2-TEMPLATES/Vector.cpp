/*
    Making a template for vector-like template
*/
#include<iostream>

// creating a vector like container using templates and dynamic arrays
template <typename T>
class vector{
public:
    int array_size;

    // default constructor
    vector() : array_size(1){


        std::cout << "Default Constructor Called" << std::endl;
    }

    vector(int size) : array_size(size){
        std::cout << "Custom Constructor Called" << std::endl;
    }

};

int main(){


    return 0;
}


