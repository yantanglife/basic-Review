/*
计数排序不是基于元素比较，而是利用数组下标来确定元素的正确位置
计数排序可以看作是一种桶排序

计数排序基于一个假设，待排序数列的所有数均为整数，且出现在(0, k) 的区间之内
如果 k (待排数组的最大值) 过大则会引起较大的空间复杂度，一般是用来排序 0 到 100 之间的数字的最好的算法
时间复杂度为 O(n+k) ，空间复杂度为 O(n+k)
*/

void CountSort(vector<int>& vecRaw, vector<int>& vecObj) {
    if (vecRaw.size() == 0) return;
    int len = *max_element(vecRaw.begin(), vecRaw.end()) + 1;
    vector<int> vecCount(len, 0);

    // 统计 value 的次数
    for (int i = 0; i < vecRaw.size(); ++i)
        vecCount[vecRaw[i]]++;
    // 次数类和，方便逆序更新
    for (int i = 1; i < len; ++i)
        vecCount[i] += vecCount[i - 1];
    // 逆序保证排序的稳定性
    for (int i = vecRaw.size() - 1; i >= 0; --i) 
        vecObj[--vecCount[vecRaw[i]]] = vecRaw[i];
}