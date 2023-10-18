#include<iostream>
class Matrix {
  private: int ** p;
  int r,c;
  public: 
  Matrix() {}
  Matrix(int x, int y) 
  {
    r = x;
    c = y;
    if ((r > 0) && (c > 0)) 
    {
      p= new int * [r];
      for (int i = 0; i < r; i++) 
      {
        p[i] = new int[c];
      }
    }
  }
  ~Matrix() 
  {
    for (int i = 0; i < r; i++)
      delete p[i];
    delete p;
  }
  int* sum_of_rows();
  int* sum_of_columns();
  void recieve_elements(void);
  int maximum(int array[],int size);
};
int* Matrix::sum_of_columns() 
{
    int * S = new int [r];
    for (int i=0;i<r; i++)
    {
        for(int j =0;j<c;j++)
        {
            S[i]=S[i]+p[j][i];
        }
    }
    return S;  
}
int* Matrix::sum_of_rows() 
{
    int * S = new int [c];
    for (int i=0;i<c; i++)
    {
        for(int j =0;j<r;j++)
        {
            S[i]=S[i]+p[i][j];
        }
    }
    return S;  
}
void Matrix::recieve_elements() 
{
  for (int i = 0; i < r; i++) 
  {
    std::cout << "\nEnter " << c << " elements of " << i + 1 << " row : ";
    for (int j = 0; j < c; j++) 
    {
      std::cin >> p[i][j];
    }
    std::cout<<std::endl;
  }
}
int Matrix::maximum(int array[],int size){
    int max_index =0;
    for(int i=1;i<size;i++){
        if(array[max_index]<array[i])
        max_index=i;
    }
    return max_index;
}
int main() 
{
  int x, y;
  std::cout << "\nEnter the number of rows: ";
  std::cin>>x;
  std::cout << "\nEnter the number of columns: ";
  std::cin>>y;  
  Matrix obj1(x, y);
  obj1.recieve_elements();
  int *Col_Sum = new int [y];
  int *Row_Sum = new int [x];
  Row_Sum = obj1.sum_of_rows();
  Col_Sum = obj1.sum_of_rows();
  int max_column = obj1.maximum(Col_Sum,y);
  int max_row = obj1.maximum(Row_Sum,x);
  std::cout<<"\nThe column number with greatest sum is : "<<max_column+1<<std::endl;
  std::cout<<"\nThe row number with greatest sum is :"<<max_row+1<<"\n\n\n"<<std::endl;
  return 0;
}
// Enter the number of rows : 2
// Enter the number of columns: 2  
// Enter the values of the matrix:
// Enter 3 elements of 1 row : 1 2 3
// Enter 3 elements of 2 row : 7 8 5
// Enter 3 elements of 3 row : 6 3 2
// The column number with maximum sum is : 1
// The row number with maximum sum is : 2