import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class SimpleMovieDatabase {
  public Map<Integer, Movie> movies = null;

  public void importMovies(String movieFilename)
  {
    this.movies = new HashMap<Integer, Movie>();
    File file = new File(movieFilename);
    try {
      BufferedReader bufferedReader = new BufferedReader(new FileReader(file));

      String line;

      while((line = bufferedReader.readLine()) != null) {
        String chunks[] = line.split(",");

        // Check for valid input
        if (chunks.length == 3) {
          if (chunks[1].length() == 1 && chunks[1].contains(" ")) {
            continue;
          }
          int key = Integer.parseInt(chunks[0]);
          String title = chunks[1];
          String[] tags = chunks[2].replace("|", ",").split(",");

          this.movies.put(key, new Movie(key, title));

          for (String tag: tags) {
            this.movies.get(key).tags.add(tag);
          }
        }
      }

      bufferedReader.close();
    } catch(IOException e) {
      e.printStackTrace();
    }
  }


  //-------------------BONUS----------------------
  public List<Movie> searchMovies(String query)
  {
    List<Movie> res = new ArrayList<Movie>();
    for (Integer key: this.movies.keySet()) {
      if (this.movies.get(key).title.toLowerCase().contains(query.toLowerCase())){
        res.add(this.movies.get(key));
      }
    }
    return res;
  }

  public List<Movie> getMoviesByTag(String tag)
  {
    List<Movie> res = new ArrayList<Movie>();
    for (Integer key: this.movies.keySet()) {
      if (this.movies.get(key).tags.contains(tag)) {
        res.add(this.movies.get(key));
      }
    }
    return res;
  }


  public static void main(String[] args)
  {
    SimpleMovieDatabase mdb = new SimpleMovieDatabase();
    mdb.importMovies("lab10_movies.txt");
    System.out.println("Done importing "+mdb.movies.size()+" movies");
    int[] mids = new int[]{139747, 141432, 139415, 139620, 141305};
    for(int mid: mids)
    {
      System.out.println("Retrieving movie ID "+mid+": "+mdb.movies.get(mid));
    }

    //Uncomment for bonus
		System.out.println("\n////////////////////////// BONUS ///////////////////////////////");
		String[] queries = new String[]{"america", "thai", "thailand"};
		for(String query: queries)
		{
			System.out.println("Results for movies that match: "+query);
			for(Movie m: mdb.searchMovies(query))
			{
				System.out.println("\t"+m);
			}
			System.out.println();
		}
		
		String[] tags = new String[]{"Musical", "Action", "Thriller"};
		for(String tag: tags)
		{
			System.out.println("Results for movies in category: "+tag);
			for(Movie m: mdb.getMoviesByTag(tag))
			{
				System.out.println("\t"+m);
			}
			System.out.println();
		}

  }

}
