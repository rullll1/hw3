//
// Created by rulll on 27/05/2022.
//

#ifndef HW3_QUEUE_H
#define HW3_QUEUE_H

#include <iostream>

template<class T>
class Queue
{
private:
    struct Node
    {
        T data;
        Node *next;
    };
    Node *head,*tail;
    int m_size;

public:
    Queue()
    {
        head = nullptr;
        tail = nullptr;
        m_size = 0;

    }
    ~Queue(){

        deleteNodes(this->head);
//        this->head = NULL;
//        this->tail = NULL;

    }

//    Queue(const Queue& other){
//        this->head = nullptr;
//        this->tail = nullptr;
//        this->m_size = 0;
//        for(ConstIterator i=other.begin(); i != other.end(); ++i){
//            try {
//                Node *tmp = new Node;
//                tmp->data = *i;
//                tmp->next = nullptr;
//
//                if(head == nullptr)
//                {
//                    head = tmp;
//                    tail = tmp;
//                }
//                else
//                {
//                    tail->next = tmp;
//                    tail = tail->next;
//                }
//                m_size += 1;
//            }
//            catch (std::bad_alloc& e){
//                deleteNodes(this->head);
//                throw;
//            }
//        }
//    }

    Queue(const Queue<T>& queue) : head(nullptr),tail(nullptr), m_size(0){
        Queue<T>::ConstIterator it = queue.begin();
        while (it != queue.end()) {
            try {pushBack(*it);}
            catch (std::bad_alloc&){
                while (head){
                    popFront();
                }
                throw;
            }
            ++it;
        }
    }

    Queue<T>& operator=(const Queue<T>& other)
    {
        Node* oldHead = this->head;
        Node* oldTail = this->tail;
        int old_size = this->size();


        this->head = nullptr;
        this->tail = nullptr;
        this->m_size = 0;

        for(ConstIterator i=other.begin(); i != other.end(); ++i){
            try {
                Node *tmp = new Node;
                tmp->data = *i;
                tmp->next = nullptr;

                if(head == nullptr)
                {
                    head = tmp;
                    tail = tmp;
                }
                else
                {
                    tail->next = tmp;
                    tail = tail->next;
                }
                m_size += 1;
            }
            catch (std::bad_alloc& e){
                deleteNodes(this->head);
                this->m_size = old_size;
                this->head = oldHead;
                this->tail = oldTail;
                throw e;
            }
        }
        deleteNodes(oldHead);
        return *this;
    }


//    void deleteNodes(Node* node){
//        if (node){
//            deleteNodes(node->next);
//            node->next = nullptr;
//            delete node;
//        }
//
//    }

    void deleteNodes(Node* node){
        while (node){
            Node* toDelete = node;
            node = node->next;
            delete (toDelete);
        }

    }

    class Iterator{
    private:
        Queue<T> m_q;
        Node* m_node;
    public:
        Iterator(Node *node){
            this->m_node = node;

        }
        Iterator& operator++(){
            if (!(this->m_node)){
                throw InvalidOperation();
            }
            Node* newHead = this->m_node->next;
//            delete this->m_q.head;
            this->m_node = newHead;
            return *this;
        }

        Iterator&  operator++(int){
            if (!(this->m_q.head->next)){
                throw InvalidOperation();
            }
            Node* newHead = m_q.head->next;
            m_q.head = newHead;
            return *this;
        }

        class InvalidOperation{};

        bool operator==(const Iterator& other) const {
            return this->m_q.head == other.m_q.head;
        }

        bool operator!=(const Iterator& other) const {
            return !(this->m_node == other.m_node);
        }

        T&  operator*(){

            return this->m_node->data;
        }


    };

    class ConstIterator{
    private:
        Queue<T> m_q;
        Node* m_node;
    public:
        ConstIterator(Node *node){
            this->m_node = node;

        }
        ConstIterator& operator++(){
            if (!(this->m_node)){
                throw InvalidOperation();
            }
            Node* newHead = this->m_node->next;
//            delete this->m_q.head;
            this->m_node = newHead;
            return *this;
        }

        ConstIterator&  operator++(int){
            if (!(this->m_q.head->next)){
                throw InvalidOperation();
            }
            Node* newHead = m_q.head->next;
            m_q.head = newHead;
            return *this;
        }

        class InvalidOperation{};

        bool operator==(const ConstIterator& other) const {
            return this->m_q.head == other.m_q.head;
        }

        bool operator!=(const ConstIterator& other) const {
            return !(this->m_node == other.m_node);
        }

        T&  operator*() const{

            return this->m_node->data;
        }


    };

    class EmptyQueue {};

    int size() const{
        return this->m_size;
    }


    void pushBack(T n)
    {
        Node *tmp = new Node;
        tmp->data = n;
        tmp->next = nullptr;

        if(head == nullptr)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
        m_size += 1;
    }
    T& front() const {
        if (this->size() == 0){
            throw EmptyQueue();
        }
        return this->head->data;
    }

    void popFront(){
        if (this->size() == 0){
            throw EmptyQueue();
        }
        Node* newHead = this->head->next;
        delete this->head;
        this->head = newHead;
        if (m_size == 1){
            this->tail = nullptr;
        }
        m_size -= 1;
    }


    Iterator begin() {
        return Iterator(this->head);
    }
    ConstIterator begin() const {
        return ConstIterator(this->head);
    }

    Iterator end() {
        if (!(this->tail)){
            return Iterator(this->tail); // to support some tests...
        }
        return Iterator(this->tail->next);
    }

    ConstIterator end() const {
        if (!(this->tail)){
            return ConstIterator(this->tail); // to support some tests...
        }
        return ConstIterator(this->tail->next);
    }
};

template<class T, typename Function>
Queue<T> filter(Queue<T>& q, Function func){
    Queue<T> newQ;
    int size = 0;
    for (typename Queue<T>::Iterator i = q.begin(); i != q.end(); size++, ++i){
        if (func(*i)){
            newQ.pushBack(*i);
        }
    }
    return newQ;
}


template<class T, typename Function>
void transform(Queue<T>&  q, Function func){
    int size = 0;
    for (typename Queue<T>::Iterator i = q.begin(); size < q.size(); size++,++i){
        func(*i);
    }
}



#endif //HW3_QUEUE_H
