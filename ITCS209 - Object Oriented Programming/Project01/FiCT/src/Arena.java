import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.Arrays;

public class Arena {

  public enum Row {Front, Back};	//enum for specifying the front or back row
  public enum Team {A, B};		//enum for specifying team A or B

  private Player[][] teamA = null;	//two dimensional array representing the players of Team A
  private Player[][] teamB = null;	//two dimensional array representing the players of Team B
  private int numRowPlayers = 0;		//number of players in each row

  public static final int MAXROUNDS = 100;	//Max number of turn
  public static final int MAXEACHTYPE = 3;	//Max number of players of each type, in each team.
  private final Path logFile = Paths.get("battle_log.txt");

  private int numRounds = 0;	//keep track of the number of rounds so far

  /**
   * Constructor.
   * @param _numRowPlayers is the number of players in each row.
   */
  public Arena(int _numRowPlayers)
  {
    // Create 2 row position each have _numRowPlayers slot
    this.teamA = new Player[2][_numRowPlayers];
    this.teamB = new Player[2][_numRowPlayers];

    this.numRowPlayers = _numRowPlayers;

    ////Keep this block of code. You need it for initialize the log file.
    ////(You will learn how to deal with files later)
    try {
      Files.deleteIfExists(logFile);
    } catch (IOException e) {
      e.printStackTrace();
    }
    /////////////////////////////////////////

  }

  /**
   * Returns true if "player" is a member of "team", false otherwise.
   * Assumption: team can be either Team.A or Team.B
   * @param player
   * @param team
   * @return
   */
  public boolean isMemberOf(Player player, Team team)
  {
    boolean found = false;

    if (team.ordinal() == 0) {
      for (int i = 0 ; i < 2 ; i++) {
        for (int j = 0 ; j < this.teamA[0].length ; j++) {
          if (player.equals(teamA[i][j])) {
            found = true;
            break;
          }
        }
        if (found) {
          break;
        }
      }
    }

    return found;
  }



  /**
   * This methods receives a player configuration (i.e., team, type, row, and position),
   * creates a new player instance, and places him at the specified position.
   * @param team is either Team.A or Team.B
   * @param pType is one of the Player.Type  {Healer, Tank, Samurai, BlackMage, Phoenix}
   * @param row	either Row.Front or Row.Back
   * @param position is the position of the player in the row. Note that position starts from 1, 2, 3....
   */
  public void addPlayer(Team team, Player.PlayerType pType, Row row, int position)
  {
    // Separate team
    if (team == Team.A) {
      // Check is slot is empty
      if (this.teamA[row.ordinal()][position - 1] == null) {
        // Add player to slot
        this.teamA[row.ordinal()][position - 1] = new Player(pType);
      }
    } else {
      if (this.teamB[row.ordinal()][position - 1] == null) {
        this.teamB[row.ordinal()][position - 1] = new Player(pType);
      }
    }
  }


  /**
   * Validate the players in both Team A and B. Returns true if all of the following conditions hold:
   *
   * 1. All the positions are filled. That is, there each team must have exactly numRow*numRowPlayers players.
   * 2. There can be at most MAXEACHTYPE players of each type in each team. For example, if MAXEACHTYPE = 3
   * then each team can have at most 3 Healers, 3 Tanks, 3 Samurais, 3 BlackMages, and 3 Phoenixes.
   *
   * Returns true if all the conditions above are satisfied, false otherwise.
   * @return
   */
  public boolean validatePlayers()
  {
    // Add variable to scan each type
    int[] playA = {0, 0, 0, 0, 0, 0}, playB = {0, 0, 0, 0, 0, 0};

    for (int i = 0 ; i < this.numRowPlayers ; i++) {
      for (int j = 0 ; j < 2 ; j++) {
        playA[this.teamA[j][i].getType().ordinal()]++;
        playB[this.teamB[j][i].getType().ordinal()]++;
      }

      for (int j = 0 ; j < 2 ; j++) {
        if (this.teamA[j][i] == null || this.teamB[j][i] == null) {
          return false;
        }
      }
    }

    for (int i = 0 ; i < 6 ; i++) {
      if (playA[i] > this.MAXEACHTYPE || playB[i] > this.MAXEACHTYPE) {
        return false;
      }
    }

    return true;
  }


