#include <iostream>
#include "BigInt.h"


using std::cout;
using std::endl;

void print_cmp_result(BigInt b, BigInt b1) {
    short i = b.cmp(b1);
    if(i == 1) std::cout << "The first BigInt " << b << " is greater than the second one " << b1 << " ." << std::endl;
    else if(i == 3) std::cout << "The second BigInt " << b1 << "is greater than the first one" << b << "." << std::endl;
    else std::cout << "These BigInt are equal." << b << " = " << b1 << std::endl;
}

void test_BigInt() {
    long int num = -4274;
    bool is_negative = (num < 0);
    unsigned long length_l = get_length_input(num);
    BigInt b1(is_negative, length_l, num);

    long int num1 = 6;
    bool is_negative_b = (num1 < 0);
    unsigned long length_b = get_length_input(num1);
    BigInt b3(is_negative_b, length_b, num1);

    print_cmp_result(b1, b3);
    b1.print();
    BigInt b2(b1);
    b2 = b1;

    std::cout << "BigInt: " << b3 << std::endl;
    std::cout << "BigInt " << b3 << " *  BigInt " << b1;
    b3 *= b1;
    std::cout <<  " = " << b3 << std::endl;
    std::cout << "BigInt " << b3 << " +  BigInt " << b1;
    b3 += b1;
    std::cout <<  " = " << b3 << std::endl;
    std::cout << "BigInt " << b3 << " -  BigInt " << b1;
    b3 -= b1;
    std::cout <<  " = " << b3 << std::endl;
}

void test_BigInt_second() {
    long int num = 963;
    bool is_negative = (num < 0);
    unsigned long length_l = get_length_input(num);
    BigInt b1(is_negative, length_l, num);

    long int num1 = -36;
    bool is_negative_b = (num1 < 0);
    unsigned long length_b = get_length_input(num1);
    BigInt b3(is_negative_b, length_b, num1);

    print_cmp_result(b1, b3);
    b1.print();
    BigInt b2(b1);
    b2 = b1;
    std::cout << "BigInt: " << b3 << std::endl;

    std::cout << "BigInt " << b2 << " *  BigInt " << b1;
    b2 *= b1;
    std::cout <<  " = " << b2 << std::endl;
    std::cout << "BigInt " << b3 << " +  BigInt " << b1;
    b3 += b1;
    std::cout << " = " << b3 << std::endl;
}

void test_BigInt_capacity() {
    long int num = -66657588456511123;
    bool is_negative = (num < 0);
    unsigned long length_l = get_length_input(num);
    BigInt b1(is_negative, length_l, num);
    std::cout << b1 << std::endl;
    long int num1 = 35435565679926;
    bool is_negative_b = (num1 < 0);
    unsigned long length_b = get_length_input(num1);
    BigInt b2(is_negative_b, length_b, num1);
    std::cout << b2 << std::endl;
    long int num2 = 2343434343434355666;
    bool is_negative_b2 = (num1 < 0);
    unsigned long length_b2 = get_length_input(num1);
    BigInt b3(is_negative_b2, length_b2, num2);
    std::cout << b3 << std::endl;
    long int num3 = 298765438765436;
    bool is_negative_b3 = (num1 < 0);
    unsigned long length_b3 = get_length_input(num1);
    BigInt b4(is_negative_b3, length_b3, num3);
    std::cout << b4 << std::endl;
}

int main() {
   test_BigInt();
   test_BigInt_second();
   test_BigInt_capacity();
   return 0;
}