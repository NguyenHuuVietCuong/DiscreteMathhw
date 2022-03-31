#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

// Ex 2 Function 
int ones(string s){
    if(s.size() == 0){
        return 0;
    }
    else{
        string temp = s.substr(0, s.size() - 1);
        if(s[s.size() - 1] == '1'){
            return 1 + ones(temp);
        }
        return ones(temp);
    }
}
// Ex 3 Function 
int m(string s){
    if(s.size() == 1){
        return s[0] - '0';
    }
    else{
        int minDigit = s[s.size() - 1] -'0';
        string temp = s.substr(0, s.size() - 1);
        return min(minDigit, m(temp));
    }
}
// Ex 4 Function 
string reverse(string s)
{
    if(s.size() == 1 || s.size() == 0){
        return s;
    }
    else{
        string rev = "";
        rev.push_back(s[s.size() - 1]);
        string rem = s.substr(0, s.size() - 1);
        return rev + reverse(rem);
    }
}
// Ex 7, 8, 9 Function 
vector <string> recursion(vector <string> &arr, int cap, int start){
    if(cap <= 1){
        arr.pop_back();
        return arr;
    }
    else if(cap == 2){
        return arr;
    }
    else{
        if(arr[arr.size() - 1].size() == (int)(cap / 2) * 2){
            return arr; 
        }
        else{
            int inputArrSize = arr.size();
            int inputStart = start; 
            for(int i = inputStart; i < inputArrSize; i ++){
                string temp1 = arr[i] + "()";
                //cout << temp1 << " ";
                string temp2 = "()" + arr[i];
                string temp3 = "(" + arr[i] + ")";
                //cout << temp2; 
                arr.push_back(temp1);
                if(temp1 != temp2){
                    arr.push_back(temp2);
                }
                arr.push_back(temp3);
                start ++;
            }
            return recursion(arr, cap, start);
        }
    }
}
// Ex 10
int homeworkGCD(int a, int b){
    if(a > b){
        return homeworkGCD(b, a);
    }
    else if(a == 0){
        return b;
    }
    else if((a % 2 == 0) && (b % 2 == 0)){
        return 2 * homeworkGCD(a / 2, b / 2);
    }
    else if((a % 2 == 0) && (b % 2 != 0)){
        return homeworkGCD(a / 2, b);
    }
    else{
        return homeworkGCD(a, b - a);
    }
}

// Ex 7, 8, 9 Testrun
int main(){
    vector <string> arr;
    arr.push_back(" ");
    arr.push_back("()");
    const int start = 1;
    int cap;
    cap = 6; 
    vector <string> temp = recursion(arr, cap, start);
    for(int i = 0; i < temp.size() - 1; i ++)
    {
        cout << temp[i] << " , ";
    }
    cout << temp[temp.size() - 1] << ".";
    return 0;
}

/*
int main()
{
    string s;
    getline(cin, s);
    //cout << ones(s) << endl;
    //cout << m(s) << endl;
    //cout << reverse(s) << endl;
}
*/