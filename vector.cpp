#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Fungsi untuk menampilkan banner selamat datang
void showWelcomeBanner()
{
    cout << "===================================" << endl;
    cout << "   SELAMAT DATANG DI PROGRAM VEKTOR" << endl;
    cout << "===================================" << endl;
    cout << "NIM: 220401010187" << endl;
    cout << "Nama Mahasiswa: LUKMAN" << endl;
    cout << "Program Studi: S1 - PJJ Informatika" << endl;
    cout << "Kelas: IT102" << endl;
}

// Fungsi untuk menampilkan menu
void showMenu()
{
    cout << "MENU:" << endl;
    cout << "1. Penjumlahan Vektor" << endl;
    cout << "2. Pengurangan Vektor" << endl;
    cout << "3. Dot Product" << endl;
    cout << "4. Perkalian Vektor dengan Skalar" << endl;
    cout << "5. Transformasi Elemen Vektor" << endl;
    cout << "6. Input Ulang Vektor" << endl;
    cout << "0. Keluar" << endl;
    cout << "Pilih operasi (0-6): ";
}

// Fungsi untuk menjumlahkan dua vektor
vector<vector<double>> addVectors(const vector<vector<double>> &v1, const vector<vector<double>> &v2)
{
    vector<vector<double>> result(v1.size(), vector<double>(v1[0].size(), 0.0));

    for (int i = 0; i < v1.size(); ++i)
    {
        for (int j = 0; j < v1[0].size(); ++j)
        {
            result[i][j] = v1[i][j] + v2[i][j];
        }
    }

    return result;
}

// Fungsi untuk mengurangkan dua vektor
vector<vector<double>> subtractVectors(const vector<vector<double>> &v1, const vector<vector<double>> &v2)
{
    vector<vector<double>> result(v1.size(), vector<double>(v1[0].size(), 0.0));

    for (int i = 0; i < v1.size(); ++i)
    {
        for (int j = 0; j < v1[0].size(); ++j)
        {
            result[i][j] = v1[i][j] - v2[i][j];
        }
    }

    return result;
}

// Fungsi untuk input vektor dari pengguna
vector<vector<double>> inputVector(int rows, int cols)
{

    vector<vector<double>> result(rows, vector<double>(cols, 0.0));

    cout << "Masukkan elemen-elemen vektor:" << endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << "Elemen[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> result[i][j];
        }
    }

    return result;
}

// Fungsi untuk menghitung dot product dua vektor
double dotProduct(const vector<vector<double>> &v1, const vector<vector<double>> &v2)
{
    double result = 0.0;

    for (int i = 0; i < v1.size(); ++i)
    {
        for (int j = 0; j < v1[0].size(); ++j)
        {
            result += v1[i][j] * v2[i][j];
        }
    }

    return result;
}

// Fungsi untuk menampilkan vektor
void displayVector(const vector<vector<double>> &v)
{
    for (const auto &row : v)
    {
        for (const auto &element : row)
        {
            cout << element << "\t";
        }
        cout << endl;
    }
}

// Fungsi untuk menampilkan vektor
void display2Vector(const vector<vector<double>> &v, const vector<vector<double>> &u)
{
    cout << "Vektor Pertama." << endl;
    for (const auto &row : v)
    {
        for (const auto &element : row)
        {
            cout << element << "\t";
        }
        cout << endl;
    }
    cout << "Vektor kedua." << endl;
    for (const auto &row : u)
    {
        for (const auto &element : row)
        {
            cout << element << "\t";
        }
        cout << endl;
    }
}
// Fungsi untuk perkalian vektor dengan skalar
vector<vector<double>> scalarMultiply(const vector<vector<double>> &v, double scalar)
{
    vector<vector<double>> result(v.size(), vector<double>(v[0].size(), 0.0));

    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = 0; j < v[0].size(); ++j)
        {
            result[i][j] = v[i][j] * scalar;
        }
    }

    return result;
}

// Fungsi untuk penukaran baris ke-i dan baris ke-j
vector<vector<double>> swapRows(const vector<vector<double>> &v, int row1, int row2)
{
    vector<vector<double>> result = v;
    swap(result[row1], result[row2]);
    return result;
}

// Fungsi untuk penukaran lajur ke-i dan lajur ke-j
vector<vector<double>> swapColumns(const vector<vector<double>> &v, int col1, int col2)
{
    vector<vector<double>> result = v;
    for (int i = 0; i < v.size(); ++i)
    {
        swap(result[i][col1], result[i][col2]);
    }
    return result;
}

