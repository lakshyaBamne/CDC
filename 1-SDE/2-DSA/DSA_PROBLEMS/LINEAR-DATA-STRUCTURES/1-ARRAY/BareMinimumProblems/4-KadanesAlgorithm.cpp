#include<iostream>
#include<vector>

using namespace std;

// first let us try the problem using the sliding window approach
long long int max_subarray_sum_naive(int arr[], int n){ 
    long long int max_sum = INT_MIN, curr_sum;
    int win_left, win_right;

    for(int win_start=0 ; win_start < n ; win_start++){
        curr_sum = arr[win_start];

        if(curr_sum > max_sum){
            max_sum = curr_sum;

            win_left = win_start;
            win_right = win_start;
        }

        for(int win_end=win_start+1 ; win_end < n ; win_end++){
            // now we need to increase the curr_sum to accomodate the new element
            curr_sum = curr_sum + arr[win_end];
            
            if(curr_sum > max_sum){
                max_sum = curr_sum;

                win_left = win_start;
                win_right = win_end;
            }
        }
    }

    return max_sum;
}

// now we take another approach by using prefix sums to get O(n) solution
long long int max_subarray_sum_prefix_sum(int arr[], int n){
    // one variable should hold the prefix sum for the current index
    // another is used to store the maximum sum obtained
    long long curr_prefix_sum = arr[0];
    long long prev_prefix_sum;

    long long min_prefix_sum = arr[0];
    
    long long max_sum = arr[0];

    for(int i=1 ; i<n ; i++){
        // first we need to update the prefix sum til the current index
        prev_prefix_sum = curr_prefix_sum;
        curr_prefix_sum = curr_prefix_sum + arr[i];

        // updating the maximum sum contiguous subarray found till now
        max_sum = (max_sum >= curr_prefix_sum) ? max_sum : curr_prefix_sum;
        max_sum = (max_sum >= (curr_prefix_sum-min_prefix_sum)) ? max_sum : curr_prefix_sum-min_prefix_sum;

        // updating the minimum prefix sum found till the current index
        min_prefix_sum = (curr_prefix_sum >= min_prefix_sum) ? min_prefix_sum : curr_prefix_sum;
    }

    return max_sum;

}

// we also discuss the Kadane's algorithm for this probelem
// this is also based on using the prefix sums but in a much more
// elegant fashion
long long int max_subarray_sum_kadane(int arr[], int n){
    return 0;
}

int main(){
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    cout << "Naive Running sum approach => " << max_subarray_sum_naive(arr, arr_size) << endl;

    cout << "Prefix Sum approach => " << max_subarray_sum_prefix_sum(arr, arr_size) << endl;

    cout << "Kadane's Algorithm => " << max_subarray_sum_kadane(arr, arr_size) << endl;

    return 0;
}