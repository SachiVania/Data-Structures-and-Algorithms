#pragma once

#include "Node.h"

class SinglyLinkedList{
    private:
        Node *m_pHead;
        Node *m_pTail;
        inline static int s_nodeCount = 0;

    public:
        SinglyLinkedList();
        ~SinglyLinkedList();

        // Insert operations
        void push_front(int data);
        void push_back(int data);
        void push_at(int data, int pos);
        // void push_after_byValue(int data);
        // void push_before_byValue(int data);
        // void push_after_byPosition(int data, int pos);
        // void push_before_byPosition(int data, int pos);

        // Delete operations
        void pop_front();
        void pop_back();
        void pop_at(int pos);
        // void pop_after_byValue(int data);
        // void pop_before_byValue(int data);
        // void pop_after_byPosition(int pos);
        // void pop_before_byPosition(int pos);

        void printList() const;
        void clearList();
        
        int front() const;
        int back() const;
        
        static int getNodeCount();
};