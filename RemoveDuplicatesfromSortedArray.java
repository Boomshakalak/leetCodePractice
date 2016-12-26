import java.util.*;
public class RemoveDuplicatesfromSortedArray{
        public static void main(String[] args) {
        int[] m = {1,1,2};
        int k = removeDuplicates(m);
        System.out.println(k);
    }
    public static int removeDuplicates(int[] nums) {
        if (nums.length==0) return 0;
        if (nums.length==1) return 1;
        int cnt=1;
        int tmp=nums[0];
        for (int i = 1;i<nums.length;i++){
            if (nums[i]!=nums[i-1]) cnt++;
            nums[cnt-1]=nums[i];
        }
        return cnt;
    }

}