/** @file ListADT.h
 *  Abstract base class for the ADT list.
 *  Lab 3: Lists and Polynomial Calculator
 *  COSC-2436 Data Structures
 *  Fall 2025
 */

#ifndef LIST_ADT_H
#define LIST_ADT_H

/** @class ListADT
 *  Abstract base class for the ADT list.
 *  Provides interface for all list implementations.
 *  @tparam T The type of elements stored in the list. */
template<typename T>
class ListADT {
public:
    /** Tests whether this list is empty.
     *  @return True if the list is empty; otherwise returns false. */
    virtual bool isEmpty() const = 0;

    /** Gets the current number of entries in this list.
     *  @return The integer number of entries currently in the list. */
    virtual int getLength() const = 0;

    /** Inserts an entry into this list at a given position.
     *  @pre None.
     *  @post If 1 <= newPosition <= getLength() + 1 and the insertion is
     *     successful, the entry at position newPosition is newEntry, and
     *     other entries are appropriately renumbered.
     *  @param newPosition The list position at which to insert newEntry.
     *  @param newEntry The object to insert into the list.
     *  @return True if insertion is successful, false otherwise. */
    virtual bool insert(int newPosition, const T &newEntry) = 0;

    /** Removes the entry at a given position from this list.
     *  @pre None.
     *  @post If 1 <= position <= getLength() and the removal is successful,
     *     the entry at position is removed, other entries are appropriately
     *     renumbered, and the returned value is true.
     *  @param position The list position of the entry to remove.
     *  @return True if removal is successful, false otherwise. */
    virtual bool remove(int position) = 0;

    /** Removes all entries from this list.
     *  @pre None.
     *  @post List contains no entries and getLength() returns 0. */
    virtual void clear() = 0;

    /** Gets the entry at a given position in this list.
     *  @pre 1 <= position <= getLength().
     *  @post None.
     *  @param position The list position of the entry to retrieve.
     *  @return The entry at position position in the list.
     *  @throw invalid_argument if position < 1 or position > getLength(). */
    virtual T getEntry(int position) const = 0;

    /** Replaces the entry at a given position in this list.
     *  @pre 1 <= position <= getLength().
     *  @post The entry at position position is replaced by newEntry.
     *  @param position The list position of the entry to replace.
     *  @param newEntry The replacement entry.
     *  @throw invalid_argument if position < 1 or position > getLength(). */
    virtual void replace(int position, const T &newEntry) = 0;

    /** Virtual destructor. */
    virtual ~ListADT() = default;
}; // end ListADT

#endif // LIST_ADT_H
