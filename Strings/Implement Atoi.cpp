#include <iostream>
#include <string>
#include <climits>
using namespace std;

/*

Given a string s, the objective is to convert it into integer format without utilizing any built-in functions. Refer the below steps to know about atoi() function.

Cases for atoi() conversion:

Skip any leading whitespaces.
Check for a sign (‘+’ or ‘-‘), default to positive if no sign is present.
Read the integer by ignoring leading zeros until a non-digit character is encountered or end of the string is reached. If no digits are present, return 0.
If the integer is greater than 231 – 1, then return 231 – 1 and if the integer is smaller than -231, then return -231.
Examples:

Input: s = "-123"
Output: -123
Explanation: It is possible to convert -123 into an integer so we returned in the form of an integer
Input: s = "  -"
Output: 0
Explanation: No digits are present, therefore the returned answer is 0.
Input: s = " 1231231231311133"
Output: 2147483647
Explanation: The converted number will be greater than 231 – 1, therefore print 231 – 1 = 2147483647.
Input: s = "-999999999999"
Output: -2147483648
Explanation: The converted number is smaller than -231, therefore print -231 = -2147483648.
Input: s = "  -0012gfg4"
Output: -12
Explanation: After ignoring leading zeros nothing is read after -12 as a non-digit character ‘g’ was encountered.

*/

class Solution
{
public:
    int myAtoi(string s)
    {
        int num = 0;
        int i = 0;
        int sign = 1; // +ve

        // Skip leading spaces
        while (i < s.size() && s[i] == ' ')
        {
            i++;
        }

        //  Check sign
        if (i < s.size() && (s[i] == '-' || s[i] == '+'))
        {
            sign = (s[i] == '+') ? 1 : -1;
            i++;
        }

        //  Convert digits
        while (i < s.size() && isdigit(s[i]))
        {
            //  Handle overflow
            if (num > INT_MAX / 10 ||
                (num == INT_MAX / 10 && s[i] > '7'))
            {
                return (sign == -1) ? INT_MIN : INT_MAX;
            }

            num = num * 10 + (s[i] - '0');
            i++;
        }

        return num * sign;
    }
};

/*

📘 String to Integer (myAtoi) — Complete Explanation
🔹 Problem Statement (Simple Language)
Hume ek string di jaati hai.
Hume us string ke starting part se ek integer banana hota hai, lekin kuch strict rules follow karne hote hain.
Hum:
string ke beech se number nahi utha sakte
direct library function (stoi) use nahi kar sakte
overflow / underflow ko handle karna zaroori hai
🔹 Important Rules (Ye clear hone chahiye)
Leading spaces ignore kiye jaate hain
Optional sign (+ / −) ho sakta hai
Digits continuous hone chahiye
Digit ke baad non-digit aaya → stop
Agar pehle hi non-digit aa gaya → answer = 0
Answer 32-bit signed integer range me hona chahiye
Overflow / underflow hone par limit return hoti hai
🔹 32-bit Integer Range (Bahut Important)
Maximum (INT_MAX) = 2147483647
Minimum (INT_MIN) = -2147483648
Is range ke bahar jaane par:
Positive → INT_MAX
Negative → INT_MIN
🔹 Step-by-Step THEORY (Without Code)
🧩 Step 1: Leading Spaces Ignore Karna
String ke start me jitne bhi spaces hain, unka koi matlab nahi.
Real number wahi se start hota hai jahan pehla non-space character milta hai.
📌 Example
"   123" → "123"
🧩 Step 2: Sign Identify Karna
Spaces ke baad:
'+' mile → number positive
'-' mile → number negative
Kuch nahi mile → positive by default
📌 Example
"-45" → negative
"+78" → positive
"90" → positive
🧩 Step 3: Digits Read Karna
Sign ke baad sirf digits padhe jaate hain.
Jaise hi koi non-digit character mile — reading stop.
📌 Example
"4193 with words" → 4193
"12a34" → 12
🧩 Step 4: Agar Digit Start Hone Se Pehle Letter Aa Jaye
Agar spaces ke baad hi letter aa gaya,
to valid integer exist nahi karta.
📌 Example
"words 123" → 0
🧩 Step 5: Overflow / Underflow Logic (Most Important)
Har naya digit add karte waqt number aise banta hai:
new_number = old_number × 10 + digit
Socho:
Copy code

INT_MAX = 2147483647
INT_MAX / 10 = 214748364
Agar:
current number 214748364 hai
aur next digit 7 se badi hai
to:
Copy code

214748364 × 10 + 8 = 2147483648  ❌ overflow
Isliye:
Last digit sirf 7 tak hi allowed hai
🧩 Step 6: Final Answer Return
Digits se jo number bana:
uspar sign lagaya jaata hai
aur final integer return kiya jaata hai
🔁 One-Line Flow (Yaad Rakhne ke Liye)
Spaces hatao → sign dekho → digits padho → non-digit pe ruk jao → overflow check → answer return

*/