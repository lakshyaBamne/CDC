/*
    Given sorted array of elements in Ascending order
    Return an array sorted in a wave like fashion

    Time Complexity => O(n) => {O(n/2)}
    Space Complexity => O(1)
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void print_vector(vector<int> &arr){
    cout << "------------------------------------------------" << endl;
    for(int i=0 ; i<arr.size() ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

// class to contain the solution for the wave array problem
class WaveArray{
public:
    // function to convert a sorted array in ascending order to wave array
    void convert_to_wave_sorted(vector<int> &arr){
        vector<int>::iterator it = arr.begin()+1;

        while(it <= arr.end()-1){
            iter_swap(it, it-1);

            it = it + 2;
        }
    }

    // function to convert an unsorted array to wave array
    void convert_to_wave(vector<int> &arr){
        vector<int>::iterator it = arr.begin();

        while(it < arr.end()){
            if(it == arr.begin()){
                // first even element
                if(*it < *(it+1)){
                    iter_swap(it, it+1);
                }
            }

            else if(it > arr.begin() && it < arr.end()-1){
                // middle even elements
                if(*it < *(it-1)){
                    iter_swap(it, it-1);
                }
                else if(*it < *(it+1)){
                    iter_swap(it, it+1);
                }
            }

            else if(it == arr.end()-1){
                // last even element
                if(*it < *(it-1)){
                    iter_swap(it, it-1);
                }
            }

            it = it + 2;
        }
    }
};

int main(){
    vector<int> vec = {2,4,7,8,9,10};
    vector<int> vec2 = {1,3,2,7,8,9,4};

    print_vector(vec);

    WaveArray wa;

    wa.convert_to_wave(vec);

    print_vector(vec);

    print_vector(vec2);

    wa.convert_to_wave(vec2);

    print_vector(vec2);

    return 0;
}
