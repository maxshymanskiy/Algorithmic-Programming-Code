#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

string processString(const string& input) 
{
    size_t spacePos = input.find(' ');
   
    string s = input.substr(0, spacePos);  // Áåðåìî ï³äðÿäîê äî ïåðøîãî ïðîá³ëó
    
    string result;
   
    size_t i = 0;

    while (i < s.length()) 
    {
        if (isdigit(s[i])) {
            bool precededByDot = (i > 0 && s[i - 1] == '.');
            size_t j = i;

            // Çáèðàºìî ãðóïó öèôð
            while (j < s.length() && isdigit(s[j])) {
                j++;
            }
            string digitGroup = s.substr(i, j - i);

            if (!precededByDot) {
                // Âèäàëÿºìî ïî÷àòêîâ³ íóë³
                size_t k = 0;

                while (k < digitGroup.length() - 1 && digitGroup[k] == '0')
                    k++;
                digitGroup = digitGroup.substr(k);

                // ßêùî âñ³ öèôðè áóëè íóëÿìè ³ ï³ñëÿ íèõ ³äå êðàïêà, çàëèøàºìî îäèí íóëü
                if (digitGroup.empty() && j < s.length() && s[j] == '.') 
                    digitGroup = "0";
            }
            else {
                // Ñêîðî÷óºìî äðîáîâó ÷àñòèíó äî äâîõ öèôð
                if (digitGroup.length() > 2) 
                    digitGroup = digitGroup.substr(0, 2);
            }

            result += digitGroup;
            i = j;
        }
        else {
            result += s[i];
            i++;
        }
    }
    return result;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string input;
    cout << "Ââåä³òü ðÿäîê: ";
    getline(cin, input);
    string output = processString(input);
    cout << "Ðåçóëüòàò: " << output << endl;
    return 0;
}
