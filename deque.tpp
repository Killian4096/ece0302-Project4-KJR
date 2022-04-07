#include "deque.hpp"

//Constructor
template <typename T>
Deque<T>::Deque(){
    frontNode = nullptr;
    backNode = nullptr;
}

//Copy Contructor
template <typename T>
Deque<T>::Deque(Deque &d){
    copyList(d->frontNode);
}

//copy Assigment
template <typename T>
Deque<T>& Deque<T>::operator=(const Deque<T>& d){
    copyList(d->frontNode);
}

//Destructor
template <typename T>
Deque<T>::~Deque(){
    //If list is empty, ignore
    if(isEmpty()){return;}

    //Traverse list and run destructor on each node
    Node<T>* traverseNode = frontNode;
    while(traverseNode != backNode){
        frontNode->~Node();
        frontNode = traverseNode;
        traverseNode = traverseNode->getNext();
    }
}

//isEmpty determines if list empty
template <typename T>
bool Deque<T>::isEmpty() const noexcept{
    return frontNode==nullptr;
}

//pushFront adds item to front of list
template <typename T>
void Deque<T>::pushFront(const T& item){
    //New node
    Node<T>* newNode = new Node<T>(item);
    //If list empty
    if(isEmpty()){
        frontNode = newNode;
        backNode = newNode;
    }
    //If item in list
    else{
        newNode->setNext(frontNode);
        frontNode = newNode;
    }
}

//pushBack adds item to back of list
template <typename T>
void Deque<T>::pushBack(const T& item){
    //New node
    Node<T>* newNode = new Node<T>(item);
    //If list empty
    if(isEmpty()){
        frontNode = newNode;
        backNode = newNode;
    }
    //If items in list
    else{
        backNode->setNext(newNode);
        backNode = newNode;
    }
}

//popFront deletes first item
template <typename T>
void Deque<T>::popFront(){
    //throw error if empty
    if(isEmpty()){
        throw std::runtime_error("Attempting to popFront empty list");
    }

    //Create buffer
    Node<T>* bufferNode = frontNode;

    //If only one item
    if(frontNode==backNode){
        backNode = nullptr;
        frontNode = nullptr;
    }
    //If more than 1 item
    else{
        frontNode = bufferNode->getNext();
    }

    //Run destructor
    bufferNode->~Node();
}

//popBack deletes last item
template <typename T>
void Deque<T>::popBack(){
    //throw error if empty
    if(isEmpty()){
        throw std::runtime_error("Attempting to popBack empty list");
    }

    //Create buffer
    Node<T>* bufferNode = backNode;

    //If only one item
    if(frontNode==backNode){
        frontNode = nullptr;
        backNode = nullptr;
    }
    //If more than 1 item
    else{
        //traverse list for next last node
        Node<T>* traverseNode = frontNode;
        while(backNode != traverseNode->getNext()){
            traverseNode = traverseNode->getNext();
        }
        backNode = traverseNode;
    }

    //Run destructor
    bufferNode->~Node();
}

//front return front item
template <typename T>
T Deque<T>::front() const{
    //Throw error if empty list
    if(isEmpty()){
        throw std::runtime_error("Attempting to access front of empty list");
    }
    return frontNode->getItem();
}

//back return back item
template <typename T>
T Deque<T>::back() const{
    //Throw error if empty list
    if(isEmpty()){
        throw std::runtime_error("Attempting to access back of empty list");
    }
    return backNode->getItem();
}

//Function to copy list
template <typename T>
void Deque<T>::copyList(const Node<T>& n){
    //If list is empty
    if(n==nullptr){
        frontNode = nullptr;
        backNode = nullptr;
    }
    frontNode = n;
    backNode = n;
    //Traverse list till end
    while(backNode->getNext()!=nullptr){
        backNode = backNode->getNext();
    }
}