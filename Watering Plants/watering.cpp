/*
 * watering.cpp
 *
 *  Created on: Sep 4, 2017
 *      Author: Manogna Sindhusha Mujje
 *      SID: 012445225
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int plan_near(void);
int plan_far(void);
int faucet(int unwatered_plants, int cum_steps, int water_amount, int cum_step_units);
void plant_print(int unwatered_plants, int cum_steps, int water_amount);
void faucet_print(int cum_steps, int water_amount);
void summary(int cum_steps, int cum_step_units);
void result (int cum_step_units_near, int cum_step_units_far);

int watering_plant; // Number of the plant that is being watered
int watered_plants; // Number of watered plants
int unwatered_plants; // Number of plants that have not been watered
int plant_count; // Number of plants read from input file
int steps; // Number of steps taken
int cum_steps; // Cumulative steps taken so far
int cum_step_units_near; // Cumulative step-units with Plan Near
int cum_step_units_far; // Cumulative step-units with Plan Far
int cum_step_units; // Cumulative step-units when walking towards FAUCET
int water_amount; // Amount of water in the can
bool flag; // Flag to set to TRUE when walking from FAUCET after filling the can
string plan; // Type of plan
string Near = "Near", Far = "Far";

const int UNITS_PER_CAN = 3;
const string INPUT_FILE_NAME = "counts.txt";


int main()
{
	flag = false;
    ifstream input;
    input.open(INPUT_FILE_NAME);
    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }

    do
    {
    		input >> plant_count;
    		if (plant_count != 0)
    		{

  // Plan Near

		cout << endl;
		cout << "==========================" << endl;
		cout << " Plan Near with " << plant_count << " plants" << endl;
		cout << "==========================" << endl;
		cout << endl;
		cout << "Where      Cum. steps  Water amt.  Cum. step-units" << endl;
		cout << "---------  ----------  ----------  ---------------" << endl;

		plan_near(); // Implement Plan Near


  // Plan Far

		cout << endl;
		cout << "==========================" << endl;
		cout << " Plan Far with " << plant_count << " plants" << endl;
		cout << "==========================" << endl;
		cout << endl;
		cout << "Where      Cum. steps  Water amt.  Cum. step-units" << endl;
		cout << "---------  ----------  ----------  ---------------" << endl;

		plan_far(); // Implement Plan Far

		//Display which plan is better
    	    result(cum_step_units_near, cum_step_units_far);
    		}

    } while (plant_count > 0);

    return 0;
}

int plan_near(void)
{
	//Initializing all the required variables
	cum_steps = 0;
	cum_step_units_near = 0;
	water_amount = UNITS_PER_CAN + 1;
	plan = "Near";
	flag = false;

	for (watering_plant = 1; watering_plant<=plant_count; watering_plant++)
	{
		//Step-Units taken from FAUCET to plants
		if (flag == true) // After the can refill till the next unwatered plant
		{
			water_amount = UNITS_PER_CAN + 1;
			steps = watered_plants + 1;
			flag = false;
		}
		else // At all other times
		{
			steps = 1;
		}

		cum_steps = cum_steps + steps;
		water_amount--;
		cum_step_units_near = cum_step_units_near + (steps*water_amount);

		watered_plants = watering_plant;
		unwatered_plants = plant_count - watering_plant;

		//Print the step details after watering each plant
		plant_print(watering_plant, cum_steps, water_amount);
		cout << setw(16) << cum_step_units_near << endl;

		// Step-Units taken on the way back to FAUCET
		if (water_amount == 1) //To refill the can when empty
		{
			cum_steps = faucet(watered_plants, cum_steps, water_amount, cum_step_units_near);
			flag = true;
		}
		else if (watered_plants == plant_count) //To complete the trip after all plants are watered
		{
			cum_step_units_near = faucet(watered_plants, cum_steps, water_amount, cum_step_units_near);
		}

	}

	return cum_step_units_near;
}

int plan_far(void)
{
	//Initializing all the required variables
	watered_plants = 0;
	cum_steps = 0;
	cum_step_units_far = 0;
	water_amount = UNITS_PER_CAN + 1; //Equals to 3 during first iteration
	plan = "Far";
	flag = false;

	for (watering_plant = plant_count; watering_plant>0; watering_plant--)
	{
		watered_plants++;
		if (flag == true) // After the can refill till the next unwatered plant
		{
			water_amount = UNITS_PER_CAN + 1; //Equals to 3 during this iteration
			steps = unwatered_plants;
			flag = false;
		}
		else if (watered_plants == 1) //For the very first time in Plan Far
		{
			steps = plant_count;
		}
		else // At all other times
		{
			steps = 1;
		}

		cum_steps = cum_steps + steps;
		water_amount--;
		cum_step_units_far = cum_step_units_far + (steps*water_amount);

		unwatered_plants = watering_plant - 1;

		//Print the step details after watering each plant
		plant_print(watering_plant, cum_steps, water_amount);
		cout << setw(16) << cum_step_units_far << endl;

		// Step-Units taken on the way back to FAUCET
		if (water_amount == 1) //To refill the can when empty
		{
			cum_steps = faucet(watering_plant, cum_steps, water_amount, cum_step_units_far);
			flag = true;
		}
		else if (unwatered_plants == 0) //To complete the trip after all plants are watered
		{
			cum_step_units_far = faucet(watering_plant, cum_steps, water_amount, cum_step_units_far);
		}
	}

	return cum_step_units_far;
}

int faucet(int watered_plants, int cum_steps, int water_amount, int cum_step_units)
{
	if(plan == "Near")
	{
		steps = watered_plants;
	}
	else
	{
		steps = watering_plant;
	}
	cum_steps = cum_steps + steps;
	water_amount--;
	cum_step_units = cum_step_units + (steps*water_amount);

	//Print step details to go to FAUCET
	faucet_print(cum_steps, water_amount);
	cout << setw(16) << cum_step_units << endl;

	if((plan == "Near" && watered_plants == plant_count) || (plan == "Far" && unwatered_plants == 0)) //When the trip is over
	{
		summary(cum_steps, cum_step_units); //Prints trip summary at the end of the each trip
		return cum_step_units;
	}
	else //At all other times
	{
		return cum_steps;
	}
}

void plant_print(int watered_plants, int cum_steps, int water_amount)
{
	cout << "Plant" << setw(3) << watered_plants << setw(9) << cum_steps << setw(11)
		 << water_amount;
}

void faucet_print(int cum_steps, int water_amount)
{
	cout << "FAUCET" << setw(11) << cum_steps << setw(11) << water_amount;
}
void summary(int cum_steps, int cum_step_units)
{
	cout << endl;
	cout << "Plan" << " " << plan << ": " << "Total steps = " << cum_steps << ", " << "total step-units = " << cum_step_units << endl;
}

void result (int cum_step_units_near, int cum_step_units_far)
{
	int diff;

	cout << endl;
	cout << "*** With " << plant_count << " plants, Plan" ;

	if (cum_step_units_near == cum_step_units_far)
	{
	cout << " Near and Plan Far, result in" << diff << " step-units each." << endl;
	}

	else if (cum_step_units_near > cum_step_units_far)
	{
		diff = cum_step_units_near - cum_step_units_far;
		cout << " " << Far;
	}
	else
	{
		diff = cum_step_units_far - cum_step_units_near;
		cout << " " << Near;
	}
	cout << " is better with " << diff << " fewer step-units." << endl;
}
