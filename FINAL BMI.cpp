#include<iostream>
using namespace std;

double calBMI(double weight, double height){
    return weight /(height*height);
}

string cata(double BMI){
    if (BMI < 18.5)
        return "Under weight";
    else if (BMI >= 18.5 && BMI < 25)
        return "Normal";
    else if (BMI >= 25 && BMI < 30)
        return "Over weight";
    else
        return "Obese";
}

void reco(string category){
    if (category == "Under weight"){
        cout<<"Increase calorie intake." << endl;
    }
    else if (category == "Normal"){
        cout<<"Maintain your diet."<<endl;
    }
    else if (category == "Over weight"){
        cout<<"Exercise regularly." << endl;
    }
    else {
        cout<<"Consult a doctor." << endl;
    }
}

void displayBMIChart() {
    cout << "\n------------------------------\n";
    cout << "       BMI Categories Chart\n";
    cout << "------------------------------\n";
    cout << "Underweight:   < 18.5\n";
    cout << "Normal weight: 18.5 - 24.9\n";
    cout << "Overweight:    25 - 29.9\n";
    cout << "Obese:         30 and above\n";
}

int main(){

    char again;

    do {
        int choice;
        double weight, height;

        cout<<"1) In kg and meters"<<endl;
        cout<<"2) Imperial system"<<endl;
        cout<<"Enter choice: ";
        cin >> choice;

        if (choice == 1){
            cout<<"Enter weight in kg and height in meters: ";
            cin >> weight >> height;
        }
        else if(choice == 2){
            cout<<"Enter weight in Pounds and height in inches: ";
            cin >> weight >> height;

            weight *= 0.453592; 
            height *= 0.0254;   
        }
        else {
            cout<<"Invalid choice"<<endl;
            cout<<"Do you want to try again? (y/n): ";
            cin >> again;
            continue;  
        }

        double BMI = calBMI(weight,height);

        cout << "\nRESULTS\n";
        cout << "-------\n";
        cout << "Your BMI is: " << BMI << endl;

        string category = cata(BMI);
        cout << "You fall in " << category << " category." << endl;

        cout << "------------------------------------"<<endl;        
        cout << "Recommendations for your health"<<endl;
        cout << "------------------------------------"<<endl;
        reco(category);

        displayBMIChart();

        cout << "\nDo you want to calculate again? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    cout << "\nThank you for using the BMI Calculator!" << endl;

    return 0;
}
