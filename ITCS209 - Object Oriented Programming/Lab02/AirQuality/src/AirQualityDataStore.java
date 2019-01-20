public class AirQualityDataStore {
  static int profileCount = 0;
  public static void main(String args[]) {
    AirQualityProfile location1 = new AirQualityProfile();
    profileCount++;
    AirQualityProfile location2 = new AirQualityProfile();
    profileCount++;

    location1.setDatetime(2019, 1, 21, 1, 0);
    location1.setLocation("Krathum Baen");
    location1.setAqi(160);
    location1.setP25(72);
    location1.setTemp(26);
    location1.setWeather("Few Clouds");

    location2.setDatetime(2019, 1, 21, 2, 0);
    location2.setLocation("Sukumvit 28 Alley");
    location2.setAqi(164);
    location2.setP25(81);
    location2.setTemp(26);
    location2.setWeather("Few Clouds");

    location1.printAirQualityInfo();
    location2.printAirQualityInfo();
  }
}
