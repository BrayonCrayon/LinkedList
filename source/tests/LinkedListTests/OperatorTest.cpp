//
// Created by Brayon on 2020-11-20.
//

using namespace std;

TEST(OperatorTest, SubscriptOperatorRetrievesNode) {
    initializer_list<int> listData = {1, 2, 3, 4, 5};
    LinkedList<int> list(listData);

    auto requestedNode = list[2];

    ASSERT_NE(nullptr, requestedNode);
    ASSERT_EQ(3, requestedNode->value());
}

TEST(OperatorTest, SubscriptOperatorCannotRevieveNodeThatDoesntExist) {
    EXPECT_THROW({
        LinkedList<int> list({1, 2, 3, 4, 5});
        auto requestedNode = list[5];
    }, range_error);

    EXPECT_THROW({
        LinkedList<int> list({1, 2, 3, 4, 5});
        auto requestedNode = list[-2];
    }, range_error);
}