#include "LinkedList.hpp"
#include <gtest/gtest.h>

TEST(LinkedList, OneNode)
{
    ListNode node{ nullptr, nullptr, nullptr, "Hi!" };
    List list(&node);
    if (std::FILE* fw = std::fopen("test.bin", "wb"))
    {
        list.Serialize(fw);
        std::fclose(fw);
    }

    List deserialized_list;
    if (std::FILE* fr = std::fopen("test.bin", "rb"))
    {
        deserialized_list.Deserialize(fr);
        std::fclose(fr);
    }

    int expected_count = 1;
    int actual_count = deserialized_list.GetCount();
    EXPECT_EQ(actual_count, expected_count);

    ListNode* head = deserialized_list.GetHead();
    EXPECT_TRUE(head->next == nullptr);
    EXPECT_TRUE(head->prev == nullptr);

    std::string expected_data("Hi!");
    std::string& actual_data = head->data;
    EXPECT_EQ(actual_data, expected_data);
}

TEST(LinkedList, FiveNodes)
{
    ListNode l1{ nullptr, nullptr, nullptr, "1" };
    ListNode l2{ &l1, nullptr, nullptr, "2" };
    ListNode l3{ &l2, nullptr, nullptr, "3" };
    ListNode l4{ &l3, nullptr, nullptr, "4" };
    ListNode l5{ &l4, nullptr, nullptr, "5" };

    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;

    // Каждая нода в rand ссылается на ноду через одну
    l1.rand = &l3;
    l2.rand = &l4;
    l3.rand = &l5;

    List list(&l1);

    if (std::FILE* fw = std::fopen("test.bin", "wb"))
    {
        list.Serialize(fw);
        std::fclose(fw);
    }

    List deserialized_list;
    if (std::FILE* fr = std::fopen("test.bin", "rb"))
    {
        deserialized_list.Deserialize(fr);
        std::fclose(fr);
    }

    int expected_count = 5;
    int actual_count = deserialized_list.GetCount();
    EXPECT_EQ(actual_count, expected_count);

    ListNode* head = deserialized_list.GetHead();
    EXPECT_TRUE(head->prev == nullptr);
    EXPECT_TRUE(head->rand == head->next->next);

    std::string expected_data("1");
    std::string& actual_data = head->data;
    EXPECT_EQ(actual_data, expected_data);

    ListNode* current_node = head->next;
    int i = 2;
    while (current_node != nullptr and current_node->next != nullptr)
    {
        ListNode* next_node = current_node->next;
        EXPECT_TRUE(next_node->prev == current_node);
        EXPECT_TRUE(current_node->rand == next_node->next);

        expected_data = std::to_string(i);
        actual_data = current_node->data;
        EXPECT_EQ(actual_data, expected_data);

        current_node = next_node;
        i++;
    }

    EXPECT_TRUE(current_node->next == nullptr);
    EXPECT_TRUE(current_node->rand == nullptr);
    expected_data = std::to_string(i);
    actual_data = current_node->data;
    EXPECT_EQ(actual_data, expected_data);
}

TEST(LinkedList, FiveNodesRandItself)
{
    ListNode l1{ nullptr, nullptr, nullptr, "1" };
    ListNode l2{ &l1, nullptr, nullptr, "2" };
    ListNode l3{ &l2, nullptr, nullptr, "3" };
    ListNode l4{ &l3, nullptr, nullptr, "4" };
    ListNode l5{ &l4, nullptr, nullptr, "5" };

    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;

    // Каждая нода в rand ссылается сама на себя
    l1.rand = &l1;
    l2.rand = &l2;
    l3.rand = &l3;
    l4.rand = &l4;
    l5.rand = &l5;

    List list(&l1);

    if (std::FILE* fw = std::fopen("test.bin", "wb"))
    {
        list.Serialize(fw);
        std::fclose(fw);
    }

    List deserialized_list;
    if (std::FILE* fr = std::fopen("test.bin", "rb"))
    {
        deserialized_list.Deserialize(fr);
        std::fclose(fr);
    }

    int expected_count = 5;
    int actual_count = deserialized_list.GetCount();
    EXPECT_EQ(actual_count, expected_count);

    ListNode* head = deserialized_list.GetHead();
    EXPECT_TRUE(head->prev == nullptr);
    EXPECT_TRUE(head->rand == head);

    std::string expected_data("1");
    std::string& actual_data = head->data;
    EXPECT_EQ(actual_data, expected_data);

    ListNode* current_node = head->next;
    int i = 2;
    while (current_node != nullptr and current_node->next != nullptr)
    {
        ListNode* next_node = current_node->next;
        EXPECT_TRUE(next_node->prev == current_node);
        EXPECT_TRUE(current_node->rand == current_node);

        expected_data = std::to_string(i);
        actual_data = current_node->data;
        EXPECT_EQ(actual_data, expected_data);

        current_node = next_node;
        i++;
    }

    EXPECT_TRUE(current_node->next == nullptr);
    expected_data = std::to_string(i);
    actual_data = current_node->data;
    EXPECT_EQ(actual_data, expected_data);
}