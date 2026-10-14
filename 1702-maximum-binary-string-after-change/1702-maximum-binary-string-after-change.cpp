class Solution {
public:
    string maximumBinaryString(string binary) {
        string ans(binary.size(),'1');
        int fZ=binary.find('0');

        int z=0;
        for(char c: binary){
            if(c=='0') z++;
        }
        if(z==0) return binary;
        
        ans[fZ+z-1]='0';
        return ans;
    } 
};