#include <iostream>

class Matrix{
    private:
        int **matrix;
        int row;
        int col;
    public:
        Matrix(int rows, int cols): row(rows), col(cols){
            matrix = new int *[rows];
            for (int i = 0; i < rows; i++){
                matrix[i] = new int [cols];
            }
        }
        ~ Matrix(){
            for (int i = 0; i < row; i++){
                delete[] matrix[i];
            }
            delete [] matrix;
            std::cout << "goint out\n";
        }
        void print(){
            int i, j = 0;
            for(i = 0; i< row; i++){
                for(j = 0; j< col; j++){
                    std::cout<<matrix[i][j]<<" ";
                }
                std::cout<<std::endl;
            }
        }

        void getValues(){
                for(int i = 0; i< row; i++){
                    for(int j = 0; j<col; j++){
                        std::cout<<"Enter value for row: "<< i <<" & column: "<< j<<": ";
                        std::cin >> matrix[i][j];
                }
            }
        }
        
        void transpose(){
            std::cout<<"In transpose\n";
            /* TODO: write logic for in place matrix transpose.
                     This can be done using cyclic shifts.
            */
            

        }
            

        
};

int main(){
    Matrix mat(2,3);
    mat.getValues();
    mat.print();
    mat.transpose();
    mat.print();


    
    return 0;
}

