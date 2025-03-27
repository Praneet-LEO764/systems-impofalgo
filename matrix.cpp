#include <iostream>
#include <fstream>
template <class T>
class matrix{
  private:
    
    int rows;
    int cols;
  public:
     T** mat;
    matrix(int r,int c){
        rows=r;
        cols=c;
        mat=new T*[rows];
        for(int i=0;i<rows;i++){
            mat[i]=new T[cols];
        }
    }

    ~matrix(){
        for(int i=0;i<rows;i++){
            delete[] mat[i];
        }
        delete[] mat;
    }

    T*& operator[](int i){
        return mat[i];
    }

    std::ofstream& print_to_file(std::ofstream& out){
      for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            out<<" "<<mat[i][j];
        }
        out<< "\n";
      }
      return out;
    }


    

};

int main (){
    matrix<float> mymat(4,5);
    mymat.mat[3][4]=9090;
    std::cout<<mymat.mat[3][4];
    
    std::ofstream out("testing.txt");
    mymat.print_to_file(out);
    out.close();

    return 0;
}