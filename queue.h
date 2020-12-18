#ifndef QUEUE_H
#define QUEUE_H
#include "../../!includes/linkedListFunctions/linkedlistfunctions.h"
#include "../../!includes/List/list.h"
#include <cassert>
using namespace std;
template<typename T>
class Queue{
public:
    Queue();
    // -----------------------------------------
    // big three:
    ~Queue();
    Queue(const Queue& other); // copy ctor
    void operator = (const Queue& RHS);// overloaded assignment operator
    // -----------------------------------------
    void push(const T& item); // add to queue
    T pop(); // remove from queue
    bool empty(); // check if queue is empty
    T front(); // return whatever is at the front
    friend ostream& operator << (ostream& outs, const Queue<T>& printMe){
        // do some stuff
        const bool debug = false;
        node<T>* w;
        w = printMe._front;
        while(w != NULL){
            outs << w->_item << " ";
            if(debug) cout << "Queue::operator <<: " << endl;
            w = w->_next;
        }
        return outs;
    }// overloaded insertion operator
    void print(); // for debugging
private:
    node<T>* _front; // points to front
    node<T>* _rear; // points to rear
};

template<typename T>
Queue<T>::Queue(){
     _front = NULL;
     _rear = NULL;
}
// -----------------------------------------
// big three:
template<typename T>
Queue<T>::~Queue(){
    // destructor
    node<T>* w;
    w = _front;
    while(_front != NULL){
        this->pop();
    }
}
template<typename T>
Queue<T>::Queue(const Queue& other){
    // copy ctor
//    cout<<"oh shit!!"<<endl;
    // all you're doing here is pointing your front to the other's front,
    // and pointing your rear to the other's rear...
    // you need a copy list function here that copies all components
    // of the list!
//    _front = other._front;
//    _rear = other._rear;
    _front = CopyList(other._front);
    _rear = LastNode(_front); // <--- should be doing this
}
template<typename T>
void Queue<T>::operator = (const Queue& RHS){
    // assignment op
    // same issue here... you can't just set the fronts and rears equal...
    // what about the rest of the list?????
    _front = CopyList(RHS._front);
//    _rear = RHS._rear;
    _rear = LastNode(_front); // <--- should be doing this
}
// -----------------------------------------
template<typename T>
void Queue<T>::push(const T& item){
    // add to rear
    const bool debug = false;
    if(empty()){
        _front = insertHead(_front, item);
        _rear = _front;
        if(debug){
            cout << "Queue::push: _rear -> "
                 << _rear->_item
                 << endl
                 << "_front -> "
                 << _front->_item << endl;
        }
    }
    else{
        // to add to a non-empty queue:
        _rear = insertAfter(_front, _rear, item);
    }
}
template<typename T>
T Queue<T>::pop(){
    assert(_front!=NULL);
    T deletedItem = _front->_item;
        // save item before you delete node so you can return
    deleteNode(_front, _front);
    //YOU ARE NOT DEALING WITH REAR ON POPPING OF THE LAST ITEM.
    return deletedItem;
}
template<typename T>
bool Queue<T>::empty(){
    const bool debug = false;
    if(_front == NULL){
        if(debug) cout << "Queue::empty(): Empty queue" << endl;
        return true;
    }
    if(debug) cout << "Queue::empty(): Queue NOT empty" << endl;
    return false;
}
template<typename T>
T Queue<T>::front(){
    // get item at front of queue
    const bool debug = false;
    if(debug) cout << "Queue::front(): " << endl;
    return this->_front->_item;
}
template<typename T>
void Queue<T>::print(){
    // blank
    const bool debug = false;
    node<T>* w;
    w = _front;
    if(debug) cout << "Queue::print: walker = " << *w << endl;
    while(w != NULL){
        cout << w->_item << " ";
        w = w->_next;
    }
    cout << endl;
}
#endif // QUEUE_H









//#ifndef QUEUE_H
//#define QUEUE_H
//#include "../../!includes/linkedListFunctions/linkedlistfunctions.h"
//#include "../../!includes/List/list.h"

//template<typename T>
//class Queue{
//public:
//    class Iterator{
//        //the nested class
//        public:
//            friend class Queue; //this will allow List to access the private members of Iterator
//            Iterator(node<T>* p = NULL):_ptr(p){
//                // ctor
//                // if pointer not given, set to NULL
//                // (this way, we don't need a default ctor)

//                // left blank

//            }
//            operator bool(){
//                //casting operator: true if _ptr not NULL
//                if(_ptr != NULL) return true;
//            }

//            Iterator next()
//            {
//                //return an iterator to the next location in the list
//                Iterator temp = _ptr->_next;
//                return temp;
//            }

