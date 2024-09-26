#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//Falta considerar os 0's quando está na função 2

void telaInicial();
int decimalBinario();
int binarioDecimal();

void telaInicial() {
	int escolha;
	cout << "\nBem vindo!" << endl;
	cout << "Digite 1 para converter de decimal para binario." << endl;
	cout << "Digite 2 para converter de binario para decimal." << endl;
	cin >> escolha;
	cout << endl;

	switch (escolha) {
	case 1:
		decimalBinario();
		break;
	case 2:
		binarioDecimal();
		break;
	default:
		cout << "A escolha eh invalida!!!" << endl << endl;
		telaInicial();
	}
}

int decimalBinario() {
	int num, numOriginal, cont = 0;
	long int bin[500];

	cout << "Digite um numero a ser convertido de Decimal para Binario:"
			<< endl;
	cin >> num;

	numOriginal = num;

	if (num < 0 || num == 0) {
		cout << "Erro. O numero inserido eh invalido" << endl;
		return 0;
	}
	if (num == 1) {
		cout << endl << "O numero " << numOriginal
				<< " em Decimal eh equivalente a 01 em Binario";
		return 0;
	}
	if (num == 2) {
		cout << endl << "O numero " << numOriginal
				<< " em Decimal eh equivalente a 10 em Binario";
		return 0;
	}

	do {
		if (num == 1) {
			bin[cont] = 1;
			num = 0;
			break;
		}

		if (num % 2 == 1) {
			bin[cont] = 1;
			cont++;
			num = (num - 1) / 2;
			continue;
		} else if (num % 2 == 0) {
			bin[cont] = 0;
			cont++;
			num /= 2;
			continue;
		}

	} while (num > 0);

	cout << endl << "O numero " << numOriginal
			<< " em Decimal eh equivalente a ";
	for (int i = cont; i >= 0; i--) {
		cout << bin[i];
	}
	cout << " em Binario." << endl;

	return 1;
}

int binarioDecimal() {
	int bin, binOriginal, cont = 0, numeroFinal = 0;

	cout << "Digite um numero a ser convertido de Binario para Decimal:"
			<< endl;
	cin >> bin;

	binOriginal = bin;

	int casas = 0;

	if (bin < 0 || bin == 0) {
		cout << "Erro. O numero inserido eh invalido" << endl;
		return 0;
	}

	while ((bin = bin / 10) > 0){
		//Para saber a quantidade de casas
		casas++;
	}

	bin = binOriginal;

	while (cont <= casas) {
		numeroFinal += pow(2, cont);
		cont++;
	}

	cout << endl << "O numero " << binOriginal
			<< " em Binario eh equivalente a " << numeroFinal << " em Decimal."
			<< endl;
	return 1;
}

int main() {
	telaInicial();
	return 0;
}
