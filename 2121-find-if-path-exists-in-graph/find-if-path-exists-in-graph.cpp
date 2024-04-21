class Solution {
public:
    vector<int> par, sz;
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        init(n);
        for(int i = 0;i<edges.size();++i)
            unity(edges[i][0], edges[i][1]);
        return find(source) == find(destination);
    }

    void init(int n){
    par.resize(n + 1), sz.resize(n + 1);
    for(int i=1;i<=n;i++)
        par[i]=i, sz[i]=1;
}

int find(int a){
    if(par[a]==a)
        return a;
    return find(par[a]);
}

bool unity(int a,int b){
    a=find(a), b=find(b);
    if(a == b)
        return false;
    if(sz[a]<sz[b])
        swap(a,b);
    par[b]=a, sz[a]+=sz[b];
    return true;
}
};