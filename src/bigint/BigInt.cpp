#include "BigInt.h"
#include <iostream>

#include <cassert>

using std::cout;
using std::endl;

#define shift 10

BigInt::BigInt(bool is_negative,  unsigned long length, long num): is_negative{is_negative}, length{length}, digits(new unsigned short [length]) {
    num = abs(num);
    size_t j = 0;
    for (size_t i = length; i > 0; i--) {
        digits[j] = static_cast<unsigned short>(num % shift);
        num /= 10;
        j++;
    }
}

BigInt::~BigInt() {
    delete[] digits;
    cout << "~BigInt destructed" << endl;
}

BigInt::BigInt(const BigInt &b) : is_negative(b.is_negative), length(b.length), digits(new unsigned short [length]) {
    for(size_t i = 0; i < length; i ++)
        digits[i] = b.digits[i];
    //cout << "Copy constructor was called" << endl;
}

BigInt &BigInt::operator=(const BigInt &b) {
    cout << "BigInt::operator=(const BigInt &b)" << endl;
    if (this == &b) {
        return *this;
    }
    if (length != b.length) {
        unsigned short *new_b = new unsigned short [b.length];
        length = b.length;
        is_negative = b.is_negative;
        delete [] digits;
        digits = new_b;
    }

    for(size_t i = 0; i < length; i ++)
        digits[i] = b.digits[i];
    return *this;
}

std::ostream & operator << (std::ostream &os, const BigInt &b) {
    if (b.is_negative)
        os << "-";
    os << '[';
    for (int i = static_cast<int>(b.length - 1); i >= 0; i--) {
        if (i < static_cast<int>(b.length - 1)) os << ", ";
        os << (b.digits[i]);
    }
    return os << ']' << std::flush;
}

unsigned short* subtraction(unsigned short* b, unsigned long b_length, unsigned short* b1,  unsigned long b1_length) {
    unsigned short *new_digits = new unsigned short [(b_length > b1_length ? b_length : b1_length)];
    unsigned long shorter_arr_length = b_length > b1_length ? b1_length : b_length;
    unsigned long result_index = 0;
    for (unsigned long i = 0; i < shorter_arr_length; i++) {
        if(b[i] >= b1[i]) {
            new_digits[i] = b[i] - b1[i];
        } else {
            b[i] = b[i] + shift;
            new_digits[i] = b[i] - b1[i];
            b[i+1] = b[i+1] - 1;
        }
        result_index++;
    }
    if(b_length != b1_length) {
        for (unsigned long i = shorter_arr_length; i < b_length; i++) {
            new_digits[result_index] = b[i];
            result_index++;
        }
    }
    return new_digits;
}

unsigned short* addition(unsigned short* b, unsigned long b_length, unsigned short* b1,  unsigned long b1_length, unsigned long& result_length) {
    unsigned short *new_digits = new unsigned short [result_length];
    unsigned long shorter_arr_length = b_length > b1_length ? b1_length : b_length;
    unsigned long result_index = 0;
    int check = 0;
    for (unsigned long i = 0; i < shorter_arr_length; i++) {
        if(check > 0) {
            new_digits[result_index] = b[i] + b1[i] + 1;
            check--;
        } else new_digits[result_index] = b[i] + b1[i];
        if (new_digits[result_index] > 9) {
            check++;
            new_digits[result_index] = new_digits[result_index] - shift;
        }
        if ((check != 0) && (i == shorter_arr_length - 1)){
            new_digits[result_index + 1] = 1;
        }
        result_index++;
    }
    if(b_length > b1_length) {
        for (unsigned long i = shorter_arr_length; i < b_length; i++) {
            if (new_digits[shorter_arr_length] == 1) new_digits[result_index] = b[i] + 1;
            else new_digits[result_index] = b[i];
            result_index++;
        }
    } else if(b_length < b1_length) {
        for (unsigned long i = shorter_arr_length; i < b1_length; i++) {
            if (new_digits[shorter_arr_length] == 1) new_digits[result_index] = b1[i] + 1;
            else new_digits[result_index] = b1[i];
            result_index++;
        }
    }

    result_length = result_index;
    return new_digits;
}

