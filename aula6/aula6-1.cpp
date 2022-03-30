#include<iostream>
#include<vector>
#include<algorithm>
#include <random>
using namespace std;

struct item {
    int id;
    double peso;
    double valor;
};

bool my_compare(item a, item b){
    return a.peso < b.peso; // ordenando pelo mais leve
}

bool my_compare_valor(item a, item b){
    return a.valor > b.valor;
}

int main() {
    // random_device rd;
    int seed = 10;
    default_random_engine generator(seed);
    uniform_real_distribution<float> distribution(0.0f, 1.0f);
    int n = 0;
    int W = 0;
    vector<item> mochila;
    vector<item> items;
    cin >> n >> W;
    items.reserve(n);
    double peso, valor;
    for(int i = 0; i < n; i++){
        cin >> peso;
        cin >> valor;
        items.push_back({i, peso, valor});
    }
    //ordenar
    sort(items.begin(), items.end(), my_compare);
    peso = 0;
    valor = 0;

    for(auto& el : items){
        if(el.peso + peso <= W && distribution(generator)>0.75){
            mochila.push_back(el);
            peso += el.peso;
            valor += el.valor;
        }
    }

    //ordenando para imprimir
    sort(mochila.begin(), mochila.end(), [](auto& i, auto&j){return i.id < j.id;});
    cout << peso << " " << valor << " 0" << endl;
    for(auto& el: mochila){
        cout << el.id << " ";
    }

    return 0;
}