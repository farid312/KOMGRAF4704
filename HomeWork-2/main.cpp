#include <iostream>
using namespace std;
int main (){
	int i, j, k, m, n, p, q, matrix1[10][10], matrix2[10][10], hasil[10][10], skalar;

	cout << "Masukkan jumlah baris matriks 1: ";
    cin >> m;
    cout << "Masukkan jumlah kolom matriks 1: ";
    cin >> n;


    cout << "Masukkan jumlah baris matriks 2: ";
    cin >> p;
    cout << "Masukkan jumlah kolom matriks 2: ";
    cin >> q;

    cout << "\n";

	cout << "Masukkan elemen matriks pertama: \n";
	for(i = 0; i < m; i++){
		for(j=0; j < n; j++){
			cin >> matrix1[i][j];
		}
	}
	cout << "\n";

	cout << "Masukkan elemen matriks kedua: \n";
    for (i = 0; i < p; i++) {
        for (j = 0; j < q; j++) {
            cin >> matrix2[i][j];
        }
    }
    cout << "\n";

	/* Penjuimlahan */
	cout << "Hasil penjumlahan matriks: \n";
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			hasil[i][j] = matrix1[i][j] + matrix2[i][j];
			cout << hasil[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "\n";

	/* Pengurangan */
	cout << "Hasil pengurangan matriks: \n";
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			hasil[i][j] = matrix1[i][j] - matrix2[i][j];
			cout << hasil[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "\n";

	/* Perkalian dengan Skalar */
	cout << "Masukkan skalar : ";
	cin >> skalar;

	cout << "Hasil perkalian scalar matriks 1 : \n";
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			hasil[i][j] = matrix1[i][j] * skalar;
			cout << hasil[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "\n";

	cout << "Hasil perkalian scalar matriks 2 : \n";
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			hasil[i][j] = matrix2[i][j] * skalar;
			cout << hasil[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "\n";

	/* Perkalian */
	if (n != p) {
        cout << "Perkalian matriks tidak memungkinkan karena jumlah kolom matriks pertama tidak sama dengan jumlah baris matriks kedua." << endl;
    }

    cout << "Hasil perkalian matriks: \n";
    for (i = 0; i < m; i++) {
        for (j = 0; j < q; j++) {
            hasil[i][j] = 0;  // Inisialisasi hasil perkalian dengan 0
            for (k = 0; k < n; k++) {
                hasil[i][j] += matrix1[i][k] * matrix2[k][j];
            }
            cout << hasil[i][j] << "\t";
        }
        cout << endl;
    }

	return 0;
}
