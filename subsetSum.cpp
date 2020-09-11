#include <iostream>
#include <set>


/*

    ESTA ES UNA IMPLEMENTACION DE UN PROGRAMA QUE ENCUENTRA UN SUBSET 
    CUYA SUMA ES IGUAL A UN TARGET DATO. 
    PARA ESTO HACE USO DE inclusion / exclusion pattern
    
    CHEQUEAR POR QUE NO ESTA FUNCIONANDO DEL TODO BIEN

*/
bool subsetSumExists (std::set<int> & myset, int target );


int main () {
    
    std::set<int> myset= {8,1, 2,5};  
    std::set<int>::iterator it;  

    std::cout<<"Before erasing the element: \n";  
    std::cout << "{ ";
    for (it=myset.begin(); it!=myset.end(); ++it) {
        std::cout << *it <<" " ;  
    }
    std::cout <<"} \n";

    int number=11; 

    std::string result = subsetSumExists (myset, 11) ==true? "si": "no";

    std::cout <<" el target es " << number << " tiene combinacion ? = "  << result << "\n";

   
    return 0;
}



int contador=0;

bool subsetSumExists (std::set<int> & myset, int target ) {

    //  std::cout << "\n RECURSION "<< contador << "----------------->\n  EL TARGET ES : "<< target << "\n\n";
    // contador ++;
    // std::set<int>::iterator it;  
    
    // std::cout << "conjunto original \n" ;

    // std::cout << "{ ";
    // for (it=myset.begin(); it!=myset.end(); ++it) {
    //     std::cout << *it <<" " ;  
    // }
    // std::cout <<"} \n\n";


    if (myset.empty()) 
    {
        return target == 0;

    } else {
        
        std::set<int>::iterator it;  
        it = myset.begin();
        int element=  *it;
        myset.erase(it);
        std::set<int> rest = myset; 

            //  std::cout << "conjunto residual \n" ;

            // std::cout << "{ ";
            // for (it=myset.begin(); it!=myset.end(); ++it) {
            //     std::cout << *it <<" " ;  
            // }
            // std::cout <<"} \n\n";

        return subsetSumExists(rest, target)  ||  subsetSumExists(rest, target - element);

    }

}