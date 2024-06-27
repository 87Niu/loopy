package com.sxn.part1;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;

public class B {

    public ArrayList<Integer> findAllPerson (int n, int[][] meetings, int firstPerson) {
        // write code here
        int[] f = new int[n];

        // 按照时间排序就完事了


        f[0] = 1; // 人员 0 感染病毒 并且与 firstPersion 有接触
        f[firstPerson] = 1;

        Arrays.sort(meetings, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[2] - o2[2];
            }
        });
//
//        for (int i = 0; i < n; i++) {
//            System.out.println(meetings[i][0] + " " + meetings[i][1] + " " + meetings[i][2]);
//        }

        for (int[] meeting : meetings) {
            // System.out.println(meeting[0] + " " + meeting[1]);
            int a = meeting[0];
            int b = meeting[1];
            if (f[a] == 1 || f[b] == 1) {
                f[a] = f[b] = 1;
            }
        }

        ArrayList<Integer> res = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (f[i] == 1) {
                res.add(i);
            }
        }
        return res;
    }
}