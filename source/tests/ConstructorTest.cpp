//
// Created by Brayon on 2020-11-11.
//

TEST(ConstructorTest, TestDefaultConstructor) {
    EXPECT_NO_THROW(LinkedList<int> list);
    LinkedList<int> list;
    ASSERT_EQ(nullptr, list.head().get());
    ASSERT_EQ(0, list.size());
}

TEST(ConstructorTest, TestOneArgConstructor) {
    EXPECT_NO_THROW(LinkedList<int> list(1));
    LinkedList<int> list(1);
    ASSERT_EQ(1, list.size());
    ASSERT_EQ(0, list.head()->value());

    LinkedList<int> list2(2);
    ASSERT_EQ(2, list2.size());


    auto currentNode = list2.head();
    for (int i = 0; i < 2; ++i) {
        ASSERT_EQ(0, currentNode->value());
        currentNode = currentNode->next();
    }
}

TEST(ConstructorTest, TestTwoArgConstructor) {
    EXPECT_NO_THROW(LinkedList<int> list(1, 5));
    LinkedList<int> list(1, 5);
    ASSERT_EQ(1, list.size());

    ASSERT_EQ(5, list.head()->value());

    LinkedList<int> list2(5, 5);
    ASSERT_EQ(5, list2.size());

    auto currentNode = list2.head();
    for (int i = 0; i < 5; ++i) {
        ASSERT_EQ(5, currentNode->value());
        currentNode = currentNode->next();
    }
}

TEST(ConstructorTest, TestInitalizerListConstructor) {
    EXPECT_NO_THROW(LinkedList<int> list({1, 2, 3, 4, 5}));
    LinkedList<int> list({1, 2, 3, 4, 5});
    ASSERT_EQ(5, list.size());

    auto currentNode = list.head();
    for (int i = 1; i <= 5; ++i) {
        ASSERT_EQ(i, currentNode->value());
        currentNode = currentNode->next();
    }
}

