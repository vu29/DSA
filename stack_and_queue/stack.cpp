#include <bits/stdc++.h>
using namespace std;

class TwoStack{
private:
    int arr[10] = {0};
    int s1Ptr = -1;
    int s2Ptr = 10;


private:
    bool isOverFlow(){
        return s1Ptr + 1 == s2Ptr;
    }

    bool isS1UnderFlow(){
        return s1Ptr <= 0;
    }

    bool isS2UnderFlow(){
        return s2Ptr >= 9;
    }

public:

    void s1_push(int data){
        if(isOverFlow()){
            cout << "Overflow" << '\n';
            return;
        }

        arr[++s1Ptr] = data;
    }

    void s2_push(int data){
        if(isOverFlow()){
            cout << "Overflow" << '\n';
            return;
        }

        arr[--s2Ptr] = data;
    }

    void s2_pop(){
        if(isS2UnderFlow()){
            cout << "underflow" << '\n';
            return;
        }
        arr[s2Ptr] = 0;
        s2Ptr++;
    }

    void s1_pop(){
        if(isS1UnderFlow()){
            cout << "underflow" << '\n';
            return;
        }
        arr[s1Ptr] = 0;
        s1Ptr--;
    }

    int s1_top(){
        if(isS1UnderFlow()){
            return -1;
        }
        
        return arr[s1Ptr];
    }

    int s2_top(){
        if(isS2UnderFlow()){
            return -1;
        }
        
        return arr[s2Ptr];
    }

    void showArr(){
        for(int i=0;i<10;i++)
            cout << arr[i] << ' ';
        cout << '\n';
    }

};

int main(){
    TwoStack ts;
    for(int i=1;i<=6;i++){
        ts.s1_push(i);
        ts.s2_push(i);
        ts.showArr();
    }
}