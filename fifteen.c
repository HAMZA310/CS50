/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc , string argv[])      
{
   //  ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}



/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
 //   printf("\033[04;31");
    
}



/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}




/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{

      int incr = 1;
      for (int row_Init = 0; row_Init< d; row_Init++)
      {
          for (int col_Init = 0; col_Init < d; col_Init++)
          {
              if ((row_Init==d-1) && (col_Init==d-1))
              {
                  board[row_Init][col_Init] = -1;
                  break;
              }
             
              //if the number of tiles is odd, swap 1 and 2.
              else if ((d == 4 || d == 6 || d == 8) && ((row_Init == d-1) && (col_Init == d-3)) )   
              {
                  board[d-1][d-2] = 2;
                  board[d-1][d-3] = 1;
                  
                  continue;
              }
              
              //Initialiing...
              board[row_Init][col_Init] = d*d-incr;
              incr = incr+1;
              
          }
                                    
      }
     
   
}





/**
 * Prints the board in its current state.
 */
void draw(void)
{
    
   
    for (int draw_row = 0; draw_row < d; draw_row++)
    {
        for (int draw_col = 0; draw_col < d; draw_col++)
      {
           
           if (board[draw_row][draw_col] == -1) 
             {

                  // hides -1 behind underscore
                  printf("   _");
                  continue;
         
             }
             
             
       //prints numbers  
       printf("  %2i", board[draw_row][draw_col]);
      
          
      }
      
    printf("\n\n");
    
        
    }
    
    
}




/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile) 
{
   
   //finding the index of tile...
    int indexrow, indexcol;
    
    for (int move_row = 0; move_row < d ; move_row++)
   {
       
         for (int move_col = 0; move_col < d; move_col++)
        
         if( tile == board[move_row][move_col])
         {
         indexrow = move_row ;
         indexcol = move_col ;
         break;
         }
         
   }
  
  
 
  //To avoid segmentation fault: if input tile is not in the board. 
  if ((indexrow>d) || (indexcol>d))
  return false;
  
 
 
  //SWAPPING...
  
  if ((board[indexrow +1][indexcol]) == -1)
  {
      int temp = board[indexrow][indexcol];  //actually there are 0's everywhere
      board[indexrow][indexcol] = board[indexrow +1][indexcol];
      board[indexrow +1][indexcol] = temp;
      return true;
  }
  
   else if ((board[indexrow - 1][indexcol]) == -1)
  {
      int temp = board[indexrow][indexcol];
      board[indexrow][indexcol] = board[indexrow -1][indexcol];
      board[indexrow -1][indexcol] = temp;
      return true;
  }
  
   else if ((board[indexrow ][indexcol + 1]) == -1)
  {
      int temp = board[indexrow][indexcol];
      board[indexrow][indexcol] = board[indexrow][indexcol + 1]; //here tile is assigned 0, and vanishes. 
      board[indexrow][indexcol + 1] = temp;
      return true;
  }
  
   else if ((board[indexrow ][indexcol - 1]) == -1)
  {
      int temp = board[indexrow][indexcol ];
      board[indexrow][indexcol] = board[indexrow ][indexcol - 1];
      board[indexrow][indexcol - 1] = temp;
      return true;
  }
             
  else 
  {
      return false;
  }
   
}



/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
 

    for ( int won_row = 0; won_row < d-1; won_row++ )
    {
    
             for( int won_col = 0; won_col < d-1; won_col++) 
        {
    
            //appropriate conditions to ensure true is returned only if game is won
            if (((board[won_row][won_col + 1]) < (board[won_row][won_col] +1 )) || (board[won_row+1][won_col] != (board[won_row][won_col] + d)) || (board[d-1][d-1] != -1))    
            return false;
     
        }
    
    
    }

return true;

}