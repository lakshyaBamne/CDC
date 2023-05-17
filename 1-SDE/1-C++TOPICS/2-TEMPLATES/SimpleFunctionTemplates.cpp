// Creating a generic function template for Selection sort algorithm
// this is for data types that already support all the required types
// this template cannot be used for complex custom data types

#include<iostream>

template <typename T>
void selection_sort(T arr[], T arr_size){
    int unsorted_index = 0;
    int min_index;
    T temp;

    // sorting ends when unsorted pointer reaches the end
    while(unsorted_index != arr_size-1){
        min_index = unsorted_index;
        
        for(int i=unsorted_index+1 ; i<arr_size ; i++){
            if( arr[i] < arr[min_index] ){
                min_index = i;
            }
        }

        // swap
        temp = arr[min_index];
        arr[min_index] = arr[unsorted_index];
        arr[unsorted_index] = temp;

        unsorted_index++;
    }
}

/*
    Simple class template for a dynamic array of a given size
*/
template <typename T>
class DynamicArray{
    public:
    int array_size;
    
    // pointer to the start of the array
    T* start = NULL;

    T arr[array_size] = new T[array_size]; 

    // by default, an array of size=1 is initialized
    DynamicArray() : array_size(1){
        std::cout << "Default Constructor called" << std::endl;

        start = new T[1];

        std::cout << "Initialized array is :- ";
        for(int i=0 ; i<array_size ; i++){
            std::cout << *(start + i) << " ";
        }
        std::cout << std::endl;
    }
    
    // if given a size, initialize the array with that size
    DynamicArray(int size) : array_size(size){
        std::cout << "Modified Constructor called" << std::endl;

        start = new T[array_size];

        std::cout << "Initialized array is :- ";
        for(int i=0 ; i<array_size ; i++){
            std::cout << *(start + i) << " ";
        }
        std::cout << std::endl;
    }

    // function prints the array at any point in time
    void print_array(){
        for(int i=0 ; i<array_size ; i++){
            std::cout << *(start++) << " ";
        }
        std::cout << std::endl;
    }

};

int main(){
    int arr[] = {5,4,6,1,2};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    char char_arr[] = {'e', 'd', 'f', 'a', 'b'};
    int char_arr_size = sizeof(char_arr)/sizeof(char_arr[0]);

    std::cout << "-----------------------------------------------------------------" << std::endl;
    std::cout << "Sorting an array using a Generic Function for Selection Sort" << std::endl;
    std::cout << "-----------------------------------------------------------------" << std::endl;
    std::cout << "For an Integer Array :- " << std::endl;
    std::cout << "-----------------------------------------------------------------" << std::endl;

    std::cout << "Initial Array :- ";
    for(int i=0 ; i<arr_size ; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "-----------------------------------------------------------------" << std::endl;
    
    selection_sort<int>(arr, arr_size);

    std::cout << "Sorted Array :- ";
    for(int i=0 ; i<arr_size ; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "-----------------------------------------------------------------" << std::endl;
    std::cout << "For a character array :- " << std::endl;
    std::cout << "-----------------------------------------------------------------" << std::endl;

    std::cout << "Initial Array :- ";
    for(int i=0 ; i<char_arr_size ; i++){
        std::cout << char_arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "-----------------------------------------------------------------" << std::endl;
    
    selection_sort<char>(char_arr, char_arr_size);

    std::cout << "Sorted Array :- ";
    for(int i=0 ; i<char_arr_size ; i++){
        std::cout << char_arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "-----------------------------------------------------------------" << std::endl;

    // using the template for the dynamic array
    DynamicArray<int> vec1;
    
    DynamicArray<double> vec2(10);

    return 0;
}

