//
// Created by Brayon on 2020-11-17.
//


using namespace std;

TEST(LongDoubleTest, TestDefaultConstructor) {
    EXPECT_NO_THROW(LinkedList<long double>());
    LinkedList<long double> list;
    ASSERT_EQ(0, list.size());
    ASSERT_EQ(nullptr, list.head());
}

TEST(LongDoubleTest, TestOneArgConstructor) {
    EXPECT_NO_THROW(LinkedList<long double>(1));
    LinkedList<long double> list(1);
    ASSERT_EQ(1, list.size());
    ASSERT_NE(nullptr, list.head().get());
    ASSERT_DOUBLE_EQ(0.0, list.head()->value());
    ASSERT_EQ(nullptr, list.head()->prev());
    ASSERT_EQ(nullptr, list.head()->next());

    LinkedList<long double> list2(4);
    ASSERT_EQ(4, list2.size());
    ASSERT_NE(nullptr, list2.head().get());
    ASSERT_EQ(nullptr, list2.head()->prev());

    auto currentNode = list2.head();
    for (int i = 0; i < list2.size(); ++i) {
        ASSERT_DOUBLE_EQ(0.0, currentNode->value());
        currentNode = currentNode->next();
    }

    LinkedList<long double> list3(0);
    ASSERT_EQ(0, list3.size());
    ASSERT_EQ(nullptr, list3.head().get());
}

TEST(LongDoubleTest, TestTwoArgConstructor) {
    EXPECT_NO_THROW(LinkedList<long double>(1, 0.5000000000000001));
    LinkedList<long double> list(1, 0.5000000000000001);
    ASSERT_EQ(1, list.size());
    ASSERT_NE(nullptr, list.head().get());
    ASSERT_DOUBLE_EQ(0.5000000000000001, list.head()->value());
    ASSERT_EQ(nullptr, list.head()->prev());
    ASSERT_EQ(nullptr, list.head()->next());

    LinkedList<long double> list2(0, 0.5000000000000001);
    ASSERT_EQ(0, list2.size());
    ASSERT_EQ(nullptr, list2.head().get());

    LinkedList<long double> list3(5, 0.5000000000000001);
    ASSERT_EQ(5, list3.size());

    auto currentNode = list3.head();
    for (int i = 0; i < 5; ++i) {
        ASSERT_DOUBLE_EQ(0.5000000000000001, currentNode->value());
        currentNode = currentNode->next();
    }
}

TEST(LongDoubleTest, TestInitalizerListConstructor) {
    initializer_list<long double> populateList = {0.5000000000000001, 1.5000000000000001, 2.5000000000000001};
    EXPECT_NO_THROW(LinkedList<long double> list(populateList));
    LinkedList<long double> list(populateList);
    ASSERT_EQ(3, list.size());

    auto currentNode = list.head();
    auto it = populateList.begin();
    for (int i = 1; i <= 3; ++i, ++it) {
        ASSERT_DOUBLE_EQ(*it, currentNode->value());
        currentNode = currentNode->next();
    }
}