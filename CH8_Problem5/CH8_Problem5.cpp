/********************************************************************************

Author: Sergio M. Castillo

Write a program that can be used to calculate the federal tax. The tax is
calculated as follows: For single people, the standard exemption is $4,000; for
married people, the standard exemption is $7,000. A person can also put up
to 6% of his or her gross income in a pension plan. The tax rates are as
follows: If the taxable income is:

• Between $0 and $15,000, the tax rate is 15%.
• Between $15,001 and $40,000, the tax is $2,250 plus 25% of the taxable
  income over $15,000.
• Over $40,000, the tax is $8,460 plus 35% of the taxable income over
  $40,000.

Prompt the user to enter the following information:

• Marital status
• If the marital status is ‘‘married,’’ ask for the number of children under
  the age of 14
• Gross salary (If the marital status is ‘‘married’’ and both spouses have
  income, enter the combined salary.)
• Percentage of gross income contributed to a pension fund

Your program must consist of at least the following functions:

a. Function getData: This function asks the user to enter the relevant data.
b. Function taxAmount: This function computes and returns the tax owed.

To calculate the taxable income, subtract the sum of the standard exemption,
the amount contributed to a pension plan, and the personal exemption,
which is $1,500 per person. (Note that if a married couple has two children
under the age of 14, then the personal exemption is $1,500 * 4 = $6,000.)

**********************************************************************************/

#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

void getData(ifstream& inF, char& maritalStatus, double& numOfChildren, double& grossSalary, double& pensionPercentage);
double taxAmount(char marriageStatus, double numOfChildrenInHousehold, double grossIncome, double pension);


int main()
{
	ifstream inFile;

	int counter;
	double children, gSalary, pensionPer, totalTaxes;
	char mStatus;

	inFile.open("familyInfo.txt");

	if (!inFile)
	{
		cout << "Cannot open input file. "
			 << "Program terminates!" << endl;
		system("pause");
		return 1;
	}
	
	cout << fixed << showpoint << setprecision(2);

	for (counter = 0; counter < 5; counter++)
	{
		getData(inFile, mStatus, children, gSalary, pensionPer);
		totalTaxes = taxAmount(mStatus, children, gSalary, pensionPer);

		cout << "$" << totalTaxes << endl;
	}

	inFile.close();

	system("pause");
	return 0;
}

void getData(ifstream& inF, char& maritalStatus, double& numOfChildren, double& grossSalary, double& pensionPercentage)

{
	inF >> maritalStatus;

	if (maritalStatus == 'm' || maritalStatus == 'M')

		inF >> numOfChildren >> grossSalary >> pensionPercentage;
	else
	    inF >> grossSalary >> pensionPercentage;
}

double taxAmount(char marriageStatus, double numOfChildrenInHousehold, double grossIncome, double pension)
{
	double const STANDARD_EXEMPTION_FOR_MARRIED_PEOPLE = 7000.00;
	double const STANDARD_EXEMPTION_FOR_SINGLE_PEOPLE = 4000.00;
	double const MAX_INCOME_PERCANTAGE_FOR_PENSION_PLAN = 0.06;
	double const TAX_RATE_FOR_FIRST_BRACKET = 0.15;
	double const TAX_RATE_FOR_SECOND_BRACKET = 0.25;
	double const TAX_AMOUNT_FOR_SECOND_BRACKET = 2250.00;
	double const TAX_RATE_FOR_THIRD_BRACKET = 0.35;
	double const TAX_AMOUNT_FOR_THIRD_BRACKET = 8460.00;
	double const MAX_INCOME_ON_FIRST_BRACKET = 15000.00;
	double const MAX_INCOME_ON_SECOND_BRACKET = 40000.00;
	double const AMOUNT_FOR_PERSONAL_EXEMPTION = 1500.00;
	double const NUMBER_OF_ADULTS_IN_HOUSEHOLD = 2.0;
	double const PERCENT = 100.0;

	double federalTaxes, taxableAmount;
	double penPercent = pension / PERCENT;
	double penTotal = grossIncome * penPercent;

	if (penPercent > MAX_INCOME_PERCANTAGE_FOR_PENSION_PLAN)
		penTotal = grossIncome * MAX_INCOME_PERCANTAGE_FOR_PENSION_PLAN;

	if (marriageStatus == 's' || marriageStatus == 'S')
	{
		taxableAmount = (grossIncome - AMOUNT_FOR_PERSONAL_EXEMPTION - penTotal - STANDARD_EXEMPTION_FOR_SINGLE_PEOPLE);
	}
	else if (marriageStatus == 'm' || marriageStatus == 'M')
	{
		taxableAmount = (grossIncome - (AMOUNT_FOR_PERSONAL_EXEMPTION * (NUMBER_OF_ADULTS_IN_HOUSEHOLD + numOfChildrenInHousehold)) - penTotal - STANDARD_EXEMPTION_FOR_MARRIED_PEOPLE);
	}
	
	if (taxableAmount <= MAX_INCOME_ON_FIRST_BRACKET)
	{
		federalTaxes = TAX_RATE_FOR_FIRST_BRACKET * taxableAmount;
	}
	else if (taxableAmount <= MAX_INCOME_ON_SECOND_BRACKET)
	{
		federalTaxes = (taxableAmount * TAX_RATE_FOR_SECOND_BRACKET) + TAX_AMOUNT_FOR_SECOND_BRACKET;
	}
	else if (taxableAmount > MAX_INCOME_ON_SECOND_BRACKET)
	{
		federalTaxes = (taxableAmount * TAX_RATE_FOR_THIRD_BRACKET) + TAX_AMOUNT_FOR_THIRD_BRACKET;
	}
	return federalTaxes;
}