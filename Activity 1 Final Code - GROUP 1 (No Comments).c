#include <stdio.h>


#define NUM_OF_STUDENTS 5
#define NUM_OF_QUIZZES 5
#define MAX_SCORE 100
#define MIN_SCORE 50
#define PASS_SCORE 75


void print_line(char CHAR, int length){
    for(int i=0; i<length; i++){
        printf("%c", CHAR);   
    }
        printf("\n");
}


void banner(){

printf(" _       __________    __________  __  _________   __________     ____  __  ___________      ___    _   _____    ____  _______   __________ \n");
printf("| |     / / ____/ /   / ____/ __ ||  |/  / ____/  /_  __/ __ |   / __ |/ / / /  _/__  /     /   |  / | / /   |  / /| |/ /__  /  / ____/ __ | \n");
printf("| | /| / / __/ / /   / /   / / / / /|_/ / __/      / / / / / /  / / / / / / // /   / /     / /| | /  |/ / /| | / /  |  /  / /  / __/ / /_/ / \n");
printf("| |/ |/ / /___/ /___/ /___/ /_/ / /  / / /___     / / / /_/ /  / /_/ / /_/ // /   / /__   / ___ |/ /|  / ___ |/ /___/ /  / /__/ /___/ _, _/  \n");
printf("|__/|__/_____/_____/|____/|____/_/  /_/_____/    /_/  |____/   |___|_|____/___/  /____/  /_/  |_/_/ |_/_/  |_/_____/_/  /____/_____/_/ |_|    \n");
printf("\n");
printf("CREATED BY:\n");
printf("  Perez, Franz [CODER] \n  Alix, Christopher [DEBUGGER]\n ANALYSTS:\n  Maracha, Jason\n  Rabina, Kenneth\n DESIGNERS:\n  Acusin, Jesther Andrue \n  De Vera, Luis Alainzo\n");
printf("\n"); 
printf("  Welcome to Quiz Analyzer, a program designed to help you analyze the quiz scores of your students. With Quiz Analyzer, you can\n");
printf(" input the IDs and up to [%d] transmuted quiz scores per student, and the program will calculate the average, highest,and lowest\n", NUM_OF_QUIZZES ); 
printf(" scores of the students. This means you can quickly analyze the quiz scores of a small group of students without having to spend \n");
printf(" too much time on manual calculations. Additionally, the program will determine if the students passed or failed based on a \n");
printf(" predetermined passing grade. ");
printf("\n\n"); 
printf(" PLEASE NOTE:\n\n"); 
printf("  This program is designed to receive up to [%d] student IDs and [%d] quiz scores. The range of scores you can input is between [%d] and [%d].", NUM_OF_STUDENTS, NUM_OF_QUIZZES, MIN_SCORE, MAX_SCORE);
printf("\n"); 
printf(" The passing average score is set to [%d].\n\n", PASS_SCORE);
printf("  This program is NOT designed to detect multiple duplications of ID numbers and incorrect input of score numbers. In the event of \n");
printf(" these mistakes, restart the progam.");
printf("\n\n\n\n");    
}

int main() {
    
    int arr_scores[NUM_OF_STUDENTS][NUM_OF_QUIZZES] = {}; 
    char id[NUM_OF_STUDENTS][20] = {}; 
    
    int i, j; 
    float ave[NUM_OF_STUDENTS] = {}; 
    int highest[NUM_OF_STUDENTS] = {}; 
    int lowest[NUM_OF_STUDENTS] = {}; 
    int score; 
    int count_passers = 0; 
    int result; 

banner();


  for (i=0; i<NUM_OF_STUDENTS; i++) {
    printf("Enter the ID number of Student %d: ", i+1);
      scanf("%s", id[i]);
    printf("Enter the scores of Student %s:\n", id[i]);

    for (j=0; j<NUM_OF_QUIZZES; j++) {
      printf("Quiz #%d:\n", j+1);
      result = scanf("%d", &score);
      while (result != 1 || score < MIN_SCORE || score > MAX_SCORE) {
        if (result == 0) {
          printf("Invalid input. Please enter a non-decimal number:\n");
          while (getchar() != '\n'); 
        } else {
          printf("Invalid score. Please enter a score between 50 and 100:\n");
        }
        result = scanf("%d", &score);
      }

      arr_scores[i][j] = score;

      ave[i] += score; 


      if (j == 0 || highest[i] < score) {
        highest[i] = score;
      }


      if (j == 0 || lowest[i] > score) {
        lowest[i] = score;
      }
    }
    ave[i] /= NUM_OF_QUIZZES; 
  }

    
    printf("\n");
    

    
    print_line('=',140);
    printf("||      ID NUMBER      ||  QUIZ #1  ||  QUIZ #2  ||  QUIZ #3  ||  QUIZ #4  || QUIZ #5   ||  AVERAGE  ||  HIGHEST  ||  LOWEST  ||  STATUS  ||\n");
    print_line('=',140);
    for (i=0; i<NUM_OF_STUDENTS; i++) {
    printf("|| %-20s", id[i]);
        
        for (j=0; j<NUM_OF_QUIZZES; j++) {
        printf("||  %-9d", arr_scores[i][j]);
        }
    
    printf("||  %-9.2f||  %-9d||  %-8d||", ave[i], highest[i], lowest[i]);
    
        if (ave[i] >= PASS_SCORE) {
          printf("  PASSED  ||\n");
          count_passers++;
        } 
        else {
          printf("  FAILED  ||\n");
        }
    }
    print_line('=',140);
    
    print_line('=',62);
        printf("||  Number of Passers: %-38d|\n", count_passers);
    print_line('=',62);
 
  return 0;
}