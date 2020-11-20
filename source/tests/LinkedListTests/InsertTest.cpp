//
// Created by Brayon on 2020-11-20.
//

using namespace std;

TEST(InsertTest, InsertWithAnEmptyList) {
    LinkedList<int> list;
    ASSERT_EQ(0, list.size());
    ASSERT_EQ(nullptr, list.head());

    list.insert(2);

    ASSERT_EQ(1, list.size());
    ASSERT_NE(nullptr, list.head());
    ASSERT_EQ(2, list.head()->value());
}

TEST(InsertTest, InsertWithExistingElementsInList) {
    initializer_list<int> listData = {1, 2, 3, 4, 5};
    LinkedList<int> list(listData);

    ASSERT_EQ(listData.size(), list.size());
    ASSERT_NE(nullptr, list.head());

    list.insert(2);
    listData = {1, 2, 3, 4, 5, 2};

    ASSERT_EQ(listData.size(), list.size());
    ASSERT_NE(nullptr, list.head());

    auto currentNode = list.head();
    for (int num : listData) {
        ASSERT_EQ(num, currentNode->value());
        currentNode = currentNode->next();
    }
}

TEST(InsertTest, InsertAtSpecificSpotInList) {
    initializer_list<int> listData = {1, 2, 3, 4, 5};
    LinkedList<int> list(listData);

    ASSERT_EQ(listData.size(), list.size());
    ASSERT_NE(nullptr, list.head());

    list.insert(2, 2);
    listData = {1, 2, 2, 3, 4, 5};

    ASSERT_EQ(listData.size(), list.size());
    ASSERT_NE(nullptr, list.head());

    auto currentNode = list.head();
    for (int num : listData) {
        ASSERT_EQ(num, currentNode->value());
        currentNode = currentNode->next();
    }
}

TEST(InsertTest, CannotInsertAtIndexThatDoesntExist) {
    EXPECT_THROW({
         LinkedList<int> list({1, 2, 3, 4});
         list.insert(5, 4);
    }, range_error);

    EXPECT_THROW({
         LinkedList<int> list({1, 2, 3, 4});
         list.insert(5, -2);
    }, range_error);
}