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

    LinkedList<int> list3(0, 1);
    ASSERT_EQ(0, list3.size());
    ASSERT_EQ(nullptr, list3.head().get());
}

TEST(ConstructorTest, TestInitalizerListConstructor) {
    initializer_list<int> listData = {1, 2, 3, 4, 5};
    EXPECT_NO_THROW(LinkedList<int> list({1, 2, 3, 4, 5}));
    LinkedList<int> list({1, 2, 3, 4, 5});
    ASSERT_EQ(5, list.size());

    auto currentNode = list.head();
    for (int i = 1; i <= 5; ++i) {
        ASSERT_EQ(i, currentNode->value());
        currentNode = currentNode->next();
    }
}

TEST(ConstructorTest, TestCopyConstructor) {
    initializer_list<int> listData = {1, 2, 3, 4, 5};
    EXPECT_NO_THROW(LinkedList<int> list(LinkedList<int>({1, 2, 3, 4, 5})));
    LinkedList<int> list(listData);
    LinkedList<int> copyList(list);
    list.~LinkedList();

    ASSERT_EQ(5, copyList.size());
    ASSERT_NE(nullptr, copyList.head());
    ASSERT_EQ(nullptr, copyList.head()->prev());
    ASSERT_NE(nullptr, copyList.head()->next());

    auto currentNode = copyList.head();
    for (int it : listData) {
        ASSERT_EQ(it, currentNode->value());
        currentNode = currentNode->next();
    }
}

TEST(ConstructorTest, TestCopyConstructorWithConst) {
    initializer_list<int> listData = {1, 2, 3, 4, 5};
    EXPECT_NO_THROW({
        LinkedList<int> const list({1, 2, 3, 4, 5});
        LinkedList<int> copyList(list);
    });
    LinkedList<int> const list(listData);
    LinkedList<int> copyList(list);
    list.~LinkedList();

    ASSERT_EQ(5, copyList.size());
    ASSERT_NE(nullptr, copyList.head());
    ASSERT_EQ(nullptr, copyList.head()->prev());
    ASSERT_NE(nullptr, copyList.head()->next());

    auto currentNode = copyList.head();
    for (int it : listData) {
        ASSERT_EQ(it, currentNode->value());
        currentNode = currentNode->next();
    }
}

TEST(ConstructorTest, TestCopyConstructorWithAssignmentOperator) {
    initializer_list<int> listData = {1, 2, 3, 4, 5};
    EXPECT_NO_THROW({
                        LinkedList<int> const list({1, 2, 3, 4, 5});
                        LinkedList<int> copyList = list;
                    });
    LinkedList<int> const list(listData);
    LinkedList<int> copyList = list;
    list.~LinkedList();

    ASSERT_EQ(5, copyList.size());
    ASSERT_NE(nullptr, copyList.head());
    ASSERT_EQ(nullptr, copyList.head()->prev());
    ASSERT_NE(nullptr, copyList.head()->next());

    auto currentNode = copyList.head();
    for (int it : listData) {
        ASSERT_EQ(it, currentNode->value());
        currentNode = currentNode->next();
    }
}

TEST(ConstructorTest, TestCopyConstructorWithNoListData) {
    EXPECT_NO_THROW({
                        LinkedList<int> const list;
                        LinkedList<int> copyList = list;
                    });
    LinkedList<int> const list;
    LinkedList<int> copyList = list;
    list.~LinkedList();

    ASSERT_EQ(0, copyList.size());
    ASSERT_EQ(nullptr, copyList.head());
}

TEST(ConstructorTest, TestMoveConstructor) {
    initializer_list<int> listData = {1, 2, 3, 4, 5};
    EXPECT_NO_THROW({
        LinkedList<int> moveList = LinkedList<int>({1, 2, 3, 4, 5});
    });
    LinkedList<int> list(listData);
    LinkedList<int> moveList = move(list);

    ASSERT_EQ(0, list.size());
    ASSERT_EQ(nullptr, list.head());

    ASSERT_EQ(5, moveList.size());
    ASSERT_NE(nullptr, moveList.head());

    auto currentNode = moveList.head();
    for (int num : listData) {
        ASSERT_EQ(num, currentNode->value());
        currentNode = currentNode->next();
    }
}
