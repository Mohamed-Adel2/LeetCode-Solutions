class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
             int ss=s.length(),ts=t.length();
     int mem[ss+1][ts+1];
     memset(mem,0,sizeof mem);
     for(int i=0;i<ss;i++){
         for(int j=0;j<ts;j++){
             if(s[i]==t[j]) {
                 mem[i + 1][j + 1] = mem[i][j] + 1;
             }
             else
                 mem[i+1][j+1]=max(mem[i][j+1],mem[i+1][j]);
         }
     }
     return mem[ss][ts];
    }
};