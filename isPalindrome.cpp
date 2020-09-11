#include <iostream>
#include <string>

/*
    ESTE PROGRAMA REPRESENTA DIFERENTES IMPLEMENTACIONES DE 
    isPalindrome , LA CUAL CHEQUEA SI UNA PALABRA SE LEE IGUAL 
    HACIA ADELANTE Y HACIA ATRAS . COMO POR EJEMPLO 'LEVEL' 
*/




/*

    ESTA FUNCION IMPLEMENTA LA DETECCION DE UNA PALABRA SI ES O NO UN 
    PALINDROME HACIENDO USO DE INDICES EN VES DE ESTAR CALCULANDO EL SUBSTRING 
    DE LA PALABRA, NI CALCULANDO LA LONGITUD DE LA MISMA CADA VEZ
    QUE SE LLAMA A LA FUNCION.

    RETURN TRUE IF THE CHARACTERS IN str FROM p1 TO p2 INCLUSIVE FORM
    IS A PALINDROME. THIS IMPLEMENTATION USE THE RECURSIVE INSIGHT
    THAT ALL STRINGS OF LENGTH 0 OR 1 ARE PALINDROMES (THE SIMPLES CASES)
    AND THAT LONGER STRINGS ARE PALINDROMES ONLY IF THEIR FIRST AND LAST
    CHARACTERS MATCH AND THE REMAINING SUBSTRING SUBSTRING IS A PALINDROME
*/
bool isSubstringPalindrome(std::string str,  int p1, int p2 ) {

    if(p1 >= p2 ) {
        return true;
    }else {
        return str[p1] == str[p2] && isSubstringPalindrome(str,  p1+1,  p2-1);
    }
}


/*
    ESTA IMPLEMENTACION DE isPalindrome BASICAMENTE HACE UN WRAPPER DE 
    isSbustringPalindrome PARA ENCONTRAR LA SOLUCION.
*/
bool isPalindrome_Wrapper(std::string str) {

    return isSubstringPalindrome(str, 0, str.length()-1);       
    
}





/*

    Function : isPalindrome
    Usage : if (isPalindrome(str))
    ______________________________
    Returns true if str is a palindrome , wich is a string that
    reads the same backwards and forwards. 
    This implementation uses the recursive insight that all strings of length 0 or 1
    are palindromes and that longer strings are palindromes if their first 
    and last characters match and the remaining substring is a palindrome


*/
bool isPalindrome(std::string str) {

    int len = str.length();

    if(len <= 1){
        return true;
    }else{
        return str[0] == str[len-1] && isPalindrome(str.substr(1, len-2));
    }
           
}



int main () {

    std::string palabraTest= "lvel";


    std::string result = isPalindrome(palabraTest) == true ? "si": "no"; 
    std::cout <<">Usando funcion isPalindrome.\n Es palindrome ? : " << result<<"\n";
    
    result = isPalindrome_Wrapper(palabraTest) == true ? "si": "no"; 
    std::cout <<">Usando funcion isPalindrome_Wrapper.\n Es palindrome ? : " << result<<"\n";
    
    return 0;
}