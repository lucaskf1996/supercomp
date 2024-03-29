#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct item
{
    int id;
    double peso;
    double valor;
    
};


int max_value = -1;
int num_leaf = 0;
int num_copy = 0;

double knapSack2(int W, vector<item> items, vector<item>& usados, vector<item>& melhor){

    double valor = 0.0;
    double peso = 0.0;
    double sem_i = 0.0, com_i = 0.0;
    vector<item> items2 = items;
    if(items.empty() || W == 0)
        return 0;
    if(items[0].peso <= W){
        usados.push_back(items[0]);
        valor = items[0].valor;
        peso = items[0].peso;
        items.erase(items.begin());
        com_i = knapSack2(W - peso, items, usados, melhor);
    }
    items2.erase(items2.begin());
    sem_i = knapSack2(W, items2, usados, melhor);
    double valor_atual = 0.0, valor_melhor = 0.0;
    for(auto& el : usados){
        valor_atual += el.valor;
    }
    for(auto& el : melhor){
        valor_melhor += el.valor;
    }
    if(valor_atual > valor_melhor){
        melhor = usados;
        max_value = valor_atual;
        num_copy++;
    }
    if(items2.size() == 0){
        num_leaf++;
    }
    usados.clear();
    return max(sem_i, valor + com_i);
}

int main() {

    int n = 0;
    int W = 0;

    vector<item> mochila;

    cin >> n >> W; 
    vector<item> items;
    vector<item> usado;
    vector<item> melhor;
    items.reserve(n);
    usado.reserve(n);
    double peso, valor;
    for(int i = 0; i < n; i++) {
        cin >> peso;
        cin >> valor;
        items.push_back({i, peso, valor});
    }
    
    cout << "RESULTADO = " << knapSack2(W, items, usado, melhor) << "\n";
    for(auto& el: melhor) {
            cout << el.id << " ";
    }
    cout << "num_leaf: " << num_leaf;

    return 0;
}