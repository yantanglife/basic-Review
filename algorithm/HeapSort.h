/*
(大顶堆, 有序区) 交换堆顶元素和大顶堆末尾元素，恢复大顶堆
*/

void max_heapify(int nums[], int start, int end) {
    int fIdx = start;
    int cIdx = fIdx * 2 + 1;
    while (cIdx <= end) {
        // 选择较大的子节点
        if (cIdx + 1 <= end && nums[cIdx] < nums[cIdx + 1])
            cIdx++;
        
        if (nums[fIdx] > nums[cIdx])
            return;
        // 交换父子节点，向下调整
        else {
            swap(nums[fIdx], nums[cIdx]);
            fIdx = cIdx;
            cIdx = fIdx * 2 + 1;
        }
    }
}

void heap_sort(int nums[], int len) {
    // 构造大顶堆
    for (int i = len - 1; i >= 0; --i) 
        max_heapify(nums, i, len - 1);
    // 将堆顶元素与最后元素 (有序元素的前一位) 交换
    // 调整大顶堆 (有序元素前)
    for (int i = len - 1; i > 0; --i) {
        swap(nums[0], nums[i]);
        max_heapify(nums, 0, i - 1);
    }
}