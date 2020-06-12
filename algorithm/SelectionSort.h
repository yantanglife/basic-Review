/*

(有序区, 无序区) 在无序区里找一个最小的元素跟在有序区的后面。对数组：比较得多，换得少

*/


void SelectionSort(vector<int> &nums) {
    int minIdx, len = nums.size();
    for (int i = 0; i < len - 1; ++i) {
        minIdx = i;
        // 找到最小的
        for (int j = i + 1; j < len; ++j) {
            if (nums[j] < nums[minIdx]) {
                minIdx = j;
            }
        }
        if (i != minIdx)
            swap(nums[i], nums[minIdx]);
    }
}
