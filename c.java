import java.io.*;
import java.util.*;

public class NQueen{
	//static int arr[];
	static boolean isSafe(int arr[], int k, int i){

		for(int j = 0; j < k - 1; j++)
		{
			if(arr[j] == i)
			{
				return false;
			}
			if(Math.abs(j - k) == Math.abs(i - arr[j])){
				return false;
			}
		}
		return true;
	}
	static void nQueen(int arr[], int k, int n){
		for(int i = 0; i < n; i++){
			if(isSafe(arr, k, i)){
				arr[k] = i;
				if(k == n - 1)
				{
					//arr[k] = arr[k];
				}
				else{
					nQueen(arr, k + 1, n);
				}
			}
		}

	}
	public static void main(String args[])throws Exception{
		int n = 4;
		int arr[] = new int[n];
		nQueen(arr, 0, n);
		for(int i = 0; i < n; i++)
		{
			System.out.println(arr[i]);
		}
	}
}
