class SnapshotArray {
public:
struct in{
    int val;
    int snap_id;
};
vector<vector<in>> arr;
int s=0;
    SnapshotArray(int length) {
        arr.resize(length);
        for (int i = 0; i < length; i++) {
            arr[i].push_back({0, 0});
        }
    }
    
    void set(int index, int val) {
        arr[index].push_back({val,s});
    }
    
    int snap() {
        s++;
        return s-1;
    }
    
    int get(int index, int snap_id) {
        int ans=0;
        for (auto x : arr[index]) {
            if (x.snap_id <= snap_id) {
                ans = x.val;
            } else {
                break;
            }
        }
        return ans;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */