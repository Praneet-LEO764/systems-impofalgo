//This was used to generate random numebers (a mersene random number sequence-approprately seeded) lying in a desired range (mapped uniformly to (0,99999).

#include <iostream>
#include <random>
#include <fstream>
int main(){
    using namespace std;
    double x=0;
    uniform_int_distribution<> distr(0, 99999);
   random_device rd;
   mt19937 gen(rd());
   ofstream outfile("random_number.csv");
   for(int i=0;i<100000;i+=1){
    x=distr(gen) ;
    outfile << x;
    if(i<99999){
        outfile<<",";
    }
   }
   outfile.close();
   return 0;
}

//************************************************************************************************