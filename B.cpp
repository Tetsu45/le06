#include <iostream>
using namespace std;
class Partition{
    private:
    int* arr1;
    int* arr2;
    int size;
    public:
    Partition(int n){
        arr1 = NULL;
        arr2 = NULL;
        size = n;
    }
    ~Partition(){
        delete[] arr1;
        delete[] arr2;
    }
    void read_inputs();
    void quickSort();
    int partition();
    //void swap();
};
void Partition:: partition(int min,int max){
    int pivot =  arr1[max];
    int i  = min-1;
    for(int j = low;j < max;j++){
        if(arr1[j] < pivot){
            i++;
            int temp;
            temp =  arr1[j];
            arr1[j] =  arr1[i];
            arr1[i] = temp;
        } 
        int temp2 = arr1[i+1];
        arr1[i+1]  =  arr1[high];
        arr1[high]  = temp2;
        return(i+1);
    }
    
}
void Partition:: read_inputs(){
    //std::cin >> size;
    for(int i = 0;i < size;){
        std::cin >> arr1[i++];
    }
}
void Partition:: quickSort(int min,int max){
    if(min < max){
        int pivot = partition(min,max);
        quickSort(min,pivot-1);
        quickSort(pivot+1,max);
    }
}
int main(){
    int n;
    std:: cin >> n;
    Partition sort(n);
    sort.read_inputs();
    sort.quickSort(0,n-1);
    return 0;
}