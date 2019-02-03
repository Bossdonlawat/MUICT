public class MyDate {
  private int year,month,day;
  private static int objectNumber = 0;
  public static String[] strMonths = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

  public MyDate(int year, int month, int day) {
    this.year = year;
    this.month = month;
    this.day = day;
    this.objectNumber++;
  }

  public MyDate() {
    this.year = 1900;
    this.month = 1;
    this.day = 1;
    this.objectNumber++;
  }

  public int getObjectNumber() {
    return objectNumber;
  }

  public int getYear() {
    return year;
  }

  public int getMonth() {
    return month;
  }

  public int getDay() {
    return day;
  }

  public void setYear(int year) {
    this.year = year;
  }

  public void setMonth(int month) {
    this.month = month;
  }

  public void setDay(int day) {
    this.day = day;
  }

  public void setDate(int year, int month, int day) {
    this.year = year;
    this.month = month;
    this.day = day;
  }

  public static boolean isLeapYear(int year) {
    if(((year % 4 == 0) && (year % 100!= 0)) || (year%400 == 0)) {
      return true;
    }
    else {
      return false;
    }
  }

  public String toString() {
    return this.day + " " + this.strMonths[this.month - 1] + " " + this.year;
  }

  public MyDate nextDay() {
    if(this.month == 12 && this.day == 31) {
      this.year++;
      this.month = 1;
      this.day = 1;
    }
    else {
      if(this.month == 4 || this.month == 6 || this.month ==9 || this.month == 11) {
        if(this.day == 30) {
          this.month++;
          this.day = 1;
        }
        else {
          this.day++;
        }
      }
      else if(month != 2) {
        if(day == 31) {
          this.month++;
          this.day = 1;
        }
        else {
          this.day++;
        }
      }
      else {
        if(isLeapYear(this.year) && this.day == 29) {
          this.month++;
          this.day = 1;
        }
        else if(!isLeapYear(this.year) && this.day == 28) {
          this.month++;
          this.day = 1;
        }
        else {
          this.day++;
        }
      }
    }
    return this;
  }

  public MyDate previousDay() {
    if(this.month == 1 && this.day == 1) {
      this.year--;
      this.month = 12;
      this.day = 31;
    }
    else {
      if(this.month == 5 || this.month == 7 || this.month == 10 || this.month == 12) {
        if(this.day == 1) {
          this.month--;
          this.day = 30;
        }
        else {
          this.day--;
        }
      }
      else if(this.month != 3) {
        if(day == 1) {
          this.month--;
          this.day = 31;
        }
        else {
          this.day--;
        }
      }
      else {
        if(isLeapYear(this.year) && day == 1) {
          this.month--;
          this.day = 29;
        }
        else if(day == 1) {
          this.month--;
          this.day = 28;
        }
        else {
          this.day--;
        }
      }
    }
    return this;
  }

  public MyDate nextMonth() {
    if(this.month == 12) {
      this.year++;
      this.month = 1;
    }
    else {
      this.month++;
    }
    if(this.day == 31 && (this.month == 4 || this.month == 6 || this.month ==9 || this.month == 11)) {
      this.day = 30;
    }
    return this;
  }

  public MyDate previousMonth() {
    if(this.month == 1) {
      this.year--;
      this.month = 12;
    }
    else {
      this.month--;
    }
    if(this.day == 31 && (this.month == 4 || this.month == 6 || this.month ==9 || this.month == 11)) {
      this.day = 30;
    }
    return this;
  }

  public MyDate nextYear() {
    if(!isLeapYear(this.year + 1) && (this.month == 2 && this.day == 29)) {
      this.day = 28;
    }
    this.year++;
    return this;
  }

  public MyDate previousYear() {
    if(!isLeapYear(this.year - 1) && (this.month == 2 && this.day == 29)) {
      this.day = 28;
    }
    this.year--;
    return this;
  }

  public static int yearDiff(MyDate start, MyDate end) {
    if (start.getYear() <= end.getYear()) {
      if(start.getMonth() <= end.getMonth() && start.getDay() <= end.getDay()) {
        return end.getYear() - start.getYear();
      }
      else {
        return end.getYear() - start.getYear() - 1;
      }
    }
    else {
      return -1;
    }
  }
}
