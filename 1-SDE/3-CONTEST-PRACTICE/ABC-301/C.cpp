#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void print_vector(vector<char> &arr){
    cout << "-------------------------------------------" << endl;
    for(int i=0 ; i<arr.size() ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print_vector(vector<int> &arr){
    cout << "-------------------------------------------" << endl;
    for(int i=0 ; i<arr.size() ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<char> find_unique(vector<char> arr){
    // first we need to sort the vector
    sort(arr.begin(), arr.end());

    // now we need to use the unique function
    vector<char>::iterator it = unique(arr.begin(), arr.end()-1);

    // now resize the vector to get the uniqueness vector
    arr.resize(distance(arr.begin(), it));

    return arr;
}

int main(){
    string inp_S,inp_T;

    cin >> inp_S;
    cin >> inp_T;

    // first let us convert these strings to vectors for easy manipulation
    vector<char> S, T;
    
    for(int i=0 ; i<inp_S.size() ; i++){
        S.push_back(inp_S[i]);
        T.push_back(inp_T[i]);
    }

    // first let us create a merged vector of these two vectors
    // to find the unique elements in the two strings
    vector<char> merged;

    for(int i=0 ; i<S.size() ; i++){
        merged.push_back(S[i]);
        merged.push_back(T[i]);
    }

    // now we need to find the unique elements in this merged vector
    vector<char> unique_chars = find_unique(merged);

    // vectors to count the number of unique characters in the given strings
    vector<int> count_S(unique_chars.size(), 0);
    vector<int> count_T(unique_chars.size(), 0);

    for(int i=0 ; i<unique_chars.size() ; i++){
        for(int j=0 ; j<S.size() ; j++){
            // populating count_S
            if(S[j] == unique_chars[i]){
                count_S[i]++;
            }

            if(T[j] == unique_chars[i]){
                count_T[i]++;
            }

        }
    }

    vector<int> discrepancy(unique_chars.size(), 0);

    // now we need to use these vectors of count_S and count_T to figure out the game
    for(int i=0 ; i<unique_chars.size() ; i++){
        if( count_S[i] != count_T[i] ){
            discrepancy[i]++;
        }
    }

    print_vector(count_S);
    print_vector(count_T);
    print_vector(discrepancy);

    return 0;
}
