/** @file LinkedList.h
 *  Link-based implementation of the ADT list.
 *  Lab 3: Lists and Polynomial Calculator
 *  COSC-2436 Data Structures
 *  Fall 2025
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "ListADT.h"
#include <string>
#include <stdexcept>

// ============================================================================
// NODE CLASS
// ============================================================================

/** @class Node
 *  A node in a linked chain.
 *  @tparam T The type of value stored in the node. */
template<typename T>
class Node {
private:
    T value;            ///< Data value stored in the node
    Node *next;         ///< Pointer to next node in the chain

public:
    /** Constructor with value only.
     *  @param value The data value for this node. */
    Node(T value) : value(value), next(nullptr) {}

    /** Constructor with value and next pointer.
     *  @param value The data value for this node.
     *  @param next Pointer to the next node. */
    Node(T value, Node *next) : value(value), next(next) {}

    /** Gets the data value stored in this node.
     *  @return The data value. */
    T getItem() const {
        return value;
    }

    /** Gets the pointer to the next node.
     *  @return Pointer to the next node in the chain. */
    Node *getNext() const {
        return next;
    }

    /** Sets the pointer to the next node.
     *  @param n Pointer to the next node. */
    void setNext(Node *n) {
        next = n;
    }

    /** Sets the data value for this node.
     *  @param v The new data value. */
    void setItem(const T &v) {
        value = v;
    }
}; // end Node

// ============================================================================
// LINKED LIST CLASS
// ============================================================================

/** @class LinkedList
 *  Link-based implementation of the ADT list.
 *  Stores list items in a chain of linked nodes.
 *  @tparam ItemType The type of elements stored in the list. */
template<class ItemType>
class LinkedList : public ListADT<ItemType> {
private:
    Node<ItemType> *headPtr;  ///< Pointer to first node in the chain
    int itemCount;            ///< Current count of list items

    /** Locates a specified node in the linked list.
     *  @pre 1 <= position <= itemCount.
     *  @post The node is found and a pointer to it is returned.
     *  @param position The number of the desired node (1-based).
     *  @return A pointer to the node at the given position.
     *  @throw out_of_range if position is invalid. */
    Node<ItemType> *getNodeAt(int position) const {
        // Debugging check of precondition
        if (position < 1 || position > itemCount) {
            throw std::out_of_range("Position out of range.");
        }

        // Count from the beginning of the chain
        Node<ItemType> *curPtr = headPtr;
        for (int skip = 1; skip < position; skip++)
            curPtr = curPtr->getNext();
        return curPtr;
    } // end getNodeAt

public:
    /** Default constructor.
     *  Creates an empty list.
     *  @post List is empty with headPtr = nullptr and itemCount = 0. */
    LinkedList() : headPtr(nullptr), itemCount(0) {}

    /** Destructor.
     *  Deallocates all nodes in the chain. */
    ~LinkedList() {
        clear();
    } // end destructor

    /** Tests whether this list is empty.
     *  @return True if the list is empty; otherwise returns false. */
    bool isEmpty() const override {
        return itemCount == 0;
    }

    /** Gets the current number of entries in this list.
     *  @return The integer number of entries currently in the list. */
    int getLength() const override {
        return itemCount;
    }

    /** Inserts an entry into this list at a given position.
     *  @pre None.
     *  @post If 1 <= newPosition <= getLength() + 1, newEntry is inserted
     *     at position newPosition, and other node positions are updated.
     *  @param newPosition The list position at which to insert newEntry (1-based).
     *  @param newEntry The object to insert into the list.
     *  @return True if insertion is successful, false otherwise. */
    bool insert(int newPosition, const ItemType &newEntry) override {
        bool ableToInsert = (newPosition >= 1) &&
                            (newPosition <= itemCount + 1);
        if (ableToInsert) {
            // Create a new node containing the new entry
            Node<ItemType> *newNodePtr = new Node<ItemType>(newEntry);
            // Attach new node to chain
            if (newPosition == 1) {
                // Insert new node at beginning of chain
                newNodePtr->setNext(headPtr);
                headPtr = newNodePtr;
            } else {
                // Find node that will be before new node
                Node<ItemType> *prevPtr = getNodeAt(newPosition - 1);
                // Insert new node after node to which prevPtr points
                newNodePtr->setNext(prevPtr->getNext());
                prevPtr->setNext(newNodePtr);
            } // end if
            itemCount++; // Increase count of entries
        } // end if
        return ableToInsert;
    } // end insert

    /** Removes the entry at a given position from this list.
     *  @pre None.
     *  @post If 1 <= position <= getLength(), the entry at position is removed,
     *     and the node is deallocated.
     *  @param position The list position of the entry to remove.
     *  @return True if removal is successful, false otherwise. */
    bool remove(int position) override {
        bool ableToRemove = (position >= 1) && (position <= itemCount);
        if (ableToRemove) {
            Node<ItemType> *curPtr = nullptr;
            if (position == 1) {
                // Remove the first node in the chain
                curPtr = headPtr; // Save pointer to node
                headPtr = headPtr->getNext();
            } else {
                // Find node that is before the one to delete
                Node<ItemType> *prevPtr = getNodeAt(position - 1);
                // Point to node to delete
                curPtr = prevPtr->getNext();
                // Disconnect indicated node from chain by connecting the
                // prior node with the one after
                prevPtr->setNext(curPtr->getNext());
            } // end if
            // Return node to system
            curPtr->setNext(nullptr);
            delete curPtr;
            curPtr = nullptr;
            itemCount--; // Decrease count of entries
        } // end if
        return ableToRemove;
    } // end remove

    /** Removes all entries from this list.
     *  @pre None.
     *  @post List contains no entries and getLength() returns 0.
     *     All nodes are deallocated. */
    void clear() override {
        while (!isEmpty())
            remove(1);
    } // end clear

    /** Gets the entry at a given position in this list.
     *  @pre 1 <= position <= getLength().
     *  @post None.
     *  @param position The list position of the entry to retrieve.
     *  @return The entry at position position in the list.
     *  @throw invalid_argument if position < 1 or position > getLength(). */
    ItemType getEntry(int position) const override {
        // Enforce precondition
        bool ableToGet = (position >= 1) && (position <= itemCount);
        if (ableToGet) {
            Node<ItemType> *nodePtr = getNodeAt(position);
            return nodePtr->getItem();
        } else {
            std::string message = "getEntry() called with an empty list or ";
            message = message + "invalid position.";
            throw std::invalid_argument(message);
        }
    } // end getEntry

    /** Replaces the entry at a given position in this list.
     *  @pre 1 <= position <= getLength().
     *  @post The entry at position position is replaced by newEntry.
     *  @param position The list position of the entry to replace.
     *  @param newEntry The replacement entry.
     *  @throw out_of_range if position is invalid. */
    void replace(int position, const ItemType &newEntry) override {
        Node<ItemType> *n = getNodeAt(position);
        n->setItem(newEntry);
    } // end replace
}; // end LinkedList

#endif // LINKED_LIST_H
