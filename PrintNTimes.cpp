//print name N times
#include<iostream>
using namespace std;

//time : O(n) Space (stack space) : O(n)
void printName(string name,int n){
    if(n == 0) return; //base condition
    cout<<name<<endl;
    printName(name,n-1); //recursive call
}

int main(){
    int n = 5;
    string name = "saurav";
    printName(name,n);
    return 0;
}