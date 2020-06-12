/*
桶排序：将值为 i 的元素放入 f(i) 号桶，最后依次把桶里的元素倒出来。
桶排序思路：
1. 设置一个定量的数组当作空桶
2. 寻访序列，并且把元素放到对应的桶
3. 对每个不是空的桶进行排序
4. 从不是空的桶里把元素再放回原来的序列中。

*/

// 假设数据分布在 [0，100)之间，每个桶内部用链表表示，在数据入桶的同时插入排序，然后把各个桶中的数据合并
// 计数排序可以看作是一种桶排序

const int BUCKET_NUM = 10;

struct ListNode {
    explicit ListNode(int i = 0) : val(i), next(NULL) {}
    int val;
    ListNode* next;
}

ListNode* insert(ListNode* head, int value) {
    ListNode* dummyNode;
    ListNode* newNode = new ListNode(value);
    ListNode *pre, *cur;
    dummyNode->next = head;
    pre = dummyNode;
    cur =  head;
    while (cur && cur->val <= value) {
        pre = cur;
        cur = cur->next;
    }
    newNode->next = cur;
    pre->next = newNode;
    return dummyNode->next;
}

ListNode* merge(ListNode *head1, ListNode *head2) {
    ListNode* dummyNode;
    ListNode* cur = dummyNode;
    while (head1 && head2) {
        if (head1->val <= head2->val) {
            cur->next = head1;
            head1 = head1->next;
        }
        else {
            cur->next = head2;
            head2 = head2->next;
        }
        cur = cur->next;
    }
    if (head1)  cur->next = head1;
    if (head2)  cur->next = head2;
    return dummyNode->next;
}

void BucketSort(int arr[], int len) {
    vector<ListNode*> buckets(BUCKET_NUM, (ListNode*)(0));
    for (int i = 0; i < n; ++i) {
        int index = arr[i] / BUCKET_NUM;
        ListNode *head = buckets[index];
        buckets[index] = insert(head, arr[i]);
    }
    ListNode *head = buckets[0];
    for (int i = 1; i < BUCKET_NUM; ++i)
        head = merge(head, buckets[i]);
    for (int i = 0; i < n; ++i) {
        arr[i] = head->val;
        head = head->next;
    }
}