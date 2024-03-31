/******************************************************/
/*************** Rock Paper Scissor Game **************/
/******************************************************/

/*
  It is one of the most common games played by everyone once in his childhood.
  Two persons use their hands and chooses random objects between rock, paper, or scissor.
  Their choice decides the winner between them.
  Single person can play this game With a computer.
  Creat has a feature where we can play the game, and maintain the score of Person 1 and Person 2.
*/

/****************** Computer Side *******************/
/* Generate random numbers in the range [0, RAND_MAX) and srand() especially will help to generate a random number at each time.
  #This random number will decide the choice of computer as:
    If the number is between 0-33 then the choice will be Stone.
    If the number is between 33-66 then the choice will be Paper.
    If the number is between 66-100 then the choice will be Scissors.
*/
/********************* User Side *********************/
/*
Take input from a user
    R -> Rock
    P -> Paper
    S -> Scissor
*/
/********************* Game Procedure *********************/
/*
The user will be asked to make choice and according to the choice of user and computer,
then the result will be displayed along with the choices of both computer and user.
 #winner of the game is decided as per the below rules:
    Rock vs Paper -> Paper wins.
    Rock vs Scissor -> Rock wins.
    Paper vs Scissor -> Scissor wins.
*/