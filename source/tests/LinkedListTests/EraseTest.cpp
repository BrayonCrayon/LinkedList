//
// Created by Brayon on 2020-11-20.
//

using namespace std;

TEST(EraseTest, ThrowsExceptionIfListIsEmpty) {
    EXPECT_THROW({
        LinkedList<int> list;
        list.erase(2);
    }, range_error);

    EXPECT_THROW({
        LinkedList<int> list;
        list.erase(-2);
    }, range_error);
}

TEST(EraseTest, ErasesAtIndex) {
    initializer_list<int> listData = {1, 2, 3, 4, 5};
    LinkedList<int> list(listData);

    ASSERT_EQ(listData.size(), list.size());
    ASSERT_NE(nullptr, list.head());

    list.erase(2);
    listData = {1, 2, 4, 5};

    ASSERT_EQ(listData.size(), list.size());

    auto currentNode = list.head();
    for (int num : listData) {
        ASSERT_EQ(num, currentNode->value());
        currentNode = currentNode->next();
    }
}

TEST(EraseTest, CannotEraseAtUndefinedIndex) {
    EXPECT_THROW({
         LinkedList<int> list({1, 2, 3, 4, 5});
         list.erase(5);
     }, range_error);

    EXPECT_THROW({
         LinkedList<int> list({1, 2, 3, 4, 5});
         list.erase(-2);
     }, range_error);
}
