package com.sxn.part1;

import java.util.*;

public class C {

    public ListNode groupSort (ListNode head, int n) {
        // write code here
        List<ListNode> list = new ArrayList<ListNode>();

        ListNode cur = head;
        ListNode dummy = null; // preta

        while (cur != null) {
            int count = 0;
            ListNode gh = cur;
            ListNode gt = null;
            while (cur != null && count < n) {
                gt = cur;
                cur = cur.next;
                count ++;
            }
            if (count == n) {
                assert gt != null;
                gt.next = null;
                list.add(sortList(gh));
            } else {
                if (dummy != null) {
                    dummy.next = gh;
                }
                break;
            }

            if (dummy != null) {
                dummy.next = list.get(list.size() - 1);
            }
            dummy = gt;

        }



        // 得到队头指针
        if (!list.isEmpty()) {
            head = list.get(0);
        }

        return head;
    }

    // 选择充新排序, 使用指针比较比较麻烦
    private ListNode sortList(ListNode gh) {
        List<Integer> val = new ArrayList<>();
        ListNode dummy = gh;
        while (dummy != null) {
            val.add(dummy.val);
            dummy = dummy.next;
        }
        // 从大到小
        val.sort(Collections.reverseOrder());

        dummy = gh;
        for (int v : val) {
            dummy.val = v;
            dummy = dummy.next;
        }
        return gh;
    }
}