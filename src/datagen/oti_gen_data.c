#include<oti/core.h>
#include <getopt.h>

static uint8_t maxorder = 1;
static uint16_t m_set   = 1;
static uint8_t o_start = 1;
static uint8_t o_end   = 1;
static uint16_t bases[150];

char directory[1024]="";

void set_nbasis(uint8_t start, uint8_t end,uint16_t set){

  int i;
  // printf("In set_nbasis\n");
  // printf("Order start: %"PRIu8", Order end: %"PRIu8" \n",start,end);
  if( start != 0 && end !=0){
    for(i=start-1;i<end;i++){
      bases[i]=set;
    }
  }
  o_start = 0;
  o_end   = 0;

}

void print_setup(void){
  printf("  == directory: %s\n",directory);
  printf("  == o_start  : %hhu\n",o_start);
  printf("  == o_end    : %hhu\n",o_end);
  printf("  == m_set    : %hu \n",m_set);
  printf("  == maxorder : %hhu\n",maxorder);
}

void print_basis(void){
  int i;
  printf("Precomputation of following OTI algebra: \n");
  for(i=0;i<maxorder;i++){
    printf(" Order: %3d, nbasis: %"PRIu16"\n",i+1,bases[i]);
  }

}

// Define the options:
// const char *name
// int has_arg
// int *flag
// int val

static struct option long_options[] =
{
  /* These options don’t set a flag.
     We distinguish them by their indices. */
  {"directory",required_argument, 0, 'd'},
  {"order",    required_argument, 0, 'o'},
  {"maxorder", required_argument, 0, 'o'},
  {"os",       required_argument, 0, 's'},
  {"of",       required_argument, 0, 'f'},
  {"m",        required_argument, 0, 'm'},
  {"bases",    required_argument, 0, 'm'},
  {0, 0, 0, 0}
};

int main (int argc, char **argv){
  
  int c;


  // printf("The values of printing formats are the following:\n");
  // printf("PRIu8 : \""PRIu8"\"\n");
  // printf("PRIu16: \""PRIu16 "\"\n");
  // printf("PRIu32: \""PRIu32 "\"\n");
  // printf("PRIu64: \""PRIu64 "\"\n\n");
  // printf("Got %d inputs\n",argc);
  // printf("Reading the inputs now:\n");

  while (1)  {
      
      /* getopt_long stores the option index here. */
      int option_index = 0;

      c = getopt_long (argc, argv, "a:d:s:f:m:o:",
                       long_options, &option_index);

      
      /* Detect the end of the options. */
      if (c == -1){
        break;
      }

      // printf("  c is: (%c,%d) with option_index %d\n", c,c,option_index);
      // printf("\nRead a valid argv: (%c,%d)\n", c,c);
      

      switch (c){
        case 'd':
          strcpy(directory,optarg);
          // printf("  Setting directory name \"%s\"\n",directory);
          // print_setup();
          break;

        case 'o':
          sscanf(optarg,"%hhu",&maxorder);
          // printf("    Setting maximum truncation order to %"PRIu8"\n",maxorder);
          // printf("  Setting maximum truncation order to %hhu\n",maxorder);
          // print_setup();
          set_nbasis(1, maxorder, m_set);
          break;

        case 'm': 
          // print_setup();
          // printf("\n");
          sscanf(optarg,"%hu",&m_set);
          // printf("  Setting the number of basis to %hu\n",m_set);
          // check that the range corresponds.
          // print_setup();
          set_nbasis(o_start, o_end, m_set);
          break;
        
        case 'a': 
          sscanf(optarg,"%hu",&m_set);
          // printf("  Setting all number of basis to %hu\n",m_set);
          // print_setup();
          set_nbasis(1, maxorder, m_set);
          break;

        case 's': 
          sscanf(optarg,"%hhu",&o_start);
          // printf("  Setting start order to %hhu\n",o_start);
          // print_setup();
          break;
        
        case 'f': 
          sscanf(optarg,"%hhu",&o_end);
          // printf("  Setting end order to %hhu\n",o_end);
          // print_setup();
          break;

        case '?':
          /* getopt_long already printed an error message. */
          break;

        // default:
        //   abort ();
        }
    }
  print_basis();

  dhelp_precompute(directory, bases, maxorder);
    
  printf("__________________________________________________\n");
  printf("Finished precomputation of data.\n");
  printf("Exiting now...\n");


  exit (0);
}