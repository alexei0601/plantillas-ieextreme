
/*
    ==========================================
               EXTENDED EUCLID
    ==========================================

    DESCRIPCION:
        Calcula gcd(a, b) y encuentra coeficientes
        x e y tales que:

            a*x + b*y = gcd(a, b)

    COMPLEJIDAD:
        Tiempo: O(log(min(a, b)))
        Espacio: O(log(min(a, b)))

    CUANDO UTILIZAR:
        - Ecuaciones diofanticas.
        - Inversos modulares.
        - Problemas de teoria de numeros.

    OBSERVACIONES:
        - Esta implementacion trabaja con
          entradas no negativas.
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll extendedGcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    ll x1, y1;

    ll g = extendedGcd(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return g;
}

int main() {
    ll a = 30;
    ll b = 18;

    ll x, y;

    ll g = extendedGcd(a, b, x, y);

    cout << "GCD: " << g << '\n';
    cout << "x: " << x << '\n';
    cout << "y: " << y << '\n';

    cout << a << "*" << x << " + "
         << b << "*" << y << " = "
         << a * x + b * y << '\n';

    return 0;
}
