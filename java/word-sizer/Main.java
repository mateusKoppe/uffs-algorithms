import java.util.Scanner;

class Main {
  public static void main (String[] args) {
    Scanner scanner = new Scanner(System.in);
    String word = scanner.nextLine();
    int amount = word.split(" ").length;
    System.out.println("Size: "+amount);
  }
}