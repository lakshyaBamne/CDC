#include<iostream>
#include<vector>

using namespace std;

// function to calculate the value of the sum of natural numbers
// till a given natural number
long long int natural_sum(int n){
    return (n*(n+1))/2;
}

// function to calculate the sum of all the elements in an array
long long int array_sum(vector<int>& arr){
    long long sum = 0;

    for(int i=0 ; i<arr.size() ; i++){
        sum = sum + arr[i];
    }

    return sum;
}

int missingNumber(vector<int>& array, int n) {
    return natural_sum(n+1)-array_sum(array);
}

int main(){
    vector<int> arr = {6,1,2,8,3,4,7,10,5};

    cout << missingNumber(arr, arr.size());

    return 0;
}