/*

(无序区, 有序区). 从无序区通过交换找出最大元素放到有序区前端.

*/

// 冒泡排序
void BubbleSort(vector<int>& nums) {
    int len = nums.size();
    for (int i = 0; i < len - 1; ++i)
        for (int j = 0; j < len - 1 - i; ++j)
            if (nums[j] > nums[j + 1])
                swap(nums[j], nums[j + 1]);
}


// 冒泡排序改进版
// 如果进行某一趟排序时没有数据交换，则说明数据已经按要求排序好
// 可立即结束排序，避免不必要的比较过程
void BubbleSortOrderly(vector<int>& nums) {
    int len = nums.size();
    bool orderly = false;
    for (int i = 0; i < len - 1 && !orderly; ++i) {
        orderly = true;
        for (int j = 0; j < len - 1 - i; ++j) {
            if (nums[j] > nums[j + 1]) {
                orderly = false;
                swap(nums[j], nums[j + 1]);
            }
        }
    }
}


// 模板
// 看情况重载 运算符 >  
template<typaname T>
void bubble_sort(T nums[], int len) {
    int len = nums.size();
    for (int i = 0; i < len - 1; ++i)
        for (int j = 0; j < len - 1 - i; ++j)
            if (nums[j] > nums[j + 1])
                swap(nums[j], nums[j + 1]);
}
