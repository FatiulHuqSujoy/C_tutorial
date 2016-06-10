/*
Coded for C tutorial's introduction.
This program is a basic math game where the player is given a simple addition or subtraction of two random numbers for user defined times.
The program shows the results i.e. the amount of right and wrong answers by the player.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void primaryMathTester(int testNum2, char name2[]);

int main (){
    //ASKS FOR NAME
    printf("What's your name?\n");
    char name[20];
    scanf("%s", name);

    printf("\nHello %s, welcome to Primary Math Tester.\n\n", name);

    //ASKS FOR NUMBER OF TESTS TO RUN
    printf("How many tests do you want?\n");
    int testNum;
    scanf("%d", &testNum);

    //CALLS THE METHOD THAT WILL EXECUTE THE TESTER
    primaryMathTester(testNum, name);

    //FAREWELLS
    printf("\nThanks for playing, %s. Tata bye bye abar jeno dekha pai.\n", name);
}

void primaryMathTester(int testNum2, char name2[]){
    int i, points = 0, mistakes = 0;

    for(i=1; i<=testNum2; i++){
        //GENERATES TWO RANDOM OPERANDS a AND b BETWEEN ONE AND ONE THOUSAND
        int a = rand()%1000+1;
        int b = rand()%1000+1;
        //GENERATES A RANDOM NUMBER FOR GETTING THE OPERATOR: PLUS OR MINUS
        int sign = rand()%2;

        char ch;
        int realAnswer;

        //IF SIGN IS ZERO, WE WILL ADD THE TWO NUMBERS
        if(sign==0){
            ch = '+';
            realAnswer = a+b;
        }
        //IF SIGN IS ONE, WE WILL SUBTRACT THE TWO NUMBERS
        else if(sign==1){
            ch = '-';
            realAnswer = a-b;
        }

        //ASKS FOR USER/PLAYER'S ANSWER
        printf("\nTest %d: What is %d %c %d = ", i, a, ch, b);
        int userAnswer;
        scanf("%d", &userAnswer);

        //IF ANSWER IS INCORRECT INSULTS THE PLAYERS AND ADDS ONE TO THE NUMBER OF MISTAKES
        if(userAnswer != realAnswer){
            printf("\nWrong answer, %s. Chih! The correct answer is: %d\n", name2, realAnswer);
            mistakes++;
        }
        //IF CORRECT ADDS ONE TO THE NUMBER OF RIGHT ANSWERS
        else{
            printf("\n%d is the right answer. Obviously.\n", realAnswer);
            points++;
        }
    }

    //GENERATES COMMENTS ACCORDING TO THE PLAYER'S ACHIEVEMENT
    char comment[50];
    if(points<mistakes){
        strcpy(comment, "You are a disgrace");
    }
    else if(points>testNum2/1.5){
        strcpy(comment, "Well done mate");
    }
    else{
        strcpy(comment, "You can(should) do better");
    }

    //PRINTS PLAYER'S SCORE
    printf("\nScorecard:\nName: %s\nCorrect Answers: %d\nWrong Answers: %d\nComment: %s.\n", name2, points, mistakes, comment);
}
