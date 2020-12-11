import java.util.Scanner;

class Author {
  public String name;
  public int age;
  public double weight;

  Author (String name) {
    this.name = name;
  }

  Author (String name, int age) {
    this.name = name;
    this.age = age;
  }

  Author (String name, int age, double weight) {
    this.name = name;
    this.age = age;
    this.weight = weight;
  }
}
