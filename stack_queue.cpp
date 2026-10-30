
/*
    ==========================================
                  STACK & QUEUE
    ==========================================

    DESCRIPCION:
        Stack: LIFO.
        Queue: FIFO.

    COMPLEJIDAD:
        push: O(1)
        pop: O(1)
        top/front: O(1)

    APLICACIONES:
        - Balanceo de parentesis.
        - Evaluacion de expresiones.
        - BFS.
        - Procesamiento de secuencias.
*/

#include <bits/stdc++.h>
using namespace std;

// Comprobar parentesis balanceados
bool balanced(const string& s) {

    stack<char> st;

    for (char c : s) {

        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        }

        else if (c == ')' || c == ']' || c == '}') {

            if (st.empty())
                return false;

            char top = st.top();
            st.pop();

            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{'))
                return false;
        }
    }

    return st.empty();
}

int main() {

    // STACK
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << st.top() << '\n';

    st.pop();

    cout << st.top() << '\n';


    // QUEUE
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << q.front() << '\n';

    q.pop();

    cout << q.front() << '\n';


    // BALANCEO
    cout << balanced("{[()]}") << '\n';
    cout << balanced("{[(])}") << '\n';

    return 0;
}
