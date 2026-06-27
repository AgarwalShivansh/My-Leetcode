class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int rightsum = 0;
        int leftsum = 0;
        int n = arr.size();
        int sum = 0;
        for(int i =0 ;i<k;i++)
        {
            leftsum = leftsum + arr[i];
            sum = leftsum;
        }
        int right = n-1;
        for(int i = k-1;i>=0;i--)
        {
            leftsum = leftsum -  arr[i];
            rightsum = rightsum + arr[right];
            right--;
            sum = max(sum , leftsum + rightsum);
        }
        return sum;
    }
};