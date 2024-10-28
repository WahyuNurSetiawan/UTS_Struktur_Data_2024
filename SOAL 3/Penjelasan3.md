# Jawaban Soal 3: Kalkulator Notasi Postfix Menggunakan Stack

Program ini mengimplementasikan kalkulator notasi _postfix_ menggunakan struktur data **stack**. Program ini dapat mengevaluasi ekspresi _postfix_ yang mendukung operasi aritmatika dasar (`+`, `-`, `*`, `/`) serta operator pangkat (`^`). Program juga menampilkan setiap langkah evaluasi dari ekspresi _postfix_.

## Penjelasan Kode

### 1. Kelas `Stack`

Kelas `Stack` adalah implementasi sederhana dari _stack_ yang membungkus `std::stack<float>` dan memiliki tiga metode:

- `push(float value)`: Menambahkan nilai ke puncak _stack_.
- `pop()`: Menghapus dan mengembalikan nilai dari puncak _stack_. Jika _stack_ kosong, program akan mengeluarkan pesan kesalahan.
- `isEmpty()`: Mengecek apakah _stack_ kosong.

```cpp
class Stack {
public:
    void push(float value) { st.push(value); }

    float pop() {
        if (st.empty()) {
            std::cerr << "Error: Stack kosong!\n";
            return 0;
        }
        float value = st.top();
        st.pop();
        return value;
    }

    bool isEmpty() const { return st.empty(); }

private:
    std::stack<float> st;
};
```

### 2. Fungsi `evaluatePostfix`

Fungsi `evaluatePostfix` mengevaluasi ekspresi _postfix_ dan mengembalikan hasil akhirnya. Fungsi ini menerima ekspresi dalam bentuk string, memprosesnya satu per satu, dan mengoperasikan setiap simbol sebagai berikut:

- **Angka**: Jika token adalah angka, nilai akan di-_push_ ke _stack_.
- **Operator**: Jika token adalah operator (`+`, `-`, `*`, `/`, `^`), program akan _pop_ dua elemen dari _stack_, melakukan operasi, dan hasilnya di-_push_ kembali ke _stack_.

Langkah-langkah evaluasi ditampilkan ke layar, dan nilai akhir yang ada di puncak _stack_ adalah hasil dari ekspresi _postfix_.

```cpp
float evaluatePostfix(const std::string &expression) {
    Stack stack;
    for (size_t i = 0; i < expression.size(); i++) {
        char token = expression[i];

        if (token == ' ') continue; // Lewati spasi

        if (isdigit(token)) {
            float number = token - '0';
            stack.push(number);
            std::cout << "Push: " << number << '\n';
        } else {
            float operand2 = stack.pop();
            float operand1 = stack.pop();
            float result;

            switch (token) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break;
                case '^': result = std::pow(operand1, operand2); break;
                default: std::cerr << "Operator tidak valid: " << token << '\n'; return 0;
            }

            stack.push(result);
            std::cout << "Operasi: " << operand1 << " " << token << " " << operand2 << " = " << result << '\n';
        }
    }
    return stack.pop();
}
```

### 3. Fungsi `main`

Fungsi `main` meminta pengguna untuk memasukkan ekspresi _postfix_, kemudian memanggil `evaluatePostfix` untuk menampilkan hasil evaluasi.

```cpp
int main() {
    std::string expression;
    std::cout << "Masukkan ekspresi postfix (misal: 5 3 + 8 2 - *): ";
    std::getline(std::cin, expression);

    float result = evaluatePostfix(expression);
    std::cout << "Hasil akhir: " << result << '\n';

    return 0;
}
```

---

## Contoh Input dan Output

### Contoh 1

#### Input

```
Masukkan ekspresi postfix (misal: 5 3 + 8 2 - *): 5 3 + 8 2 - *
```

#### Output

```
Push: 5
Push: 3
Operasi: 5 + 3 = 8
Push: 8
Push: 8
Push: 2
Operasi: 8 - 2 = 6
Operasi: 8 * 6 = 48
Hasil akhir: 48
```

### Contoh 2

#### Input

```
Masukkan ekspresi postfix (misal: 5 3 + 8 2 - *): 2 3 ^ 4 +
```

#### Output

```
Push: 2
Push: 3
Operasi: 2 ^ 3 = 8
Push: 4
Operasi: 8 + 4 = 12
Hasil akhir: 12
```
