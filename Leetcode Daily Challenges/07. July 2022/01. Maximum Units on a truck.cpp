class Solution {
public:
    static bool compare(const vector<int> &v1,const vector<int> &v2){
        return v1[1]>v2[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),compare);
        int count = 0;
       
        for(int i=0;i<boxTypes.size();i++){
            
            if(boxTypes[i][0]>=truckSize){
                count+= truckSize*boxTypes[i][1];
                 truckSize = 0;
            }
            else{
              truckSize -= boxTypes[i][0];
                count += boxTypes[i][0]*boxTypes[i][1];
            }
        }
        
        return count;
    }
};