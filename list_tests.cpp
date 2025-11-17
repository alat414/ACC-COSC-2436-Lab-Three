#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "list_adt.h"
#include "array_list.h"
#include "linked_list.h"

// ============================================================================
// PART 1: List ADT Unit Tests
// ============================================================================
/*
TEST_CASE("Simple Integer ArrayList")
{
    ArrayList<int, 64> list;

    SUBCASE("Freshly create list is empty")
    {
        CHECK(list.isEmpty() == true);
        CHECK(list.getLength() == 0);
    }
    
    SUBCASE("Verifying the insert and length of the ArrayList")
    {
        CHECK(list.insert(1,3));
        CHECK(list.getEntry(1) == 3);
    }
    SUBCASE("Verifying the insert, length and removal of items in arraylist")
    {
        CHECK(list.insert(1,6));
        CHECK(list.insert(2,7));
        CHECK(list.getLength()==2);
        CHECK(list.getEntry(1)==6);
        CHECK(list.getEntry(2)==7);
        CHECK(list.remove(2));
        CHECK(list.remove(1));
        CHECK(list.isEmpty());
    }
}
*/
TEST_CASE("Link List Implementation")
{
    LinkedList<int> List;

    SUBCASE("Verifying the inser of the Link List")
    {
        CHECK(List.insert(1,8));
        CHECK(List.insert(2,3));
        CHECK(List.getEntry(2)==3);
        CHECK(List.getLength()==2);
    }
}



// ============================================================================
// END OF TESTS
// ============================================================================
