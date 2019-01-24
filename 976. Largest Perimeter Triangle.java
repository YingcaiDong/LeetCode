class Solution {
    public int largestPerimeter(int[] A) {
        Arrays.sort(A);
        int max = A.length-1;
        int max2 = A.length-2;
        int max3 = A.length-3;
        while(max3 >= 0 && max2 > max3) {
            int twoSides = A[max3] + A[max2];
            if (twoSides > A[max]) {
                return twoSides + A[max];
            } else {
                max3 -= 1;
                max2 -= 1;
                max -= 1;
            }
        }
        return 0;
    }
}
