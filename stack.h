#ifndef STACK_H
#define STACK_H
#include "../../!includes/linkedListFunctions/linkedlistfunctions.h"
#include "../../!includes/List/list.h"
template<typename T>
class Stack{
public:
    Stack(); // ctor
    void push(const T& item); // add to stack
    T pop(); // remove from stack
    bool empty(); // check if stack is empty
    T top(); // returns whatever is at the top
    // overloaded insertion operator
    friend ostream& operator <<(ostream& outs, const Stack<T>& s){
        outs << s._stack;
        return outs;
    }
    void print(); // for debugging
private:
    List<T> _stack;
};
template<typename T>
Stack<T>::Stack(){
    // left blank
}
template<typename T>
void Stack<T>::push(const T& item){
    _stack.InsertHead(item);
}
template<typename T>
T Stack<T>::pop(){
    node<T>* top = _stack.Begin();
        // gets location of first item (the one at the top)
    return _stack.Delete(top);
        // remove item at top
}
template<typename T>
bool Stack<T>::empty(){
    const bool debug = false;
    node<T>* top = _stack.Begin();
        // gets location of first item (the one at the top)
    if(top == NULL){
        if(debug) cout << "List is empty" << endl;
        return true;
    }
    if(debug) cout << "List is NOT empty" << endl;
    return false;
}
template<typename T>
T Stack<T>::top(){
    node<T>* top = _stack.Begin();
        // gets location of first item (the one at the top)
    return top->_item;
        // return item at top
}
// overloaded insertion operator
//template<typename T>
//ostream& operator <<(ostream& outs, const Stack<T>& s){
//    outs << s._stack;
//    return outs;
//}
template<typename T>
void Stack<T>::print(){
    _stack.Print();
}
#endif // STACK_H










//#ifndef STACK_H
//#define STACK_H
//#include "../../!includes/linkedListFunctions/linkedlistfunctions.h"
//#include "../../!includes/List/list.h"
//template<typename T>
//class Stack{
//public:

//    Stack(); // ctor
//    void push(const T& item); // add to stack
//    T pop(); // remove from stack
//    bool empty(); // check if stack is empty
//    T top(); // returns whatever is at the top
//    friend ostream& operator <<(ostream& outs, const Stack<T>& s){
//        // overloaded insertion operator
//        outs << s._stack;
//        return outs;
//    }
//    void print(); // for debugging

//private:
//    List<T> _stack;
//};
//template<typename T>
//Stack<T>::Stack(){
//    // left blank
//}
//template<typename T>
//void Stack<T>::push(const T& item){
//    _stack.InsertHead(item);
//}
//template<typename T>
//T Stack<T>::pop(){
//    node<T>* top = _stack.Begin();
//        // gets location of first item (the one at the top)
//    return _stack.Delete(top);
//        // remove item at top
//}
//template<typename T>
//bool Stack<T>::empty(){
//    const bool debug = true;
//    node<T>* top = _stack.Begin();
//        // gets location of first item (the one at the top)
//    if(top == NULL){
//        if(debug) cout << "List is empty" << endl;
//        return true;
//    }
//    if(debug) cout << "List is NOT empty" << endl;
//    return false;
//}
//template<typename T>
//T Stack<T>::top(){
//    typename List<T>::Iterator s_top = _stack.Begin();
//        // gets location of first item (the one at the top)
//    return *s_top;
//        // return item at top
//}
//// overloaded insertion operator
////template<typename T>
////ostream& operator <<(ostream& outs, const Stack<T>& s){
////    outs << s._stack;
////    return outs;
////}
//template<typename T>
//void Stack<T>::print(){
//    _stack.Print();
//}

////    class Iterator{
////        //the nested class
////        public:
////            friend class Stack; //this will allow List to access the private members of Iterator
////            Iterator(node<T>* p = NULL):_ptr(p){
////                // ctor
////                // if pointer not given, set to NULL
////                // (this way, we don't need a default ctor)

////                // left blank

////            }
////            operator bool(){
////                //casting operator: true if _ptr not NULL
////                if(_ptr != NULL) return true;
////            }

////            Iterator next()
////            {
////                //return an iterator to the next location in the list
////                Iterator temp = _ptr->_next;
////                return temp;
////            }

////            T& operator *(){
////                // dereference operator
////                return _ptr->_item; // returns item
////            }
////            T* operator ->(){
////                // member access operator
////                // since this returns a pointer,
////                // I'll have it return _next
////                // instead of an item
////                // (we already have * anyway)
////                Iterator nextPtr(_ptr->_next);
////                return nextPtr;
////            }
////            bool is_null(){
////                //true if _ptr is NULL
////                if(_ptr == NULL) return true;
////            }
////            friend Iterator operator ++(Iterator& it, int unused){
////                // it++
////                // it++ will increment the value of it,
////                // but return the original value that it
////                // held before being incremented.
////                // Iterator points to the next location
////                if(it._ptr == NULL){// || it._ptr->_next == NULL
////                    return it;
////                }
////                it._ptr = it._ptr->_next;
////                return it;
////            }
////            Iterator& operator ++(){
////                // ++it
////                // ++it will increment the value of it,
////                // and then return the incremented value.
////                if(_ptr == NULL || _ptr->_next == NULL){
////                    return *this;
////                }
////                _ptr = _ptr->_next;
////                return *this;

////            }
////            friend bool operator !=(const Iterator& left, const Iterator& right){
////                //it != it
////                if(left._ptr != right._ptr) return true;
////            }
////            friend bool operator ==(const Iterator& left, const Iterator& right){
////                //true if left == right
////                if(left._ptr == right._ptr) return true;
////            }
////        private:
//////            node<T>* _ptr; //pointer being encapsulated
////            List<T>::Iterator _it;

////        };


//#endif // STACK_H



