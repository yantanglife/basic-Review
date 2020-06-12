/*
基数排序 (Radix Sort) 是桶排序的扩展
基本思想是：将整数按位数切割成不同的数字，然后按每个位数分别比较

具体做法是：将所有待比较数值统一为同样的数位长度，数位较短的数前面补零。
然后，从最低位开始，依次进行一次排序。这样从最低位排序一直到最高位排序完成以后, 数列就变成一个有序序列
*/

// 最大数的位数
int getMaxNumLen(int arr[], int len) {
    int maxVal = arr[0];
    for (int i = 1; i < len; ++i)
        if (arr[i] > maxVal)
            maxVal = arr[i];
    int maxNumLen = 1;
    int p = 10;
    while (maxVal >= p) {
        // 使用除法避免溢出
        maxVal /= 10;
        ++maxNumLen;
    }
    return maxNumLen;
}

// 按某位进行排序
void countSort(int arr[], int len, int exp) {
    // exp = 1, 2, 3... 对应个、十、百位...
    int *output = new int[len];
    int buckets[10] = { 0 };
    int radix = 1;
    while (--exp)
        radix *= 10;
    int i;
    // 记录某位上数出现的次数
    for (i = 0; i < len; ++i)
        buckets[(arr[i] / radix) % 10]++;
    // 便于逆序更新
    for (i = 1; i < 10; ++i)
        buckets[i] += buckets[i - 1];
    // 将数据存储到临时数组
    for (i = len - 1; i >= 0; --i) {
        int num = (arr[i] / radix) % 10;
        output[buckets[num] - 1] = arr[i];
        buckets[num]--;
    }
    // 更新 arr
    for (i = 0; i < len; ++i)
        arr[i] = output[i];
    delete[] output;
}

void radixSort(int arr[], int len) {
    int maxNumLen = getMaxNumLen(arr, len);
    // 从个位开始排序
    for (int exp = 1; exp <= maxNumLen; ++exp) {
        countSort(arr, len, exp);
    }
}
