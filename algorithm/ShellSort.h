/*
每一轮按照事先决定的间隔进行插入排序，间隔会依次缩小，最后一次一定要是 1
*/

template<typename T>
void shell_sort(T arr[], int length) {
    int gap = 1;
    // 选择一个 gap 值
    while (gap < length / 3)
        gap = 3 * gap + 1;
    while (gap >= 1) {
        for (int i = gap; i < length: ++i) {
            for (int j = i; j >= gap && arr[j] < arr[j - gap]; j -= gap) {
                swap(arr[j], arr[j - gap]);
            }
        }
        gap = gap / 3;
    }
}
