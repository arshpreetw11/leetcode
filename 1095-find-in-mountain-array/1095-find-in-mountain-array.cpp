/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int binarySearch(MountainArray &m,int l,int r,int target,bool asc){
        while(l<=r){
            int mid=l+(r-l)/2;
            int val=m.get(mid);
            if(val==target) return mid;
            if(asc){
                if(val<target){
                    l=mid+1;
                }
                else
                    r=mid-1;
            }else{
            if(val<target){
                r=mid-1;
            }
            else
                l=mid+1;}
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int len=mountainArr.length();
        int left=0;
        int right=len-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1)) left=mid+1;
            else 
                right=mid-1;
        }
        int peak=left;
        int ans=binarySearch(mountainArr,0,peak,target,true);
        if(ans!=-1) return ans;
        return binarySearch(mountainArr,peak+1,len-1,target,false);
    }
};