#include<iostream>
int* sort(int arr1[],int arr2[],int merge[], int size)
{
   int x =0;
   for(int i =0; i<size; i++)
   {
    merge[x]=arr1[i];
    merge[x+size] = arr2[i];
    x++;
   }
   if(arr1[0]>arr1[size-1])
   {
    for( int i=0;i<size*2;i++)
    {
            for (int j = i+1;j<size*2;j++)
            {
                if(merge[j]<merge[i])
                {
                    int temp = merge[j];
                    merge[j]= merge[i];
                    merge[i] = temp;
                }
            }
        }
   }
   else
   {
    for( int i=0;i<size*2;i++)
    {
            for (int j = i+1;j<size*2;j++)
            {
                if(merge[j]>merge[i])
                {
                    int temp = merge[j];
                    merge[j]= merge[i];
                    merge[i] = temp;
                }
            }
        }

   }
    return merge;
}
int* get_array(int size)
{
    int *array = new int[size];
    for(int i =0;i<size;i++)
    {
        std::cin>>array[i];
    }
    return array;
}
void print_array(int array[] ,int size)
{
    for(int i =0;i<size;i++)
    std::cout<<array[i]<<" ";
}
int main()
{
    int s ;
    std::cout<<"\nEnter the size of the two arrays : ";
    std::cin>>s;
    int *array3= new int[s*2];
    std::cout<<"\nEnter the first sorted array : "<<std::endl;
    int *array1=get_array(s);
    std::cout<<"\nEnter the second sorted array : "<<std::endl;
    int *array2= get_array(s);
    array3=sort(array1,array2,array3,s);
    std::cout<<"\n\nThe merged array is : ";
    print_array(array3, s * 2); 
    std::cout<<std::endl<<"\n\n\n"; 
    delete[] array1;
    delete[] array2;
    delete[] array3;  
    return 0;

}

/* Enter the size of the two arrays : 4
   Enter the first sorted array :
   2
   5
   8
   11
   Enter the second sorted array : 
   1
   4
   7
   9

   The merged array is : 11 9 8 7 5 4 2 1
*/