#include <iostream>

using namespace std;

class Matrix{
    private:
        float **_mat;
        int _rows;
        int _cols;
    
    public:
        Matrix(int r, int c): _rows(r), _cols(c){
            _mat = new float* [_rows];
            for(int i=0; i< _rows; i++){
                _mat[i] = new float[_cols];
            }
        }

        int rows() const {return _rows;}
        int cols() const {return _cols;}

        ~Matrix(){
            for(int i=0; i<_rows; i++){
                delete [] _mat[i];
            }
            delete [] _mat;
        }

        float*& operator[](const int i){return _mat[i];}

        friend ostream& operator<<(ostream& out, const Matrix& m){
            for(int i=0; i< m.rows(); i++){
                for(int j=0;j< m.cols(); j++){
                    out<< ""<< m._mat[i][j];
                }
                out<<endl;
            }
            return out;
        } 
};

int main(){
    Matrix m(4,5);
    for (int i=0; i<m.rows(); i++){
        for (int j=0; j<m.cols();j++){
            m[i][j]=i+j+1;
        }
    }
    cout<< m;
    return 0;
}