#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int bitDivide(int64_t *a, int64_t b) {
    int res = 0;
    while(*a - b >= 0){
        int bitShifter = 0;
        while(*a - ((b << 1) << bitShifter) >= 0) {
            bitShifter++;
        }
        res += 1 << bitShifter;
        // return divided value for next division using pointer
        *a -= b << bitShifter;
    }
    return res;
}
class Solution {
    public: 
    string fractionToDecimal(int numerator, int denominator) {
        string result;
        result = '"';
        string temp;
        int res = 0;
        // Check denominator is not 0
        if (!denominator) {
            cout << "Divide by 0 error";
            return 0;
        }
        // Handle Mersenne number division 
        // Handle positive or negative 
        if (numerator < 0 ^ denominator < 0) {
            result += '-';
            }
        // make each ints positive to use bitwise divide for faster division.
        int64_t aNumerator = abs(numerator);
        int64_t aDenominator = abs(denominator);
        res = bitDivide(&aNumerator, aDenominator);
        // add integer bigger than 0.
        result += to_string(res);
        // if divided result does not have non integer remainder, return integer result.
        if (!aNumerator) {
            result += '"';
            return result;
        }
    
        // if remainder cannot find repeated number in 50,000 times, it will stop searching the result.
        int remainderArray[50000];
        // add .
        result += '.';
        for (int i = 0; i < 50000; i++) {
            for (int j = 0; j < i; j++) {
                if (aNumerator == remainderArray[j]) {
                    temp = temp.insert(j, "(");
                    temp += ")\"";
                    result += temp;
                    return result;
                }
            }
            remainderArray[i] = aNumerator;
            aNumerator *= 10;
            temp += to_string(bitDivide(&aNumerator, aDenominator));
            if (!aNumerator) {
                temp += '"';
                result += temp;
                return result;
            }
        }
        // if it does not return 0 until 50,000 times and still have remainder, stop calculating.
        if (aNumerator) {
                temp += "...\"";
                result += temp;
                return result;
            }
            result += '"';
                return result;
            
    }
};

int main() {
    Solution S1;
    int numerator, denominator;
    cout << "Type numerator: ";
    cin >> numerator;
    cout << "Type Denominator: ";
    cin >> denominator;
    clock_t begin = clock();
    cout << S1.fractionToDecimal(numerator,denominator) << endl;
    clock_t end = clock();
    cout << double(end - begin) / CLOCKS_PER_SEC << " time passed(unit is second)";
}
