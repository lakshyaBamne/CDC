// codes to practice application of STL-Vector

#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main(){
    // declaring a vector for integers
    vector<int> hue1;

    cout << "Initialized a vector without any arguments :- " << endl;
    cout << "Size of vector :- " << hue1.size() << endl;
    cout << "Capacity of the vector :- " << hue1.capacity() << endl;

    for(int i=0 ; i<10 ; i++){
        hue1.push_back(i);

        cout << "-------------------------------------------------" << endl;
        cout << "After inserting a vector at the end :- " << endl;
        cout << "Size of vector :- " << hue1.size() << endl;
        cout << "Capacity of the vector :- " << hue1.capacity() << endl;
    }

    

    return 0;
}
