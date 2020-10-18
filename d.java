import java.util.*;
import java.io.*;

public class Maze{

	static boolean isSafe(int arr[][], int n, int i, int j){

		if(i < n && j < n && i >= 0 && j >= 0 && arr[i][j] == 1){
			return true;
		}
		return false;
	}
	static boolean maze(int arr[][], int n){

		int solution[][] = new int[n][n];
		int i = 0, j = 0;
		boolean answer = mazeUtil(arr, n, i, j, solution);
		if(answer)
		{
			
			for(int i1 = 0; i1 < n; i1++)
			{
				for(int j1 = 0; j1 < n; j1++)
				{
					System.out.print(solution[i1][j1] + " ");
				}
				System.out.println();
			}
			return true;
		}
		System.out.println("Blocked");
		return false;
	}
	static boolean mazeUtil(int arr[][], int n, int i, int j, int solution[][]){
		if(i == n - 1 && j == n - 1){

			solution[i][j] = 1;
			return true;
		}
		if(isSafe(arr, n, i, j)){
			solution[i][j] = 1;
			if(mazeUtil(arr, n, i + 1, j, solution)){
				return true;
			}
			if(mazeUtil(arr, n, i, j + 1, solution)){
				return true;
			}
			solution[i][j] = 0;
			return false;
		}
		return false;
	}
	public static void main(String args[]) throws Exception{
		int n = 4;
		int arr1[][] = { { 1, 0, 0, 0 }, 
                         { 1, 1, 0, 1 }, 
                         { 0, 1, 0, 0 }, 
                         { 1, 1, 1, 1 }
                     };
        boolean x = maze(arr1,n);

	}
}
