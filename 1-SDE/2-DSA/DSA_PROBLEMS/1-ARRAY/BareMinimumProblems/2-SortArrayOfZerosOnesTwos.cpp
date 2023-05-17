#include<iostream>

using namespace std;

void print_array(int* arr, int arr_size){
    cout << "--------------------------------------------------" << endl;
    for(int i=0 ; i<arr_size ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

// function to use two pointers to segregate 0,1 in exactly one pass
void sort_01(int* arr, int arr_size){
    // we need two indices to make this segregation
    int left=0, right=arr_size-1;

    while(left < right){
        // keep incrementing left till a 1 is encountered
        while(left<right && arr[left]!=1){
            left++;
        }

        // keep decrementing right till a 0 is encountered
        while(left<right && arr[right]!=0){
            right--;
        }

        // if incrementation/decrementation do not result in left<right
        if(left<right){
            if(arr[left] > arr[right]){
                swap(arr[left], arr[right]);
            }
            left++;
            right--;
        }
    }

    
}

// sorting in exactly one pass and this method is stable
// counting method required 2 passes and is not stable
void sort_012(int* arr, int arr_size){
    // we require 3 indices to solve this segregation problem
    int low=0, mid=0, high=arr_size-1;

    while( mid < high ){
        if(arr[mid] == 0){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else if(arr[mid] == 2){
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main(){
    int arr[] = {0,1,0,0,1,1,2,1,2,0,1,1,0};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    print_array(arr, arr_size);

    sort_012(arr, arr_size);

    print_array(arr, arr_size);

    int arr2[] = {0, 1, 0, 1, 0, 0, 1, 1, 1, 0};
    int arr2_size = sizeof(arr2)/sizeof(arr2[0]);

    print_array(arr2, arr2_size);

    sort_01(arr2, arr2_size);

    print_array(arr2, arr2_size);


    return 0;
}