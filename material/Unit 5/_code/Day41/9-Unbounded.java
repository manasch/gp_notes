import java.util.*;
public class Unbounded
{
   public static void main(String[] args) 
   {
    List < Integer > int_List = Arrays.asList(1, 3, 5, 7);//Integer List 
    List < Double > double_List = Arrays.asList(10.2, 15.3, 20.4, 25.5);//Double list 
    print_List(int_List);
    print_List(double_List);
  }
  // I dont care what type this is as long it is an object
  private static void print_List(List < ?>Unbounded_list)//unbounded wildcard used 
  {
    System.out.println(Unbounded_list);
  } 
}