#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
  int a, b, c, e; // Use for selecting menu
  char d; //Use for confirmation
  float sum;
  int table_seat[10] = {2, 2, 2, 2, 4, 4 ,4 ,4, 8, 8}; // Number of seats on table n+1
  int table_occupied[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // For storing occupied table set 1 for occupied and 0 for empty
  int table_order_food[10][4]; // For storing quantity of food ordered ex. table 1 order 1 fried rice table_order_food[0][1] will equal 1
  int table_order_drink[10][3]; // For storing quantity of food ordered ex. table 6 order 1 coca cola table_order_drink[5][0] will equal 1
  int tmp_order_food[4]; // Temporary sotring order here ONLY ADD INTO table_order WHEN ORDER IS CONFIRMED ONLY!!!
  int tmp_order_drink[3]; // Temporary sotring order here ONLY ADD INTO table_order WHEN ORDER IS CONFIRMED ONLY!!!

  // Intitialize
  for (int i = 0 ; i < 10 ; i++) {
    for (int j = 0 ; j < 4 ; j++)
      table_order_food[i][j] = 0;
    for (int j = 0 ; j < 3 ; j++)
      table_order_drink[i][j] = 0;
  }
  for (int i = 0 ; i < 4 ; i++)
    tmp_order_food[i] = 0;
  for (int i = 0 ; i < 3 ; i++)
    tmp_order_drink[i] = 0;
  // Intitialized

  goto main;
  main:
    printf("============================================================\n");
    printf("ICT Restaurant System\n");
    printf("============================================================\n");
    printf("[1] Book a table\n");
    printf("[2] Order food & drink\n");
    printf("[3] Display and clear a bill\n");
    printf("[0] Exit\n");
    printf("------------------------------------------------------------\n");
    printf("Enter the choice: ");
    scanf("%d", &a);
    system("@cls||clear");
    switch (a) {
      case 1:
        goto book;
        break;
      case 2:
        goto order;
        break;
      case 3:
        goto bill;
        break;
      case 0:
        goto end;
      default:
        goto main;
    }
  book:
    printf ("[Book a table]\n\n");
    b = -1;
    while (b <= 0) {
      printf ("Enter the number of people: ");
      scanf ("%d", &b);
    }
    printf ("============================================================\n");
    printf ("%-45s%s", "List of tables", "Status");
    printf ("\n============================================================\n");
    for (int i = 0 ; i < 10 ; i++) {
      printf ("%-6s%-2d%-2s%-2d%-33s" ,"Table", i + 1,": ", table_seat[i],"seats");
      if (table_occupied[i])
        printf ("Occupied");
      else if (table_seat[i] < b)
        printf ("Not enough seat");
      else
        printf ("Available");
      printf ("\n");
    }
    c = -1;
    while (c != 0) {
      printf ("Enter a table number (input 0 to cancel): ");
      scanf ("%d", &c);
      if (c == 0) {
        system("@cls||clear");
        goto main;
      }
      else if (c < 0 || c > 10)
        printf ("Invalid choice\n");
      else if (table_occupied[c - 1])
        printf ("Please enter the available table.\n");
      else if (table_seat[c - 1] < b)
        printf ("Not enough seat\n");
      else {
        table_occupied[c - 1] = 1;
        system("@cls||clear");
        goto main;
      }
    }
  order:
    printf ("[Order food & drink]\n\nList of occupied tables:\n");
    for (int i = 0 ; i < 10 ; i++) {
      if (table_occupied[i])
        printf ("Table %d\n", i + 1);
    }
    printf ("\n");
    b = -1;
    while (b < 0 || b > 10) {
      printf ("Enter the table number [1-10] (0 to exit): ");
      scanf ("%d", &b);
      if (b == 0) {
        system("@cls||clear");
        goto main;
      }
      if (b >= 0 && b <= 10) {
        if (table_occupied[b - 1])
          break;
        else
          printf ("This table is not occupied\n");
      }
      else {
        printf ("Invalid Input\n");
      }
    }
    printf ("============================================================\n");
    printf ("Order food & drink\n");
    printf ("============================================================\n\n");
    printf ("%-46s%s", "Food Menu", "Price (Baht)\n");
    printf ("------------------------------------------------------------\n");
    printf ("%-46s%s", "[1] Kao Pad Kra Pao", "45.0\n");
    printf ("%-46s%s", "[2] Fried Rice", "45.0\n");
    printf ("%-46s%s", "[3] Kha Nar Mhoo Krob", "50.0\n");
    printf ("%-46s%s", "[4] Tom Yum Koong Nam Khon", "60.0\n");
    printf ("------------------------------------------------------------\n");
    c = -1;
    while (c != 0) {
      printf ("Enter the choice (input 0 to stop): ");
      scanf ("%d", &c);
      if (c == 0)
        break;
      else {
        if (c <= 0 || c > 4)
          printf ("Invalid choice!\n");
        else
          tmp_order_food[c - 1]++;
      }
    }
    printf ("%-46s%s", "Drink Menu", "Price (Baht)\n");
    printf ("------------------------------------------------------------\n");
    printf ("%-46s%s", "[1] Coca Cola", "20.0\n");
    printf ("%-46s%s", "[2] Orange Juice", "30.0\n");
    printf ("%-46s%s", "[3] Still Water", "10.0\n");
    printf ("------------------------------------------------------------\n");
    c = -1;
    while (c != 0) {
      printf ("Enter the choice (input 0 to stop): ");
      scanf ("%d", &c);
      if (c == 0)
        break;
      else {
        if (c <= 0 || c > 3)
          printf ("Invalid choice!\n");
        else
          tmp_order_drink[c - 1]++;
      }
    }
    printf ("\nYou have order the following:");
    for (int i = 0 ; i < 4 ; i++) {
      if (tmp_order_food[i] == 0)
        continue;
      switch (i) {
        case 0:
          printf ("\n[F] Kao Pad Kra Pao x%d", tmp_order_food[i]);
          break;
        case 1:
          printf ("\n[F] Fried Rice x%d", tmp_order_food[i]);
          break;
        case 2:
          printf ("\n[F] Kha Nar Mhoo Krob x%d", tmp_order_food[i]);
          break;
        case 3:
          printf ("\n[F] Tom Yum Koong Nam Khon x%d", tmp_order_food[i]);
          break;
      }
    }
    for (int i = 0 ; i < 3 ; i++) {
      if (tmp_order_drink[i] == 0)
        continue;
      switch (i) {
        case 0:
          printf ("\n[D] Coca Cola x%d", tmp_order_drink[i]);
          break;
        case 1:
          printf ("\n[D] Orange Juice x%d", tmp_order_drink[i]);
          break;
        case 2:
          printf ("\n[D] Still Water x%d", tmp_order_drink[i]);
          break;
      }
    }
    d = 0;
    printf ("\n");
    while (d >= 0) {
      printf ("Confirm? (y|n): ");
      scanf(" %c", &d);
      if (d == 121 || d == 89) {
        for (int i = 0 ; i < 4 ; i++)
          table_order_food[b - 1][i] = tmp_order_food[i];
        for (int i = 0 ; i < 3 ; i++)
          table_order_drink[b - 1][i] = tmp_order_drink[i];
        system("@cls||clear");
        goto main;
      }
      else if (d == 110 || d == 78) {
        system("@cls||clear");
        goto main;
      }
    }
  bill:
    printf ("[Display and clear a bill]\n\nList of occupied tables:\n");
    for (int i = 0 ; i < 10 ; i++) {
      if (table_occupied[i])
        printf ("Table %d\n", i + 1);
    }
    printf ("\n");
    b = -1;
    while (b < 0 || b > 10) {
      printf ("Enter the table number [1-10] (0 to exit): ");
      scanf ("%d", &b);
      if (b == 0) {
        system("@cls||clear");
        goto main;
      }
      if (b >= 0 && b <= 10) {
        if (table_occupied[b - 1])
          break;
        else {
          printf ("There is no one sitting at the table.\nPress Enter to go back to the main menu.\n");
          getch();
          system("@cls||clear");
          goto main;
        }
      }
      else {
        printf ("Invalid Input\n");
      }
    }
    printf ("You have order following:\n");
    printf ("%-38s%-7s%s", "Food Menu", "Qty.", "Price (Baht)\n");
    printf ("------------------------------------------------------------\n");
    e = 0;
    for (int i = 0 ; i < 4 ; i ++) {
      if (table_order_food[b - 1][i] == 0)
        continue;
      else {
        e = 1;
        switch (i) {
          case 0:
            printf ("%-38s%-7d%.1f", "[1] Kao Pad Kra Pao", table_order_food[b - 1][i], table_order_food[b - 1][i] * 45.0);
            break;
          case 1:
            printf ("%-38s%-7d%.1f", "[2] Fried Rice", table_order_food[b - 1][i], table_order_food[b - 1][i] * 45.0);
            break;
          case 2:
            printf ("%-38s%-7d%.1f", "[3] Kha Nar Mhoo Krob", table_order_food[b - 1][i], table_order_food[b - 1][i] * 50.0);
            break;
          case 3:
            printf ("%-38s%-7d%.1f", "[4] Tom Yum Koong Nam Khon", table_order_food[b - 1][i], table_order_food[b - 1][i] * 60.0);
            break;
        }
        printf ("\n");
      }
    }
    if (!e)
      printf ("None\n");
    printf ("------------------------------------------------------------\n\n");
    printf ("%-38s%-7s%s", "Drink Menu", "Qty.", "Price (Baht)\n");
    printf ("------------------------------------------------------------\n");
    e = 0;
    for (int i = 0 ; i < 3 ; i ++) {
      if (table_order_drink[b - 1][i] == 0)
        continue;
      else {
        e = 1;
        switch (i) {
          case 0:
            printf ("%-38s%-7d%.1f", "[1] Coca Cola", table_order_drink[b - 1][i], table_order_drink[b - 1][i] * 20.0);
            break;
          case 1:
            printf ("%-38s%-7d%.1f", "[2] Orange Juice", table_order_drink[b - 1][i], table_order_drink[b - 1][i] * 30.0);
            break;
          case 2:
            printf ("%-38s%-7d%.1f", "[3] Still Water", table_order_drink[b - 1][i], table_order_drink[b - 1][i] * 10.0);
            break;
        }
        printf ("\n");
      }
    }
    if (!e)
      printf ("None\n");
    printf ("------------------------------------------------------------\n\n");
    sum = 0;
    for (int i = 0 ; i < 4 ; i ++) {
      switch (i) {
        case 0:
          sum += table_order_food[b - 1][i] * 45.0;
          break;
        case 1:
          sum += table_order_food[b - 1][i] * 45.0;
          break;
        case 2:
          sum += table_order_food[b - 1][i] * 50.0;
          break;
        case 3:
          sum += table_order_food[b - 1][i] * 60.0;
          break;
      }
    }
    for (int i = 0 ; i < 4 ; i ++) {
      switch (i) {
        case 0:
          sum += table_order_drink[b - 1][i] * 20.0;
          break;
        case 1:
          sum += table_order_drink[b - 1][i] * 30.0;
          break;
        case 2:
          sum += table_order_drink[b - 1][i] * 10.0;
          break;
      }
    }
    printf ("** Total amount: %.2f", sum);
    d = 0;
    printf ("\n");
    while (d >= 0) {
      printf ("Do you want to clear the bill? (y|n): ");
      scanf(" %c", &d);
      if (d == 121 || d == 89) {
        table_occupied[b - 1] = 0;
        for (int i = 0 ; i < 4 ; i++)
          table_order_food[b - 1][i] = 0;
        for (int i = 0 ; i < 3 ; i++)
          table_order_drink[b - 1][i] = 0;
        system("@cls||clear");
        goto main;
      }
      else if (d == 110 || d == 78) {
        system("@cls||clear");
        goto main;
      }
    }
  end:
  return 0;
}