/*
	==================================================
	Workshop #6 (Part-2):
	==================================================
	Name   : Ansh Girdhar
	ID     : 152552204
	Email  : agirdhar@myseneca.ca
	Section: ZDD
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "w6p2.h"
int getIntPositive(int* num)
{
	int value;
	do {
		scanf("%d", &value);
		if (value <= 0) 
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (value <= 0);
	if (num != 0)
	{
		*num = value;
	}
	return value;
}
double getDoublePositive(double* pos_dbl)
{
	double value;
	do {
		scanf("%lf", &value);
		if (value <= 0) {
			printf("ERROR: Enter a positive value: ");
		}
	} while (value <= 0);
	if (pos_dbl != NULL)
	{
		*pos_dbl = value;
	}
	return value;
}
void openingMessage(const int numPRO)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", numPRO);
	printf("NOTE: A 'serving' is %dg\n", maxGrams);
}
struct CatFoodInfo getCatFoodInfo(const int sequence_num)
{
	struct CatFoodInfo get = { 0 };
	printf("\nCat Food Product #%d\n", sequence_num + 1);
	
	printf("--------------------\n");
	
	printf("SKU           : ");
	getIntPositive(&get.sku);

	printf("PRICE         : $");
	getDoublePositive(&get.price);

	printf("WEIGHT (LBS)  : ");
	getDoublePositive(&get.weight);

	printf("CALORIES/SERV.: ");
	getIntPositive(&get.cal);

	return get;
}

void displayCatFoodHeader(void)
{
	printf("\nSKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

void displayCatFoodData(const int Sku, const double* Price, const int Cal_ps, const double* Weight)
{
	printf("%07d %10.2lf %10.1lf %8d\n", Sku, *Price, *Weight, Cal_ps);
}

double convertLbsKg(const double* lbs_to_kg, double* kg_converted)
{
	double wght;
	
	wght = *lbs_to_kg;
	
	wght = wght / lbstokg;
	
	if (kg_converted != 0)
	{
		*kg_converted = wght;
	}
	
	return wght;
}
int convertLbsG(const double* lbs, int* result)
{
	double num;
	double value;
	int converted;
	num = *lbs;
	value = convertLbsKg(&num, &value);
	converted = value * 1000;
	if (result != 0)
	{
		*result = converted;
	}
	return converted;
}
void convertLbs(const double* lbsweight, double* kgweight, int* result1)
{
	double num, value;
	int answer;
	num = *lbsweight;
	value = convertLbsKg(&num, kgweight);
	*kgweight = value;
	answer = value * 1000;
	*result1 = answer;
}
double calculateServings(const int serving, const int total_serving, double* result)
{
	double i, j;
	i = serving;
	j = total_serving;
	double answer;
	answer = j / i;
	if (result != 0)
	{
		*result = answer;
	}
	return answer;
}
double calculateCostPerServing(const double* product, const double* serv, double* result)
{
	double num, value, answer;
	num = *serv;
	value = *product;
	answer = value / num;
	if (result != 0)
	{
		*result = answer;
	}
	return answer;
}
double calculateCostPerCal(const double* product_price, const double* total_cal, double* cal_result)
{
	double num, value, answer;
	num = *total_cal;
	value = *product_price;
	answer = value / num;
	if (cal_result != 0)
	{
		*cal_result = answer;
	}
	return answer;
}
struct ReportData calculateReportData(const struct CatFoodInfo product_data)
{
	struct ReportData report;
	double total_cal;
	report.SKU = product_data.sku;
	report.PRICE = product_data.price;
	report.CAL = product_data.cal;
	report.lbs_weight = product_data.weight;
	report.kg_weight = convertLbsKg(&report.lbs_weight, &report.kg_weight);
	report.gram_weight = convertLbsG(&report.lbs_weight, &report.gram_weight);
	report.SERVING = calculateServings(maxGrams, report.gram_weight, &report.SERVING);
	report.cost_serv = calculateCostPerServing(&report.PRICE, &report.SERVING, &report.cost_serv);
	total_cal = report.CAL * report.SERVING;
	report.CalCost_serv = calculateCostPerCal(&report.PRICE, &total_cal, &report.CalCost_serv);
	return report;
}
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg\n", maxGrams);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}
void displayReportData(const struct ReportData display, const int cheap)
{
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", display.SKU, display.PRICE, display.lbs_weight, display.kg_weight, display.gram_weight, display.CAL, display.SERVING, display.cost_serv, display.CalCost_serv);
}
void displayFinalAnalysis(const struct CatFoodInfo data)
{
	printf("Final Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%.2lf\n", data.sku, data.price);
	printf("\nHappy shopping!\n");
}
void start(void)
{
	struct ReportData data[maxProduct];
	int i, j, cheap_product;
	cheap_product = 0;
	int count = 0;
	struct CatFoodInfo catfoodinfo[maxProduct] = { {0} };
	openingMessage(maxProduct);
	for (i = 0; i < maxProduct; i++)
	{
		catfoodinfo[i] = getCatFoodInfo(i);
		data[i] = calculateReportData(catfoodinfo[i]);
	}
	for (i = 0; i < maxProduct; i++)
	{
		for (j = 0; j < maxProduct; j++)
		{
			if ( data[i].cost_serv < data[j].cost_serv)
			{
				count++;
				if (count == maxProduct - 1)
				{
					cheap_product = i;
				}
			}
		}
	}
	displayCatFoodHeader();
	
	for (i = 0; i < maxProduct; i++)
	{
		displayCatFoodData(catfoodinfo[i].sku, &catfoodinfo[i].price, catfoodinfo[i].cal, &catfoodinfo[i].weight);
	}
	printf("\n");
	displayReportHeader();

	for (i = 0; i < maxProduct; i++)
	{
		displayReportData(data[i], cheap_product);
		if (i == cheap_product)
		{
			printf(" ***");
		}
		printf("\n");
	}
	printf("\n");
	
	displayFinalAnalysis(catfoodinfo[cheap_product]);
}