// Fungsi transformasi elemen vektor berdasarkan pilihan pengguna
vector<vector<double>> elementwiseTransform(const vector<vector<double>> &v, int transformType)
{
    vector<vector<double>> result = v;

    switch (transformType)
    {
    case 1:
        // Penukaran baris ke-i dan ke-j
        int row1, row2;
        cout << "Masukkan nomor baris ke-i yang ingin ditukar: ";
        cin >> row1;
        cout << "Masukkan nomor baris ke-j yang ingin ditukar: ";
        cin >> row2;
        result = swapRows(result, row1 - 1, row2 - 1);
        break;

    case 2:
        // Penukaran lajur ke-i dan ke-j
        int col1, col2;
        cout << "Masukkan nomor lajur ke-i yang ingin ditukar: ";
        cin >> col1;
        cout << "Masukkan nomor lajur ke-j yang ingin ditukar: ";
        cin >> col2;
        result = swapColumns(result, col1 - 1, col2 - 1);
        break;

    default:
        cout << "Pilihan transformasi tidak valid." << endl;
    }

    return result;
}

int main()
{

    showWelcomeBanner();

    vector<vector<double>> vector1, vector2, vector3, result;
    int rows, cols;
    cout << "Masukkan jumlah baris vektor: ";
    cin >> rows;
    cout << "Masukkan jumlah kolom vektor: ";
    cin >> cols;
    // Input vektor dari pengguna
    cout << "Masukkan vektor pertama:" << endl;
    vector1 = inputVector(rows, cols);

    cout << "Masukkan vektor kedua:" << endl;
    vector2 = inputVector(rows, cols);

    int choice;
    do
    {
        showMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            // Penjumlahan vektor
            result = addVectors(vector1, vector2);
            display2Vector(vector1, vector2);
            cout << "Hasil Penjumlahan Vektor:" << endl;
            displayVector(result);
            break;

        case 2:
            // Pengurangan vektor
            result = subtractVectors(vector1, vector2);
            display2Vector(vector1, vector2);
            cout << "Hasil Pengurangan Vektor:" << endl;
            displayVector(result);
            break;

        case 3:
            // Dot product
            display2Vector(vector1, vector2);
            cout << "Dot Product: " << dotProduct(vector1, vector2) << endl;
            break;
        case 4:
            // Input vektor dari pengguna
            cout << "Masukkan jumlah baris vektor: ";
            cin >> rows;
            cout << "Masukkan jumlah kolom vektor: ";
            cin >> cols;
            cout << "Masukkan vektor:" << endl;
            vector3 = inputVector(rows, cols);
            // Perkalian vektor dengan skalar
            double scalar;
            cout << "Masukkan skalar: ";
            cin >> scalar;
            result = scalarMultiply(vector3, scalar);
            cout << "Vektor input" << endl;
            displayVector(vector3);
            cout << "Hasil Perkalian Vektor dengan Skalar:" << endl;
            displayVector(result);
            break;
        case 5:
            cout << "Masukkan jumlah baris vektor: ";
            cin >> rows;
            cout << "Masukkan jumlah kolom vektor: ";
            cin >> cols;
            // Input vektor dari pengguna
            cout << "Masukkan vektor:" << endl;
            vector3 = inputVector(rows, cols);
            // Pilihan tipe transformasi elemen vektor
            int transformType;
            cout << "Pilih tipe transformasi elemen vektor:" << endl;
            cout << "1. Penukaran baris ke-i dan baris ke-j" << endl;
            cout << "2. Penukaran lajur ke-i dan lajur ke-j" << endl;
            cout << "Pilih transformasi (1-2): ";
            cin >> transformType;

            result = elementwiseTransform(vector3, transformType);
            cout << "Vektor input" << endl;
            displayVector(vector3);
            cout << "Hasil Transformasi Elemen Vektor:" << endl;
            displayVector(result);
            break;

        case 6:
            // Input ulang vektor
            cout << "Masukkan jumlah baris vektor: ";
            cin >> rows;
            cout << "Masukkan jumlah kolom vektor: ";
            cin >> cols;
            // Input vektor dari pengguna
            cout << "Masukkan vektor pertama:" << endl;
            vector1 = inputVector(rows, cols);

            cout << "Masukkan vektor kedua:" << endl;
            vector2 = inputVector(rows, cols);
            break;

        case 0:
            // Keluar
            cout << "Terima kasih telah menggunakan program vektor." << endl;
            break;

        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }

    } while (choice != 0);

    return 0;
}
