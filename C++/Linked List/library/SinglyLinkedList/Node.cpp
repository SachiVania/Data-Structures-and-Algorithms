#include "Node.h"

Node :: Node(int data) {
    m_data = data;
    m_pNext = nullptr;
}

Node :: ~Node() {
    m_pNext = nullptr;
}