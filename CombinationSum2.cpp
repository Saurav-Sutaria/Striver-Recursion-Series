/*given an array and a sum k, find all the unique combination of array
where the choosen numbers sum to k, we can't repeat the element
ALL THE COMBINATIONS MUST BE UNIQUE
E.g ; arr = {2,3,6,7} k = 7;
    ans = {7}
*/
#include<bits/stdc++.h>
using namespace std;
/*
brute force: add the answer vector in set and print all the elements of set
T : O(2^n * klogn)
*/
void findSubseq(vector<int> arr,int i,int k,int sum,vector<int> ans,set<vector<int>>& s){
    if(sum == k){
       s.insert(ans);
       return;
    }
    if(i >= arr.size() || sum > k) return;

    //elment picked
    ans.push_back(arr[i]);
    findSubseq(arr,i+1,k,sum + arr[i],ans,s);
    ans.pop_back();

    //element not picked
    findSubseq(arr,i+1,k,sum,ans,s);

}

/*
optimized :
before picking the element check it the same element was picked up before or not
[1,1,1,2,2] currently we are at idx =0, target = 4, so at idx 1 we have possibilty to pick any element
 | | | | |
 1 0 0 1 1 if we pick idx 0 then we can't pick idx 1 and 2 at this point becuase the combination
 will be same

*/
void findSubseq1(vector<int> arr,int idx,int k,vector<int> ans){
    if(k == 0){
        for(auto i : ans) cout<<i<<" ";
        cout<<endl;
        return;
    }
    if(idx >= arr.size()) return;

    
    for(int i=idx;i<arr.size();i++){
        if(i > idx && arr[i] == arr[i-1]) continue;
        if(arr[i] > k) break;
         
        ans.push_back(arr[i]);
        findSubseq1(arr,i+1,k-arr[i],ans);
        ans.pop_back();
    }
}
int main(){
    vector<int> arr = {1,1,1,2,2};
    sort(arr.begin(),arr.end());
    int k = 4;
    vector<int> ans;
    // set<vector<int>> s;
    // findSubseq(arr,0,k,0,ans,s);
    // for(auto i:s){
    //     for(auto j:i) cout<<j<<" ";
    //     cout<<endl;
    // }

    findSubseq1(arr,0,k,ans);
    return 0;
}