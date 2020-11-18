//
// Created by Brayon on 2020-11-14.
//

#include <string>

using namespace std;

TEST(StringTest, TestDefaultConstructor) {
    EXPECT_NO_THROW(LinkedList<string>());
    LinkedList<string> list;
    ASSERT_EQ(0, list.size());
    ASSERT_EQ(nullptr, list.head());
}

TEST(StringTest, TestOneArgConstructor) {
    EXPECT_NO_THROW(LinkedList<string>(1));
    LinkedList<string> list(1);
    ASSERT_EQ(1, list.size());
    ASSERT_NE(nullptr, list.head().get());
    EXPECT_EQ("", list.head()->value());
    ASSERT_EQ(nullptr, list.head()->prev());
    ASSERT_EQ(nullptr, list.head()->next());

    LinkedList<string> list2(4);
    ASSERT_EQ(4, list2.size());
    ASSERT_NE(nullptr, list2.head().get());
    ASSERT_EQ(nullptr, list2.head()->prev());

    auto currentNode = list2.head();
    for (int i = 0; i < list2.size(); ++i) {
        EXPECT_EQ("", currentNode->value());
        currentNode = currentNode->next();
    }

    LinkedList<string> list3(0);
    ASSERT_EQ(0, list3.size());
    ASSERT_EQ(nullptr, list3.head().get());
}

TEST(StringTest, TestTwoArgConstructor) {
    EXPECT_NO_THROW(LinkedList<string>(1, "marty"));
    LinkedList<string> list(1, "marty");
    ASSERT_EQ(1, list.size());
    ASSERT_NE(nullptr, list.head().get());
    EXPECT_EQ( "marty",list.head()->value());
    ASSERT_EQ(nullptr, list.head()->prev());
    ASSERT_EQ(nullptr, list.head()->next());

    LinkedList<string> list2(0, "rick");
    ASSERT_EQ(0, list2.size());
    ASSERT_EQ(nullptr, list2.head().get());

    LinkedList<string> list3(5, "morty");
    ASSERT_EQ(5, list3.size());

    auto currentNode = list3.head();
    for (int i = 0; i < 5; ++i) {
        ASSERT_EQ("morty", currentNode->value());
        currentNode = currentNode->next();
    }
}

TEST(StringTest, TestInitalizerListConstructor) {
    initializer_list<string> populateList = {"rick", "morty", "glen"};
    EXPECT_NO_THROW(LinkedList<string> list(populateList));
    LinkedList<string> list(populateList);
    ASSERT_EQ(3, list.size());

    auto currentNode = list.head();
    auto it = populateList.begin();
    for (int i = 1; i <= 3; ++i, ++it) {
        EXPECT_EQ(*it, currentNode->value());
        currentNode = currentNode->next();
    }
}