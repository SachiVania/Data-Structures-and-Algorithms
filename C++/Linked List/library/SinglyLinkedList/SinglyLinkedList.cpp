#include <iostream>
#include "SinglyLinkedList.h"

SinglyLinkedList :: SinglyLinkedList(){
    m_pHead = nullptr;
    m_pTail = nullptr;
}

SinglyLinkedList :: ~SinglyLinkedList(){
    while (m_pHead != nullptr) {
        pop_front();
    }

    m_pHead = nullptr;
    m_pTail = nullptr;
}

void SinglyLinkedList :: push_front(int data){
    Node *node = new Node(data);
    node->m_pNext = m_pHead;

    if (m_pHead == nullptr){
        m_pTail = node;
    }

    m_pHead = node;
    ++s_nodeCount;
}

void SinglyLinkedList :: push_back(int data){
    if (m_pHead == nullptr){
        push_front(data);
        return;
    }

    Node *node = new Node(data);
    node->m_pNext = nullptr;
    m_pTail->m_pNext = node;
    m_pTail = node;
    ++s_nodeCount;
}

void SinglyLinkedList :: push_at(int data, int pos){
    // invalid position received
    if (pos > s_nodeCount){
        std::cout << "[push_at] Invalid position" << std::endl;
        return;
    }

    // list is empty
    if (m_pHead == nullptr){
        push_front(data);
        return;
    }

    if (pos == 1){
        push_front(data);
        return;
    }

    Node *ptr = m_pHead;
    int count = 1;

    while (count != pos-1){
        ptr = ptr->m_pNext;
        count++;
    }

    Node *node = new Node(data);
    node->m_pNext = ptr->m_pNext;
    ptr->m_pNext = node;
    ++s_nodeCount;
}
/*
void SinglyLinkedList :: push_after_byValue(int data){
    ++s_nodeCount;

}

void SinglyLinkedList :: push_before_byValue(int data){
    ++s_nodeCount;

}

void SinglyLinkedList :: push_after_byPosition(int data, int pos){
    // invalid position received
    if (pos > s_nodeCount){
        std::cout << "[push_after_byPosition] Invalid position" << std::endl;
        return;
    }

    // list is empty
    if (m_pHead == nullptr){
        push_front(data);
        return;
    }

    // after the last node
    if (pos == s_nodeCount){
        push_back(data);
        return;
    }

    // in-between positions
    Node *ptr = m_pHead;
    int count = 1;

    while (count != pos){
        ptr = ptr->m_pNext;
        count++;
    }

    Node *node = new Node(data);
    node->m_pNext = ptr->m_pNext;
    ptr->m_pNext = node;
    ++s_nodeCount;
}

void SinglyLinkedList :: push_before_byPosition(int data, int pos){
    // invalid position received
    if (pos > s_nodeCount){
        std::cout << "[push_before_byPosition] Invalid position" << std::endl;
        return;
    }

    // list is empty or position=1 is received
    if (m_pHead == nullptr || pos == 1){
        push_front(data);
        return;
    }

    // in-between positions
    Node *ptr = m_pHead;
    int count = 1;

    while (count != pos-1){
        ptr = ptr->m_pNext;
        count++;
    }

    Node *node = new Node(data);
    node->m_pNext = ptr->m_pNext;
    ptr->m_pNext = node;
    ++s_nodeCount;
}
*/
void SinglyLinkedList :: pop_front(){
    if (m_pHead == nullptr){
        std::cout << "[pop_front] The list is empty" << std::endl;
        return;
    }

    if (m_pHead->m_pNext == nullptr){
        // std::cout << "[pop_front] Single node to delete" << std::endl;
        m_pTail = nullptr;
    }

    Node *del = m_pHead;
    m_pHead = m_pHead->m_pNext;
    delete del;
    --s_nodeCount;
}

void SinglyLinkedList :: pop_back(){
    if (m_pTail == nullptr){
        std::cout << "[pop_back] The list is empty" << std::endl;
        return;
    }

    Node *ptr = m_pHead;
    int count = 1;
    // arrive on the second last node
    while (count < s_nodeCount-1){
        ptr = ptr->m_pNext;
        ++count;
    }

    Node *del = nullptr;
    if (ptr->m_pNext == nullptr){
        // single node
        del = ptr;
        m_pHead = nullptr;
        m_pTail = nullptr;
    }
    else{
        del = ptr->m_pNext;
    }

    delete del;
    ptr->m_pNext = nullptr;
    --s_nodeCount;
}
/*
void SinglyLinkedList :: pop_at(int pos){
    --s_nodeCount;

}

void SinglyLinkedList :: pop_after_byValue(int data){
    --s_nodeCount;

}

void SinglyLinkedList :: pop_before_byValue(int data){
    --s_nodeCount;

}

void SinglyLinkedList :: pop_after_byPosition(int pos){
    --s_nodeCount;

}

void SinglyLinkedList :: pop_before_byPosition(int pos){
    --s_nodeCount;

}
*/
void SinglyLinkedList :: printList() const{

    Node* ptr = m_pHead;
    int count = 1;

    while (ptr != nullptr){
        std::cout << "[" << count << "] " << ptr->m_data << "\t";
        ptr = ptr-> m_pNext;
        count++;
    }
    std::cout << std::endl;
}

void SinglyLinkedList :: clearList(){
    while (m_pHead != nullptr)
        pop_front();
}

int SinglyLinkedList :: front() const{
    if (m_pHead == nullptr)
        return -1;

    return m_pHead->m_data;
}

int SinglyLinkedList :: back() const{
    if (m_pTail == nullptr)
        return -1;

    return m_pTail->m_data;
}

int SinglyLinkedList :: getNodeCount(){
    return s_nodeCount;
}

// void createList_push_front ( SinglyLinkedList &list, int arr[5]){
//     for (int i=0 ; i<5 ; i++)
//         list.push_front(arr[i]);
// }

// #define METHODNAME push_at


// void createList_METHODNAME ( SinglyLinkedList &list, int arr[5]){
//     for (int i=0 ; i<5 ; i++)
//         list.METHODNAME(arr[i]);
// }

int main()
{
    SinglyLinkedList list;
    int arr[]{1, 2, 3, 4, 5};

    // createList_METHODNAME(list, arr);

    // for (int i=0 ; i<5 ; i++)
    //     list.push_front(arr[i]);
    // list.printList();
    
    // // for (int i=0 ; i<5 ; i++)
    //     list.pop_front();
    // list.printList();
    //     list.pop_front();
    // list.printList();
    //     list.pop_front();
    // list.printList();
    //     list.pop_front();
    // list.printList();
    //     list.pop_front();
    // list.printList();

    // list.clearList();
    

    for (int i=0 ; i<5 ; i++)
        list.push_back(arr[i]);
    list.printList();
    
    for (int i=0 ; i<5 ; i++)
    {
        list.pop_back();
        list.printList();
    }

    list.clearList();
    


    return 0;
}