  /**
   * Returns the sum of HP of all the players in the given "team"
   * @param team
   * @return
   */
  public static double getSumHP(Player[][] team)
  {
    double sum = 0;

    for (int i = 0 ; i < team[0].length ; i++) {
      sum+= team[0][i].getCurrentHP();
      sum+= team[1][i].getCurrentHP();
    }

    return sum;
  }

  /**
   * Return the team (either teamA or teamB) whose number of alive players is higher than the other.
   *
   * If the two teams have an equal number of alive players, then the team whose sum of HP of all the
   * players is higher is returned.
   *
   * If the sums of HP of all the players of both teams are equal, return teamA.
   * @return
   */
  public Player[][] getWinningTeam()
  {
    if (aliveCount(this.teamA) == aliveCount(this.teamB)) {
      if (getSumHP(this.teamA) > getSumHP(this.teamB)) {
        return this.teamA;
      } else {
        return this.teamB;
      }
    } else if (aliveCount(this.teamA) > aliveCount(this.teamB)) {
      return this.teamA;
    } else {
      return this.teamB;
    }
  }

  /**
   * This method simulates the battle between teamA and teamB. The method should have a loop that signifies
   * a round of the battle. In each round, each player in teamA invokes the method takeAction(). The players'
   * turns are ordered by its position in the team. Once all the players in teamA have invoked takeAction(),
   * not it is teamB's turn to do the same.
   *
   * The battle terminates if one of the following two conditions is met:
   *
   * 1. All the players in a team has been eliminated.
   * 2. The number of rounds exceeds MAXROUNDS
   *
   * After the battle terminates, report the winning team, which is determined by getWinningTeam().
   */
  public void startBattle()
  {
    boolean isGameEnd = false;

    while (this.numRounds < 100) {
      System.out.println("\n@ Round " + this.numRounds+ ":");

      for (int i = 0 ; i < 2 ; i++) {
        for (int j = 0 ; j < this.numRowPlayers ; j++) {
          if (this.teamA[i][j].isAlive() && !this.teamA[i][j].isSleeping()) {
            this.teamA[i][j].takeAction(this);
            if (aliveCount(this.teamB) == 0) {
              isGameEnd = true;
              break;
            }
          }
        }
        if (isGameEnd) {
          break;
        }
      }

      if (!isGameEnd) {
        for (int i = 0 ; i < 2 ; i++) {
          for (int j = 0 ; j < this.numRowPlayers ; j++) {
            if (this.teamB[i][j].isAlive() && !this.teamB[i][j].isSleeping()) {
              this.teamB[i][j].takeAction(this);
              if(aliveCount(this.teamA) == 0) {
                isGameEnd = true;
                break;
              }
            }
          }
          if (isGameEnd) {
            break;
          }
        }

        System.out.println("");
        displayArea(this, true);
      }

      logAfterEachRound();

      this.numRounds++;
      if (isGameEnd) {
        break;
      }
    }

    System.out.println("");
    displayArea(this, true);
    logAfterEachRound();
  }

  // Other method created outside requirements
  public Player[][] getMyTeam(Player player) {
    if (isMemberOf(player, Team.A)) {
      return this.teamA;
    } else {
      return this.teamB;
    }
  }

  public Player[][] getOtherTeam(Player player) {
    if (isMemberOf(player, Team.A)) {
      return this.teamB;
    } else {
      return this.teamA;
    }
  }

  public int getRound() {
    return this.numRounds;
  }

