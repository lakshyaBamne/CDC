// Implementing a Dynamic Array like Vector using 
// dynamic memory allocation using new/delete
// first we make a class and make sure it works fine
// then make a template out of it for various data types

#include<iostream>

class vector{
private: // private member attributes

    int size;
    int capacity;
    int* array = NULL;

public: // public member functions

    // default constructor is called when an empty vector is initialized
    vector() : size(0), capacity(1){
        array = new int[capacity];

        this->print_array();
    }

    // modified constructor is called when a vector of fixed size is requested
    vector(int array_size) : size(0), capacity(array_size){
        array = new int[capacity];

        this->print_array();
    }

    int get_size(){
        return size;
    }

    int get_capacity(){
        return capacity;
    }

    // method to push an element at the end of the array
    void push_back(int element){
        if(size == capacity){
            // array is full and needs to be grown
            grow_array();
        }
        
        // now insert the element
        array[size] = element;
        size++;

        std::cout << "Element added" << std::endl;
    }

    // method to grow the array to double it's current capacity
    void grow_array(){
        std::cout << "Array size doubled ( " << capacity << " -> " << capacity*2 << " )" << std::endl;

        int* bigger = new int[capacity*2];

        capacity = capacity*2;

        for(int i=0 ; i<size ; i++){
            bigger[i] = array[i];
        }
        delete[] array;
        array = bigger;

    }   

    void shrink_array(){

    }

    void print_array(){
        if(size){
            std::cout << "Elements :- ";
            for(int i=0 ; i<size ; i++){
                std::cout << array[i] << " ";
            }
            std::cout << std::endl;
        }
        else{
            std::cout << "Array is empty !!" << std::endl;
        }
        
    }


};

int main(){
    vector hue;

    std::cout << hue.get_capacity() << std::endl;

    for(int i=0 ; i<11 ; i++){
        hue.push_back(i+10);
        hue.print_array();
    }

    std::cout << hue.get_capacity() << std::endl;

    return 0;
}

