for (i = 1; i < n; i++)
{
	v = a[i]; // caut pozitia lui v in sirul a0, ..., ai
	for (poz = i; poz && a[poz - 1] > v; poz--) a[poz] = a[poz - 1];
	a[poz] = v;
}
