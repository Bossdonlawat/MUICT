#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
int main(int argc, char const *argv[])
{
  int  a, b, c, e; // Use for selecting menu
  int discount;//Discount percent
  char d[20]; //Use for confirmation
  float sum_food, sum_drink, sum_discount_food, sum_discount_drink;
  int table_seat[10] = {2, 2, 2, 2, 4, 4 ,4 ,4, 8, 8}; // Number of seats on table n+1
  int table_occupied[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // For storing occupied table set 1 for occupied and 0 for empty
  int table_order_food[10][4]; // For storing quantity of food ordered ex. table 1 order 1 fried rice table_order_food[0][1] will equal 1
  int table_order_drink[10][3]; // For storing quantity of food ordered ex. table 6 order 1 coca cola table_order_drink[5][0] will equal 1
  int tmp_order_food[4]; // Temporary sotring order here ONLY ADD INTO table_order WHEN ORDER IS CONFIRMED ONLY!!!
  int tmp_order_drink[3]; // Temporary sotring order here ONLY ADD INTO table_order WHEN ORDER IS CONFIRMED ONLY!!!
  int tmp_cancel_food[4];// Temporary sotring cancel order here ONLY ADD INTO table_order WHEN ORDER IS CONFIRMED ONLY!!!
  int tmp_cancel_drink[3]; // Temporary sotring cancel order here ONLY ADD INTO table_order WHEN ORDER IS CONFIRMED ONLY!!!
  int save_food[4]={0, 0, 0, 0};//for end job
  int save_drink[3]={0, 0, 0};//for end job
  int save_table=0;//for end  job
  float save_money_food=0;//for end job
  float save_money_drink=0;//for end job
  int best_food[4]={0,0,0,0};//store most sold food
  int best_drink[3]={0,0,0};//store most sold drink
  int che=-1;//to check something [in end function]

  srand(time(NULL));//Random discount
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
  for (int i = 0 ; i < 4 ; i++)
    tmp_cancel_food[i] = 0;
  for (int i = 0 ; i < 3 ; i++)
    tmp_cancel_drink[i] = 0;

  // Intitialized

  goto main;
  main:
    printf("============================================================\n");
    printf("ICT Restaurant System\n");
    printf("============================================================\n");
    printf("[1] Book a table\n");
    printf("[2] Order food & drink\n");
    printf("[3] Display and clear a bill\n");
    printf("[4] Cancel order\n");
    printf("[0] Exit\n");

    printf("------------------------------------------------------------\n");
    printf("Enter the choice: ");
    a=99;
    scanf("%d", &a);
    fflush(stdin);
    //int atoi (a);
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
      case 4:
        goto cancel;
        break;
      case 0:
        goto end;
      default:
        goto main;
        break;
    }
  book:
    printf ("[Book a table]\n\n");
    b = -1;
    while (b <= 0) {
      printf ("Enter the number of people: ");
      b=99;
      scanf ("%d", &b);
      fflush(stdin);
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
    printf ("*Make sure you input the integer\n");

    c = -1;
    while (c != 0) {
      printf ("Enter a table number (input 0 to cancel): ");
      c=99;
      scanf ("%d", &c);
      fflush(stdin);
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
    while (b) {
      printf ("Enter the table number [1-10] (0 to exit): ");
      b=99;
      scanf ("%d", &b);
      fflush(stdin);
      if (b == 0) {
        system("@cls||clear");
        goto main;
      }
      if (b >= 0 && b <= 10) {
        if (table_occupied[b - 1])
          break;
        else {
          printf ("The table is not occupied.\n");
        }
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
    printf ("%61s", "*Please order one menu at a time*\n");
    printf ("------------------------------------------------------------\n");

    c = -1;
    while (c != 0) {
    printf ("Enter the choice (input 0 to stop): ");
      c=99;
      scanf ("%d", &c);
      fflush(stdin);
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
    printf ("%61s", "*Please order one menu at a time*\n");
    printf ("------------------------------------------------------------\n");
    c = -1;
    while (c != 0) {
      printf ("Enter the choice (input 0 to stop): ");
      c=99;
      scanf ("%d", &c);
      fflush(stdin);
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
    d[0]=0;
    printf ("\n");
    while (d[0] >= 0) {
      printf ("Confirm? (y|n): ");
      scanf(" %s",&d);
      fflush(stdin);
      if(d[1]=='\0'){
          if (d[0] == 121 || d[0] == 89) {
            for (int i = 0 ; i < 4 ; i++)
              table_order_food[b - 1][i] += tmp_order_food[i];
            for (int i = 0 ; i < 3 ; i++)
              table_order_drink[b - 1][i] += tmp_order_drink[i];
                 for (int i = 0 ; i < 4 ; i++){
              tmp_order_food[i]=0;

            }
            for (int i = 0 ; i < 3 ; i++){
              tmp_order_drink[i]=0;

            }
            system("@cls||clear");
            goto main;
          }
          else if (d[0] == 110 || d[0] == 78) {
             for (int i = 0 ; i < 4 ; i++){
              tmp_order_food[i]=0;

            }
            for (int i = 0 ; i < 3 ; i++){
              tmp_order_drink[i]=0;

            }

            system("@cls||clear");
            goto main;
          }
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
      b=99;
      scanf ("%d", &b);
      fflush(stdin);
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
    sum_food = 0;
    for (int i = 0 ; i < 4 ; i ++) {
      switch (i) {
        case 0:
          sum_food += table_order_food[b - 1][i] * 45.0;
          break;
        case 1:
          sum_food += table_order_food[b - 1][i] * 45.0;
          break;
        case 2:
          sum_food += table_order_food[b - 1][i] * 50.0;
          break;
        case 3:
          sum_food += table_order_food[b - 1][i] * 60.0;
          break;
      }
    }
    sum_drink = 0;
    for (int i = 0 ; i < 4 ; i ++) {
      switch (i) {
        case 0:
          sum_drink += table_order_drink[b - 1][i] * 20.0;
          break;
        case 1:
          sum_drink += table_order_drink[b - 1][i] * 30.0;
          break;
        case 2:
          sum_drink += table_order_drink[b - 1][i] * 10.0;
          break;
      }
    }
    printf ("** Total amount: %.2f", sum_food+sum_drink);
    d[0] = 0;
    printf ("\n");

    while (d[0] >= 0) {
      printf ("Do you want to clear the bill? (y|n): ");
      scanf(" %s",d);
      fflush(stdin);
      if(d[1]=='\0'){
          if (d[0] == 121 || d[0] == 89) {

          for(int i=0;i<4;i++){//save food when comfirm
            save_food[i]=save_food[i]+table_order_food[b-1][i];
          }
          for(int i=0;i<3;i++){
            save_drink[i]=save_drink[i]+table_order_drink[b-1][i];
          }
          save_table++;

            if(sum_food!=0||sum_drink!=0){ //discount feature
            discount = rand() % 11;
            sum_discount_food = (sum_food*(100-discount))/100;
            sum_discount_drink = (sum_drink*(100-discount))/100;

            //save money
            save_money_food = save_money_food + sum_discount_food;
            save_money_drink = save_money_drink + sum_discount_drink;

        if(discount!=0){
            printf("\n**You got %d%% discount**\n",discount);
            printf("Total amount is %.2f\n\n",sum_discount_food+sum_discount_drink);
            printf("Press any key to continue\n");
            getch();
                }
            }
            table_occupied[b - 1] = 0;
            for (int i = 0 ; i < 4 ; i++){
              tmp_order_food[i]=0;
              table_order_food[b - 1][i] = 0;
            }
            for (int i = 0 ; i < 3 ; i++){
              tmp_order_drink[i]=0;
              table_order_drink[b - 1][i] = 0;
            }
            system("@cls||clear");
            goto main;
          }
          else if (d[0] == 110 || d[0] == 78) {
            system("@cls||clear");
            goto main;
          }
        }
    }
  cancel:

    //select table
    printf ("[Cancel order]\n\nList of occupied tables:\n");
    for (int i = 0 ; i < 10 ; i++) {
      if (table_occupied[i])
        printf ("Table %d\n", i + 1);
    }
    printf ("\n");
    b = -1;
    while (b) {
      printf ("Enter the table number [1-10] (0 to exit): ");
      b=99;
      scanf ("%d", &b);
      fflush(stdin);
      if (b == 0) {
        system("@cls||clear");
        goto main;
      }
      if (b >= 0 && b <= 10) {
        if (table_occupied[b - 1])
          break;
        else {
          printf ("The table is not occupied.\n");
        }
      }
      else {
        printf ("Invalid Input\n");
      }
    }


    printf ("You have order following:\n"); //Show menu that you order
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

    printf ("%61s", "*Please cancel one menu at a time*\n");
    printf ("------------------------------------------------------------\n\n");


//cancel food
    c = -1;
        while (c != 0) {
        printf ("Enter the choice (input 0 to stop): ");
          c=99;
          scanf ("%d", &c);
          fflush(stdin);
              if (c == 0)
                break;
              else {
                if (c <= 0 || c > 4)
                  printf ("Invalid choice!\n");
                else if(tmp_cancel_food[c-1]<table_order_food[b-1][c-1])
                {
                  tmp_cancel_food[c - 1]++;
                }
          else printf("\n*ERROR cannot cancel the order\n\n");
              }
        }
//show drink that ordered
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

    printf ("%61s", "*Please cancel one menu at a time*\n");
    printf ("------------------------------------------------------------\n\n");
    //cancel drink
    c = -1;
        while (c != 0) {
        printf ("Enter the choice (input 0 to stop): ");
          c=99;
          scanf ("%d", &c);
          fflush(stdin);
              if (c == 0)
                break;
              else {
                if (c <= 0 || c > 3)
                  printf ("Invalid choice!\n");
                else if(tmp_cancel_drink[c-1]<table_order_drink[b-1][c-1])
                {
                  tmp_cancel_drink[c - 1]++;
                }
          else printf("\n*ERROR cannot cancel the order\n\n");
              }
        }
    //show order after cancel and ask permission
    system("@cls||clear");
    printf("Left order\n");
    printf ("------------------------------------------------------------");
    e=0;
    for (int i = 0 ; i < 4 ; i++) {
      if (table_order_food[b-1][i]-tmp_cancel_food[i] == 0)
        continue;
      else{
        e=1;
      switch (i) {
        case 0:
          printf ("\n[F] Kao Pad Kra Pao x%d", table_order_food[b-1][i]-tmp_cancel_food[i]);
          break;
        case 1:
          printf ("\n[F] Fried Rice x%d", table_order_food[b-1][i]-tmp_cancel_food[i]);
          break;
        case 2:
          printf ("\n[F] Kha Nar Mhoo Krob x%d", table_order_food[b-1][i]-tmp_cancel_food[i]);
          break;
        case 3:
          printf ("\n[F] Tom Yum Koong Nam Khon x%d", table_order_food[b-1][i]-tmp_cancel_food[i]);
          break;
        }
      }
    }

    for (int i = 0 ; i < 3 ; i++) {
      if (table_order_drink[b-1][i]-tmp_cancel_drink[i] == 0)
        continue;
      else {
            e=1;
      switch (i) {
        case 0:
          printf ("\n[D] Coca Cola x%d", table_order_drink[b-1][i]-tmp_cancel_drink[i]);
          break;
        case 1:
          printf ("\n[D] Orange Juice x%d", table_order_drink[b-1][i]-tmp_cancel_drink[i]);
          break;
        case 2:
          printf ("\n[D] Still Water x%d", table_order_drink[b-1][i]-tmp_cancel_drink[i]);
          break;
        }
      }
    }
    if(!e)
        printf("\nNone");
    printf ("\n------------------------------------------------------------");
    //ask permission
    d[0]=0;
    while (d[0] >= 0) {
      printf ("\n\nDo you want to confirm the cancel? (y|n): ");
      scanf(" %s", d);
      fflush(stdin);
      if(d[1]=='\0'){
          if (d[0] == 121 || d[0] == 89) {
            for (int i = 0 ; i < 4 ; i++){
                table_order_food[b-1][i] = table_order_food[b-1][i]-tmp_cancel_food[i];
                tmp_cancel_food[i]=0;

            }
            for (int i = 0 ; i < 3 ; i++){
                table_order_drink[b-1][i] = table_order_drink[b-1][i]-tmp_cancel_drink[i];
                tmp_cancel_drink[i]=0;
            }
            system("@cls||clear");
            goto main;
          }
          else if (d[0] == 110 || d[0] == 78) {
             for (int i = 0 ; i < 4 ; i++){
                tmp_cancel_food[i]=0;

            }
            for (int i = 0 ; i < 3 ; i++){
                tmp_cancel_drink[i]=0;
            }

            system("@cls||clear");
            goto main;
          }
      }
    }

  end:
    d[0]=0;
    while (d[0] >= 0) {//comfirmation
      printf ("Do you want to end the program? (y|n): ");
      scanf(" %s", d);
      fflush(stdin);
      if(d[1]=='\0'){

          if (d[0] == 121 || d[0] == 89) {//yes

              for(int i=0;i<10;i++)//check if there are still have table occu
              {
                  if(table_occupied[i]==1)
                  {
                      printf("\nWe still have a table that doesn't clear bill yet\n");
                      printf("Please check all of the bill first\n\n");
                      printf("Press any key to continue");
                      getch();

                      system("@cls||clear");
                      goto main;
                  }
              }

              for(int i=0;i<4;i++){//check most sold food
                  if(save_food[i]>che){
                      che=save_food[i];
                      best_food[0]=i;
                      best_food[1]=0;
                      best_food[2]=0;
                      best_food[3]=0;
                  }else if(save_food[i]==che&&che!=0){
                      if(best_food[1]==0){
                        best_food[1]=i;
                      }else if(best_food[2]==0){
                        best_food[2]=i;
                      }else if(best_food[3]==0){
                        best_food[3]=i;
                      }
                  }
              }
              che=-1;

              for(int i=0;i<3;i++){//check most sold drink
                  if(save_drink[i]>che){
                      che=save_drink[i];
                      best_drink[0]=i;
                      best_drink[1]=0;
                      best_drink[2]=0;
                  }
                  else if(save_drink[i]==che&&che!=0){
                    if(best_drink[1]==0){
                        best_drink[1]=i;
                      }else if(best_drink[2]==0){
                        best_drink[2]=i;
                      }
                  }
              }
              che=0;

              for(int i=0;i<4;i++){
                  if(save_food[i]==0){
                      che++;
                  }
              }

              if(best_food[1]!=0){
                  if(best_food[0]==0){ //print most sold food
                      printf("\nMost sold food is : [1] Kao Pad Kra Pao");
                  }else if(best_food[0]==1){
                      printf("\nMost sold food is : [2] Fried Rice");
                  }else if(best_food[0]==2){
                      printf("\nMost sold food is : [3] Kha Nar Mhoo Krob");
                  }else if(best_food[0]==3){
                      printf("\nMost sold food is : [4] Tom Yum Koong Nam Khon");
                  }
                  if(best_food[1]==1){
                      printf(" , [2] Fried Rice");
                  }else if(best_food[1]==2){
                      printf(" , [3] Kha Nar Mhoo Krob");
                  }else if(best_food[1]==3){
                      printf(" , [4] Tom Yum Koong Nam Khon");
                  }
                  if(best_food[2]==2){
                      printf(" , [3] Kha Nar Mhoo Krob");
                  }else if(best_food[2]==3){
                      printf(" , [4] Tom Yum Koong Nam Khon");
                  }if(best_food[3]==3){
                      printf(" , [4] Tom Yum Koong Nam Khon");
                  }

              }else if(che!=4){
                  if(best_food[0]==0){ //print most sold food
                      printf("\nMost sold food is : [1] Kao Pad Kra Pao");
                  }else if(best_food[0]==1){
                      printf("\nMost sold food is : [2] Fried Rice");
                  }else if(best_food[0]==2){
                      printf("\nMost sold food is : [3] Kha Nar Mhoo Krob");
                  }else if(best_food[0]==3){
                      printf("\nMost sold food is : [4] Tom Yum Koong Nam Khon");
                  }
              }else printf("\nMost sold food is : no food have sold yet");
              che=0;

              for(int i=0;i<3;i++){
                  if(save_drink[i]==0){
                      che++;
                  }
              }
               if(best_drink[1]!=0){
                  if(best_drink[0]==0){ //print most sold drink
                      printf("\nMost sold drink is: [1] Coca Cola");
                  }else if(best_drink[0]==1){
                      printf("\nMost sold drink is: [2] Orange Juice");
                  }else if(best_drink[0]==2){
                      printf("\nMost sold drink is: [3] Still Water");
                  }

                  if(best_drink[1]==1){
                      printf(" , [2] Orange Juice");
                  }else if(best_drink[1]==2){
                      printf(" , [3] Still Water");
                  }
                  if(best_drink[2]==2){
                      printf(" , [3] Still Water");
                  }
              }else if(che!=3){
                  if(best_drink[0]==0){ //print most sold drink
                      printf("\nMost sold drink is: [1] Coca Cola");
                  }else if(best_drink[0]==1){
                      printf("\nMost sold drink is: [2] Orange Juice");
                  }else if(best_drink[0]==2){
                      printf("\nMost sold drink is: [3] Still Water");
                  }
              }else printf("\nMost sold drink is : no drink have sold yet");



                printf("\n\nTotal money made: %.2f Baht\n",save_money_drink+save_money_food); //print total money made *already cal discount
                printf(">>From food : %.2f Baht\n",save_money_food); //print total money made from food *already cal discount
                printf(">>From drink: %.2f Baht\n\n",save_money_drink); //print total money made from drink *already cal discount

              printf("=========FOOD=========\n");
              if(save_food[0]>1){ //use if just to have right grammar
              printf("%-45s %d %-10s" ,"[1] Kao Pad Kra Pao  have a total of",save_food[0] ,"dishes serve\n");
              }else printf("%-45s %d %-10s" ,"[1] Kao Pad Kra Pao  have a total of",save_food[0] ,"dish serve\n");

              if(save_food[1]>1){
              printf("%-45s %d %-10s" ,"[2] Fried Rice  have a total of",save_food[1] ,"dishes serve\n");
              }else printf("%-45s %d %-10s" ,"[2] Fried Rice  have a total of",save_food[1] ,"dish serve\n");

              if(save_food[2]>1){
              printf("%-45s %d %-10s" ,"[3] Kha Nar Mhoo Krob  have a total of",save_food[2] ,"dishes serve\n");
              }else printf("%-45s %d %-10s" ,"[3] Kha Nar Mhoo Krob  have a total of", save_food[2], "dish serve\n");

              if(save_food[3]>1){
              printf("%-45s %d %-10s" ,"[4] Tom Yum Koong Nam Khon  have a total of",save_food[3] ,"dishes serve\n\n");
              }else printf("%-45s %d %-10s" ,"[4] Tom Yum Koong Nam Khon  have a total of",save_food[3] ,"dish serve\n\n");

              printf("=========DRINK========\n");
              if(save_drink[0]>1){
              printf("%-45s %d %-10s" ,"[1] Coca Cola  have a total of",save_drink[0] ,"cups serve\n");
              }else printf("%-45s %d %-10s" ,"[1] Coca Cola  have a total of",save_drink[0] ,"cup serve\n");

              if(save_drink[1]>1){
              printf("%-45s %d %-10s" ,"[2] Orange Juice  have a total of",save_drink[1] ,"cups serve\n");
              }else printf("%-45s %d %-10s" ,"[2] Orange Juice  have a total of",save_drink[1] ,"cup serve\n");

              if(save_drink[2]>1){
              printf("%-45s %d %-10s" ,"[3] Still Water  have a total of",save_drink[2] ,"cups serve\n\n");
              }else printf("%-45s %d %-10s" ,"[3] Still Water  have a total of",save_drink[2] ,"cup serve\n\n");


              if(save_table>1){
              printf("We have %d number of bills\n",save_table);
              }else printf("We have %d number of bill\n",save_table);

                break;
          }
          else if (d[0] == 110 || d[0] == 78) {//no
            system("@cls||clear");
            goto main;
          }
      }
    }

  return 0;
}
