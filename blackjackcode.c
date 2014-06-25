# include <stdio.h>
# include <stdlib.h>
# include <time.h>

//Function Prototypes
int Drawcard();
int Printhands();
int Blackjackcheck(int c);
int Hit();


//Declaring global variables
int Carddrawn=0, phcount=-1, i, count=0, pccount=-1, dccount=-1, dhcount=-1,
dcount = 0;
char hitorstay = 0;
char *hit = "H";
char *stay= "S";
int v=0;

//Declaring arrays
int b_array[52] = {0};
int d_array[52]={2,3,4,5,6,7,8,9,10,10,10,10,11,2,3,4,5,6,7,8,9,10,10,10,10,11,2,3,4,5,6,7,8,9,10,10,10,10,11,2,3,4,5,6,7,8,9,10,10,10,10,11,}; 
char *s_array[] = {"2H","3H","4H","5H","6H", "7H","8H","9H","10H","Jack H",
"Queen H","King H","Ace H", "2D","3D","4D","5D","6D",
"7D","8D","9D","10D","Jack D", "Queen D","King D","Ace D",
"2C","3C","4C","5C","6C", "7C","8C","9C","10C","Jack C", "Queen C","King C","Ace C", 
  "2S","3S","4S","5S","6S", "7S","8S","9S","10S","Jack S", "Queen S","King S","Ace S" };
int phand[12] = {0};
char *pcard[12] = {"0", "0","0","0","0","0","0","0","0","0","0","0"};
int dhand[12] = {0};
char *dcard[12] = {"0", "0","0","0","0","0","0","0","0","0","0","0"};


int main()
{
   printf("\n Blackjack Started!!! First Cards Dealt! \n");
   
/* **************************************************
            Player Draws 2 Cards
*/

   Carddrawn = Drawcard();
   b_array[Carddrawn] = 1;
   phcount++;
   pccount++;
   phand[phcount] = d_array[Carddrawn];
   pcard[pccount] = s_array[Carddrawn];
   count = count + phand[phcount];

   Carddrawn = Drawcard();
   b_array[Carddrawn] = 1;
   phcount++;
   pccount++;
   phand[phcount] = d_array[Carddrawn];
   pcard[pccount] = s_array[Carddrawn];
   count = count + phand[phcount];



   
/* ***************************************************
            Dealer draws 2 Cards
*/

   Carddrawn = Drawcard();
   b_array[Carddrawn] = 1;
   dhcount++;
   dccount++;
   dhand[dhcount] = d_array[Carddrawn];
   dcard[dccount] = s_array[Carddrawn];
   dcount = dcount + dhand[dhcount];

   Carddrawn = Drawcard();
   b_array[Carddrawn] = 1;
   dhcount++;
   dccount++;
   dhand[dhcount] = d_array[Carddrawn];
   dcard[dccount] = s_array[Carddrawn];
   dcount = dcount + dhand[dhcount];



   printf("\n \t Dealer \n\n");
   printf(" Card: \n");
   printf(" %s \n", dcard[0]);
   printf("\n Count: \n %d \n", dhand[0]);

   printf("\n \t Player \n\n");
   printf(" Cards: \n");
   printf(" %s \n", pcard[0]);
   printf(" %s \n", pcard[1]);
   printf("\n Count: \n %d \n", phand[0]+phand[1]);
   
   /* *********************************************
                Check if you hit Blackjack
   */

   Blackjackcheck(count);
  

if(count!=21)
   {
      


//  ***********  Begin Hit or Stay Loop ***********************

   while(hitorstay != *stay)
{
          printf("\n Do you want to Hit or Stay? \n");
          printf(" Enter H for hit and S for stay \n");
      
         scanf("%c", &hitorstay);

     if(hitorstay==*hit)
      {
           printf(" Hit! \n\n");
        Hit();
       

                if(count>21)
                   break;

            printf("\n \t Dealer \n\n");
            printf(" Card: \n");
               printf(" %s \n", dcard[0]);
            printf("\n Count: \n %d \n", dhand[0]);
        
            printf("\n \t Player \n\n");
           printf(" Cards: \n");
             phcount=0;
        
    int h;

          for ( h=0; h<=pccount; h++)
               {  
                  printf(" %s   \n", pcard[phcount]); 
                  phcount++;
                }
          printf("\n Count: \n %d \n\n", count);
      }
  
     if(hitorstay==*stay)
        {
            printf(" Stay \n\n");
            break;
        }


      if(hitorstay!=*hit && hitorstay!=*stay)
         printf("\n Error! Choose Again! \n\n");
      
      getchar();

    
   }  
// ********* Out of HitStay End of Game ****************************


//********** Dealer Hits Until He is Between 17 and 21 *********

       while(dcount<17 )
    {
      dHit();
    }


/* ********** As long as no one busts, it prints the hands of both players ****/

      if(count<=21)
          Printhands();


    }
/* ****** This is the display if you bust.  It doesn't show the  ***********
          dealers other cards.  Just like in real blackjack. */
    
   if (count>21)
     {
       
       
       printf("\n \t Dealer \n\n");
       printf(" Card: \n");
       printf(" %s \n", dcard[0]);
       printf("\n Count: \n %d \n", dhand[0]);

       printf("\n \t Player \n\n");
       printf(" Cards: \n");
       phcount=0;

        int e;
         for ( e=0; e<=pccount; e++)
           {  
             printf(" %s   \n", pcard[phcount]); 
             phcount++;
           } 

       printf("\n Count: \n %d \n", count);
       printf("\n\n Bust!! You lose.\n");
     }
     



// ******** Checks if Dealer Bust ****************
     
    if(count<=21)
      {
        if (dcount>21)
        printf("\n\n Dealer Bust!! You win! \n");
       }

// ****** Compares Cards to See who wins ***********

    if(count<=21 && dcount<=21 )
      {
        if(count>dcount)
           printf("\n YOU WIN!!! \n");

        if(dcount>count)
           printf("\n You Lose \n");

        if(count==dcount)
           printf("\n Push!!!  You Draw.\n");
      }



   return 0;
}


