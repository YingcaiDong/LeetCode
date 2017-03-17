class Solution(object):
    def getSum(self, a, b):
        carry = (a&b)<<1
        sum = a^b
        while carry:
            temp = sum
            sum ^= carry
            carry = ((temp&carry)<<1)&0xFFFFFFFF
        if sum&0x10000000 == 0x10000000:
            return sum
        else:
            return sum&0xFFFFFFFF
