//
// Created by Brayon on 2020-11-17.
//


using namespace std;

TEST(CharTest, TestDefaultConstructor) {
    EXPECT_NO_THROW(LinkedList<char>());
    LinkedList<char> list;
    ASSERT_EQ(0, list.size());
    ASSERT_EQ(nullptr, list.head());
}

TEST(CharTest, TestOneArgConstructor) {
    EXPECT_NO_THROW(LinkedList<char>(1));
    LinkedList<char> list(1);
    ASSERT_EQ(1, list.size());
    ASSERT_NE(nullptr, list.head().get());
    ASSERT_EQ(char{}, list.head()->value());
    ASSERT_EQ(nullptr, list.head()->prev());
    ASSERT_EQ(nullptr, list.head()->next()->value_ptr());

    LinkedList<char> list2(4);
    ASSERT_EQ(4, list2.size());
    ASSERT_NE(nullptr, list2.head().get());
    ASSERT_EQ(nullptr, list2.head()->prev());

    auto currentNode = list2.head();
    for (int i = 0; i < list2.size(); ++i) {
        ASSERT_EQ(char{}, currentNode->value());
        currentNode = currentNode->next();
    }

    LinkedList<char> list3(0);
    ASSERT_EQ(0, list3.size());
    ASSERT_EQ(nullptr, list3.head().get());
}

TEST(CharTest, TestTwoArgConstructor) {
    EXPECT_NO_THROW(LinkedList<char>(1, 'a'));
    LinkedList<char> list(1, 'a');
    ASSERT_EQ(1, list.size());
    ASSERT_NE(nullptr, list.head().get());
    ASSERT_EQ('a', list.head()->value());
    ASSERT_EQ(nullptr, list.head()->prev());
    ASSERT_EQ(nullptr, list.head()->next()->value_ptr());

    LinkedList<char> list2(0, 'a');
    ASSERT_EQ(0, list2.size());
    ASSERT_EQ(nullptr, list2.head().get());

    LinkedList<char> list3(5, 'a');
    ASSERT_EQ(5, list3.size());

    auto currentNode = list3.head();
    for (int i = 0; i < 5; ++i) {
        ASSERT_EQ('a', currentNode->value());
        currentNode = currentNode->next();
    }
}

TEST(CharTest, TestInitalizerListConstructor) {
    initializer_list<char> populateList = {'a', 'b', 'c'};
    EXPECT_NO_THROW(LinkedList<char> list(populateList));
    LinkedList<char> list(populateList);
    ASSERT_EQ(3, list.size());

    auto currentNode = list.head();
    auto it = populateList.begin();
    for (int i = 1; i <= 3; ++i, ++it) {
        ASSERT_EQ(*it, currentNode->value());
        currentNode = currentNode->next();
    }
}