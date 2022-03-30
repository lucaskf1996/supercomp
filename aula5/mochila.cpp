#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct object{
    int id;
    int value;
    int weight;
};

int main(int args, char* argv[]){
    ifstream inFile(argv[1]);
    int numObj;
    int weightBP;
    string temp;
    getline(inFile, temp, ' ');
    numObj = stoi(temp);
    object objList[numObj];
    getline(inFile, temp, '\n');
    weightBP = stoi(temp);
    int ids[numObj];
    for(int i = 0; i < numObj; i++){
	ids[i] = i;
	getline(inFile, temp, ' ');
	objList[i].id = i;
	objList[i].weight = stoi(temp);
	getline(inFile, temp, '\n');
	objList[i].value = stoi(temp);
    }
    inFile.close();
    int peso = 0;
    int valor = 0;
    vector<int> resposta = {0};
    int T = 0;
    for(int i = 0; i<numObj; i++){
	if(peso + objList[i].weight < weightBP){
	    resposta[T] = ids[i];
	    peso += objList[i].weight;
	    valor += objList[i].value;
	    T += 1;
        }
    }
    cout << peso << ' ' << valor << ' ' << 0 << endl;
    for(int i = 0; i < T; i++){
	cout << resposta[i] << ' ';
    }
    cout << endl;
}
