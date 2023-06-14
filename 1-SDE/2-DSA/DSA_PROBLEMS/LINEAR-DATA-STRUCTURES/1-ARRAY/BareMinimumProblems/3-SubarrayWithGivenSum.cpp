/*
    Naive approach is O(n^3) using nested looping
*/

#include<iostream>
#include<vector>

using namespace std;

void print_vector(vector<int> arr){
    for(int i=0 ; i<arr.size() ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

/*
    Code for Naive Approach => O(n^3) by using 3 nested loops
*/

//Function to find a continuous sub-array which adds up to a given number.
vector<int> subarray_sum(vector<int> arr, int n, long long s){
    long long int curr_sum;
    vector<int> result;
    
    for(int i=0 ; i<n ; i++){
        for(int j=i ; j<n ; j++){
            curr_sum = 0;

            for(int k=i ; k<=j ; k++){
                curr_sum = curr_sum + arr[k];
            }

            cout << curr_sum << endl;

            if(curr_sum == s){
                // found the sub array with the required sum
                result.push_back(i);
                result.push_back(j);

                return result;
            }
        }
    }

    result.push_back(-1);
    return result;
}

/*
    Another solution => using the Sliding Window Approach make it O(n^2)
    => still Time Limit Exceeded
*/

vector<int> sub_array_sliding_window(vector<int> arr, int n, long long s){
    // outer for loop tells what will the length of the sliding window be
    // starting from length=1 to length=n(size of the array)
    vector<int> result;

    vector<vector<int>> all_result;
    
    long long curr_sum;
    
    for(int i=1 ; i<=n ; i++){
        // inner loop is used to slide the window to the required positions
        // the window always starts sliding from the first index of the array
        curr_sum = 0;

        // we must calculate the result for the first window
        for(int j=0 ; j<i ; j++){
            curr_sum = curr_sum + arr[j];
        }

        if(curr_sum == s){
            result.push_back(0);
            result.push_back(i - 1);

            all_result.push_back(result);
            result.clear();
        }

        // now we keep changing it for every iteration
        for(int j=1 ; j<=n-i ; j++){
            curr_sum = curr_sum - arr[j-1];

            curr_sum = curr_sum + arr[j+i-1];

            if(curr_sum == s){
                result.push_back(j);
                result.push_back(j + i - 1);

                all_result.push_back(result);
                result.clear();
            }
        }
    }


    if(all_result.size() == 0){
        result.push_back(-1);
    }

    // let us print the all_result vector to see the results
    cout << "All results :-" << endl;

    for(int i=0 ; i<all_result.size() ; i++){
        print_vector(all_result[i]);
    }
    
    int min_value = all_result[0][0];
    int min_index = 0;

    // now we need to find the result with the lowest first index
    for(int i=1 ; i<all_result.size() ; i++){
        if(all_result[i][0] < min_value){
            min_value = all_result[i][0];
            min_index = i;
        }
    }

    return all_result[min_index];
}

/*
    Editorial Code (final optimum solution) =>  this works in O(n) *(-_-)*

    => here we make the window size variable and changes when required
*/

vector<int> subarray_sum_final(vector<int> arr, int n, long long s){
    // we have to maintain two variables to be used
    int win_start = 0;
    long long curr_sum = arr[0];

    

}


int main(){
    vector<int> arr = {1,2,4,7,5};

    int target = 12;

    vector<int> result = subarray_sum(arr, arr.size(), target);

    cout << "Result (Naive) :- " << endl;
    for(int i=result[0] ; i <= result[1] ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "----------------------------------------------" << endl;

    result = sub_array_sliding_window(arr, arr.size(), target);

    cout << "Result (Sliding Window) :- " << endl;
    for(int i=result[0] ; i<= result[1] ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "----------------------------------------------" << endl;

    result = subarray_sum_final(arr, arr.size(), target);

    cout << "Result (Modified Sliding Window) :- " << endl;
    for(int i=result[0] ; i<= result[1] ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "----------------------------------------------" << endl;

    return 0;
}