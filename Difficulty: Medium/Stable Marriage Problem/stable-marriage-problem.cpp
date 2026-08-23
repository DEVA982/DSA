class Solution {
public:

    vector<int> stableMarriage(vector<vector<int>> &men,
                               vector<vector<int>> &women) {

        int n = men.size();

        // menList[m] = woman currently matched with man m
        vector<int> menList(n, -1);

        // womenList[w] = man currently matched with woman w
        vector<int> womenList(n, -1);

        // next[m] = next woman to whom man m should propose
        vector<int> next(n, 0);

        // rank[w][m] = preference rank of man m for woman w
        vector<vector<int>> rank(n, vector<int>(n));

        for(int w = 0 ; w<n ; w++){
            for(int i = 0 ; i<n ; i++){
                rank[w][women[w][i]]=i;
            }
        }
        
        while(true){
            int menInd = -1;
            for(int j = 0 ; j<n ; j++){
                if(menList[j]==-1){
                    menInd = j;
                    break;
                }
            }
            if(menInd==-1){
                break;
            }
            int wom = men[menInd][next[menInd]];
            next[menInd]=next[menInd]+1;
            
            if(womenList[wom]==-1){
                womenList[wom]=menInd;
                menList[menInd]=wom;
            }
            else{
                int currentMan = womenList[wom];
                if(rank[wom][menInd]<rank[wom][currentMan]){
                    womenList[wom]=menInd;
                    menList[menInd]=wom;
                    menList[currentMan]=-1;
                    
                }
            }
            
            
        }
        return menList;
    }
};