import java.io.*;
import java.util.*;

public class Subset_sum{
    private static void subsetsum(int ele[],int n,int sum)
    {
        boolean arr[][]=new boolean[n+1][sum+1];
        for(int i=0;i<=n;i++)
        {
            arr[i][0]=true;
        }
        for(int i=1;i<=sum;i++)
        {
            arr[0][i]=false;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(ele[i-1]>j)
                {
                    arr[i][j]=arr[i-1][j];
                }
                else
                {
                    arr[i][j]=arr[i-1][j] || arr[i-1][j-ele[i-1]];
                }
            }
        }
        if(arr[n][sum])
        System.out.println("Possible");
        else
        System.out.println("Not Possible");
    }
    public static void main(String[] args) {
        subsetsum(new int[]{2,3,7,8,10}, 5, 6);

    }
}
