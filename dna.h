#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
using namespace std;

class dna {
private:
    //
    // This implementation is a doubly-linked structure.  The nodes are structs
    // called Nucleotides.  Size could keep track of how many Nucleotides are
    // currently in the list.  front should always point to the first
    // Nucleotide and back should point to the last one.
    struct Nucleotide {
        char value;
        Nucleotide *next;
        Nucleotide *prev;
    };
    int Size;
    Nucleotide *front;
    Nucleotide *back;
    //
    // findFirst: (private)
    //
    // Searches dna for the first copy of the sequence target, returning a
    // pointer to that occurrence or nullptr if the target sequence isn't
    // present.
    // Performance requirement:  this function doesn't have a set Big O target,s
    // but should not time out on test cases and be reasonable.
    //
    Nucleotide* findFirst(dna target) {
        
        // TO DO: write this.
        Nucleotide* tmp = target.front;
        Nucleotide* node = nullptr;
        Nucleotide* cur = front;
        Nucleotide* ptr=nullptr;
        // loop thru cur 
        while(cur != nullptr ) {
             ptr = cur;
             //loop thru tmp and set ptr to cur
             while(tmp != nullptr) {
                if (ptr == NULL) {
                    break;
                }
                // if ptr is value equal 
                // then we next until its eitehr
                // null or not the value
                else if (tmp -> value == ptr -> value) { 
                ptr = ptr -> next; 
                tmp = tmp -> next; 
                } else {
                    break;
                }
            }
            // if we get temp to null then we know it
            // has a mtch
            if (tmp == NULL) { 
                node = cur;
                return node;
            }
            // this resets everything
            tmp = target.front; 
            cur = cur->next;
        }
        return node; // TO DO: update this.
    }
    
public:
    //
    // default constructor:
    //
    // Called automatically by C++ to create an empty dna object with two
    // Nucleotides, each with the value of 'X'.
    //
    dna() {
        front = new Nucleotide;
        back = new Nucleotide;
        // link those up
        front -> next = back;
        front -> prev = nullptr;
        // link up back
        back -> prev = front;
        back -> next = nullptr;
        // set value to x
        front -> value = 'X';
        back -> value = 'X';
        // set size
        Size = 2;
    }
    //
    // second constructor:
    //
    // Produces a new strand of nucleotides spelled out in the sequence given
    // by str.
    // Performance requirement: O(n)
    //
    dna(const string& str) {
        // set size to legnth 
        Size = str.length();
        if (Size == 0) {
            front = NULL;
            back = NULL;
            return;
        }
        Nucleotide *newNode;
        // connect them 
        front = new Nucleotide;
        front -> value = str.at(0);
        front -> next = NULL;
        front -> prev = NULL;
        back = front;
        // loop thru add value to newNode
        // add the newnode top back and connect
        for (int i = 1; i < Size; i++) {
            newNode = new Nucleotide;
            newNode -> value = str.at(i);
            newNode -> prev = back;
            newNode -> next = NULL;
            back -> next = newNode;
            back = newNode;
        }
    }
    //
    // copy constructor:
    //
    // Called automatically by C++ to create a dna object that contains a copy
    // of an existing dna object.
    // Performance requirement: O(n)
    //
    dna(const dna& other) {
        //set size
        Size = other.Size;
        Nucleotide *newNode;
        //connect them like secound
        Nucleotide *tmp = other.front;
        front = new Nucleotide;
        front -> value = tmp->value;
        front -> next = NULL;
        front -> prev = NULL;
        back = front;
        tmp = tmp -> next;
        //same thign as secoudn constructoor basically 
        for(int i = 1;i < other.Size; i++){
            newNode = new Nucleotide;
            newNode -> value = tmp -> value;
            newNode -> prev = back;
            newNode -> next = NULL;
            back -> next = newNode;
            back = newNode;
            tmp = tmp -> next;
        }
    }
    //
    // destructor:
    //
    // Called automatically by C++ to free the memory associated by
    // the dna object.
    // Performance requirement: O(n)
    //
    virtual ~dna() {
        Nucleotide *temp;
        while (front != nullptr) {
            temp = front -> next;
            delete front;
            front = temp;
        }
    }
    //
    // clear:
    //
    // Frees all memory in the chain of nucleotides in the dna obeject.  This
    // function should also set front, back, and Size, appropriately.
    // Performance requirement: O(n)
    //
    void clear() {
        // TO DO: write this.
        Nucleotide *temp;
        // loop intil i delete everyhting
        while (front != nullptr) {
            Size--;
            temp = front -> next;
            delete front;
            front = temp;
        }
        // connect them
        front = nullptr;
        back = nullptr;
        back = front;
    }
    //
    // operator=
    //
    // Called when you assign one dna object into another, i.e. this = other;
    // Performance requirement: O(n)
    //
    dna& operator=(const dna& other) {
        clear();
        //clear the old value
        this -> Size = other.Size;
        // set the new size
        Nucleotide *newNode;
        // connect them similar to secound
        Nucleotide *tmp = other.front;
        this -> front = new Nucleotide;
        this -> front -> value = tmp -> value;
        this -> front -> next = NULL;
        this -> front -> prev = NULL;
        this -> back = front;
        tmp = tmp -> next;
        // same conecpt as secound
        for(int i = 1;i < other.Size; i++){
            newNode = new Nucleotide;
            newNode -> value = tmp -> value;
            newNode -> prev = this -> back;
            newNode -> next = NULL;
            this -> back -> next = newNode;
            this -> back = newNode;
            tmp = tmp -> next;
        }
        return *this;  // TO DO: update this.
    }
    //
    // size:
    //
    // Returns the # of Nucleotides currently in the dna strand.
    // Performance requirement: O(1)
    //
    int size() const {
        return Size;  // TO DO: update this.
    }
    //
    // at(i):
    //
    // Returns a reference to the ith Nucleotide's value, which allows
    // you to read (access) or write (modify) this value.  If i is out of
    // bounds, an exception is thrown.
    // Performance requirement: O(n)
    //
    char& at(int i) {
        
        char out;
        // TO DO: write this.
        // if its our of range throw
        if ( i< 0 || i > Size) {
            throw out_of_range ("out of bounds");
        }
        // loop until i is reached and return that
        int counter = 0;
        Nucleotide *tmp = front;
        while (tmp != nullptr) {
            if (counter == i) {
                return tmp -> value;
            }
            tmp = tmp -> next;
            counter++;
        }
        throw out_of_range ("out of bounds");
    }
    //
    // toString:
    //
    // Returns a string spelling out the contents of the dna sequence.
    // Performance requirement: O(n)
    //
    string toString() const {
        string transform = "";
        Nucleotide *tmp = front;
        //loop and put those data in list
        while (tmp != nullptr) {
            transform += tmp -> value;
            tmp = tmp -> next;
        }
        return transform;  // TO DO: update this.
    }
    //
    // operator==
    //
    // This operator determines how you define equality between two operators.
    // In this function, you should compare other and this.  The two objects
    // should be considered equal if they have the same sequence of values and
    // in the same order.
    // Performance requirement: O(n)
    //
    bool operator==(const dna& other) const {
        // TO DO: write this.
        Nucleotide *tmp = front;
        Nucleotide *tmp2 = other.front;
        // check size first
        if(Size != other.Size){
            return false;
        }
        // loop both and check if the values
        // match if not false
        while (tmp != nullptr) {
            if(tmp -> value != tmp2 -> value) {
                return false;
            }
            tmp2 = tmp2 -> next;
            tmp = tmp -> next;
        }
        return true;  // TO DO: update this.
    }
    //
    // splice:
    //
    // Removes the first copy of the sequence in target that appears in the
    // dna sequence of current object.  This requires the linked structure to
    // be properly re-wired after removal.
    // Performance requirement: this function doesn't have a set Big O target,
    // but should not time out on test cases and be reasonable.
    //
    bool splice(dna target) {
        Nucleotide* cur =front;
        Nucleotide *tmp=target.front;
        Nucleotide* x = findFirst(target);
        // if x is null from find first
        // then we knwo false
        if (x != nullptr) {
            while (tmp != nullptr) {
                // prev and next of the node to be 
                // removed 
                Nucleotide* sucNode=x->next;
                Nucleotide* prevNode= x->prev;
                Size--;
                //if cur has a next
                if (sucNode != NULL) {
                    sucNode -> prev = prevNode;
                    }
                // if cur has a prev
                if (prevNode != NULL) {
                    prevNode -> next = sucNode;
                    }
                 // if its the head
                if (x == front) {
                    front = sucNode;
                    }
                // if its the tail
                if (x == back) { // Removed tail
                    back = prevNode;
                    }   
                tmp = tmp -> next;
                x = x -> next;
            }
        return true;
        }
    return false;  // TO DO: update this.
    }
    //
    // isLinked()
    //
   // Checks if a strand is linked correctly.  This is provided for you.
    // You should use it to test your linked structure often.
    // Performance requirement: O(n)
    //
    bool isLinked() {
        Nucleotide* start = front;
        // If we're at the start of a strand,
        // we should not have a previous pointer.
        if (start != nullptr && start->prev != nullptr) {
            return false;
        }
        // Walk the list, ensuring at each point that the next/prev pointers
        // are consistent with one another.
        for (Nucleotide* curr = start; curr != nullptr; curr = curr->next) {
            if (curr->next != nullptr && curr->next->prev != curr) return false;
            if (curr->prev != nullptr && curr->prev->next != curr) return false;
        }
        return true;
    }
};
