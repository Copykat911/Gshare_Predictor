
#include "Gshare.h"                     // Holds variables

//  ╔╦╗┌─┐┬┌┐┌
//  ║║║├─┤││││
//  ╩ ╩┴ ┴┴┘└┘
//**********************************************************//
//         <argv[1]>     <argv[2]>        <argv[3]>         //
//   ./SIM     M             N          <TRACE_FILE>        //
//**********************************************************//
int main(int argc, char *argv[])
{
     open_file(argv);                        // Open file

     simulation_properties(argv);            // Set up M, N, etc.

     int M_TABLE[size_of_table];             // Table array

     init_table(M_TABLE);                    // Fill table with weakly taken
     
               // While the file is not empty, pull a line
     while(fscanf(fp, "%s %s", store_file_address,outcome) != EOF)
     {
          outcome_char = outcome[0];         // Put char from array into char var

          ++total_instructions;              // ++ instruction count

          hex_to_int();                      // Hex address -> int

          find_M_index();                    // Isolate M and XOR with GHB

          prediction = M_TABLE[M_index];     // Get the prediction from the index

          compare_outcome();                 // Compare indexed prediction with outcome

          M_TABLE[M_index] = prediction;     // Update prediction
     }

     fclose(fp);                             // Close file pointer

     misoutcome_ratio = (float)miss / (float)total_instructions;     // Calculate miss rate
     
     printf("%d\t %d\t %.2f%%\n", M, N, misoutcome_ratio*100);        // Print results
     
     return 0;                                                        // Exit Successfully
}
 
//  ╔═╗┬┌┬┐┬ ┬┬  ┌─┐┌┬┐┬┌─┐┌┐┌  ╔═╗┬─┐┌─┐┌─┐┌─┐┬─┐┌┬┐┬┌─┐┌─┐
//  ╚═╗│││││ ││  ├─┤ │ ││ ││││  ╠═╝├┬┘│ │├─┘├┤ ├┬┘ │ │├┤ └─┐
//  ╚═╝┴┴ ┴└─┘┴─┘┴ ┴ ┴ ┴└─┘┘└┘  ╩  ┴└─└─┘┴  └─┘┴└─ ┴ ┴└─┘└─┘
//**********************************************************
void simulation_properties(char **argv)
{
     if(argv[1] < 0 || argv[2] < 0)
          exit(0);                      // Exit if Args 1 & 2 are < 0	

     M    =    atoi(argv[1]);           // Store M

     N    =    atoi(argv[2]);           // Store N

     size_of_table 	=    pow(2, M);     // Find size of table
}

//  ╦═╗┌─┐┬  ┬┌─┐┬─┐┌─┐┌─┐  ╔═╗┌┬┐┌┬┐┬─┐┌─┐┌─┐┌─┐
//  ╠╦╝├┤ └┐┌┘├┤ ├┬┘└─┐├┤   ╠═╣ ││ ││├┬┘├┤ └─┐└─┐
//  ╩╚═└─┘ └┘ └─┘┴└─└─┘└─┘  ╩ ╩─┴┘─┴┘┴└─└─┘└─┘└─┘
//***********************************************
void create_reverse_array()
{
     int i = 30, j = 0;                                          // Declare counters

     for(j = 0; i>=0; --i)                                       // While i is above 0
     {
          if(store_file_address[i] != '\000')                    // If the data != NULL
          {
               reversed_file_address[j]=store_file_address[i];   // Store into new array

               ++j;                                              // Increase J counter
          }
     }
}

//  ╦ ╦┌─┐─┐ ┬  ┌┬┐┌─┐  ╦┌┐┌┌┬┐┌─┐┌─┐┌─┐┬─┐
//  ╠═╣├┤ ┌┴┬┘   │ │ │  ║│││ │ ├┤ │ ┬├┤ ├┬┘
//  ╩ ╩└─┘┴ └─   ┴ └─┘  ╩┘└┘ ┴ └─┘└─┘└─┘┴└─
//*****************************************
void hex_to_int()
{
     create_reverse_array();	// Reverse array for hex -> int conversion (Makes LSB index 0)
     
     int i = 0, j = 0, hold[17];
     unsigned long long int powerOfSixteen = 0,
                            temp = 0,
                            sum = 0;
     
     integer_Address = 0;

     char tempstr[17]={'\000'};
     int u = 16;
     
     // while(reversed_file_address[i] != '\000' [Not at the end])
     while(u != 0)
     {
          if(reversed_file_address[i] != '\000')
          {
               tempstr[i] = reversed_file_address[i];
               if ((int)tempstr[i] <= 57 && (int)tempstr[i] >= 48)
                    hold[i] = (int)tempstr[i] - 48;

               if ((int)tempstr[i] <= 102 && (int)tempstr[i] >= 97)
                    hold[i] = (int)tempstr[i] - 87;

               if ((int)tempstr[i] <= 70 && (int)tempstr[i] >= 65)
                    hold[i] = (int)tempstr[i] - 55;

               powerOfSixteen = (unsigned long int)pow(16, i);

               integer_Address += (hold[i] * powerOfSixteen);

               i++;
          }
     u--;
     }

     int o = 0;
     char m = '\000';

     while(o <19)
     {
          store_file_address[o] = '\000';
          o++;
     }
     o = 0;

     while (o <19)
     {
          reversed_file_address[o] = '\000';
          o++;
     }
}

