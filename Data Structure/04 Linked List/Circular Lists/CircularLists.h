#ifndef CIRCULARLISTS_H
#define CIRCULARLISTS_H

#include<iostream>

template<class T> class CircularList;

template<class T>
class ListNode 
{
    friend class CircularList<T>;
private:
    T data;
    ListNode<T> *link;
    ListNode(T element = T(), ListNode<T> *next = NULL) : data(element), link(next) {}
};

template<class T>
class CircularList 
{
private:
    ListNode<T> *last;
    static ListNode<T>* av; // Available list for recycling nodes
public:
    CircularList();
    ~CircularList();
    ListNode<T> *GetNode();
    void RetNode(ListNode<T>*&);
    void InsertFront(const T&);
    void InsertBack(const T&);
    void Output() const; // Function to Output the list
};

#include"CircularLists.cpp"
#endif