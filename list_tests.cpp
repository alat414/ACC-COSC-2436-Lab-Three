#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "list_adt.h"
#include "array_list.h"
#include "linked_list.h"

// ============================================================================
// PART 1: List ADT Unit Tests
// ============================================================================

void testListADT(ListADT<int>& list) {
    
}

TEST_SUITE("List Tests")
{
    TEST_CASE("ArrayList Implementation") 
    {
        ArrayList<int, 64> list;

        std::cout << "DEBUG: isEmpty function returns " << list.isEmpty() << std::endl;
        std::cout << "DEBUG: getLength function returns " << list.getLength() << std::endl;


        SUBCASE("Empty list")
        {
            CHECK(list.isEmpty() == true);
            CHECK(list.getLength() == 0);
        }

        SUBCASE("Access empty list throws")
        {
            CHECK_THROWS_AS(list.getEntry(0), std::out_of_range);
            CHECK_THROWS_AS(list.remove(0), std::out_of_range);
        }
        /*SUBCASE("Add item at the beginning")
        {
            list.insert(0,10);
            CHECK(list.getEntry(0) == 10);
        }
        
    

    TEST_CASE("LinkedList Implementation") 
    {
        LinkedList<int> list;
    }*/
    }
    
}


// ============================================================================
// END OF TESTS
// ============================================================================
