/*
ID: amogh.d1
TASK: palsquare
LANG: JAVA 
*/
import java.util.*;
import java.io.*;
import java.math.BigInteger;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;

 class main{
    public static void main(String[] args) throws IOException {
        Scanner reader = new Scanner(new File("palsquare.in"));
        BufferedWriter bw = new BufferedWriter(new FileWriter("palsquare.out"));
        int base = reader.nextInt();
        for(int i = 1; i <= 300; i++){
            int num = i * i;
            String a = Integer.toString(num, base);
            boolean works = true;
            for(int j = 0; j < a.length(); j++){
                if(a.charAt(j) != a.charAt(a.length() - j - 1)){
                    works = false;
                }
            }
            
            if(works){
                bw.write(a + " " + Integer.toString(i, base) + "\n");
            }
        }
    }
}