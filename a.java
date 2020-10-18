import java.util.*;
import java.io.*;

public class TowerOfHanoi{

	public static void func_TOH(int n, String src, String dest, String temp){
		if(n == 1){
			System.out.println("Move plate from " + src + " to " + dest);
			return;
		}
		func_TOH(n - 1, src, temp, dest);
		System.out.println("Move plate from " + src + " to " + dest);
		func_TOH(n - 1, temp, dest, src);
		
	}
	public static void main(String args[]){
		
		int n = 3;
		String src = "src";
		String dest = "dest";
		String temp = "temp";
				
		func_TOH(n, src, dest, temp);
	}
}
