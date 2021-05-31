#include <bits/stdc++.h>
using namespace std;

#define f(a,b) for(int i=(a);i<(b);i++)

struct Item
{
    int value,weight;
};

bool compare(Item a, Item b){
    double ra = (double) a.value / (double) a.weight;
    double rb = (double) b.value / (double) b.weight;

    return ra > rb;
}

double fractional_knapsack(Item* arr,int n,int max_weight){
    sort(arr,arr+n,compare);

    int current_weight = 0;
    double current_val = 0;
    f(0,n){
        if(current_weight + arr[i].weight <= max_weight){
            current_weight += arr[i].weight;
            current_val += arr[i].value;
        }
        else{
            int remaining_weight = max_weight - current_weight;
            double ratio = (double) arr[i].value / (double) arr[i].weight;
            current_val += ratio * remaining_weight;
            break;
        }
    }

    return current_val;
}





int knapsackBruteForce(Item* arr, int W, int n){
    if(n == 0 || W == 0){
        return 0;
    }

    if(arr[n-1].weight > W){
        return knapsackBruteForce(arr,W,n-1);
    }
    else{
        return max(
            (arr[n-1].value + knapsackBruteForce(arr,W-(arr[n-1].weight),n-1)),
            knapsackBruteForce(arr,W,n-1)
        );
    }
}

int main(){
    int n,max_weight;
    cin >> n >> max_weight;
    int val,weight;
    Item arr[n];
    f(0,n){
        cin >> val >> weight;
        arr[i].weight = weight;
        arr[i].value = val;
    }

    //cout << fractional_knapsack(arr,n,max_weight) << '\n';
    cout << knapsackBruteForce(arr,max_weight,n) << '\n';
}
