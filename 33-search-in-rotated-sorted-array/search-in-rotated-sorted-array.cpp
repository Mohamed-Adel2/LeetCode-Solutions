class Solution {
public:
    int modifiedBinarySearch(vector<int>& v){
        int l=0,r=v.size()-2;
        while(l<=r){
            int mid=(l+r)/2;
            if(v[mid]<v[mid+1]){
                if(v[mid]<v[v.size()-1]){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            else{
                return mid;
            }
        }
        return -1;
    }
    int binarySearch(vector<int> v,int target,int l,int r){
        while(l<=r){
            int mid=(l+r)/2;
            if(v[mid]<target)
                l=mid+1;
            else if(v[mid]>target)
                r=mid-1;
            else
                return mid;
        }
        return -1;
    }
    int search(vector<int>& v, int target) {
        int turn= modifiedBinarySearch(v);
        if(turn==-1){
            return binarySearch(v,target,0,v.size()-1);
        }
        if(target<=v[v.size()-1]){
            return binarySearch(v,target,turn+1,v.size()-1);
        }
        else if(target>v[v.size()-1]){
            return binarySearch(v,target,0,turn);
        }
        return -1; 
    }
};