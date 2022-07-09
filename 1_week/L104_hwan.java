import java.util.Scanner;

public class L104_hwan {
	public static String solution(String phone_number) {
        
        char[] Number = phone_number.toCharArray(); //String to Array
        
        for(int count = 0; count < (Number.length - 4); count++) {
        	Number[count] = '*';
        }
        
        String answer = String.valueOf(Number);//Array to String
        
        return answer;
    }
	public static void main(String[] args) {
		
		Scanner scHandyNum = new Scanner(System.in);
		String phone_number = scHandyNum.nextLine();
		scHandyNum.close();
		
		System.out.print(solution(phone_number));
		
	}

}