#include <iostream>
#include <vector>

/*

    ESTE PROGRAMA HACE UNA IMPLEMENTACION DEL ALGORITMO BINARY_SEARCH
    USANDO RECURSIVIDIDAD. BASICAMENTE EL PROGRAMA RETORNA EL INDICE  DE UN VALOR DADO EN UN VECTOR

*/

int binarySearch (std::string key, std::vector<std::string> & vec, int p1, int p2) {

    if(p1 >p2) return -1;

    int mid= (p1+p2)/2;

    if(key == vec[mid])  return mid;

    if(key < vec[mid]) {
        return binarySearch(key,  vec, p1,  mid - 1);
    }else{
        return binarySearch(key,  vec, mid + 1 ,  p2);
    }


}


int findInSortedVector(std::string key, std::vector<std::string> & vec) {

    return binarySearch(key, vec, 0 , vec.size()-1);
}



int main () {

    std::vector<std::string> myVector{"1","2","3","4","5"};

    std::cout <<"tiene el numero 4 , cual es su indice ?" << findInSortedVector(" 4 ", myVector );

    return 0;
}