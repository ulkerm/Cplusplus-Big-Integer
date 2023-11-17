#pragma once

#include <ostream>

class BigInt {
private:
    bool is_negative;
    unsigned long length;
    unsigned short *digits;

public:
    explicit BigInt(bool is_negative,  unsigned long length, long num);
    ~BigInt();

    unsigned long get_length() const { return length; };

    void print() const;
    BigInt(const BigInt& b);  // copy constructor
    BigInt& operator=(const BigInt& b); // assignment

    short cmp(const BigInt &b) const;
    short cmp_arr(const BigInt &b) const;

    BigInt& operator+= (const BigInt& b);
    BigInt& operator-= (BigInt& b);
    BigInt& operator/= (long divisor);
    BigInt& operator*= (const BigInt& b);

    friend std::ostream& operator<<(std::ostream& os, const BigInt& b);
};

BigInt operator/(BigInt a, long divisor);
BigInt operator*(BigInt a, const BigInt& b);
unsigned short* addition(unsigned short* b, unsigned long b_length, unsigned short* b1,  unsigned long b1_length, unsigned long& result_length);
unsigned short* subtraction(unsigned short* b, unsigned long b_length, unsigned short* b1,  unsigned long b1_length);

unsigned long get_length_input(long num);
