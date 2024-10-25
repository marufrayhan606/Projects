#include <iostream>
#include "crops.h"
#include "menu.h"
using namespace std;

enum Location
{
    DHAKA,
    CHITTAGONG,
    RAJSHAHI,
    KHULNA,
    BARISAL,
    SYLHET,
    RANGPUR,
    MYMENSINGH
};
enum SoilType
{
    CLAY,
    SANDY    
};
enum Season
{
    SUMMER,
    MONSOON,
    WINTER
};

double landArea;
int choice;
Location landLocation;
double phLevel;
SoilType soil;
Season season;

void dataForCrops()
{

    cout << "Enter the land area in acres: ";
    cin >> landArea;

    cout << "Choose the land location: " << endl;
    cout << "1. Dhaka" << endl;
    cout << "2. Chittagong" << endl;
    cout << "3. Rajshahi" << endl;
    cout << "4. Khulna" << endl;
    cout << "5. Barisal" << endl;
    cout << "6. Sylhet" << endl;
    cout << "7. Rangpur" << endl;
    cout << "8. Mymensingh" << endl;
    do
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            landLocation = DHAKA;
            break;
        case 2:
            landLocation = CHITTAGONG;
            break;
        case 3:
            landLocation = RAJSHAHI;
            break;
        case 4:
            landLocation = KHULNA;
            break;
        case 5:
            landLocation = BARISAL;
            break;
        case 6:
            landLocation = SYLHET;
            break;
        case 7:
            landLocation = RANGPUR;
            break;
        case 8:
            landLocation = MYMENSINGH;
            break;
        default:
            cout << "Invalid choice. Please try again" << endl;
            break;
        }
    } while (!(choice >= 1 && choice <= 8));

    system("cls");

    cout << "Enter the PH level: ";
    cin >> phLevel;

    cout << "Choose the soil type: " << endl;
    cout << "1. Clay" << endl;
    cout << "2. Sandy" << endl;
    

    do
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            soil = CLAY;
            break;
        case 2:
            soil = SANDY;
            break;
        default:
            cout << "Invalid choice. Please try again" << endl;
            break;
        }
    } while (!(choice >= 1 && choice <= 2));

    cout << "Choose the current season: " << endl;
    cout << "1. Summer" << endl;
    cout << "2. Monsoon" << endl;
    cout << "3. Winter" << endl;
    do
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            season = SUMMER;
            break;
        case 2:
            season = MONSOON;
            break;
        case 3:
            season = WINTER;
            break;
        default:
            cout << "Invalid choice. Please try again" << endl;
            break;
        }
    } while (!(choice >= 1 && choice <= 3));
}


