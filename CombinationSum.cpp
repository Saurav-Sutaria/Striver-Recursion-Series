/*given an array and a sum k, find all the unique combination of array
where the choosen numbers sum to k, we can repeat the element
E.g ; arr = {2,3,6,7} k = 7;
    ans = {2,2,3}, {7}

Logic : if you pick an element don't increase the index
if element is not picked then increase the index
Time : O(k * 2^t) k: avg length, t : target
Space : O(k * x) x: number of combination
*/
#include<bits/stdc++.h>
using namespace std;

void findSubseq(vector<int> arr,int i,int k,int sum,vector<int> ans){
    if(sum == k){
        for(auto i:ans) cout<<i<<" ";
        cout<<endl;
        return;
    }
    if(i >= arr.size() || sum > k) return;

    //elment picked
    ans.push_back(arr[i]);
    findSubseq(arr,i,k,sum + arr[i],ans);
    ans.pop_back();

    //element not picked
    findSubseq(arr,i+1,k,sum,ans);

}

int main(){
    vector<int> arr = {2,2,3,6,7};
    int k = 7;
    vector<int> ans;
    findSubseq(arr,0,k,0,ans);
    return 0;
}