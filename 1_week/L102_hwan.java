import java.util.Scanner;
import java.util.Arrays;

class Solution {
    static public long[] solution(long x, int n) {
        long[] answer = new long [n];
        
        for(int count = 0; count < n; count++){
            answer[count] = x * (count+1); 
        }
        return answer;
    }
}

public class L102_hwan {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        long x = sc.nextLong();
        int n = sc.nextInt();
        
        System.out.println(Arrays.toString(Solution.solution(x, n)));    
    }     
}