void suggestCrop()
{
    double seedAmount, seedCost, fertilizerCost;

    cout << "\nRecommended Crops Based on Your Input:\n";
    if (landLocation == DHAKA)
    {
        if (season == SUMMER)
        {
            if (soil == CLAY && phLevel >= 5.5 && phLevel <= 7.0)
            {
                cout << "- Rice\n";
                cout << "Recommended Fertilizer: Urea\n";
                seedAmount = landArea * 40;
                seedCost = seedAmount * 50;
                fertilizerCost = landArea * 500;
            }
            else if (soil == SANDY && phLevel >= 5.5 && phLevel <= 7.0)
            {
                cout << "- Corn\n";
                cout << "Recommended Fertilizer: DAP\n";
                seedAmount = landArea * 18;
                seedCost = seedAmount * 130;
                fertilizerCost = landArea * 550;
            }
        }
        else if (season == MONSOON)
        {
            if (soil == CLAY && phLevel >= 6.0 && phLevel <= 7.5)
            {
                cout << "- Jute\n";
                cout << "Recommended Fertilizer: Urea\n";
                seedAmount = landArea * 30;
                seedCost = seedAmount * 80;
                fertilizerCost = landArea * 500;
            }
            else if (soil == SANDY && phLevel >= 5.5 && phLevel <= 7.0)
            {
                cout << "- Sugarcane\n";
                cout << "Recommended Fertilizer: DAP\n";
                seedAmount = landArea * 60;
                seedCost = seedAmount * 40;
                fertilizerCost = landArea * 800;
            }
        }
        else if (season == WINTER)
        {
            if (soil == CLAY && phLevel >= 5.5 && phLevel <= 7.0)
            {
                cout << "- Wheat\n";
                cout << "Recommended Fertilizer: Urea\n";
                seedAmount = landArea * 50;
                seedCost = seedAmount * 70;
                fertilizerCost = landArea * 600;
            }
            else if (soil == SANDY && phLevel >= 5.5 && phLevel <= 7.0)
            {
                cout << "- Peas\n";
                cout << "Recommended Fertilizer: DAP\n";
                seedAmount = landArea * 45;
                seedCost = seedAmount * 70;
                fertilizerCost = landArea * 300;
            }
        }
    }
    else if (landLocation == CHITTAGONG)
    {
        if (season == MONSOON)
        {
            if (soil == CLAY && phLevel >= 5.5 && phLevel <= 7.5)
            {
                cout << "- Sugarcane\n";
                cout << "Recommended Fertilizer: DAP\n";
                seedAmount = landArea * 60;
                seedCost = seedAmount * 40;
                fertilizerCost = landArea * 800;
            }
            else if (soil == SANDY && phLevel >= 5.5 && phLevel <= 7.0)
            {
                cout << "- Pineapple\n";
                cout << "Recommended Fertilizer: Urea\n";
                seedAmount = landArea * 10;
                seedCost = seedAmount * 250;
                fertilizerCost = landArea * 600;
            }
        }
        else if (season == WINTER)
        {
            if (soil == CLAY && phLevel >= 6.0 && phLevel <= 7.5)
            {
                cout << "- Mustard\n";
                cout << "Recommended Fertilizer: Urea\n";
                seedAmount = landArea * 30;
                seedCost = seedAmount * 50;
                fertilizerCost = landArea * 400;
            }
            else if (soil == SANDY && phLevel >= 5.5 && phLevel <= 7.0)
            {
                cout << "- Peas\n";
                cout << "Recommended Fertilizer: DAP\n";
                seedAmount = landArea * 45;
                seedCost = seedAmount * 70;
                fertilizerCost = landArea * 300;
            }
        }
        else if (season == SUMMER)
        {
            if (soil == CLAY && phLevel >= 5.5 && phLevel <= 7.0)
            {
                cout << "- Brinjal\n";
                cout << "Recommended Fertilizer: Urea\n";
                seedAmount = landArea * 10;
                seedCost = seedAmount * 100;
                fertilizerCost = landArea * 600;
            }
            else if (soil == SANDY && phLevel >= 5.5 && phLevel <= 7.0)
            {
                cout << "- Pineapple\n";
                cout << "Recommended Fertilizer: Urea\n";
                seedAmount = landArea * 10;
                seedCost = seedAmount * 250;
                fertilizerCost = landArea * 600;
            }
        }
    }
    else if (landLocation == RAJSHAHI)
    {
        if (season == SUMMER)
        {
            if (soil == CLAY && phLevel >= 6.0 && phLevel <= 7.5)
            {
                cout << "- Mango\n";
                cout << "Recommended Fertilizer: Urea\n";
                seedAmount = landArea * 5;
                seedCost = seedAmount * 150;
                fertilizerCost = landArea * 1000;
            }
            else if (soil == SANDY && phLevel >= 5.5 && phLevel <= 7.0)
            {
                cout << "- Pineapple\n";
                cout << "Recommended Fertilizer: Urea\n";
                seedAmount = landArea * 10;
                seedCost = seedAmount * 250;
                fertilizerCost = landArea * 600;
            }
        }
        else if (season == WINTER)
        {
            if (soil == CLAY && phLevel >= 5.5 && phLevel <= 7.0)
            {
                cout << "- Potato\n";
                cout << "Recommended Fertilizer: Urea\n";
                seedAmount = landArea * 60;
                seedCost = seedAmount * 90;
                fertilizerCost = landArea * 500;
            }
            else if (soil == SANDY && phLevel >= 5.5 && phLevel <= 7.0)
            {
                cout << "- Peas\n";
                cout << "Recommended Fertilizer: DAP\n";
                seedAmount = landArea * 45;
                seedCost = seedAmount * 70;
                fertilizerCost = landArea * 300;
            }
        }
        else if (season == MONSOON)
        {
            if (soil == CLAY && phLevel >= 5.5 && phLevel <= 7.0)
            {
                cout << "- Watermelon\n";
                cout << "Recommended Fertilizer: Urea\n";
                seedAmount = landArea * 15;
                seedCost = seedAmount * 200;
                fertilizerCost = landArea * 700;
            }
            else if (soil == SANDY && phLevel >= 5.5 && phLevel <= 7.0)
            {
                cout << "- Pineapple\n";
                cout << "Recommended Fertilizer: Urea\n";
                seedAmount = landArea * 10;
                seedCost = seedAmount * 250;
                fertilizerCost = landArea * 600;
            }
        }
    }
    else if (landLocation == KHULNA)
    {
        if (season == SUMMER)
        {
            if (soil == CLAY && phLevel >= 6.0 && phLevel <= 7.0)
            {
                cout << "- Watermelon\n";
                cout << "Recommended Fertilizer: Urea\n";
                seedAmount = landArea * 15;
                seedCost = seedAmount * 200;
                fertilizerCost = landArea * 700;
            }
            else if (soil == SANDY && phLevel >= 5.5 && phLevel <= 7.0)
            {
                cout << "- Pineapple\n";
                cout << "Recommended Fertilizer: Urea\n";
                seedAmount = landArea * 10;
                seedCost = seedAmount * 250;
                fertilizerCost = landArea * 600;
            }
        }
        else if (season == WINTER)
        {
            if (soil == CLAY && phLevel >= 5.5 && phLevel <= 7.0)
            {
                cout << "- Cabbage\n";
                cout << "Recommended Fertilizer: Urea\n";
                seedAmount = landArea * 50;
                seedCost = seedAmount * 60;
                fertilizerCost = landArea * 400;
            }
            else if (soil == SANDY && phLevel >= 5.5 && phLevel <= 7.0)
            {
                cout << "- Peas\n";
                cout << "Recommended Fertilizer: DAP\n";
                seedAmount = landArea * 45;
                seedCost = seedAmount * 70;
                fertilizerCost = landArea * 300;
            }
        }
        else if (season == MONSOON)
        {
            if (soil == CLAY && phLevel >= 5.5 && phLevel <= 7.0)
            {
                cout << "- Brinjal\n";
                cout << "Recommended Fertilizer: Urea\n";
                seedAmount = landArea * 10;
                seedCost = seedAmount * 100;
                fertilizerCost = landArea * 600;
            }
            else if (soil == SANDY && phLevel >= 5.5 && phLevel <= 7.0)
            {
                cout << "- Pineapple\n";
                cout << "Recommended Fertilizer: Urea\n";
                seedAmount = landArea * 10;
                seedCost = seedAmount * 250;
                fertilizerCost = landArea * 600;
            }
        }
    }
    else if (landLocation == BARISAL)
    {
        if (season == SUMMER)
        {
            if (soil == CLAY && phLevel >= 5.5 && phLevel <= 6.5)
            {
                cout << "- Tomato\n";
                cout << "Recommended Fertilizer: Urea\n";
                seedAmount = landArea * 20;
                seedCost = seedAmount * 150;
                fertilizerCost = landArea * 500;
            }
            else if (soil == SANDY && phLevel >= 5.5 && phLevel <= 7.0)
            {
                cout << "- Pineapple\n";
                cout << "Recommended Fertilizer: Urea\n";
                seedAmount = landArea * 10;
                seedCost = seedAmount * 250;
                fertilizerCost = landArea * 600;
            }
        }
        else if (season == WINTER)
        {
            if (soil == CLAY && phLevel >= 6.0 && phLevel <= 7.5)
            {
                cout << "- Potato\n";
                cout << "Recommended Fertilizer: Urea\n";
                seedAmount = landArea * 30;
                seedCost = seedAmount * 100;
                fertilizerCost = landArea * 300;
            }
            else if (soil == SANDY && phLevel >= 5.5 && phLevel <= 7.0)
            {
                cout << "- Peas\n";
                cout << "Recommended Fertilizer: DAP\n";
                seedAmount = landArea * 45;
                seedCost = seedAmount * 70;
                fertilizerCost = landArea * 300;
            }
        }
        else if (season == MONSOON)
        {
            if (soil == CLAY && phLevel >= 5.5 && phLevel <= 7.0)
            {
                cout << "- Cucumber\n";
                cout << "Recommended Fertilizer: Urea\n";
                seedAmount = landArea * 15;
                seedCost = seedAmount * 80;
                fertilizerCost = landArea * 500;
            }
            else if (soil == SANDY && phLevel >= 5.5 && phLevel <= 7.0)
            {
                cout << "- Pineapple\n";
                cout << "Recommended Fertilizer: Urea\n";
                seedAmount = landArea * 10;
                seedCost = seedAmount * 250;
                fertilizerCost = landArea * 600;
            }
        }
    }
    else if (landLocation == SYLHET)
    {
        if (season == SUMMER)
        {
            if (soil == CLAY && phLevel >= 5.0 && phLevel <= 6.5)
            {
                cout << "- Pineapple\n";
                cout << "Recommended Fertilizer: Urea\n";
                seedAmount = landArea * 10;
                seedCost = seedAmount * 250;
                fertilizerCost = landArea * 600;
            }
            else if (soil == SANDY && phLevel >= 5.5 && phLevel <= 7.0)
            {
                cout << "- Pineapple\n";
                cout << "Recommended Fertilizer: Urea\n";
                seedAmount = landArea * 10;
                seedCost = seedAmount * 250;
                fertilizerCost = landArea * 600;
            }
        }
        else if (season == WINTER)
        {
            if (soil == CLAY && phLevel >= 6.0 && phLevel <= 7.0)
            {
                cout << "- Carrot\n";
                cout << "Recommended Fertilizer: Urea\n";
                seedAmount = landArea * 40;
                seedCost = seedAmount * 80;
                fertilizerCost = landArea * 350;
            }
            else if (soil == SANDY && phLevel >= 5.5 && phLevel <= 7.0)
            {
                cout << "- Peas\n";
                cout << "Recommended Fertilizer: DAP\n";
                seedAmount = landArea * 45;
                seedCost = seedAmount * 70;
                fertilizerCost = landArea * 300;
            }
        }
        else if (season == MONSOON)
        {
            if (soil == CLAY && phLevel >= 5.5 && phLevel <= 7.0)
            {
                cout << "- Cabbage\n";
                cout << "Recommended Fertilizer: Urea\n";
                seedAmount = landArea * 50;
                seedCost = seedAmount * 60;
                fertilizerCost = landArea * 400;
            }
            else if (soil == SANDY && phLevel >= 5.5 && phLevel <= 7.0)
            {
                cout << "- Pineapple\n";
                cout << "Recommended Fertilizer: Urea\n";
                seedAmount = landArea * 10;
                seedCost = seedAmount * 250;
                fertilizerCost = landArea * 600;
            }
        }
    }
    else if (landLocation == RANGPUR)
    {
        if (season == SUMMER)
        {
            if (soil == CLAY && phLevel >= 5.5 && phLevel <= 7.0)
            {
                cout << "- Rice\n";
                cout << "Recommended Fertilizer: Urea\n";
                seedAmount = landArea * 25;
                seedCost = seedAmount * 120;
                fertilizerCost = landArea * 400;

            }
            else if (soil == SANDY && phLevel >= 5.5 && phLevel <= 7.0)
            {
                cout << "- Corn\n";
                cout << "Recommended Fertilizer: DAP\n";
                seedAmount = landArea * 18;
                seedCost = seedAmount * 130;
                fertilizerCost = landArea * 550;
            }
        }
        else if (season == WINTER)
        {
            if (soil == CLAY && phLevel >= 6.0 && phLevel <= 7.5)
            {
                cout << "- Wheat\n";
                cout << "Recommended Fertilizer: Urea\n";
                seedAmount = landArea * 35;
                seedCost = seedAmount * 90;
                fertilizerCost = landArea * 450;
            }
            else if (soil == SANDY && phLevel >= 5.5 && phLevel <= 7.0)
            {
                cout << "- Peas\n";
                cout << "Recommended Fertilizer: DAP\n";
                seedAmount = landArea * 45;
                seedCost = seedAmount * 70;
                fertilizerCost = landArea * 300;
            }
        }
        else if (season == MONSOON)
        {
            if (soil == CLAY && phLevel >= 5.5 && phLevel <= 7.0)
            {
                cout << "- Jute\n";
                cout << "Recommended Fertilizer: Urea\n";
                seedAmount = landArea * 30;
                seedCost = seedAmount * 80;
                fertilizerCost = landArea * 500;
            }
            else if (soil == SANDY && phLevel >= 5.5 && phLevel <= 7.0)
            {
                cout << "- Pineapple\n";
                cout << "Recommended Fertilizer: Urea\n";
                seedAmount = landArea * 10;
                seedCost = seedAmount * 250;
                fertilizerCost = landArea * 600;
            }
        }
    }
    else if (landLocation == MYMENSINGH)
    {
        if (season == SUMMER)
        {
            if (soil == CLAY && phLevel >= 5.0 && phLevel <= 6.0)
            {
                cout << "- Corn\n";
                cout << "Recommended Fertilizer: DAP\n";
                seedAmount = landArea * 18;
                seedCost = seedAmount * 130;
                fertilizerCost = landArea * 550;
            }
            else if (soil == SANDY && phLevel >= 5.5 && phLevel <= 7.0)
            {
                cout << "- Pineapple\n";
                cout << "Recommended Fertilizer: Urea\n";
                seedAmount = landArea * 10;
                seedCost = seedAmount * 250;
                fertilizerCost = landArea * 600;
            }
        }
        else if (season == WINTER)
        {
            if (soil == CLAY && phLevel >= 6.5 && phLevel <= 7.5)
            {
                cout << "- Peas\n";
                cout << "Recommended Fertilizer: DAP\n";
                seedAmount = landArea * 45;
                seedCost = seedAmount * 70;
                fertilizerCost = landArea * 300;
            }
            else if (soil == SANDY && phLevel >= 5.5 && phLevel <= 7.0)
            {
                cout << "- Peas\n";
                cout << "Recommended Fertilizer: DAP\n";
                seedAmount = landArea * 45;
                seedCost = seedAmount * 70;
                fertilizerCost = landArea * 300;
            }
        }
        else if (season == MONSOON)
        {
            if (soil == CLAY && phLevel >= 5.5 && phLevel <= 7.0)
            {
                cout << "- Watermelon\n";
                cout << "Recommended Fertilizer: Urea\n";
                seedAmount = landArea * 15;
                seedCost = seedAmount * 200;
                fertilizerCost = landArea * 700;
            }
            else if (soil == SANDY && phLevel >= 5.5 && phLevel <= 7.0)
            {
                cout << "- Pineapple\n";
                cout << "Recommended Fertilizer: Urea\n";
                seedAmount = landArea * 10;
                seedCost = seedAmount * 250;
                fertilizerCost = landArea * 600;
            }
        }
    }

    cout << "Approximate Seed Amount: " << seedAmount << " kg\n";
    cout << "Approximate Seed Cost: " << seedCost << " tk\n";
    cout << "Recommended Fertilizer Cost: " << fertilizerCost << " tk\n";

    if (phLevel < 5.5)
    {
        cout << "\nNote: Soil is acidic. Consider adding lime.\n";
    }
    else if (phLevel > 7.5)
    {
        cout << "\nNote: Soil is alkaline. Consider adding sulfur.\n";
    }

    cout << "\n\nPress any key to return to Home Screen";
    cin.ignore();
    cin.get();
    
    if (loginUser())
    {
        loggedInLayout();
    }
    else
    {
        homeLayout();
    }
    
}


void crops()
{
    system("cls");
    dataForCrops();
    system("cls");
    suggestCrop();
}