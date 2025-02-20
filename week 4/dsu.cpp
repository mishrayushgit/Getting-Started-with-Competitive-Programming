#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
class Unionfind{
    private:
    vi p,rank,setSize;
    int numSets;
    public:
    Unionfind(int N){
        p.assign(N,0); // assigning each element as zero
        for (int i = 0; i < N; i++)
        {
            p[i] = i;
            //initially everyone is their own parent
        }
        rank.assign(N,0);
        setSize.assign(N,1);
        numSets = N;
    }
    int findSet(int n){
        if(n ==p[n]){
            return n;
        }

        return p[n] = findSet(p[n]);

    }
    bool isSameSet(int i,int j){
        return findSet(i) == findSet(j);
    }
    void UnionSet(int i , int j){
        if(findSet(i) == findSet(j)){
            return;
        }
        int x = findSet(i);
        int y = findSet(j);
        if(rank[x]>rank[y]){
            swap(x,y);
        }
        p[x] = y;
        if(rank[x] == rank[y]){
            rank[y]++;
        }
        setSize[y]+=setSize[x];
        numSets--;
    }
    int sizeofset(int i){
        return setSize[findSet(i)];
    }
    int disjointSets(){
        return numSets;
    }
};
int main(){
    Unionfind u(4); // {0, 1, 2, 3}

    u.UnionSet(1, 2);
    u.UnionSet(2, 3);

    cout << "Find(3): " << u.findSet(3) << endl;
    cout << "Find(0): " << u.findSet(0) << endl;
    cout << "Size of set containing 1: " << u.sizeofset(1) << endl;
    cout << "Number of disjoint sets: " << u.disjointSets() << endl;
    
}