BigInt &BigInt::operator-=( BigInt &b) {
    if(is_negative == b.is_negative && is_negative == false) {
        digits = subtraction(digits, length, b.digits, b.length);
    } else if (is_negative == b.is_negative && is_negative == true) {
        b.is_negative = false;
        if((*this).cmp_arr(b) == 1)
            digits = subtraction(digits, length, b.digits, b.length);
        else if ((*this).cmp_arr(b) == 2) {
            digits = subtraction(b.digits, b.length, digits, length);
            is_negative = b.is_negative;
        }
    } else {
        digits = addition(digits, length, b.digits, b.length, length);
    }
    return *this;
}

BigInt &BigInt::operator+=(const BigInt &b) {
    if(is_negative == b.is_negative)
        digits = addition(digits, length, b.digits, b.length, length);
    else if((*this).cmp_arr(b) == 1)
        digits = subtraction(digits, length, b.digits, b.length);
    else if ((*this).cmp_arr(b) == 2) {
        digits = subtraction(b.digits, b.length, digits, length);
        length = length > b.length ? length : b.length;
        is_negative = b.is_negative;
    }
    return *this;
}

void BigInt::print() const {
    if (is_negative)
        std::cout << "-";
    for (int i = static_cast<int>(length - 1); i >= 0; i--)
        std::cout << digits[i];
    std::cout << std::endl;
}


short BigInt::cmp_arr(const BigInt &b) const {
    if (length > b.length)
        return 1;
    else if (length < b.length)
        return 2;
    else {
        for (int i = static_cast<int>(b.length - 1); i >= 0; i--) {
            if (digits[i] > b.digits[i])
                return 1;
            else if (digits[i] < b.digits[i])
                return 2;
        }
    }
    return 0;
}

short BigInt::cmp(const BigInt &b) const {
    if(is_negative == false && b.is_negative == true)
        return 1;
    else if(is_negative == true && b.is_negative == false)
        return 3;
    else {
        if ((length > b.length && is_negative == false) || (length < b.length && is_negative == true))
            return 1;
        else if ((length > b.length && is_negative == true) || (length < b.length && is_negative == false))
            return 3;
        else {
            for (int i = static_cast<int>(b.length - 1); i >= 0; i--) {
                if ((digits[i] > b.digits[i] && !is_negative) || (digits[i] < b.digits[i] && is_negative))
                    return 1;
                else if((digits[i] > b.digits[i] && is_negative) || (digits[i] < b.digits[i] && !is_negative))
                    return 3;
            }
        }
    }
    return 0;
}

BigInt &BigInt::operator/=(long divisor) {
    assert(divisor != 0);
    bool is_negative_divisor = (divisor < 0);
    if(is_negative_divisor) divisor = divisor + (-2) * divisor;
    unsigned long unsigned_divisor = static_cast<unsigned long>(divisor);

    unsigned short *result_digits = new unsigned short[length];
    unsigned long i = length - 1;
    unsigned long currentIndex = 0;
    unsigned long temp = 0;

    while (currentIndex < length || temp >= unsigned_divisor) {
        if (temp < unsigned_divisor && currentIndex < length) {
            temp = temp * shift + digits[currentIndex];
            currentIndex++;
        }
        result_digits[i] =  static_cast<unsigned short>(temp) / static_cast<unsigned short>(unsigned_divisor) ;
        temp %= unsigned_divisor;
        i--;
    }
    length = length - i;
    delete[] digits;
    digits = result_digits;
    if(is_negative != is_negative_divisor) is_negative = true;
    else is_negative = false;
    return *this;
}

unsigned long get_length_input(long num) {
    unsigned long length = 0;
    long temp = num;
    while (temp != 0) {
        temp /= shift;
        ++length;
    }
    return length;
}

BigInt operator/(BigInt a, long divisor) {
    return a /= divisor;
}

BigInt operator*(BigInt a, const BigInt& b) {
    return a *= b;
}

BigInt &BigInt::operator*=(const BigInt &b) {
    unsigned short *new_digits = new unsigned short[length + b.length]();
    unsigned short temp = 0;

    for(unsigned long i = 0; i < length; i++) {
        unsigned short carry = 0;
        for(unsigned long j = 0; j <= b.length || carry; j++) {
            if (j < b.length)
                temp = new_digits[i + j] + digits[i] * b.digits[j] + carry;
            else
                temp = new_digits[i + j] + digits[i] * 0 + carry;

            new_digits[i + j] = temp % shift;
            carry = temp / shift;
        }
    }
    delete[] digits;
    digits = new_digits;
    if(is_negative != b.is_negative) is_negative = true;

    length += b.length;
    return *this;
}
