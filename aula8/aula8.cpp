#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
using namespace std;

struct item {
    int id;
    double peso;
    double valor;
};

struct Bag{
    vector<int> itemIDs;
    int peso=0;
    int valor=0;
};

// bool my_compare(item a, item b){
//     return a.peso < b.peso; // ordenando pelo mais leve
// }

// bool my_compare_valor(item a, item b){
//     return a.valor > b.valor;
// }

Bag recursiveBag(int n, int W, int index, vector<item> items, Bag bag){
    Bag newBag1;
    
    index++;
    
    if(n==index || bag.peso>=W){
        return bag;
    }

    newBag1 = recursiveBag(n, W, index, items, bag);
    bag.peso+=items[index].peso;
    bag.itemIDs.push_back(items[index].id);
    bag.valor += items[index].valor;
    bag = recursiveBag(n, W, index, items, bag);

    if(bag.peso>W){
        return newBag1;
    }
    else if(newBag1.valor>bag.valor){
        return newBag1;
    }
    else{
        return bag;
    }
}

int main() {
    random_device rd;
    int seed = rd();
    default_random_engine generator(seed);
    uniform_real_distribution<float> distribution(0.0f, 1.0f);
    int n = 0;
    int W = 0;
    int index = -1;
    vector<item> bestMochila;
    vector<item> items;
    Bag bag;
    cin >> n >> W;
    items.reserve(n);
    double peso, valor, melhor, maior;
    for(int i = 0; i < n; i++){
        cin >> peso;
        cin >> valor;
        items.push_back({i, peso, valor});
    }
    bag = recursiveBag(n, W, index, items, bag);
    cout << bag.peso << " " << bag.valor << " 0" << endl;
    for(auto& el: bag.itemIDs){
        cout << el << " ";
    }
    cout << endl;
    // }
    return 0;
}