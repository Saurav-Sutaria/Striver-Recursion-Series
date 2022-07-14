//print all number between 1 to n
#include<iostream>
using namespace std;

//time: O(n) space: O(n)
void printN(int i,int n){
    if(i > n) return; //base condition
    cout<<i<<endl;
    printN(i+1,n); //recursive call
}
int main(){
    int n = 10;
    printN(1,n);
    return 0;
}