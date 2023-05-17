#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void print_vector(vector<int> &arr){
    for(int i=0 ; i<arr.size() ; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int N;

    cin >> N;

    vector<int> vec(N);

    for(int i=0 ; i<N ; i++){
        cin >> vec[i];
    }

    // extra vector for use in calculating distances
    vector<int> diff_vec(N-1);

    for(int i=0 ; i<diff_vec.size() ; i++){
        diff_vec[i] = abs(vec[i] - vec[i+1]);
    }

    // now we need to start removing distances using this extra vector
    // we need to start by finding the first non-1 element in the extra vector

    // vectors and iterators for later use
    vector<int> initializer;
    vector<int>::iterator it1;

    int recent_one = 0;

    while(recent_one < diff_vec.size()){
        // start by finding the first pair of elements whose difference 
        // is not equal to 1 and store the index in recent_one
        for(int i=0 ; i<diff_vec.size() ; i++){
            if(diff_vec[i] != 1){
                recent_one = i;
                break;
            }
        }

        // given i, i+1 are the pair of elements that do not have a difference of 1
        if(vec[recent_one] < vec[recent_one+1]){
            // case-1

            // initializing a vector to be inserted at a position
            for(int i=1 ; i<diff_vec[recent_one] ; i++){
                initializer.push_back(vec[recent_one] + i);
            }

            it1 = vec.begin() + recent_one+1;

            // now we need to append the required list at the required index
            vec.insert(it1, initializer.begin(), initializer.end());

            // now empty the initializer for the next iteration
            initializer.clear();

        }
        else{
            //case-2
            // initializing a vector to be inserted at a position
            for(int i=1 ; i<diff_vec[recent_one] ; i++){
                initializer.push_back(vec[recent_one] - i);
            }

            it1 = vec.begin() + recent_one+1;

            // now we need to append the required list at the required index
            vec.insert(it1, initializer.begin(), initializer.end());

            initializer.clear();

        }

        // also now we need to change the recent_one values from the diff_vec
        diff_vec.insert(diff_vec.begin()+recent_one+1, diff_vec[recent_one]-1, 1);

        diff_vec[recent_one] = 1;

        recent_one = recent_one + 1;
    }

    print_vector(vec);

    return 0;
}