#ifndef DEQUE_HPP
#define DEQUE_HPP

#include "abstract_deque.hpp"
#include "Node.hpp"

template <typename T>
class Deque: public AbstractDeque<T>{

  public:
    //Constructor
    Deque();

    //Copy Contructor
    Deque(Deque &d);

    //Destructor
    ~Deque();

    //Copy Assigment
    Deque& operator=(const Deque& d);

    //To implement
    bool isEmpty() const noexcept;
    void pushFront(const T& item);
    void pushBack(const T& item);
    void popFront();
    void popBack();
    T front() const;
    T back() const;



  private:
    Node<T> *frontNode;
    Node<T> *backNode;

    void copyList(const Node<T>& n);
  
};

#include "deque.tpp"

#endif
