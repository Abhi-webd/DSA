#include <bits/stdc++.h>
using namespace std;

string keypad[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void printKeypad(string input, string output, int i){
    if(input[i] == '\0'){
        cout<<output<<" ";
        return;
    }

    int cur_digit = input[i] - '0';
    if(cur_digit == 0 || cur_digit == 1){
        printKeypad(input,output,i+1);
    }

    for(int k = 0 ; k < keypad[cur_digit].size() ; k++){
        printKeypad(input,output+keypad[cur_digit][k],i+1);
    }
    return;
}

int main()
{
    string input;
    string output;
    cin>>input;
    int i = 0;
    printKeypad(input,output,i);


    return 0;
}
