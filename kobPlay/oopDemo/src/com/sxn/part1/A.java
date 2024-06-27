package com.sxn.part1;

public class A {

    public long minOperations (int[] num1, int[] num2, int k) {
        // write code here

        int n = num1.length;
        int[] f = new int[n];

        for (int i = 0; i < n; i ++) {
            f[i] = num2[i] - num1[i];
        }

        int zheng = 0;
        int fu = 0;

        for (int d : f) {
            if (d > 0) {
                zheng += d;
            } else if (d < 0) {
                fu += Math.abs(d);
            }
        }

        // 1 和 2 的数组差 只要不想等,那么就无法使其相等
        if (zheng != fu) {
            return -1;
        }

        // 如果相等
        return (zheng + k - 1) / k;
    }
}