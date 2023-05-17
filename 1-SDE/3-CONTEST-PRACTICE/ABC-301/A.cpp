#include<iostream>

using namespace std;

int main(){
    int N;

    cin >> N;

    string s;

    cin >> s;

    int count_T = 0, count_A = 0;

    for(int i=0 ; i<s.size() ; i++){
        if(s[i] == 'T'){
            count_T++;
        }
        else{
            count_A++;
        }
    }

    if(count_A == count_T){
        // find the person at the last position
        // the other one is the winner
        if(s[s.size()-1] == 'T'){
            cout << "A";
        }
        else{
            cout << "T";
        }
    }
    
    else if(count_A > count_T){
        cout << "A";
    }
    else{
        cout << "T";
    }

    return 0;
}
