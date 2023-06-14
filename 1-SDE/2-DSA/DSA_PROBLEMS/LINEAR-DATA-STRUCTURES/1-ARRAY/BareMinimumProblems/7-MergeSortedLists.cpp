#include<iostream>
#include<vector>

using namespace std;

void print_array(int* arr, int arr_size){
    for(int i=0 ; i<arr_size ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print_vector(vector<int> &arr){
    for(int i=0 ; i<arr.size() ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int* merge(int* A, int n1, int* B, int n2) {
    int sorted[n1+n2] = {};

    int a=0, b=0;
    int s=0;

    // atleast one array whould be 
    while( a<n1 && b<n2 ){
        if( A[a] <= B[b] ){
            sorted[s] = A[a];
            s++;
            a++;
        }
        else{
            sorted[s] = B[b];
            s++;
            b++;
        }
    }
    
    if( a==n1 ){
        // a is exhausted and hence all elements of the other array 
        // are appended directly
        while( b<n2 ){
            sorted[s] = B[b];
            b++;
            s++;
        }
    }
    else if(b==n2){
        while( a<n1 ){
            sorted[s] = A[a];
            a++;
            s++;
        }
    }

    int* result = new int[n1+n2];

    for(int i=0 ; i<n1+n2 ; i++){
        result[i] = sorted[i];
    }

    return result;

}

void merge(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int a=0, b=0;

    // we add elements from the back of the array for better efficiency
    while( a<A.size() && b<B.size() ){
        if( A[a] < B[b] ){
            // do nothing
            a++;
        }
        else{
            A.insert( A.begin() + a , B[b] );
            a++;
            b++;
        }
    }

    if( a == A.size() ){
        // insert all elements of B at the end of A
        while( b<B.size() ){
            A.push_back(B[b]);
            b++;
        }
    }


}

int main(){
    vector<int> A = {1,5,8};
    vector<int> B = {6,9};

    merge(A, B);

    print_vector(A);

    return 0;
}