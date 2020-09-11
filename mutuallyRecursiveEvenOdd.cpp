#include <iostream>


/*

    ESTE PROGRAMA PERMITE SABER SI UN NUMERO ES PAR O IMPAR
    PARA HACER ESTA IMPLEMENTACION , SE HACE USO DE RECURSIVIDAD CRUZADA
    DONDE UNA FUNCION LLAMA A OTRA Y VICEVERSA HASTA ENCONTRAR LA RESPUESTA

*/
bool isEven(unsigned int n) ;
bool isOdd(unsigned int n);


bool isEven_Wrapper(unsigned int n);
bool isOdd_Wrapper(unsigned int n);
bool generalizada(unsigned int n);

int main (){

    int number = 8;
    std::string result = isEven(number) ==true ? "si" : "no";
    std::cout << "Probando si " << number << " es par ? "<< result <<" ->usango la cruzada \n" ; 

   
    result = isEven_Wrapper(number) == true ? "si" : "no";
    std::cout << "Probando si " << number << " es par ? "<< result <<" ->usango la generalizada  \n" ; 

    result = isOdd_Wrapper(number) == true ? "si" : "no";
    std::cout << "Probando si " << number << " es impar ? "<< result <<" ->usango la generalizada  \n" ; 


    return 0;
}


bool isEven(unsigned int n) {

    if(n == 0) {
        return true;
    }else {
        return isOdd(n-1);
    }
   

}

bool isOdd(unsigned int n) {
    return !isEven(n);
}




bool isEven_Wrapper(unsigned int n) {
    return generalizada(  n) ;
}

bool isOdd_Wrapper(unsigned int n) {
    return !generalizada(  n) ;
}

bool generalizada(unsigned int n) {
      if(n == 0) {
        return true;
    }else {
        return !generalizada(n-1);
    }
}