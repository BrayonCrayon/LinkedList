//
// Created by Brayon on 2020-11-24.
//

using namespace std;

TEST(IteratorTest, BasicIteratorBeginTest) {
    EXPECT_NO_THROW({
        LinkedList<int> list({1, 2, 3, 4, 5});
        LinkedList<int>::Iterator it = list.begin();
    });

    initializer_list<int> listData = {1, 2, 3, 4, 5};
    LinkedList<int> list(listData);
    LinkedList<int>::Iterator listIter = list.begin();

    for (initializer_list<int>::iterator it = listData.begin(); it != listData.end(); ++it, ++listIter) {
        ASSERT_EQ(*it, listIter->value());
    }
}

TEST(IteratorTest, IteratorBeginWithEmptyListTest) {
    EXPECT_NO_THROW({
       LinkedList<int> list;
       LinkedList<int>::Iterator it = list.begin();
    });

    LinkedList<int> list;
    LinkedList<int>::Iterator it = list.begin();
    ASSERT_TRUE(*it == nullptr);
}

TEST(IteratorTest, ThrowsErrorIfItatoringPassedListLength) {
    EXPECT_THROW({
        LinkedList<int> list({1, 2, 3, 4});
        LinkedList<int>::Iterator listIter = list.begin();

        for (int i = 0; i < 5; ++i) {
            listIter++;
        }
    }, range_error);
}

TEST(IteratorTest, IteratorAbleToReachEndAndReverseToBegining) {
    initializer_list<int> listData = {1, 2, 3, 4, 5};
    LinkedList<int> list(listData);
    LinkedList<int>::Iterator listIter = list.begin();
    initializer_list<int>::iterator it = listData.begin();

    for (; it != listData.end(); ++it, ++listIter) {
        ASSERT_EQ(*it, listIter->value());
    }

    ASSERT_EQ(nullptr, listIter->value_ptr());
    ASSERT_EQ(0, *it);

    --it;
    --listIter;
    for (; it != listData.begin(); --it, --listIter) {
        ASSERT_EQ(*it, listIter->value());
    }
}