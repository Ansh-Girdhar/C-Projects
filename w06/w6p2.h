/*
	==================================================
	Workshop #6 (Part-2):
	==================================================
	Name   : Ansh Girdhar
	ID     : 152552204
	Email  : agirdhar@myseneca.ca
	Section: ZDD
*/

#define maxProduct 3
#define maxGrams 64
#define lbstokg 2.20462
struct ReportData
{
	int SKU;
	double PRICE;
	int CAL;
	double lbs_weight;
	double kg_weight;
	int gram_weight;
	double SERVING;
	double cost_serv;
	double CalCost_serv;
};
struct CatFoodInfo
{
	int sku;
	double price;
	double weight;
	int cal;
};
int getIntPositive(int* num);
double getDoublePositive(double* pos_dbl);
void openingMessage(const int numPRO);
struct CatFoodInfo getCatFoodInfo(const int sequence_num);
void displayCatFoodHeader(void);
void displayCatFoodData(const int Sku, const double* Price, const int Cal_ps, const double* Weight);
double convertLbsKg(const double* lbs_to_kg, double* kg_converted);
int convertLbsG(const double* lbs, int* result);
void convertLbs(const double* lbsweight, double* kgweight, int* result1);
double calculateServings(const int serving, const int total_serving, double* result);
double calculateCostPerServing(const double* product, const double* serv, double* result);
double calculateCostPerCal(const double* product_price, const double* total_cal, double* cal_result);
struct ReportData calculateReportData(const struct CatFoodInfo product_data);
void displayReportHeader(void);
void displayReportData(const struct ReportData display, const int cheap);
void displayFinalAnalysis(const struct CatFoodInfo data);
void start(void);
