import java.util.*;
import java.io.*;


public class LCS
{
    private static void func(String s1 , String s2)
    {
        int n=s1.length();
        int m=s2.length();
        int arr[][]=new int[n+1][m+1];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                char c1=s1.charAt(i-1);
                char c2=s2.charAt(j-1);
                if(c1==c2)
                {
                    arr[i][j]=Math.max(1+arr[i-1][j-1], Math.max(arr[i-1][j], arr[i][j-1]));
                }
                else
                {
                    arr[i][j]=Math.max(arr[i-1][j], arr[i][j-1]);
                }
            }
        }
        System.out.println(arr[n][m]);
        int i=n,j=m;
        StringBuffer sb=new StringBuffer();
        while(i>0 && j>0)
        {
            if(arr[i][j]!=arr[i-1][j] && arr[i][j]!=arr[i][j-1])
            {
                sb.append(s1.charAt(i-1));
                i--;
                j--;
            }
            else if(arr[i][j]==arr[i-1][j])
            {
                i--;
            }
            else if(arr[i][j-1]==arr[i][j])
            {
                j--;
            }
        }
        System.out.println(sb.reverse());
    }
    public static void main(String[] args) {
        func("abcaf", "acbcf");
    }
}
