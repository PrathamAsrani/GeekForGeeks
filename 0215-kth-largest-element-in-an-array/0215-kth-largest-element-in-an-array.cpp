class max_heap{
    vector<int> arr;
    int parent(int i) {return (i-1)/2;}
    int leftChild(int i) {return 2*i+1;};
    int rightChild(int i) {return 2*i+2;};
    void ShiftUp(int i){
        while(i > 0 && arr[i] > arr[parent(i)]){
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }
    void maxHeapify(int i){
        int mx = i, left = leftChild(i), right = rightChild(i);
        if(left < arr.size() && arr[mx] < arr[left])
            mx = left;
        if(right < arr.size() && arr[mx] < arr[right])
            mx = right;
        if(i != mx){
            swap(arr[i], arr[mx]);
            maxHeapify(mx);
        }
    }
public:
    void insert(int e){
        arr.push_back(e);
        ShiftUp(arr.size()-1);
    }

    int extractMax(){
        if(arr.empty())
            return -1;
        int res = arr[0];
        arr[0] = arr[arr.size()-1];
        arr.pop_back();
        maxHeapify(0);
        return res;
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {
        // sort(arr.begin(), arr.end(), greater<int> ());
        // return arr[k-1];
        
        int n = arr.size();
        max_heap *heap = new max_heap();
        for(int i = 0; i < n; i++)
            heap->insert(arr[i]);
        int res = -1;
        while(k--)
            res = (heap->extractMax());
        return res;
    }
};