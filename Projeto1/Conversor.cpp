#include <iostream>

using namespace std;

int main (){

	int num, numOriginal, cont = 0;
	long int bin[500];

	cout << "Digite um número a ser convertido de Decimal para Binário:"<< endl;
	cin >> num;

	numOriginal = num;

	if (num < 0 || num == 0){
		cout << "Erro. O número inserido é inválido" << endl;
		return 0;
	}
	if (num == 2){
		cout << endl << "O número " << numOriginal << " em Decimal é equivalente a 10 em Binário";
		return 0;
	}
	if (num == 1){
		cout << endl << "O número " << numOriginal << " em Decimal é equivalente a 01 em Binário";
		return 0;
	}

	do {
		if (num == 1){
			bin[cont] = 1;
			num = 0;
			break;
		}

		if (num % 2 == 1){
			bin[cont] = 1;
			cont++;
			num = (num - 1) / 2;
			continue;
		}else
			if (num % 2 == 0){
			bin[cont] = 0;
			cont++;
			num /= 2;
			continue;
		}

	}while (num > 0);

	cout << endl << "O número " << numOriginal << " em Decimal é equivalente a ";
	for (int i = cont; i >= 0; i--){
		cout << bin[i];
	}
	cout << " em Binário." << endl;

	return 0;
}
