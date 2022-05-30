# Problem link -> https://leetcode.com/problems/divide-two-integers/

def divide(self, dividend: int, divisor: int) -> int:
    if dividend == 0:
        return 0
    if dividend == -2147483648 and divisor == -1:
        return 2147483647
    q = 0
    s = 1 if (dividend > 0 and divisor > 0) or (dividend < 0 and divisor < 0) else 0
    dvd, dvs = abs(dividend), abs(divisor)
    while dvd >= dvs:
        i = 
        tmp = dvs
        while dvd >= tmp:
            tmp = tmp << 1
            i += 1
        dvd -= tmp >> 1
        q += 1 << (i - 1)
    return q if s else -q