class Solution {
    int count = 0;

public:

    int countRangeSum(vector<int>& nums, int lower, int upper) {
      vector<long long> prefix(nums.size() + 1,0);

      for(int i = 0; i < nums.size(); i++){
        prefix[i + 1] = prefix[i] + nums[i];
      }  

      mergesort(prefix,0,prefix.size(),lower,upper);
      return count;
    }

    void mergesort(vector<long long>& sum,int left,int right,int lower,int upper){
        if(right - left <= 1)
        return;
        
        int mid = left + (right - left) / 2;

        mergesort(sum,left,mid,lower,upper);
        mergesort(sum, mid, right, lower, upper);

        int j = mid , k = mid;
        for(int i = left;i < mid;i++){
            while(k < right && sum[k] - sum[i] < lower)
            k++;

            while(j < right && sum[j] - sum[i] <= upper)
            j++;
            count += j - k;
        }

        vector<long long> temp(right - left);
        int i = left, p = mid,t = 0;

        while(i < mid && p < right){
            if(sum[i] <= sum[p])
            temp[t++] = sum[i++];

            else
            temp[t++] = sum[p++];
        }
        while(i < mid) temp[t++] = sum[i++];
        while(p < right) temp[t++] = sum[p++];

        for(int x = 0; x < temp.size(); x++){
            sum[left + x] = temp[x];
        }
    }
};