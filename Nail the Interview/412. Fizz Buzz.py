class Solution(object):
    def fizzBuzz(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        value = []
        for i in range(1, n+1):
            if i%3 == 0 and i%5 != 0:
                value.append("Fizz")
            elif i%5 == 0 and i%3 != 0:
                value.append("Buzz")
            elif i%5 == 0 and i%3 == 0:
                value.append("FizzBuzz")
            else:
                value.append(str(i))
        return value
