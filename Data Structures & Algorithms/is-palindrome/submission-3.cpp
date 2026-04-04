#include <cctype>  // Для tolower

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        while (l < r) {
            // Пропускаем символы, которые не являются буквами или цифрами
            if (!isalnum(s[l])) {
                l++;
                continue;
            }
            if (!isalnum(s[r])) {
                r--;
                continue;
            }
            
            // Преобразуем символы в нижний регистр
            if (isupper(s[l])) {
                s[l] = tolower(s[l]);
            }
            if (isupper(s[r])) {
                s[r] = tolower(s[r]);
            }

            // Сравниваем символы
            if (s[l] != s[r]) {
                return false;
            }

            l++;
            r--;
        }
        return true;
    }
};