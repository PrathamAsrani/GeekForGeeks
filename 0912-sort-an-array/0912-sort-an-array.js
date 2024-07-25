/**
 * @param {number[]} nums
 * @return {number[]}
 */


var sortArray = function(nums) {

    const merge = (arr, l, m, r) => {
        let sz = r-l+1, i = l, j = m+1, k = 0
        let tmp = Array.from({length: sz}, () => 0)
        while(i <= m && j <= r){
            if(arr[i] <= arr[j]){
                tmp[k++] = arr[i++];
            } else {
                tmp[k++] = arr[j++];
            }
        }
        while(i <= m) tmp[k++] = arr[i++];
        while(j <= r) tmp[k++] = arr[j++];
        for(let it = 0; it < sz; it++)
            arr[it+l] = tmp[it];
    }

    const ms = (arr, l, r) => {
        if(l < r){
            let m = Math.floor((l+r)/2)
            ms(arr, l, m);
            ms(arr, m+1, r);
            merge(arr, l, m, r);
        }
    }

    // self
    // ms(nums, 0, nums.length-1)

    // inbuilt
    // nums.sort((a, b) => a-b)

    const partition = (arr, l, r) => {
        let pivot = arr[r], i = (l-1);
        for(let j = l; j <= r-1; j++){
            if(arr[j] < pivot){
                i++
                [arr[i], arr[j]] = [arr[j], arr[i]]
            }
        }
        i++
        [arr[i], arr[r]] = [arr[r], arr[i]]
        return i
    }

    const qs = (arr, l, r) => {
        if(l < r) {
            let p = partition(arr, l, r)
            qs(arr, l, p-1)
            qs(arr, p+1, r)
        }
    }
    // qs(nums, 0, nums.length-1)

    const heapify = (arr, n, i) => {
        let lrg = i, l = 2*i+1, r = 2*i+2
        if(l < n && arr[l] > arr[lrg]) lrg = l
        if(r < n && arr[r] > arr[lrg]) lrg = r
        if(lrg != i){
            [arr[lrg], arr[i]] = [arr[i], arr[lrg]]
            heapify(arr, n, lrg)
        }
    }

    const hs = (arr, n) => {
        for(let i = Math.floor(n/2)-1; i >= 0; i--){
            heapify(arr, n, i);
        }
        for(let i = n-1; i > 0; i--){
            [arr[i], arr[0]] = [arr[0], arr[i]]
            heapify(arr, i, 0)
        }
    }
    hs(nums, nums.length)
    return nums
};