#include <iostream>
#include "complex_n.h"
#include <gtest/gtest.h>


int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}


TEST(ComplexTest, ConstructorTest) {
    Complex_n a;
    Complex_n b(1);
    Complex_n c(1, 2);

    ASSERT_EQ(a.get_re(), 0);
    ASSERT_EQ(a.get_im(), 0);

    ASSERT_EQ(b.get_re(), 1);
    ASSERT_EQ(b.get_im(), 0);

    ASSERT_EQ(c.get_re(), 1);
    ASSERT_EQ(c.get_im(), 2);
}

TEST(ComplexTest, EqualityTest) {
    Complex_n a(1, 2);
    Complex_n b(1, 2);
    Complex_n c(2, 3);
    Complex_n d(3, 0);
    double x = 3;

    ASSERT_TRUE(a == b);
    ASSERT_TRUE(b == a);
    ASSERT_FALSE(a != b);
    ASSERT_TRUE(b != c);
    ASSERT_FALSE(a == x);
    ASSERT_TRUE(a != x);
    ASSERT_TRUE(d == x);
    ASSERT_TRUE(x == d);
}

TEST(ComplexTest, UnaryOpersTest) {
    Complex_n a(1, 2);

    Complex_n b = +a;
    Complex_n c = -a;

    ASSERT_TRUE(a == b);

    ASSERT_EQ(a.get_re(), -c.get_re());
    ASSERT_EQ(a.get_im(), -c.get_im());
}

TEST(ComplexTest, MethodsTest) {
    Complex_n a(1, 2);
    Complex_n b = a.conjugate();
    double c = a.cabs();

    ASSERT_EQ(c, sqrt(5));

    ASSERT_EQ(b.get_re(), a.get_re());
    ASSERT_EQ(b.get_im(), -a.get_im());
}


TEST(ComplexTest, ArifmTest1) {
    Complex_n a(1, 2);
    Complex_n b(2, 3);
    double c = 2.0;

    Complex_n sum1 = a + b;
    Complex_n sum2 = b + a;
    ASSERT_TRUE(sum1 == sum2);
    ASSERT_EQ(sum1.get_re(), 3);
    ASSERT_EQ(sum2.get_im(), 5);

    Complex_n mult1 = a * b;
    Complex_n mult2 = b * a;
    ASSERT_TRUE(mult1 == mult2);
    ASSERT_EQ(mult1.get_re(), -4);
    ASSERT_EQ(mult1.get_im(), 7);

    Complex_n div = a / b;
    ASSERT_EQ(div.get_re(), 8.0/13);
    ASSERT_EQ(div.get_im(), 1.0/13);

    Complex_n sub = a - b;
    ASSERT_EQ(sub.get_re(), -1);
    ASSERT_EQ(sub.get_im(), -1);

    ASSERT_EQ((a / c).get_re(), a.get_re() / c);
    ASSERT_EQ((a / c).get_im(), a.get_im() / c);

    ASSERT_EQ((a * c).get_re(), a.get_re() * c);
    ASSERT_EQ((a * c).get_im(), a.get_im() * c);

    ASSERT_EQ((a + c).get_re(), a.get_re() + c);
    ASSERT_EQ((a + c).get_im(), a.get_im());

    ASSERT_EQ((a - c).get_re(), a.get_re() - c);
    ASSERT_EQ((a - c).get_im(), a.get_im());
}

TEST(ComplexTest, ArifmTest2) {
    Complex_n a(1, 2);
    Complex_n b(2, 3);
    double c = 2.0;

    Complex_n sum_d = a;
    Complex_n mult_d = a;
    Complex_n div_d = a;
    Complex_n sub_d = a;

    Complex_n sum1 = a;
    Complex_n sum2 = b;

    Complex_n mult1 = a;
    Complex_n mult2 = b;

    Complex_n div = a;

    Complex_n sub = a;

    sum1 += b;
    sum2 += a;
    ASSERT_TRUE(sum1 == sum2);
    ASSERT_EQ(sum1.get_re(), 3);
    ASSERT_EQ(sum2.get_im(), 5);

    mult1 *= b;
    mult2 *= a;
    ASSERT_TRUE(mult1 == mult2);
    ASSERT_EQ(mult1.get_re(), -4);
    ASSERT_EQ(mult1.get_im(), 7);

    div /= b;
    ASSERT_EQ(div.get_re(), 8.0/13);
    ASSERT_EQ(div.get_im(), 1.0/13);

    sub -= b;
    ASSERT_EQ(sub.get_re(), -1);
    ASSERT_EQ(sub.get_im(), -1);

    div_d /= c;
    ASSERT_EQ((div_d).get_re(), a.get_re() / c);
    ASSERT_EQ((div_d).get_im(), a.get_im() / c);

    mult_d *= c;
    ASSERT_EQ((mult_d).get_re(), a.get_re() * c);
    ASSERT_EQ((mult_d).get_im(), a.get_im() * c);

    sum_d += c;
    ASSERT_EQ((sum_d).get_re(), a.get_re() + c);
    ASSERT_EQ((sum_d).get_im(), a.get_im());

    sub_d -= c;
    ASSERT_EQ((sub_d).get_re(), a.get_re() - c);
    ASSERT_EQ((sub_d).get_im(), a.get_im());
}

TEST(ComplexTest, IOTest) {
    Complex_n a;
    std::cin >> a;
    std::cout << a << '\n';
}

