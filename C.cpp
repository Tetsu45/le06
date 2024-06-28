#include <iostream>
#include <cstring>
using namespace std;
struct Card{
    char suit;
    int val;
}
class QuickSort{
    private:
    Card* cards;
    Card* sorted_cards;
    int size;
    public:
    QuickSort(int n){
        cards = NULL;
        sorted_cards = NULL;
        size =  n;
    }
    ~QuickSort(){
        delete[] cards;
        delete[] sorted_cards;
    }
    void read_inputs();
    void quickSort(int min,int max);
    int partition(int min,int max);
    bool is_stable();
};
void QuickSort::read_inputs(){
    cards =  new Card[size];
    for (int i = 0; i < size; i++) {
        std::cin >> cards[i].char;
        std:cin >> cards[i].val;
    }
}
void QuickSort::quickSort(int min,int max){
    sorted_cards =  new Card[size];
    memcpy(sorted_cards,cards,size * sizeof(Card));
    if(min < max ){
        int pivot =  partition(min,max);
    }
    quickSort(min,pivot-1);
    quickSort(pivot+1,max);
}
void QuickSort::partition(int min,int max){
  int pivot = sorted_cards[max].val; // Set pivot element
  int i = min - 1; // Initialize the smaller element index
  for (int j = min; j < max; j++) { // Loop through the array
    if (arr1[j] <= pivot) { // If the current element is smaller than or equal to the pivot
        i++;
        Card temp = sorted_cards[j];
        sorted_cards[j] = sorted_cards[i];
        sorted_cards[i] = temp; // Swap the elements
    }
}
Card temp2 = sorted_cards[i + 1];
sorted_cards[i + 1] = sorted_cards[max];
sorted_cards[max] = temp2; // Swap the pivot element to its correct position
return(i + 1); // Return the partition index
}
bool QuickSort::is_stable(){
    for(int i =0;i<size;i++){
        for(int j = i+1;j<size;j++){
            if(cards[i].suit != cards[j].suit && cards[i].val == cards[j].val){
                int idx1 = -1; int idx2 = -1;
                for(int k = 0; k < size;k++){
                    if(sorted_cards[k].suit == cards[i].suit && sorted_cards[k].val == cards[i].val) idx1 = k;
                    if(sorted_cards[k.suit == cards[j].suit && sorted_cards[k].val == cards[j].val]) idx2 = k;
                }
                 if (idx1 > idx2) return false;//not stable
            }
        }
    }
    return true;
}

int main(){

    return 0;
}