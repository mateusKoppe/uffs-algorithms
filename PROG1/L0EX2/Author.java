import java.util.Scanner;

class Author {
  public int id;
  public String name;

  void loadFromInput () {
    Scanner scanner = new Scanner(System.in);
    System.out.print("Enter author's id: ");
    try {
      this.id = Integer.parseInt(scanner.nextLine());
    } catch (Exception error) {
      System.out.println("Invalid Id");
    }
    System.out.print("Enter author's name: ");
    this.name = scanner.nextLine();
  }
}
