class Date {
  private int day;
  private int month;

  public Date () {
    this.day = 1;
    this.month = 1;
  }

  public Date (int month) {
    if (!isDateValid(month, 1)) {
      /* I don`t you how to trigger errors yet and I`m to lazy to search for */
      System.out.println("Invalid Date");
      return;
    }
    this.day = 1;
    this.month = month;
  }

  public Date (int month, int day) {
    if (!isDateValid(month, day)) {
      System.out.println("Invalid Date");
      return;
    }
    this.day = day;
    this.month = month;
  }

  public boolean isDateValid (int month, int day) {
    int[] monthRange = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month < 1 || month > 12) {
      return false;
    }
    if (month < 1 && month > 12) {
      return false;
    }
    int actualMonthLimit = monthRange[month - 1];
    if (day > monthRange[month-1] || day < 0) {
      return false;
    }
    return true;
  }

  public void print () {
    System.out.println(this.day + "/" + this.month);
  }

  public void setDay (int day) {
    this.day = day;
  }

  public void setMonth (int month) {
    this.month = month;
  }
}