/** @file ArrayList.h
 *  Array-based implementation of the ADT list.
 *  Lab 3: Lists and Polynomial Calculator
 *  COSC-2436 Data Structures
 *  Fall 2025
 */

#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include "ListADT.h"
#include <string>
#include <stdexcept>

/** Maximum size for arrays in this lab. */
constexpr int MAX_ARRAY_SIZE = 64;

/** @class ArrayList
 *  Array-based implementation of the ADT list.
 *  Stores list items in a fixed-size array.
 *  @tparam T The type of elements stored in the list.
 *  @tparam N The maximum capacity of the array (must be >= MAX_ARRAY_SIZE). */
template<typename T, int N>
class ArrayList final : public ListADT<T> {
private:
    int itemCount;           ///< Current count of list items
    int maxItems;            ///< Maximum capacity of the list
    T items[N]{};            ///< Array of list items (items[0] is ignored)

public:
    /** Default constructor.
     *  Creates an empty list with maximum capacity N.
     *  @pre N >= MAX_ARRAY_SIZE.
     *  @post List is empty with itemCount = 0 and maxItems = N. */
    ArrayList() : itemCount(0), maxItems(N) {
        static_assert(N >= MAX_ARRAY_SIZE, "Array size must be at least MAX_ARRAY_SIZE");
    }

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
     *  @post If 1 <= newPosition <= getLength() + 1 and the list is not full,
     *     newEntry is inserted at position newPosition, and other entries are
     *     shifted toward the end of the array.
     *  @param newPosition The list position at which to insert newEntry (1-based).
     *  @param newEntry The object to insert into the list.
     *  @return True if insertion is successful, false if position is invalid
     *     or list is full. */
    bool insert(int newPosition, const T &newEntry) override {
        bool ableToInsert = (newPosition >= 1) &&
                            (newPosition <= itemCount + 1) &&
                            (itemCount < maxItems);
        if (ableToInsert) {
            // Make room for new entry by shifting all entries at
            // positions >= newPosition toward the end of the array
            // (no shift if newPosition == itemCount + 1)
            for (int pos = itemCount; pos >= newPosition; pos--)
                items[pos] = items[pos - 1];
            // Insert new entry
            items[newPosition - 1] = newEntry;
            itemCount++; // Increase count of entries
        } // end if
        return ableToInsert;
    } // end insert

    /** Removes the entry at a given position from this list.
     *  @pre None.
     *  @post If 1 <= position <= getLength(), the entry at position is removed,
     *     other entries are shifted toward the beginning of the array.
     *  @param position The list position of the entry to remove.
     *  @return True if removal is successful, false otherwise. */
    bool remove(int position) override {
        bool ableToRemove = (position >= 1) && (position <= itemCount);
        if (ableToRemove) {
            // Remove entry by shifting all entries after the one at
            // position toward the beginning of the array
            // (no shift if position == itemCount)
            for (int fromIndex = position, toIndex = fromIndex - 1;
                 fromIndex < itemCount; fromIndex++, toIndex++)
                items[toIndex] = items[fromIndex];
            itemCount--; // Decrease count of entries
        } // end if
        return ableToRemove;
    } // end remove

    /** Removes all entries from this list.
     *  @pre None.
     *  @post List contains no entries and getLength() returns 0. */
    void clear() override {
        itemCount = 0;
    } // end clear

    /** Gets the entry at a given position in this list.
     *  @pre 1 <= position <= getLength().
     *  @post None.
     *  @param position The list position of the entry to retrieve.
     *  @return The entry at position position in the list.
     *  @throw invalid_argument if position < 1 or position > getLength(). */
    T getEntry(int position) const override {
        // Enforce precondition
        bool ableToGet = (position >= 1) && (position <= itemCount);
        if (ableToGet)
            return items[position - 1];
        else {
            std::string message = "getEntry() called with an empty list or ";
            message = message + "invalid position.";
            throw std::invalid_argument(message);
        } // end if
    } // end getEntry

    /** Replaces the entry at a given position in this list.
     *  @pre 1 <= position <= getLength().
     *  @post The entry at position position is replaced by newEntry.
     *  @param position The list position of the entry to replace.
     *  @param newEntry The replacement entry.
     *  @throw invalid_argument if position < 1 or position > getLength(). */
    void replace(int position, const T &newEntry) override {
        // Enforce precondition
        bool ableToSet = (position >= 1) && (position <= itemCount);
        if (ableToSet)
            items[position - 1] = newEntry;
        else {
            std::string message = "replace() called with an empty list or ";
            message = message + "invalid position.";
            throw std::invalid_argument(message);
        } // end if
    } // end replace
}; // end ArrayList

#endif // ARRAY_LIST_H
