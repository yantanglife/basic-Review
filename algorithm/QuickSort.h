/*
(小数, 基准元素, 大数)
在区间中随机挑选一个元素作基准，将小于基准的元素放在基准之前，大于基准的元素放在基准之后，再分别对小数区与大数区进行排序
*/

void QuickSort(vector<int> &nums, int low, int high) {
    if (low >= high)
        return;
    int first = low;
    int last = high;
    int key = nums[first];
    while (first < last) {
        // 先从右边开始，找到小于的
        while (first < last && nums[last] >= key)
            last--;
        while (first < last && nums[first] <= key)
            first++;
        if (first < last)
            swap(nums[first], nums[last]);
    }
    // 基准置位
    if (nums[first] < nums[low])
        swap(nums[low], nums[first]);
    else
        first++;
    QuickSort(nums, low, first - 1);
    QuickSort(nums, first + 1, high);
}
