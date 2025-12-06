#include <iostream>
#include <iomanip>
using namespace std;

void determineBMI(float height, float weight)
{
    //Calculate BMI
    float bmi = weight / (height * height);

    //Determine BMI category
    if (bmi < 18.5)
        cout << "BMI: " << bmi << " (Underweight)" << endl;
    else if (bmi < 25)
        cout << "BMI: " << bmi << " (Normal weight)" << endl;
    else if (bmi < 30)
        cout << "BMI: " << bmi << " (Overweight)" << endl;
    else
        cout << "BMI: " << bmi << " (Obese)" << endl;
}

int main()
{
    int weight;
    float height, bmi;

    //Input weight in kg
    cout << "Enter weight in kg:" << endl;
    cin >> weight;

    //Input height in metres
    cout << "Enter height in metres:" << endl;
    cin >> height;

    //Determine BMI category
    determineBMI(height, weight);

    return 0;
}