  public int aliveCount(Player[][] team) {
    int alive = 0;

    for (int i = 0 ; i < 2 ; i++) {
      for(int j = 0 ; j < team[0].length ; j++) {
        if (team[i][j].isAlive()) {
          alive++;
        }
      }
    }

    return alive;
  }

  public Team getTeam(Player player) {
    if (isMemberOf(player, Team.A)) {
      return Team.A;
    } else {
      return Team.B;
    }
  }

  public int getCoordinateRow(Player player) {
    if (isMemberOf(player, Team.A)) {
      for (int i = 0 ; i < 2 ; i++) {
        for (int j = 0 ; j < this.teamA[0].length ; j++) {
          if (player.equals(this.teamA[i][j])) {
            return j + 1;
          }
        }
      }
    } else {
      for (int i=0 ; i < 2 ; i++) {
        for (int j=0 ; j < this.teamB[0].length ; j++) {
          if (player.equals(this.teamB[i][j])) {
            return j + 1;
          }
        }
      }
    }

    return 0;
  }

  public Row getCoordinateCol(Player player) {
    if (isMemberOf(player, Team.A)) {
      for (int i = 0 ; i < 2 ; i++) {
        for (int j = 0 ; j < this.teamA[0].length ; j++) {
          if (player.equals(this.teamA[i][j])) {
            if (i == 0) {
              return Row.Front;
            } else {
              return Row.Back;
            }
          }
        }
      }
    } else {
      for (int i = 0 ; i < 2 ; i++) {
        for (int j = 0 ; j < this.teamB[0].length ; j++) {
          if (player.equals(this.teamB[i][j])) {
            if (i == 0) {
              return Row.Front;
            } else {
              return Row.Back;
            }
          }
        }
      }
    }

    return Row.Front;
  }


  /**
   * This method displays the current area state, and is already implemented for you.
   * In startBattle(), you should call this method once before the battle starts, and
   * after each round ends.
   *
   * @param arena
   * @param verbose
   */
  public static void displayArea(Arena arena, boolean verbose)
  {
    StringBuilder str = new StringBuilder();
    if(verbose)
    {
      str.append(String.format("%43s   %40s","Team A","")+"\t\t"+String.format("%-38s%-40s","","Team B")+"\n");
      str.append(String.format("%43s","BACK ROW")+String.format("%43s","FRONT ROW")+"  |  "+String.format("%-43s","FRONT ROW")+"\t"+String.format("%-43s","BACK ROW")+"\n");
      for(int i = 0; i < arena.numRowPlayers; i++)
      {
        str.append(String.format("%43s",arena.teamA[1][i])+String.format("%43s",arena.teamA[0][i])+"  |  "+String.format("%-43s",arena.teamB[0][i])+String.format("%-43s",arena.teamB[1][i])+"\n");
      }
    }

    str.append("@ Total HP of Team A = "+getSumHP(arena.teamA)+". @ Total HP of Team B = "+getSumHP(arena.teamB)+"\n\n");
    System.out.print(str.toString());


  }

  /**
   * This method writes a log (as round number, sum of HP of teamA, and sum of HP of teamB) into the log file.
   * You are not to modify this method, however, this method must be call by startBattle() after each round.
   *
   * The output file will be tested against the auto-grader, so make sure the output look something like:
   *
   * 1	47415.0	49923.0
   * 2	44977.0	46990.0
   * 3	42092.0	43525.0
   * 4	44408.0	43210.0
   *
   * Where the numbers of the first, second, and third columns specify round numbers, sum of HP of teamA, and sum of HP of teamB respectively.
   */
  private void logAfterEachRound()
  {
    try {
      Files.write(logFile, Arrays.asList(new String[]{numRounds+"\t"+getSumHP(teamA)+"\t"+getSumHP(teamB)}), StandardOpenOption.APPEND, StandardOpenOption.CREATE);
    } catch (IOException e) {
      e.printStackTrace();
    }

  }

}
