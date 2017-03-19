class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        lengh = len(prices)
        buy = {'flag': False}
        sell = {'flag': False}
        profit = 0
        for i in range(0, lengh):
        	if lengh == 1:
        		profit = 0
        	elif i>0 and i<lengh-1:
        		if prices[i-1]>=prices[i] and prices[i+1]>prices[i] and not buy['flag']:
        			buy['price'] = prices[i]
        			buy['flag'] = True
        		elif prices[i-1]<prices[i] and prices[i+1]<=prices[i] and buy['flag']:
        			sell['price'] = prices[i]
        			sell['flag'] = True
        	elif i-1<0:
        		if prices[i]<prices[i+1] and not buy['flag']:
        			buy['price'] = prices[i]
        			buy['flag'] = True
        	elif i+1>lengh-1:
        		if prices[i-1]<prices[i] and buy['flag']:
        			sell['price'] = prices[i]
        			sell['flag'] = True
        	if buy['flag'] and sell['flag']:
        		profit += sell['price'] - buy['price']
        		buy['flag'] = False
        		sell['flag'] = False
        return profit
