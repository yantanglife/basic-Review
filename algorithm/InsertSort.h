/*
(有序区, 无序区) 把无序区的第一个元素插入到有序区的合适的位置。对数组：比较得少，换得多
*/

void InsertSort(vector<int> &nums) {
    int len = nums.size();
    for (int i = 1; i < len; ++i) {
        auto temp = nums[i];
        for (int j = i - 1; j >= 0; --j) {
            if (nums[j] > temp) {
                nums[j + 1] = nums[j];
                nums[j] = temp;
            }
            else
                break;
        }
    }
}