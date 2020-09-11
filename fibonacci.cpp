#include <iostream>

/*
    ESTE PROGRAMA CALCULA EL VALOR DE LA SERIE DE FIBONNACICI PARA UN NUMERO n DADO
    THIS PROGRAM CALCULATES THE VALUE OF THE FIBONACCI SERIES FOR A GIVEN NUMBER n
*/

const int MIN_INDEX = 0;
const int MAX_INDEX = 20; 

//  ESTE CONTADOR ME PERMITE SABER CUANTAS LLAMADAS SE HA HECHO A UNS MISMA FUNCION
//  PARA TENER IDEA DEL DESEMPENO DE UNA FUNCION DE RECURSIVIDAD
    int contador=0;


/*
    ESTA ES UNA IMPLEMENTACION GENERAL DE UNA SERIE SIMILAR A LA DE FIBONACCI
    QUE FUNDAMENTALMENTE RESULTA DE SUMAR SUS DOS INMEDIATOS TERMINOS ANTERIORES, 
    DADOS UNOS TERMINOS T0 Y T1 BASE.
    ESTA FUNCION ES IMPLEMENTADA USANDO RECURSIVIDAD TRADICIONAL Y TASITA
    ES DECIR SE PROYECTA LA FUNCION MATEMATICA PERO EN ESTE CASO SE USA EL VALOR n
    COMO UN INDICADOR DE LA POSICION DENTRO DE LA SERIE, Y LAS LLAMADAS A LA MISMA FUNCION
    SON ACUMULATIVAS INTERCAMBIANDO LOS TERMINOS t0 Y t1,
    HACIENDO QUE SE OPTIMISE DE UNA MANERA IMPORTANTE.
*/

int additiveSequence_Acummulative(int n, int t0, int t1) {
    contador++;
    if(n == 0) {
        return t0;
    }if(n == 1) {
        return t1;
    }else {
        return additiveSequence_Acummulative(n - 1 ,  t1,  t0 + t1) ;
    }
}



/*

    ESTA ES UNA IMPLEMENTACION GENERAL DE UNA SERIE QUE FUNDAMENTALMENTE RESULTA DE 
    SUMAR SUS DOS INMEDIATOS TERMINOS ANTERIORES, DADOS UNOS TERMINOS T0 Y T1 BASE
    ESTA FUNCION ES IMPLEMENTADA USANDO RECURSIVIDAD TRADICIONAL Y TASITA
    ES DECIR SE PROYECTA LA FUNCION MATEMATICA TAL CUAL ES CONCEVIDA
    
    EN ESTA FUNCION SE TIENE LA VENTAJA QUE SE GENERALIZO LA SERIE Y ESTO PERMITE
    QUE NO SOLO SE PUEDA IMPLEMENTAR LA SERIE DE FIBONACCI SINO OTRAS SERIES DONDE
    SE PUEDE CAMBIAR EL T0 Y EL T1 INICIAL, PERMITIENDO GENERAR OTROS TERMINOS
    NO OBSTANTE LA IMPLEMENTACION NO ES MUY EFICIENTE, YA QUE LA RECURSIVIDAD HACE
    LLAMADAS INDEPENDIENTES PARA CADA n HACIENDO QUE ESTE SE RAMIFIQUE HE INDIVIDUALICE
    Y DE ESTA MANERA HACER MUCHAS LLAMADAS A LA MISMA FUNCION.

*/
int additiveSequence_1(int n, int t0, int t1) {
    contador++;
    if(n == 0) {
        return t0;
    }if(n == 1) {
        return t1;
    }else {
        return additiveSequence_1(n-1 ,  t0,  t1) +  additiveSequence_1(n-2,  t0,  t1 );
    }
}


/*
    PARA IMPLEMENTAR USAREMOS UNA FUNCION GENERALIZADA LLAMADA additiveSequence
    A LA CUAL LE PASAREMOS LOS TERMINOS INICIALES T0=0 Y T1=1 INICIALES 
*/

int fibonacci_Usando_Wrapper_Generalizacion(int n) {

     return additiveSequence_1(n, 0, 1);

}





/*

    ESTA ES LA IMPLEMENTACION DE FIBONACCI BASICA 
    REPRESENTANDO LA SERIE LITERALMENTE COMO ES EN MATEMATICA
    
    ESTA IMPLEMENTACION TIENE DOS DEFICINENCIAS:
    -> UNA ES DE DESEMPENO YA QUE HACE MUCHAS LLAMADAS A LA MISMA FUNCION, ABRIENDOSE COMO UN ARBOL
    -> LA FUNCION SOLO SE PUEDE USAR PARA FIBONACCI, SI SE QUISIERA IMPLEMENTAR OTRA SERIE USANDO OTROS TERMINOS INICIALES NO SE PODRIA

*/

int fibonacci_Original(int n) {
    contador++;
    if(n < 2) {
        return n;
    
    }else {
        return fibonacci_Original( n-1 ) +  fibonacci_Original( n-2 );
    }
}



/*

    ESTA FUNCION MUESTRA EL RESULTADO DE LAS SERIES USANDO 
    DIFERENTES IMPLEMENTACIONESDE RECURSIVIDAD
    
*/

void showfibonacci() {


    std::cout <<"This program lists the fibonacci_original sequence: \n" <<std::endl;
    contador=0;
    for (int i = MIN_INDEX; i <=MAX_INDEX; i++) {
        if(i < 10) std::cout <<" ";
        std::cout << "fib(" << i << ")";
        std::cout << " = "  << fibonacci_Original(i) << "\n";//std::setw(4) 
    }
    std::cout << "# de llamadas = " << contador  << "\n\n";





    contador=0;
    std::cout <<"This program lists the fibonacci_Usando_Wrapper_Generalizacion sequence: " <<std::endl;

    for (int i = MIN_INDEX; i <=MAX_INDEX; i++) {
        if(i < 10) std::cout <<" ";
        std::cout << "fib(" << i << ")";
        std::cout << " = "  << fibonacci_Usando_Wrapper_Generalizacion(i) << "\n";//std::setw(4) 
    }
    std::cout << "# de llamadas =  " << contador  << "\n\n";

    
    




    contador=0;
    std::cout <<"\n\nThis program lists the serie3_7 sequence using additiveSequence_1(): " <<std::endl;

    for (int i = MIN_INDEX; i <=MAX_INDEX; i++) {
        if(i < 10) std::cout <<" ";
        std::cout << "serier3_7(" << i << ")";
        std::cout << " = "  << additiveSequence_1(i, 3,7) << "\n";//std::setw(4) 
    }
    std::cout << "# de llamadas = " << contador << "\n\n";




    
    contador=0;
    std::cout <<"\n\nThis program lists the serie3_7 sequence using additiveSequence_Acummulative(): " <<std::endl;

    for (int i = MIN_INDEX; i <=MAX_INDEX; i++) {

        if(i < 10) std::cout <<" ";
        std::cout << "serier3_7(" << i << ")";
        std::cout << " = "  << additiveSequence_Acummulative(i, 3,7) << "\n";//std::setw(4) 
       
    }
     std::cout << "# de llamadas = " << contador << "\n\n";

}

int main () {

    //std::cout << fibonacci(8);
    showfibonacci();
    return 0;
}