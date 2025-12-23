for (dr = n-1;  dr > 0;  dr--)
{
	// calculez maximul de la 0 la dr
	for (max = a[0], pozmax = 0, i = 1; i <= dr; i++)
		if (a[i] > max) max = a[i], pozmax = i;
	a[pozmax] = a[dr]; // plasez maximul pe pozitia dr
	a[dr] = max;
}
