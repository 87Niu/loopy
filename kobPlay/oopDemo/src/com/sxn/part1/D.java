package com.sxn.part1;

import java.util.Arrays;
import java.util.Comparator;

public class D {
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 计算小明面试成功可能性的最大和
     * @param interviews int整型二维数组 interviews[i] = [startTime_i, endTime_i, possibility_i] 第 i 个面试在 startTime_i 时间开始， endTime_i 时间结束，通过的可能性是 possibility_i
     * @param k int整型 最多参加的面试次数
     * @return int整型
     */
    public int maxValue (int[][] interviews, int k) {
        // write code here
        Arrays.sort(interviews, Comparator.comparingInt(a -> a[1]));

        int n = interviews.length;
        int[][] f = new int[n + 1][k + 1];

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                f[i][j] = f[i - 1][j];

                int poss = interviews[i - 1][2];
                int index = findNextInterView(interviews, i - 1);
                if (index != -1) {
                    poss += f[index + 1][j - 1];
                }
                f[i][j] = Math.max(f[i][j], poss);
            }
        }
        return f[n][k];
    }

    private int findNextInterView(int[][] interviews, int m) {
        for (int i = m - 1; i >= 0; i --) {
            if (interviews[i][1] <= interviews[m][0]) {
                return i;
            }
        }
        return -1;
    }
}