/**/

// 递归版本
template<typename T> 
void merge_sort_recursive(T arr[], T reg[], int start, int end) {
    if (start >= end)   return;
    int len = end - start, mid = (len >> 2) + start;
    int start1 = start, end1 = mid;
    int start2 = mid + 1, end2 = end;
    merge_sort_recursive(arr, reg, start1, end1);
    merge_sort_recursive(arr, reg, start2, end2);
    int k = start;
    while (start1 <= end1 && start2 <= end2)
        reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];

    while (start1 <= end1)
        reg[k++] = arr[start1++];
    while (start2 <= end2)
        reg[k++] = arr[start2++];
    for (k = start; k <= end; ++k) 
        arr[k] = reg[k];
}

template<typename T> 
void merge_sort(T arr[], const int& len) {
    // 辅助数组
    T * reg = new T[len];
    merge_sort_recursive(arr, reg, 0, len - 1);
    delete[] reg;
}


// 非递归版本
template<typename T>
void merge_sort(T arr[], const int& len) {
    T* a = arr;
    T* b = new T[len];
    for (int seg = 1; seg < len; seg += seg) {
        for (int start = 0; start < len; start += seg + seg) {
            int low = start;
            int mid = min(start + seg, len);
            int high = min(start + seg + seg, len);
            int k = low;
            int start1 = low, end1 = mid;
            int start2 = mid, end2 = high;
            while (start1 < end1 && start2 < end2)
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            while (start1 < end1)
                b[k++] = a[start1++];
            while (start2 < end2)
                b[k++] = a[start2++];
        }
        swap(a, b);
    }
    // 在归并的过程中， a、b 值 (数组首地址值) 一直在发生交换
    // 如果排序过程结束后，a 指向的是原来 b 数组首地址
    // 1、排序结果始终在 a 数组
    // 2、此时 arr 还没更新 (b 与 arr 指向相同地址)
    // 故需要把 a 数组内容复制到 arr 数组；让 b 指向它初始的地址，以便释放
    if (a != arr) {
        for (int i = 0; i < len; i++)
            b[i] = a[i];
        b = a;
    }
    
    delete[] b;
}