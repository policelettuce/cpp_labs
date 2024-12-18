#include <iostream>
#include <vector>
#include <map>
#include <chrono>

using namespace std;

class SparseVector {
private:
    map<int, double> elements; // (index, value)
public:
    void insert(int index, double value) {
        if (value != 0) {
            elements[index] = value;
        }
        else {
            elements.erase(index);
        }
    }

    double get(int index) const {
        auto it = elements.find(index);
        if (it != elements.end()) {
            return it->second;
        }
        return 0;
    }

    void print() const {
        for (const auto& elem : elements) {
            cout << "Index: " << elem.first << ", Value: " << elem.second << endl;
        }
    }
};

class SparseMatrix {
private:
    map<pair<int, int>, double> elements; // ((row, column), value)
public:

    void insert(int row, int col, double value) {
        if (value != 0) {
            elements[{row, col}] = value;
        }
        else {

            elements.erase({ row, col });
        }
    }

    double get(int row, int col) const {
        auto it = elements.find({ row, col });
        if (it != elements.end()) {
            return it->second;
        }
        return 0;
    }

    void print() const {
        for (const auto& elem : elements) {
            cout << "Row: " << elem.first.first << ", Col: " << elem.first.second << ", Value: " << elem.second << endl;
        }
    }
};

class DenseVector {
private:
    vector<double> elements;
public:

    void insert(int index, double value) {
        if (index >= elements.size()) {
            elements.resize(index + 1, 0);
        }
        elements[index] = value;
    }

    double get(int index) const {
        if (index < elements.size()) {
            return elements[index];
        }
        return 0;
    }

    void print() const {
        for (size_t i = 0; i < elements.size(); ++i) {
            cout << "Index: " << i << ", Value: " << elements[i] << endl;

        }
    }
};

class DenseMatrix {
private:
    vector<vector<double>> elements;
public:

    void insert(int row, int col, double value) {
        if (row >= elements.size()) {
            elements.resize(row + 1, vector<double>(col + 1, 0));
        }
        if (col >= elements[row].size()) {
            elements[row].resize(col + 1, 0);
        }
        elements[row][col] = value;
    }

    double get(int row, int col) const {
        if (row < elements.size() && col < elements[row].size()) {
            return elements[row][col];
        }
        return 0;
    }

    void print() const {
        for (size_t i = 0; i < elements.size(); ++i) {
            for (size_t j = 0; j < elements[i].size(); ++j) {
                cout << "Row: " << i << ", Col: " << j << ", Value: " << elements[i][j] << endl;
            }
        }
    }
};


template <typename Func>
auto measure_time(Func func) {
    auto start = chrono::high_resolution_clock::now();
    func();
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::microseconds>(end - start).count();
}

int main() {
    SparseVector sparseVec;
    DenseVector denseVec;
    auto sparseInsertTime = measure_time([&]() {
        for (int i = 0; i < 10000; ++i) {
            sparseVec.insert(i, i % 10 == 0 ? i : 0);
        }
    });
    auto denseInsertTime = measure_time([&]() {
        for (int i = 0; i < 10000; ++i) {
            denseVec.insert(i, i % 10 == 0 ? i : 0);
        }
    });
    cout << "Sparse vector insertion time: " << sparseInsertTime << " microseconds" << endl;
    cout << "Dense vector insertion time: " << denseInsertTime << " microseconds" << endl;
    auto sparseGetTime = measure_time([&]() {
        for (int i = 0; i < 10000; ++i) {
            sparseVec.get(i);
        }
    });
    auto denseGetTime = measure_time([&]() {
        for (int i = 0; i < 10000; ++i) {
            denseVec.get(i);
        }
    });
    cout << "Sparse vector get time: " << sparseGetTime << " microseconds" << endl;
    cout << "Dense vector get time: " << denseGetTime << " microseconds" << endl;

    SparseMatrix sparseMat;
    DenseMatrix denseMat;
    auto sparseMatrixInsertTime = measure_time([&]() {
        for (int i = 0; i < 100; ++i) {
            for (int j = 0; j < 100; ++j) {
                sparseMat.insert(i, j, (i + j) % 10 == 0 ? i + j : 0);
            }
        }
    });
    auto denseMatrixInsertTime = measure_time([&]() {
        for (int i = 0; i < 100; ++i) {
            for (int j = 0; j < 100; ++j) {
                denseMat.insert(i, j, (i + j) % 10 == 0 ? i + j : 0);
            }
        }
    });
    cout << "Sparse matrix insertion time: " << sparseMatrixInsertTime << "microseconds" << endl;
    cout << "Dense matrix insertion time: " << denseMatrixInsertTime << " microseconds" << endl;
    auto sparseMatrixGetTime = measure_time([&]() {
        for (int i = 0; i < 100; ++i) {
            for (int j = 0; j < 100; ++j) {
                sparseMat.get(i, j);
            }
        }
    });
    auto denseMatrixGetTime = measure_time([&]() {
        for (int i = 0; i < 100; ++i) {
            for (int j = 0; j < 100; ++j) {
                denseMat.get(i, j);
            }
        }
    });
    cout << "Sparse matrix get time: " << sparseMatrixGetTime << " microseconds" <<endl;
    cout << "Dense matrix get time: " << denseMatrixGetTime << " microseconds" << endl;
    return 0;
}