import java.util.*;
import java.io.*;

public class Sort_Array{
    public static void sortArray(ArrayList<Integer> al){
        if(al.size() == 1){     //Base condition
            return;
        }

        int temp = al.get(al.size() - 1);
        al.remove(al.size() - 1);
        sortArray(al);
        insert_element(al , temp);
    }

    public static void insert_element(ArrayList<Integer> al , int temp){
        if(al.size() == 0 || al.get(al.size() - 1) <= temp)
        {
            al.add(temp);
            return;
        }
        int val = al.get(al.size() - 1);
        al.remove(al.size() - 1);
        insert_element(al , temp);
        al.add(val);
    }
    public static void main(String args[]) throws Exception{
        ArrayList<Integer> al = new ArrayList<>();
        al.add(5);
        al.add(1);
        al.add(0);
        al.add(2);
        sortArray(al);
        for(int i = 0; i < al.size(); i++){
            System.out.println(al.get(i));
        }
    }
}
