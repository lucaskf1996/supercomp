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

bool my_compare(item a, item b){
    return a.peso < b.peso; // ordenando pelo mais leve
}

bool my_compare_valor(item a, item b){
    return a.valor > b.valor;
}

int main() {
    random_device rd;
    int seed = rd();
    default_random_engine generator(seed);
    uniform_real_distribution<float> distribution(0.0f, 1.0f);
    int n = 0;
    int W = 0;
    vector<item> mochila;
    vector<item> bestMochila;
    vector<item> items;
    cin >> n >> W;
    items.reserve(n);
    double peso, valor, melhor, maior;
    for(int i = 0; i < n; i++){
        cin >> peso;
        cin >> valor;
        items.push_back({i, peso, valor});
    }
    //ordenar
    // sort(items.begin(), items.end(), my_compare);
    melhor = 0;
    maior = 0;
    for(int i = 0; i < 100000000; i++){ 
        mochila.clear(); 
        peso = 0;
        valor = 0;

        for(auto& el : items){
            if(el.peso + peso <= W && distribution(generator)>0.50){
                mochila.push_back(el);
                peso += el.peso;
                valor += el.valor;
            }
        }  

        //ordenando para imprimir
        sort(mochila.begin(), mochila.end(), [](auto& i, auto&j){return i.id < j.id;});
        if (valor>melhor){
            melhor = valor;
            maior = peso;
            bestMochila = mochila;
        }
        // cout << peso << " " << valor << " 0" << endl;
        // for(auto& el: mochila){
        //     cout << el.id << " ";
        // }
        // cout << endl;
    }
    cout << endl << maior << " " << melhor << " 0" << endl;
        for(auto& el: bestMochila){
            cout << el.id << " ";
        }
    return 0;
}