#include <iostream>
class polynomial{
    private:
       int* poly;
       
    public:
       int size;          //Note here size refers to the degree of the polynomial
       polynomial(int x[],int deg){
        size=deg;
          poly=new int[size+1];
          for(int i=0;i<=size;i++){
            poly[i]=x[i];
          }
               }
       int* multiply(const polynomial &other){
        int deg= size+other.size;
        int* newpoly=new int[deg+1];
        for(int i=0;i<=deg;i++){
           newpoly[i]=0;
        }
        for(int i=0;i<=size;i++){
            for(int j=0;j<=other.size;j++){
                newpoly[i+j]+=poly[i]*other.poly[j];
            }
        }
        return newpoly;
       }
       void print() {
        for (int i = 0; i <= size; i++)
            std::cout << poly[i] << " ";
        std::cout << '\n';
    }
};
int main(){
    int s[]={0,1,2,3,4};
    int x[]={0,0,10,20};
    polynomial blah=polynomial(s,4); 
    polynomial blahx=polynomial(x,3);
    int* multiplied=blah.multiply(blahx);
    for(int i=0;i<=blah.size+blahx.size;i++){

        std::cout<<multiplied[i]<<" ";}
 
    return 0;   
}
