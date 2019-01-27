import java.time.*;

public class AirQualityProfile {
  private String location, weather;
  private int aqi, p25, temp;
  private LocalDateTime datetime;

  public void setDatetime(LocalDateTime a) {
    datetime = a;
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

  public LocalDateTime getDatetime() {
    return datetime;
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
    System.out.println(getLocation() + " at " + getDatetime());
    System.out.println("AQI: " + getAqi() + ", PM2.5: " + getP25() + "microgram/m3");
    System.out.println(getTemp() + " celsius (" + getWeather() + ")");
    // System.out.println("Is unhealthy?: " + isUnhealthy());
    // System.out.println("Overall:" + airCondition());
  }

  public String airCondition() {
    if(aqi > 300) {
      return "Hazardous";
    }
    else if(aqi > 200) {
      return "Very Unhealthy";
    }
    else if(aqi > 150) {
      return "Unhealthy";
    }
    else if(aqi > 100) {
      return "Unhealthy for Sensitive Groups";
    }
    else if(aqi > 50) {
      return "Moderate";
    }
    else {
      return "Good";
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
