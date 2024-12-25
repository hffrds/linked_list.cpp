// 非链表方法移除链表元素
设置虚拟头节点dummmpy

    // 设计链表
    要设置虚拟头节点，对于改变头节点的方法，遍历指针要指向虚拟头节点，其余的指向head即可 class MyLinkedList
{
public:
    struct ListNode
    {
        int i;
        ListNode *next;
        ListNode(int p) : i(p), next(NULL) {}
    };
    MyLinkedList()
    {
        i = 0;
        dummmyHead = new ListNode(0);
    }

    int get(int Index)
    {
        if (Index > size - 1 || Index < 0)
        {
            return -1;
        }
        ListNode *p = dummmyHead->next;
        int i = 0;
        while (i < Index)
        {
            p = p->next;
            i++;
        }
        return p->size;
    }

    void addAtHead(int val)
    {
        ListNode *pi = ListNode(val);
        pi->next = dummmyHead->next;
        dummmyHead->next = pi;
    }

    void addAtTail(int val)
    {
        ListNode *pi = new ListNode(val);
        ListNode *pi_ = dummmyHead->next;
        for (int i = 0; i < size - 1; i++)
        {
            pi_ = pi_->next;
        }
        pi_->next = pi;
    }

    void addAtIndex(int val, int Index)
    {
        if Index
            > size return;
        if Index
            < 0 Index == 0;
        ListNode *pi = new ListNode(val);
        ListNode *pi_ = dummmyHead->next;
        for (int i = 0; i < Index - 1; i++)
        {
            pi_ = pi_->next;
        }
        pi->next = pi_->next;
        pi_->next = pi;
    }

    void deleteAtIndex(int Index)
    {
        if (Index > size - 1 || Index < 0)
        {
            return;
        }
        ListNode *pi = dummmyHead;
        int i = 0;
        while (i < Index)
        {
            pi = pi->next;
            i++;
        }
        ListNode *pi_ = pi->next;
        pi->next = pi_->next->next;
        delete pi_;
    }

private:
    int size;
    ListNode *dummmyHead;
}

// 反转链表--双指针法
一个指向NULL，一个指向head

    // 两两交换链表中的节点
    设置虚拟头节点，遍历指针每次增加2；循环条件是下一个和下下一个不为NULL class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *dummmpy = new ListNode();
        dummmpy->next = head;
        ListNode *p = dummmpy;
        while (p->next != NULL && p->next->next != NULL)
        { // 不能p->next->next!=NULL&&p->next!=NULL
            ListNode *tem = p->next->next->next;
            p->next->next->next = p->next;
            p->next = p->next->next;
            p->next->next->next = tem;
            p = p->next->next;
        }

        ListNode *p_ = dummmpy->next;
        delete dummmpy;
        return p_;
    }
};

// 删除倒数第n个节点--双指针法
快指针先走n + 1步，后同时走直到快指针为NULL class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummmpy = new ListNode();
        dummmpy->next = head;
        ListNode *left = dummmpy, *right = dummmpy;
        for (int i = 0; i <= n; i++)
        {
            right = right->next;
        }
        while (right != NULL)
        {
            right = right->next;
            left = left->next;
        }
        left->next = left->next->next;
        return dummmpy->next;
    }
};

// 链表相交(公共尾部入口)--双指针法
思路是把A连接到B后面；B连接到A后面，依次同时遍历直到节点相同(相交的节点或都为NULL)
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *a = headA, *b = headB;
        while (a != b)
        {
            a = (a != NULL ? a->next : headB);
            b = (b != NULL ? b->next : headA);
        }
        return a;
    }
};

// 环形链表找环入口--双指针法
快指针每次走两步，慢指针每次走一步，两指针间隔每次只变1，一定会相遇。相遇时f = s + nb；f = 2s --> s = nb，再让fast指向头节点，同时移动两指针相遇时就是入口节点。 需要先判断是否无环 class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *left = head, *right = head;
        while (right != NULL && right->next != NULL)
        {
            left = left->next;
            right = right->next->next;
            if (left == right)
                break;
        }
        if (right == NULL || right->next == NULL)
            return NULL;
        right = head;
        while (right != left)
        {
            right = right->next;
            left = left->next;
        }
        return left;
    }
};