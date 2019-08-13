import java.util.Scanner;

class Main {
  public static void main (String args[]) {
    Author author = new Author();
    author.loadFromInput();
    System.out.println("The author's id is: " + author.id);
    System.out.println("The author's name is: " + author.name);
  }
}
