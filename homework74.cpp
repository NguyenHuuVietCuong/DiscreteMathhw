#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int gcd(int a, int b){
    if(a == 0 || b == 0){
        return a + b;
    }
    else if(a == b){
        return a;
    }
    else{
        if(a > b){
            return gcd(a % b, b);
        }
        return gcd(a, b % a);
    }
}
int lcm(int a, int b){
    return (a / gcd(a, b)) * b;
}
int ex1(){
    int multipleOf12 = 0;
    int multipleOf15 = 0;
    int multipleOf12And15 = 0;
    for(int i = 1; i <= 1000; i ++){
        if(i % 12 == 0){
            multipleOf12 ++;
        }
        else if(i % 15 == 0){
            multipleOf15 ++;
        }
        else if(i % lcm(12, 15) == 0){
            multipleOf12And15 ++;
        }
    }
    return multipleOf12 + multipleOf15 - multipleOf12And15;
}
int factorial(int n){
    if(n == 1){
        return 1;
    }
    return n * factorial(n - 1);
}
int combination(int n, int r){
    if(n == r || r == 0){
        return 1;
    }
    return factorial(n) / (factorial(r) * factorial(n - r));
}
int permutation(int n, int r){
    if(n == r || r == 0){
        return 1;
    }
    return factorial(n) / factorial(n - r);
}
long long ex6(){ //Điều kiện: (số chữ số 0) < (số chữ số 1) suy ra (số chữ số 1) nhỏ nhất là 7
    long long res = 0;
    for(int i = 7; i <= 12; i ++){
        res += (combination(12, i) * combination(12, 12 - i));
    }
    return res;
}
long long ex7(){ //Điều kiện: (số chữ số 0) <= (số chữ số 1) - 1 suy ra (số chữ số 0) nhỏ nhất là 6 và lớn nhất là 11 do luôn có sẵn 1 chữ số 1 ở đầu
    long long res = 0;
    for(int i = 11; i >= 6; i --){
        res += combination(i, 11 - i);
    }
    return res;
}
long long ex8(int n){
    long long res = 0;
    int tempN = n / 2;
    for(int i = tempN; i >= 0; i --){
        res += combination(tempN, i);
    }
    if(n % 2 == 1){
        res *= 2;
    }
    return res; 
}
long long ex9And10 (int n){
    long long res = n;
    for(int i = 2; i <= sqrt(n); i ++){
        if(n % i == 0){
            res -= (res / i);
            while(n % i == 0){
                n = n / i;
            }
        }
    }
    if(n != 1){
        res -= (res / n);
    }
    return res;
}
int main(){
    int n;
    cin >> n;
    cout << ex9And10(n);
}