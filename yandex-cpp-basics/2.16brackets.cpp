#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

#ifdef ACTIVE_MAIN
int main() {
    std::string s;
    std::cin >> s;

    std::stack<char> st;

    std::unordered_map<char, char> brackets = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        }
        else {
            if (st.empty() || st.top() != brackets[c]) {
                std::cout << "NO" << std::endl;
                return 0;
            }
            st.pop();
        }
    }

    // Последовательность правильная, если стек пуст
    if (st.empty()) {
        std::cout << "YES" << std::endl;
    }
    else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
#endif

/*
   На вход подаётся скобочная последовательность — строка, которая состоит из скобок ()[]{}.
   Вам нужно определить, является ли она правильной. В правильной скобочной последовательности каждой открывающей скобке соответствует закрывающая и пары скобок корректно вложены друг в друга.

    Формат ввода
    Строка, состоящая из символов ()[]{}.

    Формат вывода
    Напечатайте YES, если скобочная последовательность является правильной, и NO в противном случае.
*/
