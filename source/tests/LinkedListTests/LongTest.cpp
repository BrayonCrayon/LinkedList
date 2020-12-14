//
// Created by Brayon on 2020-11-17.
//

using namespace std;

TEST(LongTest, TestDefaultConstructor) {
    EXPECT_NO_THROW(LinkedList<long>());
    LinkedList<long> list;
    ASSERT_EQ(0, list.size());
    ASSERT_EQ(nullptr, list.head());
}

TEST(LongTest, TestOneArgConstructor) {
    EXPECT_NO_THROW(LinkedList<long>(1));
    LinkedList<long> list(1);
    ASSERT_EQ(1, list.size());
    ASSERT_NE(nullptr, list.head().get());
    ASSERT_EQ(0, list.head()->value());
    ASSERT_EQ(nullptr, list.head()->prev());
    ASSERT_EQ(nullptr, list.head()->next()->value_ptr());

    LinkedList<long> list2(4);
    ASSERT_EQ(4, list2.size());
    ASSERT_NE(nullptr, list2.head().get());
    ASSERT_EQ(nullptr, list2.head()->prev());

    auto currentNode = list2.head();
    for (int i = 0; i < list2.size(); ++i) {
        ASSERT_EQ(0, currentNode->value());
        currentNode = currentNode->next();
    }

    LinkedList<long> list3(0);
    ASSERT_EQ(0, list3.size());
    ASSERT_EQ(nullptr, list3.head().get());
}

TEST(LongTest, TestTwoArgConstructor) {
    EXPECT_NO_THROW(LinkedList<long>(1, 1000000000));
    LinkedList<long> list(1, 1000000000);
    ASSERT_EQ(1, list.size());
    ASSERT_NE(nullptr, list.head().get());
    ASSERT_EQ(1000000000, list.head()->value());
    ASSERT_EQ(nullptr, list.head()->prev());
    ASSERT_EQ(nullptr, list.head()->next()->value_ptr());

    LinkedList<long> list2(0, 1000000000);
    ASSERT_EQ(0, list2.size());
    ASSERT_EQ(nullptr, list2.head().get());

    LinkedList<long> list3(5, 1000000000);
    ASSERT_EQ(5, list3.size());

    auto currentNode = list3.head();
    for (int i = 0; i < 5; ++i) {
        ASSERT_EQ(1000000000, currentNode->value());
        currentNode = currentNode->next();
    }
}

TEST(LongTest, TestInitalizerListConstructor) {
    initializer_list<long> populateList = {1000000000, 1000000000, 1000000000};
    EXPECT_NO_THROW(LinkedList<long> list(populateList));
    LinkedList<long> list(populateList);
    ASSERT_EQ(3, list.size());

    auto currentNode = list.head();
    auto it = populateList.begin();
    for (int i = 1; i <= 3; ++i, ++it) {
        ASSERT_EQ(*it, currentNode->value());
        currentNode = currentNode->next();
    }
}