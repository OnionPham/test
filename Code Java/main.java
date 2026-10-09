import java.util.Scanner;

public class main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String n = sc.nextLine();
        String[] a = n.split(" ");
        int res = 0;
        for(String x : a){
            if(x.matches("-?\\d+")){
                res += Integer.parseInt(x);
            }
        }
        System.out.println(res);
    }
}
