#include <iostream>

/*
    ESTE PROGRAMA CALCULA EL FACTORIAL DE UN NUMERO n DADO
    THIS PROGRAMA RETURN N-FACTOR FOR GIVED n NUMBER
*/


int factorial(int n) {

    if(n==0){
        return 1;
    }else {
        return n *  factorial(n-1);
    }
}

int main () {

    std::cout << factorial(5);
    return 0;
}