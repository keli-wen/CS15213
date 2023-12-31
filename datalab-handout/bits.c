/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0 
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) { //* Finish.
  return (~(x & y)) & (~((~x) & (~y)));
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) { //* Finish
  /* 
   ! I use gpt to solve this problem.
   * Since, I never realized that I can use constant numbers.
   */
  return 1 << 31;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) { //* Finish.
  // Max two's compement number: 1<<32-1.
  // 1. Add one: x + 1 -> negative integer.
  // 2. Use !!(x+1) to avoid -1.
  return !(x + (x + 1) + 1) & !!(x + 1);
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) { //* Finish
  /*
   ! I use gpt to solve this problem.
   * Since, I believed that 0xAA represented 4 bits.
   * 
   */
  // Construct a mask.
  int mask = 0xAA << 24 | 0xAA << 16 | 0xAA << 8 | 0xAA;
  x = x & mask;
  return !(x ^ mask);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) { //* Finish.
  // 0x0110 2 + 4
  // 0x1001
  return (~x) + 1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) { //*Finish
  /*
   ! I use gpt to solve this problem.
   * Since I don't know how to check whether a value is within a given range.
   */
  // Represent: x - 0x30
  int lowerBound = ~(0x30) + 1 + x;
  // Represent: 0x39 - x
  int upperBound = ~(x) + 1 + 0x39;
  // Check the sign bit.
  return !((lowerBound | upperBound) >> 31);
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) { //* Finish
  /*
   !  I use gpt to solve this problem.
   * if x <=> !!(x)
   * !!(x) == 1 -> mask = 1111
   * !!(x) == 0 -> mask = 0000
   */
  int mask = ~(!!(x)) + 1;
  return (mask & y) | (~mask & z);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) { //*Finish 
  /*
   * I tackled this problem on my own.
   * Initially, I sought to resolve it by checking the sign bit of (y - x).
   * However, I discovered that if both x and y are very small negative numbers,
   * (y - x) could cause an overflow. As a result, I decided to split the problem
   * into two parts.
   * First, we check the top 31 bits using (y - x), which is the same as (y + ~x + 1).
   * Second, we specifically examine the lowbit of x and y.
   * When the top 31 bits of x and y are equal, we need to assess the lowbit of x and y.
   */
  // y - x >= 0
  // x - y <= 0
  int lowX = x & 1;
  int lowY = y & 1;
  int cx = x >> 1;
  int cy = y >> 1;
  int ySubx = cy + (~cx) + 1;
  // y_c >= x_c => (sub >> 31) == 0.
  // if y_c == x_c we need to check lowX and lowY.
  // Only the case lowX = 1 and lowY = 0 don't meet our execption.
  int yEqX = !(cx ^ cy);
  return !(ySubx >> 31) & ((yEqX & !(lowX & (lowY ^ 1))) | (!yEqX));
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) { //* Finish
  /*
   ! I use gpt to solve this problem.
   * I'm completely clueless about this problem. 
   */
  // Only when x is equal to zero the flag highest bit will be zero.
  // When x is equal to zero, the highest bit of the flag will also be zero.
  int flag = (x | (~x + 1));
  return ((flag >> 31) & 0x01) ^ 1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) { //* Finish
  /*
   ! I use gpt to solve this problem.
   * I'm completely clueless about this problem.
   */
  // The problem it to find the highest bit of x.
  int sign, bit16, bit8, bit4, bit2, bit1, bit0;
  sign = x >> 31;

  // Bitwise XOR with sign gives us the value with all the bits flipped 
  // if the number was negative. This allows us to always look for the left-most
  // 1 bit.
  x ^= sign;

  // Check if left 16 bits have a 1.
  bit16 = !!(x >> 16) << 4;
  // If bit16 is non-zero, shift x right by 16 else leave x unchanged.
  x = x >> bit16;

  bit8 = !!(x >> 8) << 3;
  x = x >> bit8;

  bit4 = !!(x >> 4) << 2;
  x = x >> bit4;

  bit2 = !!(x >> 2) << 1;
  x = x >> bit2;

  bit1 = !!(x >> 1);
  x = x >> bit1;

  bit0 = !!(x);
  return bit16 + bit8 + bit4 + bit2 + bit1 + bit0 + 1;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) { //* Finish
  /*
  ! I use gpt to solve this problem.
  Single Precision (32 bits) IEEE

  SEEEEEEE EFFFFFFF FFFFFFFF FFFFFFFF

  S - Sign bit (1 bit)
  E - Exponent (8 bits)
  F - Fraction (23 bits)

  Sign bit: 0 for positive, 1 for negative.
  Exponent: Biased exponent value.
  Fraction: Fraction portion of significand.

  Examples:

  0 01111111 00000000000000000000000 = 1.0
  1 01111111 00000000000000000000000 = -1.0  
  0 10001001 10010010000111111011011 = -3.14159
  */
  int exp = (uf >> 23) & 0xFF;  // extract exponent
  int sign = uf & (1 << 31);  // extract sign bit
  
  if (exp == 0xFF) { // if uf is NaN or infinity
    return uf;
  } else if (exp == 0) { // if uf is denormalized
    return sign | (uf << 1);
  } else if (exp == 0xFE) { // if the result is going to be infinity
    return sign | 0x7F800000;  // return +/- infinity
  } else {  // if uf is a normalized float
    return uf + (1 << 23);  // increase exponent by 1
  }
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) { //* Finish.
  /*
   * I tackled this problem on my own.
   *  
  */
  unsigned exp = (uf >> 23) & 0xFF;
  int sign = uf & (1 << 31);
  unsigned frac = uf & 0x007FFFFFu;
  // If uf is NaN or infinity.
  if (exp == 0xFE) {
    return 0x80000000u;
  } else if (exp != 0) {
    int E = exp - (0x7F);
    if (E > 31) {
      // Don't in the integer range.
      return 0x80000000u;
    } else if (E >= 0) {
      int res;
      if (23 - E >= 0)
        res = ((1 << 23) | frac) >> (23 - E);
      else 
        res = ((1 << 23) | frac) << (E - 23);
      if (!sign)
        return res;
      else 
        return ~(res) + 1;
    } else {
      return 0;
    }
  } else {
    // If uf is unformated, it'll never greater than one.
    return 0;
  }
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) { //* Finish
  /*
   * I tackled the problem on my own.
   * Just to check whether exponent is too large or too small and respond
   * accordingly.
   */
  // Just one bit.
  int bais = 0x7F;
  if (x >= 0) {
    if (x > 0x7F) return 0x7F800000u;
    else {
      return (x + bais) << 23;
    }
  } else {
    x = -x;
    if (x > 0x7E) return 0;
    else {
      return (bais - x) << 23 | (1 << 30);
    }
  }
}