//             Function Definitions
/*
******************************************************
*******************************************************
*********************************************************
*/
int Drawcard() {
   
  int i = 0;

  srand(time(NULL));
  i = rand() % 52;

  while( b_array[i] == 1)
    {
       i = rand() % 52;

       if(b_array[i] ==0)
          {
            break;
          }
    }
  return i;
}

// *************************************************************

int Blackjackcheck( int c)
{
  if(c==21)
{   

  // Display dealers cards and check for a draw
    
    Printhands();
    printf("\n Blackjack!!! \n");
    
    if (dcount==count)
       printf(" Push!!! You draw. ");


    
}
  return 0;
}



// ***************************************************************
int Printhands()
{  
   int f, e;

  printf("\n \t Dealer \n\n");
   printf(" Cards: \n");
  dhcount=0;

for ( f=0; f<=dccount; f++)
  {
   
   printf(" %s   \n", dcard[dhcount]); 
   dhcount++;
  }

  printf("\n Count: \n %d \n", dcount);

  printf("\n \t Player \n\n");
   printf(" Cards: \n");
  phcount=0;

for ( e=0; e<=pccount; e++)
  {  
   printf(" %s   \n", pcard[phcount]); 
   phcount++;
  }

  printf("\n Count: \n %d \n", count);
  return 0;
}

// ***************************************************************************

int Hit()
{
   Carddrawn = Drawcard();
   b_array[Carddrawn] = 1;
   phcount++;
   pccount++;
   phand[phcount] = d_array[Carddrawn];
   pcard[pccount] = s_array[Carddrawn];
   count = count + phand[phcount];
   
   
             if(count>21)
                {
                  int w;
                  for(w=0; w<=11; w++)
                  {
                   if(phand[w] == 11 )   
                      {
                         phand[w] = 1;
                         count = phand[0]+ phand[1]+phand[2]+phand[3]+ phand[4]+phand[5]+ phand[6]+phand[7]+  phand[8]+phand[9]+phand[10]+ phand[11];                       }                   }            
                }
                 

}

int dHit()
{
   Carddrawn = Drawcard();
   b_array[Carddrawn] = 1;
   dhcount++;
   dccount++;
   dhand[dhcount] = d_array[Carddrawn];
   dcard[dccount] = s_array[Carddrawn];
   dcount = dcount + dhand[dhcount];
  
   if(count>21)
                {
                  int n;
                  for(n=0; n<=11; n++)
                  {
                   if(dhand[n] == 11 )   
                      {
                         dhand[n] = 1;
                         dcount = dhand[0]+ dhand[1]+dhand[2]+dhand[3]+ dhand[4]+dhand[5]+ dhand[6]+dhand[7]+  dhand[8]+dhand[9]+dhand[10]+ dhand[11];
                      }                  
                  }              

                }
}
