import java.util.*;

class Solution {
public void setZeroes(int[][] nums) {
List<int[]> flags = new ArrayList<>();
    for (int i = 0; i < nums.length; i++) {
        for (int j = 0; j < nums[i].length; j++) {
            if (nums[i][j] == 0) {
                flags.add(new int[]{i, j});
            }
        }
    }
    for (int[] pos : flags) {
        int row = pos[0];
        int col = pos[1];

        for (int i = 0; i < nums.length; i++) {
            nums[i][col] = 0;
        }

        for (int j = 0; j < nums[row].length; j++) {
            nums[row][j] = 0;
        }
    }
}
}
