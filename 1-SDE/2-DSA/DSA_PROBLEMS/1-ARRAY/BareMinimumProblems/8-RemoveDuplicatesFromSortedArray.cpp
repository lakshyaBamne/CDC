#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void remove_duplicates(vector<int> &arr){
    // first sort the given array
    sort(arr.begin(), arr.end());

    // now use the unique function
    vector<int>::iterator it = unique(arr.begin(), arr.end());

    // now wesize the array
    arr.resize(distance(arr.begin(), it));
}

int main(){
    vector<int> arr = {1,2,3,2,2,1,1,9,9,10,2};

    remove_duplicates(arr);

    for(int i=0 ; i<arr.size() ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}