import java.util.Scanner;

class Main {
  public static void main (String args[]) {
    System.out.print("Enter the author's name: ");
    Scanner scanner = new Scanner(System.in);
    Author author = new Author();
    author.name = scanner.nextLine();
    System.out.println("The author's name is: " + author.name);
  }
}
