//ДЛЯ УДОБСТВА 2 И 3 ЗАДАНИЯ БЫЛИ ЗАКОММЕНТИРОВАНЫ 
//2 ЗАДАНИЕ СТРОЧКА (121)
//3 ЗАДАНИЕ СТРОЧКА (221)
#include <iostream>
using namespace std;


// Функция для добавления столбца в двумерный массив
int** addColumn(int** array, int rows, int& cols, int* newColumn, int& position) {

    if (position < 0 || position > cols) {//если введенная позиция больше или меньше нужного нам диапазона то ничего не заработает

        cout << "Invalid column insertion position!!" << endl;
        return array;
    }

    // создаем новый массив с увеличенным количеством столбцов
    int** newArray = new int* [rows];
    for (int i = 0; i < rows; i++) {

        newArray[i] = new int[cols + 1];//увеличиваем количество столбцов на 1 
    }

    cols++; // увеличиваем количество столбцов( что бы при выводе в мейне не возникла ошибка)

    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < position; j++) {// копируем существующие данные

            newArray[i][j] = array[i][j];
        }

        newArray[i][position] = newColumn[i];//вставляем новый столбец
        for (int j = position; j < cols; j++) {

            newArray[i][j + 1] = array[i][j];
        }
    }

    //удаляем старый массив 
    for (int i = 0; i < rows; i++) {
        delete[] array[i];
    }
    delete[] array;

    array = newArray;//обновляем указатель
    return newArray;
}


int main() {

    int rows = 3;//строка
    int cols = 3;//столбец

    /*создаем двумерный массив
    Сначала создаётся одномерный массив указателей, а затем каждому элементу этого массива присваивается адрес одномерного массива*/
    int** array = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        array[i] = new int[cols];
    }

    // Заполняем массив данными
    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < cols; j++) {

            array[i][j] = i * cols + j;
            //array[i][j] = i * j;
        }
    }

    //вывод матрицы 
    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < cols; j++) {

            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    // Создаем новый столбец, который хотим добавить
    int* newColumn = new int[rows];
    for (int i = 0; i < rows; i++) {

        newColumn[i] = i * rows;
    }

    int posision;
    cout << "Enter position for column: ";
    cin >> posision;

    // Добавляем новый столбец на позицию 1 (нумерация с 0)
    array = addColumn(array, rows, cols, newColumn, posision);


    //Измененная матрица 
    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < cols; j++) {

            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; i++) {

        delete[] array[i];
    }
    delete[] array;

    delete[] newColumn;

    return 0;
}


//-------------------------------------------------------------------------------------------------------------------------------------------------

/*
// Функция для удаления столбца из двумерного массива
int **deleteColumn(int **array, int rows, int& cols, int position) {

    if (position < 0 || position >= cols) {

        cout << "Invalid column insertion position!!" << endl;
        return array;
    }

    //cоздаем новый массив с уменьшенным количеством столбцов
    int** newArray = new int* [rows];
    for (int i = 0; i < rows; i++) {

        newArray[i] = new int[cols - 1];
    }

    for (int i = 0; i < rows; i++) {

        int newColumnIndex = 0;

        for (int j = 0; j < cols; j++) {

            if (j != position) {//проверят не являеться ли столбец тем что мы удаляем

                newArray[i][newColumnIndex] = array[i][j];
                newColumnIndex++;
            }
        }
    }

    // удаляем старый массив
    for (int i = 0; i < rows; i++) {

        delete[] array[i];
    }
    delete[] array;

    cols--; // уменьшаем количество столбцов
    return newArray;
}

int main() {
    int rows = 3; // Строки
    int cols = 4; // Столбцы

    // Создаем двумерный массив
    int** array = new int* [rows];
    for (int i = 0; i < rows; i++) {

        array[i] = new int[cols];
    }

    // Заполняем массив данными
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            array[i][j] = i * j;
        }
    }

    // Выводим матрицы
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    int position;
    cout << "Enter position for column: ";
    cin >> position;

    // Вызываем функцию deleteColumn
    array = deleteColumn(array, rows, cols, position);

    // Выводим результат
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    // Очищаем память
    for (int i = 0; i < rows; i++) {

        delete[] array[i];
    }
    delete[] array;

    return 0;
}

*/

