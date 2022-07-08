import java.util.Scanner;

class L101_hwan {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        String Star = "";
        
        for(int Jump = 0; Jump < b; Jump++){
            for(int count = 0; count < a; count++){
                Star +="*"; 
            }
            Star += "\n";
        }
        
        System.out.println(Star);
    }
}