//
// Created by Brayon on 2020-11-17.
//

using namespace std;

TEST(FloatTest, TestDefaultConstructor) {
    EXPECT_NO_THROW(LinkedList<float>());
    LinkedList<float> list;
    ASSERT_EQ(0, list.size());
    ASSERT_EQ(nullptr, list.head());
}

TEST(FloatTest, TestOneArgConstructor) {
    EXPECT_NO_THROW(LinkedList<float>(1));
    LinkedList<float> list(1);
    ASSERT_EQ(1, list.size());
    ASSERT_NE(nullptr, list.head().get());
    ASSERT_FLOAT_EQ(0.0, list.head()->value());
    ASSERT_EQ(nullptr, list.head()->prev());
    ASSERT_EQ(nullptr, list.head()->next());

    LinkedList<float> list2(4);
    ASSERT_EQ(4, list2.size());
    ASSERT_NE(nullptr, list2.head().get());
    ASSERT_EQ(nullptr, list2.head()->prev());

    auto currentNode = list2.head();
    for (int i = 0; i < list2.size(); ++i) {
        ASSERT_FLOAT_EQ(0.0, currentNode->value());
        currentNode = currentNode->next();
    }

    LinkedList<float> list3(0);
    ASSERT_EQ(0, list3.size());
    ASSERT_EQ(nullptr, list3.head().get());
}

TEST(FloatTest, TestTwoArgConstructor) {
    float testingValue = 0.5000001;
    EXPECT_NO_THROW(LinkedList<float>(1, testingValue));
    LinkedList<float> list(1, testingValue);
    ASSERT_EQ(1, list.size());
    ASSERT_NE(nullptr, list.head().get());
    ASSERT_FLOAT_EQ(testingValue, list.head()->value());
    ASSERT_EQ(nullptr, list.head()->prev());
    ASSERT_EQ(nullptr, list.head()->next());

    LinkedList<float> list2(0, testingValue);
    ASSERT_EQ(0, list2.size());
    ASSERT_EQ(nullptr, list2.head().get());

    LinkedList<float> list3(5, testingValue);
    ASSERT_EQ(5, list3.size());

    auto currentNode = list3.head();
    for (int i = 0; i < 5; ++i) {
        ASSERT_FLOAT_EQ(testingValue, currentNode->value());
        currentNode = currentNode->next();
    }
}

TEST(FloatTest, TestInitalizerListConstructor) {
    initializer_list<float> populateList = {0.5000001, 1.5000001, 2.5000001};
    EXPECT_NO_THROW(LinkedList<float> list(populateList));
    LinkedList<float> list(populateList);
    ASSERT_EQ(3, list.size());

    auto currentNode = list.head();
    auto it = populateList.begin();
    for (int i = 1; i <= 3; ++i, ++it) {
        ASSERT_FLOAT_EQ(*it, currentNode->value());
        currentNode = currentNode->next();
    }
}