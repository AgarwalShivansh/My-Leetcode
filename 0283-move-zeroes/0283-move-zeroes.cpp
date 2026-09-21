class Solution {
public:
   void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int insertPosition = 0;

        /*
         * Place non-zero values at the front
         * in the same order they appear.
         */
        for (int index = 0; index < n; index++) {
            // Only non-zero values belong in the front section.
            if (nums[index] != 0) {
                nums[insertPosition] = nums[index];
                insertPosition++;
            }
        }

        /*
         * Positions left after compaction
         * must contain zeroes.
         */
        while (insertPosition < n) {
            nums[insertPosition] = 0;
            insertPosition++;
        }
    }
};