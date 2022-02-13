import java.math.BigInteger;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class name{
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        
        int base = Integer.parseInt(reader.readLine());
        
        for(Integer i = 1; i <= 300; i++){
            Integer num = i * i;
            String a = Integer.toString(num, base);
            
            boolean works = true;
            for(int j = 0; j < a.length(); j++){
                if(a.charAt(j) != a.charAt(a.length() - j - 1)){
                    works = false;
                }
            }
            
            if(works){
                System.out.print(a + " ");
                System.out.println(Integer.toString(i, base));
            }
        }
    }
}