//  ╦┌┐┌┬┌┬┐┬┌─┐┬  ┬┌─┐┌─┐  ┌┬┐┌─┐┌┐ ┬  ┌─┐
//  ║││││ │ │├─┤│  │┌─┘├┤    │ ├─┤├┴┐│  ├┤
//  ╩┘└┘┴ ┴ ┴┴ ┴┴─┘┴└─┘└─┘   ┴ ┴ ┴└─┘┴─┘└─┘
//*****************************************
void init_table(int *M_TABLE)
{
     for (int i = 0; i < size_of_table; i++)           // While counter < size of table
          M_TABLE[i] = 2;                              // Weakly taken
}

//  ┌─┐┌─┐┌┬┐┌─┐┌─┐┬─┐┌─┐   ┌─┐┬ ┬┌┬┐┌─┐┌─┐┌┬┐┌─┐
//  │  │ ││││├─┘├─┤├┬┘├┤    │ ││ │ │ │  │ ││││├┤
//  └─┘└─┘┴ ┴┴  ┴ ┴┴└─└─┘   └─┘└─┘ ┴ └─┘└─┘┴ ┴└─┘
//***********************************************
void compare_outcome()
{
     
          if(outcome_char == 't')                      // Outcome = T
          {
               if(prediction >= 2)                     // Prediction = T
               {
                    ++hit;                             // Add to hits
                    if(prediction != 3)                // Don't increase if 3
                         ++prediction;                 // Increase
               }
               else                                    // Prediction = N
               {
                    ++miss;                            // Add to misses
                    if(prediction != 3)                // Don't increase if 3
                         ++prediction;                 // Increase
               }
               GHB >>= 1;                              // Shift 1 -> GHB
               GHB += pow(2, N - 1);                   // Shift in 1 -> GHB
          }
          else                                         // Outcome = N
          {
               if (prediction >= 2)                    // Prediction = T
               {
                    ++miss;                            // Add to misses
                    if(prediction != 0)                // Don't decrease if 0
                         --prediction;                 // Decrease
               }
               else                                    // Prediction = N
               {
                    ++hit;                             // Add to hits
                    if(prediction != 0)                // Don't increase if above 3
                         --prediction;                 // Decrease
               }
               GHB >>= 1;                              // Shift in 0 -> GHB
          }
}

//  ╔═╗┬┌┐┌┌┬┐  ╔╦╗  ┬┌┐┌┌┬┐┌─┐─┐ ┬
//  ╠╣ ││││ ││  ║║║  ││││ ││├┤ ┌┴┬┘
//  ╚  ┴┘└┘─┴┘  ╩ ╩  ┴┘└┘─┴┘└─┘┴ └─
//*********************************
void find_M_index()
{
     integer_Address >>= 2;                            // Drop the offset

     isolated_M = integer_Address % size_of_table;	// Bring address down to M bits

     N_EXT = GHB << (M - N);                           // Shift the GHB

     M_index = N_EXT ^ isolated_M;                     // XOR operation

}

//  ╔═╗┌─┐┌─┐┌┐┌  ╔═╗┬┬  ┌─┐
//  ║ ║├─┘├┤ │││  ╠╣ ││  ├┤
//  ╚═╝┴  └─┘┘└┘  ╚  ┴┴─┘└─┘
//**************************
void open_file(char **argv)
{
    char* fname = argv[3];                             // Arg 3 is file name

     fp = fopen(fname, "r");
     
     if(fp == NULL)                                    // Could not open file
     {
          printf("Could not open file.\n");
          printf("Try entering the file name.");
          printf("If all else.\n");
          printf("Bring test case to executable dir\n");

          exit(0);                                     // Exit program, could not open file
     }
}