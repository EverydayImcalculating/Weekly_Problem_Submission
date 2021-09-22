#include <iostream>
using namespace std;
int main () {
    double Weight, Height;
    cout <<  "******BODY MASS INDEX CALCULATOR******\n";
    cout << "Enter your Weight in Kilogram : ";
    cin >> Weight;
    cout << "Enter your Height in Meter : ";
    cin >> Height;
    cout << endl;
    double BMI;
    BMI = Weight / (Height * Height);
    if (BMI < 18.5) {
        cout << "Your weight is in the Underweight.\n\n";
    } else if (BMI >= 18.5 && BMI <= 24.9) {
        cout << "Your weight is in the Healthy weight.\n\n";
    } else if (BMI >= 25.0 && BMI <= 29.9) {
        cout << "Your weight is in Risk of overweight.\n\n";
    } else {
        cout << "Your weight is in the Overweight.\n\n";
    } 
    
} 