//            T& operator *(){
//                // dereference operator
//                return _ptr->_item; // returns item
//            }
//            T* operator ->(){
//                // member access operator
//                // since this returns a pointer,
//                // I'll have it return _next
//                // instead of an item
//                // (we already have * anyway)
//                Iterator nextPtr(_ptr->_next);
//                return nextPtr;
//            }
//            bool is_null(){
//                //true if _ptr is NULL
//                if(_ptr == NULL) return true;
//            }
//            friend Iterator operator ++(Iterator& it, int unused){
//                // it++
//                // it++ will increment the value of it,
//                // but return the original value that it
//                // held before being incremented.
//                // Iterator points to the next location
//                if(it._ptr == NULL){// || it._ptr->_next == NULL
//                    return it;
//                }
//                it._ptr = it._ptr->_next;
//                return it;
//            }
//            Iterator& operator ++(){
//                // ++it
//                // ++it will increment the value of it,
//                // and then return the incremented value.
//                if(_ptr == NULL || _ptr->_next == NULL){
//                    return *this;
//                }
//                _ptr = _ptr->_next;
//                return *this;

//            }
//            friend bool operator !=(const Iterator& left, const Iterator& right){
//                //it != it
//                if(left._ptr != right._ptr) return true;
//            }
//            friend bool operator ==(const Iterator& left, const Iterator& right){
//                //true if left == right
//                if(left._ptr == right._ptr) return true;
//            }
//        private:
//            node<T>* _ptr; //pointer being encapsulated

//        };

//    // Queue class members:
//    Queue();
//    // -----------------------------------------
//    // big three:
//    ~Queue();
//    Queue(const Queue& other); // copy ctor
//    void operator = (const Queue& RHS);// overloaded assignment operator
//    // -----------------------------------------
//    void push(const T& item); // add to queue
//    T pop(); // remove from queue
//    bool empty(); // check if queue is empty
//    T front(); // return whatever is at the front
//    friend ostream& operator << (ostream& outs, const Queue<T>& printMe){
//        // overloaded insertion operator
//        const bool debug = false;
//        const node<T>* w;
//        w = printMe._front;
//        while(w != NULL){
//            outs << w->_item << " ";
//            if(debug) cout << "Queue::operator <<: " << endl;
//            w = w->_next;
//        }
//        return outs;
//    }
//    void print(); // for debugging
//    void debug();
//    Iterator Begin() const;
//    Iterator End() const;
//private:
//    node<T>*  _front;
//    node<T>* _rear;
//};

//void debug(){
//    cout << "HELLO???????" << endl;
//}

//template<typename T>
//Queue<T>::Queue(){
//     _front = NULL;
//     _rear = NULL;
//}
//// -----------------------------------------
//// big three:
//template<typename T>
//Queue<T>::~Queue(){
//    Iterator w;
//    w = _front;
//    while(w != _rear->_next){ // can't compare these. replace null with end()
//        this->pop();
//    }
//}
//template<typename T>
//Queue<T>::Queue(const Queue& other){
//    _front = other._front;
//    _rear = other._rear;
//}
//template<typename T>
//void Queue<T>::operator = (const Queue& RHS){
//    _front = RHS._front;
//    _rear = RHS._rear;
//}
//// -----------------------------------------
//template<typename T>
//void Queue<T>::push(const T& item){
//    // add to rear
//    const bool debug = false;
//    if(empty()){
//        _front = insertHead(_front, item);
//        _rear = _front;
//        if(debug){
//            cout << "Queue::push: _rear -> "
//                 << _rear->_item
//                 << endl
//                 << "_front -> "
//                 << _front->_item << endl;
//        }
//    }
//    else{
//        // to add to a non-empty queue:
//        _rear = insertAfter(_front, _rear, item);
//    }
//}
//template<typename T>
//T Queue<T>::pop(){
//    T deletedItem = _front->_item;
//        // save item before you delete node so you can return
//    deleteNode(_front, _front);
//    return deletedItem;
//}
//template<typename T>
//bool Queue<T>::empty(){
//    const bool debug = false;
//    if(_front == NULL){
//        if(debug) cout << "Queue::empty(): Empty queue" << endl;
//        return true;
//    }
//    if(debug) cout << "Queue::empty(): Queue NOT empty" << endl;
//    return false;
//}
//template<typename T>
//T Queue<T>::front(){
//    // get item at front of queue
//    const bool debug = true;
//    if(debug) cout << "Queue::front(): " << endl;
//    return this->_front->_item;
//}
//template<typename T>
//void Queue<T>::print(){
//    // blank
//    const bool debug = false;
//    node<T>* w;
//    w = _front;
//    if(debug) cout << "Queue::print: walker = " << *w << endl;
//    while(w != NULL){
//        cout << w->_item << " ";
//        w = w->_next;
//    }
//    cout << endl;
//}
//template<class T>
//typename Queue<T>::Iterator Queue<T>::Begin() const{
//    // return _front
//    Iterator it;
//    it = _front;
//    return it;
//}
//template<class T>
//typename Queue<T>::Iterator Queue<T>::End() const{
//    // return _rear
//    Iterator it;
//    it = _rear->_next;
//    return it;
//}
//#endif // QUEUE_H
