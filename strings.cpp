
/*
    ==========================================
                      STRINGS
    ==========================================

    DESCRIPCION:
        Manipulacion y procesamiento de cadenas.

    CONTENIDO:
        - Inversion.
        - Palindromos.
        - Frecuencia de caracteres.
        - Busqueda de subcadenas.
        - Conversion numerica.

    COMPLEJIDAD:
        Depende de la operacion.

    APLICACIONES:
        - Procesamiento de texto.
        - Comparacion de cadenas.
        - Busqueda de patrones.
*/

#include <bits/stdc++.h>
using namespace std;

// Comprobar palindromo
bool isPalindrome(const string& s) {

    int left = 0;
    int right = (int)s.size() - 1;

    while (left < right) {

        if (s[left] != s[right])
            return false;

        left++;
        right--;
    }

    return true;
}

// Frecuencia de caracteres
map<char, int> frequency(const string& s) {

    map<char, int> freq;

    for (char c : s)
        freq[c]++;

    return freq;
}

int main() {

    string s = "radar";

    // Longitud
    cout << s.size() << '\n';

    // Invertir
    string reversed = s;
    reverse(reversed.begin(), reversed.end());

    cout << reversed << '\n';

    // Palindromo
    cout << isPalindrome(s) << '\n';

    // Buscar subcadena
    string text = "competitive programming";

    cout << text.find("programming") << '\n';

    // Frecuencia
    auto freq = frequency("banana");

    for (auto [c, count] : freq)
        cout << c << ": " << count << '\n';

    // Conversion
    int n = stoi("123");

    cout << n + 10 << '\n';

    return 0;
}
