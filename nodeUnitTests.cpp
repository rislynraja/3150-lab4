#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
/*
  https://hackingcpp.com/cpp/tools/testing_frameworks.html
 */

#include "Node.h"
#include "LinkedList.h"
#include "./include/doctest.h"
#include <sstream>

TEST_CASE("testing build_linked_list") {
    LinkedList test;
    test.build_linked_list(5);

    CHECK(test.get_linked_list_data_item_value(0) == 1);
    CHECK(test.get_linked_list_data_item_value(1) == 2);
    CHECK(test.get_linked_list_data_item_value(2) == 3);
    CHECK(test.get_linked_list_data_item_value(3) == 4);
    CHECK(test.get_linked_list_data_item_value(4) == 5);
}

TEST_CASE("testing print_linked_list") {
    LinkedList test2;
    test2.build_linked_list(5);

    std::ostringstream output;
    std::streambuf* temp = std::cout.rdbuf(output.rdbuf()); // storing output to check without printing
    test2.print_linked_list();
    std::cout.rdbuf(temp); // rdbuf = stream buffer

    CHECK(output.str() == "1 -> 2 -> 3 -> 4 -> 5 -> NULL\n");
}

TEST_CASE("testing delete_entire_linked_list") {
    LinkedList test3;
    test3.build_linked_list(5);
    test3.delete_entire_linked_list();

    CHECK(test3.get_linked_list_data_item_value(0) == -1); 
    CHECK(test3.get_linked_list_data_item_value(1) == -1);
    CHECK(test3.get_linked_list_data_item_value(2) == -1);
    CHECK(test3.get_linked_list_data_item_value(3) == -1);
    CHECK(test3.get_linked_list_data_item_value(4) == -1);
    // because it's empty should return -1
}

TEST_CASE("testing get_linked_list_data_item_value") {
    LinkedList test4;
    test4.insertAtEnd(343);
    test4.insertAtEnd(58);
    test4.insertAtEnd(1);
    test4.insertAtEnd(2020);

    CHECK(test4.get_linked_list_data_item_value(0) == 343);
    CHECK(test4.get_linked_list_data_item_value(1) == 58);
    CHECK(test4.get_linked_list_data_item_value(2) == 1);
    CHECK(test4.get_linked_list_data_item_value(3) == 2020);
    CHECK(test4.get_linked_list_data_item_value(4) == -1); // not there
}

TEST_CASE("testing delete_list_element") {
    LinkedList test5;
    test5.insertAtEnd(101);
    test5.insertAtEnd(202);
    test5.insertAtEnd(303);

    CHECK(test5.delete_list_element(1) == true); // should remove successfully
    CHECK(test5.get_linked_list_data_item_value(1) == 303); // moved up
    CHECK(test5.delete_list_element(10) == false); // unable to delete because it doesn't exist
}

TEST_CASE("testing pointerJumping") {
    LinkedList test5;
    test5.build_linked_list(5);
    test5.pointerJumping();

    Node* last = test5.getLastElement();
    CHECK(last->data == 5);

    last = test5.root;
    while(last && last->next) {
        CHECK(last->next->data == 5); // the one they all point to should have a data value of 5 (since that's the last one)
        last = last->next;
    }
}

TEST_CASE("testing hasNegativePrefixSum") {
    LinkedList test6;
    test6.insertAtEnd(5);
    test6.insertAtEnd(-3);
    test6.insertAtEnd(-10);
    test6.insertAtEnd(2);

    CHECK(test6.hasNegativePrefixSum() == true);

    LinkedList test7;
    test7.insertAtEnd(5);
    test7.insertAtEnd(3);
    test7.insertAtEnd(1);

    CHECK(test7.hasNegativePrefixSum() == false);
}

TEST_CASE("testing hasPositivePrefixSum") {
    LinkedList test8;
    test8.insertAtEnd(-5);
    test8.insertAtEnd(-3);
    test8.insertAtEnd(10);

    CHECK(test8.hasPositivePrefixSum() == true);

    LinkedList test9;
    test9.insertAtEnd(-5);
    test9.insertAtEnd(-3);
    test9.insertAtEnd(-1);

    CHECK(test9.hasPositivePrefixSum() == false);
}

TEST_CASE("testing deleteNode") {
    LinkedList test10;
    test10.insertAtEnd(5);
    test10.deleteNode(5);

    CHECK(test10.get_linked_list_data_item_value(5) == -1);
}

TEST_CASE("testing getLastElement") {
    LinkedList test11;
    test11.insertAtEnd(3);
    test11.insertAtEnd(5);
    test11.insertAtEnd(11);

    CHECK(test11.getLastElement()->data == 11);
}

TEST_CASE("testing insertAtEnd") {
    LinkedList test12;
    test12.insertAtEnd(2);
    test12.insertAtEnd(4);
    test12.insertAtBeginning(5);

    CHECK(test12.getLastElement()->data == 4);
}

TEST_CASE("testing insertAtBeginning") {
    LinkedList test13;
    test13.insertAtBeginning(5);
    test13.insertAtBeginning(153);
    test13.insertAtBeginning(93);

    CHECK(test13.root->data == 93);

    test13.insertAtBeginning(2933);

    CHECK(test13.root->data == 2933);
}

TEST_CASE("testing move constructor") {
    LinkedList test14;
    test14.insertAtEnd(5);
    test14.insertAtEnd(4);
    test14.insertAtEnd(3);

    LinkedList move14(std::move(test14));

    CHECK(move14.get_linked_list_data_item_value(0) == 5);
    CHECK(move14.get_linked_list_data_item_value(1) == 4);
    CHECK(move14.get_linked_list_data_item_value(2) == 3);

    CHECK(test14.getLastElement() == nullptr); // orignal null
}

TEST_CASE("testing move copy constructor") {
    LinkedList test15;
    test15.insertAtEnd(4);
    test15.insertAtEnd(5);
    test15.insertAtEnd(6);

    LinkedList test16;
    test16.insertAtEnd(7);

    test16 = std::move(test15);

    CHECK(test16.get_linked_list_data_item_value(0) == 4);
    CHECK(test16.get_linked_list_data_item_value(1) == 5);
    CHECK(test16.get_linked_list_data_item_value(2) == 6);

    CHECK(test15.getLastElement() == nullptr); 

}