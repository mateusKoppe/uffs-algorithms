import java.util.Scanner;

class Main {
  public static void main (String args[]) {
    Author author = new Author("Charlie Brown");
    System.out.println("The first author's name is: " + author.name);
    Author author2 = new Author("Charlie Brownssauro", 27);
    System.out.println("The second author's name is: " + author2.name);
    System.out.println("The second author's age is: " + author2.age);
    Author author3 = new Author("Charlie Brownson", 31, 78.5);
    System.out.println("The second author's name is: " + author3.name);
    System.out.println("The second author's age is: " + author3.age);
    System.out.println("The second author's weight is: " + author3.weight);
  }
}
