//
// Created by atom on 2023/5/1.
//
#include <stdio.h>


//复数结构定义
struct Complex
{
    double real;
    double imag;
};

//创造一个复数
struct Complex make_complex(double real, double imag)
{
    struct Complex c;
    c.real = real;
    c.imag = imag;
    return c;
}
//复数的实部
double get_real(struct Complex c)
{
    return c.real;
}
//复数的虚部
double get_imag(struct Complex c)
{
    return c.imag;
}
//复数的加法
struct Complex add_complex(struct Complex c1, struct Complex c2)
{
    struct Complex c;
    c.real = c1.real + c2.real;
    c.imag = c1.imag + c2.imag;
    return c;
}
//复数的减法
struct Complex sub_complex(struct Complex c1, struct Complex c2)
{
    struct Complex c;
    c.real = c1.real - c2.real;
    c.imag = c1.imag - c2.imag;
    return c;
}
//复数的乘法
struct Complex mul_complex(struct Complex c1, struct Complex c2)
{
    struct Complex c;
    c.real = c1.real * c2.real - c1.imag * c2.imag;
    c.imag = c1.real * c2.imag + c1.imag * c2.real;
    return c;
}
//复数的除法
struct Complex div_complex(struct Complex c1, struct Complex c2)
{
    struct Complex c;
    c.real = (c1.real * c2.real + c1.imag * c2.imag) / (c2.real * c2.real + c2.imag * c2.imag);
    c.imag = (c1.imag * c2.real - c1.real * c2.imag) / (c2.real * c2.real + c2.imag * c2.imag);
    return c;
}




//有理数的结构体定义
struct Rational
{
    int numerator;//分子
    int denominator;//分母
};

//创造一个有理数
struct Rational make_rational(int numerator, int denominator)
{
    struct Rational r;
    r.numerator = numerator;
    r.denominator = denominator;
    return r;
}

//有理数的分母
int get_denominator(struct Rational r)
{
    return r.denominator;
}

//有理数的分子
int get_numerator(struct Rational r)
{
    return r.numerator;
}

//有理数的加法
struct Rational add_rational(struct Rational r1, struct Rational r2)
{
    struct Rational r;
    r.numerator = r1.numerator * r2.denominator + r2.numerator * r1.denominator;
    r.denominator = r1.denominator * r2.denominator;
    return r;
}

//有理数的减法
struct Rational sub_rational(struct Rational r1, struct Rational r2)
{
    struct Rational r;
    r.numerator = r1.numerator * r2.denominator - r2.numerator * r1.denominator;
    r.denominator = r1.denominator * r2.denominator;
    return r;
}

//有理数的乘法
struct Rational mul_rational(struct Rational r1, struct Rational r2)
{
    struct Rational r;
    r.numerator = r1.numerator * r2.numerator;
    r.denominator = r1.denominator * r2.denominator;
    return r;
}

//有理数的除法
struct Rational div_rational(struct Rational r1, struct Rational r2)
{
    struct Rational r;
    r.numerator = r1.numerator * r2.denominator;
    r.denominator = r1.denominator * r2.numerator;
    return r;
}

//约分有理数
struct Rational reduce_rational(struct Rational r)
{
    int a = r.numerator;
    int b = r.denominator;
    int c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    r.numerator /= a;
    r.denominator /= a;
    return r;
}

//判断两个有理数是否相等
int equal_rational(struct Rational r1, struct Rational r2)
{
    return r1.numerator * r2.denominator == r2.numerator * r1.denominator;
}

int main(int argc, char const *argv[])
{
    //有理数
    struct Rational r1 = make_rational(1, 2);
    //复数
    struct Complex c1 = make_complex(1, 2);
    //加法
    struct Rational r2 = add_rational(r1, r1);
    struct Complex c2 = add_complex(c1, c1);
    //减法
    struct Rational r3 = sub_rational(r1, r1);
    struct Complex c3 = sub_complex(c1, c1);
    //乘法
    struct Rational r4 = mul_rational(r1, r1);
    struct Complex c4 = mul_complex(c1, c1);
    //除法
    struct Rational r5 = div_rational(r1, r1);
    struct Complex c5 = div_complex(c1, c1);

    printf("r1 = %d/%d\n", get_numerator(r1), get_denominator(r1));
    printf("c1 = %f + %fi\n", get_real(c1), get_imag(c1));
    printf("r2 = %d/%d\n", get_numerator(r2), get_denominator(r2));
    printf("c2 = %f + %fi\n", get_real(c2), get_imag(c2));
    printf("r3 = %d/%d\n", get_numerator(r3), get_denominator(r3));
    printf("c3 = %f + %fi\n", get_real(c3), get_imag(c3));
    printf("r4 = %d/%d\n", get_numerator(r4), get_denominator(r4));
    printf("c4 = %f + %fi\n", get_real(c4), get_imag(c4));
    printf("r5 = %d/%d\n", get_numerator(r5), get_denominator(r5));
    printf("c5 = %f + %fi\n", get_real(c5), get_imag(c5));
    return 0;
}
