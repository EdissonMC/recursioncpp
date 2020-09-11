#include <iostream>

/*
    File towerHanoi.cpp
    ___________________
    This program solves the Tower of Hanoi puzzle

*/

/* Function prototypes */
void moveTower(int n, char start , char finish, char tmp);


int main() {

    int numberOfDisk =3;
    moveTower(numberOfDisk , 'A', 'B', 'C');

    return 0;
}


/*
    Function : moveTower
    Usage: moveTower(n,  start,  finish, tmp)
    ________________________________________
    Moves a tower of size n from the start spire to the finish spire
    using the tmp spire as the temporary repository

*/
void moveTower(int n,  char start,  char finish,  char tmp) {


    if (n == 1) {
        std::cout << start << "--> "<<    finish <<std::endl;
    }else{

        moveTower(n-1,  start, tmp,  finish);

        std::cout << start << "--> "<<  finish <<std::endl;

        moveTower(n-1,  tmp, finish,  start);

    }


}