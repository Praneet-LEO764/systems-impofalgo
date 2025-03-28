#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>
//In this version of the code, we will have to manually put the number of numbers we want to sort (present in the csv file-random_number.csv), i will post a newer version, where such an explicit declaration wont be necessary).
void insert(double a[],int i);
int main(){
    
        int o=0;
    std::string line;
    double a[100000];
    std::ifstream infile("random_number.csv");
    while(o<100000){
        std::getline(infile,line,',');
       a[o]=std::stod(line);
       o++;

    }
    auto start=std::chrono::high_resolution_clock::now();
    int size =100000;
    for(int i=1;i<size;i+=1){

        insert(a,i);
    }
    /*int g=0;
    while(g<size){
     std::cout<< a[g]<<",";
     g+=1;
    }*/
  auto end=std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout<< duration.count();
  return 0;
}


void insert(double a[],int i){
    int j=i;
    int y=i;
    double x=a[j];
    while(i>0 && x<a[i-1] ){
     i-=1;
     y=i;
    }
    if(y!=j){
        int dif = j-y;
        while(dif>0){
            
            a[y+dif]= a[y+dif-1];
            dif-=1;
        }
        a[y]=x;
    }

}