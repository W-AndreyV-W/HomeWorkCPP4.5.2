#include <iostream>

template<class T> class Table {
public:
    Table(unsigned int row, unsigned int column) {
        _row = row;
        _column = column;
        create_array();
    }

    ~Table() {
        for (int i = 0; i < _row; i++) {
            delete[] array[i];
        }
        delete[] array;
        array = nullptr;
    }
    
    const T* operator [](const unsigned int row) const {
        return array[row];
    }

    T* operator [](const unsigned int row) {
        return array[row];
    }

    const void size(int& row, int& column) {
        row = _row;
        column = _column;
    }

private:
    T** array = nullptr;
    int _column = 1;
    int _row = 1;

    void create_array() {
        array = new T * [_row];
        for (int i = 0; i < _row; i++) {
            array[i] = new T[_column]{};
        }
    }
};

int main()
{
    int row = 0;
    int column = 0;
    auto test = Table<int>(2, 3);
    test[0][1] = 3;
    test[1][0] = 4;
    std::cout << test[0][1] << std::endl;
    test.size(row, column);
    std::cout << row << " " << column << std::endl;
}