#include <stdio.h>
#include <stdlib.h>

int main() 
{
	int days = 0;

	printf("How many days would you like to analyse? ");
	scanf_s("%i", &days);

	float* arrayOfDays = (float*)malloc(days * sizeof(float));

	float avarage = 0;
	int highestTemperatureIndex = 0;
	int lowestTemperatureIndex = 0;
	int moreThanAvarage = 0;

	for (int i = 0; i < days; i++)
	{
		printf("What was the temperature on day %i? ", i + 1);
		scanf_s("%f", &arrayOfDays[i]);
		if (arrayOfDays[i] > arrayOfDays[highestTemperatureIndex])
		{
			highestTemperatureIndex = i;
		}
		else if (arrayOfDays[i] < arrayOfDays[lowestTemperatureIndex]) 
		{
			lowestTemperatureIndex = i;
		}
		avarage += arrayOfDays[i];
	}

	avarage /= days;

	for (int i = 0; i < days; i++)
	{
		if (arrayOfDays[i] > avarage)
		{
			moreThanAvarage++;
		}
	}

	printf("The highest temperature happened on the day %i, and was %.2f\n", highestTemperatureIndex + 1, arrayOfDays[highestTemperatureIndex]);
	printf("The lowest temperature happened on the day %i, and was %.2f\n", lowestTemperatureIndex + 1, arrayOfDays[lowestTemperatureIndex]);
	printf("The avarage temperature was %.2f\n", avarage);
	printf("%i days had temperature above avarage\n", moreThanAvarage);

	free(arrayOfDays);

	return 0;
}