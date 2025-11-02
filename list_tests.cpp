#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "list_adt.h"
#include "array_list.h"
#include "linked_list.h"

// ============================================================================
// PART 1: List ADT Unit Tests
// ============================================================================

void testListADT(ListADT<int>& list) 
{
    LinkedList <int itemtype testList>;
    if (LinkedList != 0)
    {
        std::cout << "List is not empty " << std::endl;
    }
    else
    {
        std::cout << "List is empty"  << std::endl;
    }
    // TODO: finish
}

TEST_CASE("ArrayList Implementation") {
    ArrayList<int, 64> list;
    testListADT(list);
}

TEST_CASE("LinkedList Implementation") {
    LinkedList<int> list;
    testListADT(list);
}

// ============================================================================
// END OF TESTS
// ============================================================================
