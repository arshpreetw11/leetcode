class Solution {
public:
    bool sumGame(string num) {
        int QR=0,QL=0;
        for(int i=0;i<num.size();i++){
            char ch=num[i];
            if(ch=='?'){
                if(i>=num.size()/2)
                    QR++;
                else 
                    QL++;
            }  
        }
        int sz=num.size();
        
        int sumLeft=0;
        int sumRight=0;
        for(int i=0;i<sz;i++){
            if(num[i]!='?'){
                if(i>=sz/2){
                    sumRight+=num[i]-'0';
                }else{
                    sumLeft+=num[i]-'0';
                }
            }
        }
        int diff=(sumLeft-sumRight);
        int qdiff=(QL-QR);

        if(qdiff%2) return true;

        return diff!=-9*qdiff/2;
    }
};