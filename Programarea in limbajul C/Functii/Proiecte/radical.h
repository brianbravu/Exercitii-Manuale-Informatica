#pragma once

double R2(double a)
{
	double x0 = a, x1;
	for (int i = 1; i <= 10; i++)
	{
		x1 = 0.5 * (x0 + a / x0);
		x0 = x1;
	}
	return x1;
}

double R3(double a)
{
	double x0 = a, x1;
	for (int i = 1; i <= 10; i++)
	{
		x1 = (1 / 3.0) * (2 * x0 + a / (x0 * x0));
		x0 = x1;
	}
	return x1;
}
