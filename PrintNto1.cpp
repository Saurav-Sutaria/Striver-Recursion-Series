//print all number between n to 1
#include<iostream>
using namespace std;

//time: O(n) space: O(n)
void printN(int i,int n){
    if(i < 1) return; //base condition
    cout<<i<<endl;
    printN(i-1,n); //recursive call
}
int main(){
    int n = 10;
    printN(n,n);
    return 0;
}