//-------------------------------------------------------------------------------------------------------------------------------------------------
/*

int** createMatrix(int M, int N);
void printMatrix(int** matrix, int M, int N);
void shiftRows(int** matrix, int N, int count, char direction);
void shiftColumns(int** matrix, int M, int count, char direction);

int main() {
    setlocale(LC_ALL, "Ukrainian");

    int M, N;

    cout << "Введите количество строк: ";
    cin >> M;
    cout << "Введите количество столбцов: ";
    cin >> N;

    //сощдание матрицы
    int** matrix = createMatrix(M, N);

    //вывод матрицы
    cout << "Исходная матрица:\n";
    printMatrix(matrix, M, N);

    int count;
    cout << "Введите количество раз для сдвига: ";
    cin >> count;

    //выбор направления сдвига 
    char direction;
    cout << "Введите направление сдвига (L - влево, R - вправо, U - вверх, D - вниз): ";
    cin >> direction;

    if (direction == 'L' || direction == 'R' || direction == 'l' || direction == 'r') {
        shiftRows(matrix, M, count, direction);
    }
    else if (direction == 'U' || direction == 'D' || direction == 'u' || direction == 'd') {
        shiftColumns(matrix, N, count, direction);
    }
    else {
        cout << "Неверный ввод\n";
        return 1;
    }

    //вывод изменненой матрицы
    cout << "Матрица после сдвига:\n";
    printMatrix(matrix, M, N);

    //освобождение памяти
    for (int i = 0; i < M; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}

//создание и инициализация матрицы
int** createMatrix(int M, int N) {

    int** matrix = new int* [M];
    for (int i = 0; i < M; ++i) {
        matrix[i] = new int[N];
    }
    for (int row = 0; row < M; ++row) {

        for (int col = 0; col < N; ++col) {

            matrix[row][col] = row * 2 + col;
        }
    }
    return matrix;
}

//вывод матрицы
void printMatrix(int** matrix, int M, int N) {

    for (int row = 0; row < M; ++row) {

        for (int col = 0; col < N; ++col) {

            cout << matrix[row][col] << '\t';
        }
        cout << '\n';
    }
}

void shiftRows(int** arr, int M, int shift, char direction) {

    for (int i = 0; i < M; i++) {
        //Инициализация временных переменных для хранения значений во время сдвига
        int temp_0 = arr[i][0];
        int temp_1 = 0;

        for (int j = 0, k = 0; k < M; k++) {

            if (direction == 'R') {

                temp_1 = arr[i][(j - shift + M) % M];//Вычисление новой позиции текущего элемента после сдвига вправо
                arr[i][(j - shift + M) % M] = temp_0; //Обновление значения в новой позиции сохраненным значением
                j = (j - shift + M) % M; //Обновление текущей позиции столбца
            }
            else {

                temp_1 = arr[i][(j + shift) % M];
                arr[i][(j + shift) % M] = temp_0;
                j = (j + shift) % M;
            }
            temp_0 = temp_1;//Обновление временного хранилища значением из новой позиции
        }
    }
}

void shiftColumns(int** arr, int n, int shift, char direction) {

    for (int j = 0; j < n; j++) {
        int temp_0 = arr[0][j];
        int temp_1 = 0;

        for (int i = 0, k = 0; k < n; k++) {

            if (direction == 'D') {

                temp_1 = arr[(i - shift + n) % n][j];
                arr[(i - shift + n) % n][j] = temp_0;
                i = (i - shift + n) % n;
            }
            else {

                temp_1 = arr[(i + shift) % n][j];
                arr[(i + shift) % n][j] = temp_0;
                i = (i + shift) % n;
            }
            temp_0 = temp_1;
        }
    }
}*/







