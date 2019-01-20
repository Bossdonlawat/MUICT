public class AirQualityProfile {
  private String location, weather;
  private int aqi, p25, temp;
  private LocalDateTime datetime = new LocalDateTime();

  public void setDatetime(int year, int month, int day, int hour, int minute) {
    datetime.setYear(year);
    datetime.setMonth(month);
    datetime.setDay(day);
    datetime.setHour(hour);
    datetime.setMinute(minute);
  }

  public void setLocation(String a) {
    location = a;
  }

  public void setAqi(int a) {
    aqi = a;
  }

  public void setP25(int a) {
    p25 = a;
  }

  public void setTemp(int a) {
    temp = a;
  }

  public void setWeather(String a) {
    weather = a;
  }

  public String getDatetime() {
    return datetime.getYear() + "-" + ((datetime.getMonth()) < 10 ? "0": "") + datetime.getMonth() + "-" + ((datetime.getDay()) < 10 ? "0": "") + datetime.getDay() + " " + ((datetime.getHour()) < 10 ? "0": "") + datetime.getHour() + ":" + ((datetime.getMinute()) < 10 ? "0": "") + datetime.getMinute();
  }

  public String getLocation() {
    return location;
  }

  public int getAqi() {
    return aqi;
  }

  public int getP25() {
    return p25;
  }

  public int getTemp() {
    return temp;
  }

  public String getWeather() {
    return weather;
  }

  public void printAirQualityInfo() {
    System.out.println(location + " at " + getDatetime());
    System.out.println("AQI: " + aqi + ", PM2.5: " + p25 + "microgram/m3");
    System.out.println(temp + " celsius (" + weather + ")");
  }

  public void airCondition() {
    if(aqi > 300) {
      System.out.println("Hazardous");
    }
    else if(aqi > 200) {
      System.out.println("Very Unhealthy");
    }
    else if(aqi > 150) {
      System.out.println("Unhealthy");
    }
    else if(aqi > 100) {
      System.out.println("Unhealthy for Sensitive Groups");
    }
    else if(aqi > 50) {
      System.out.println("Moderate");
    }
    else {
      System.out.println("Good");
    }
  }

  public boolean isUnhealthy() {
    if(aqi > 100) {
      return true;
    }
    else {
      return false;
    }
  }

}
