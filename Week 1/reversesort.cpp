#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator> 
using namespace std;
void reversort(vector<int>& arr,int size){
int cost = 0;
vector<int> vec; 
for (int i = 0; i < size-1; i++)
{
int m = *min_element(arr.begin()+i, arr.end());
auto x = find(arr.begin() + i,arr.end(),m);
reverse(arr.begin()+i,x+1);
// cost += distance(arr.begin(),x)- i+ 1;
// cost += distance(arr.begin()+i,x+1);
cost += (x - (arr.begin() + i)) + 1;
}
cout<<cost;
}
int main(){
    vector<int> arr ={1,3,4,5,2};
    int size = arr.size();
    reversort(arr,size);
    return 0;
}