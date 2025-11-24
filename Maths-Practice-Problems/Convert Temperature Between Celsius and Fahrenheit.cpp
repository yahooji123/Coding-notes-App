
#include<iostream>
using namespace std;

/*

Conversion Formulas:
Celsius to Fahrenheit:

[ F = C \times \frac{9}{5} + 32 ]

Fahrenheit to Celsius:

[ C = (F - 32) \times \frac{5}{9} ]


 Examples:
Example 1:
Input:

temp = 0, conversion = "CtoF"

Output:

32.00

Explanation: 0 degrees Celsius is equivalent to 32 degrees Fahrenheit.

Example 2:
Input:

temp = 32, conversion = "FtoC"

Output:

0.00

Explanation: 32 degrees Fahrenheit is equivalent to 0 degrees Celsius.

Note:
The input will always be a floating-point number for temperature and a string for the conversion type, which will either be "CtoF" or "FtoC".
Example 1:

Input:

Input: temperature = 0, conversionType = 'CtoF'

Output:

32.00
Explanation:0°C converted to Fahrenheit: (0 × 9/5) + 32 = 32.00°F.

Example 2:

Input:

Input: temperature = 100, conversionType = 'CtoF'

Output:

212.00
Explanation:100°C converted to Fahrenheit: (100 × 9/5) + 32 = 212.00°F.

Example 3:

Input:

Input: temperature = -40, conversionType = 'CtoF'

Output:

-40.00
Explanation:-40°C and -40°F are the same temperature.

*/

class TemperatureConverter {
public:
  double convertTemperature(double temp, string conversionType) {
    // Implement the conversion here

    if (conversionType == "CtoF") {
    return  ((temp * 9) / 5) + 32;
    }

    return (temp - 32) * 5 / 9;
  }
};
