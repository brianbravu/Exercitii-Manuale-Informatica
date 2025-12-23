#pragma once
class mesaj
{
private:
	char* sir;
	int lg;
public:
	mesaj(); // Constructor fara parametri
	mesaj(const char s[]); // Constructor supraincarcat
	~mesaj(); // Destructor
	mesaj(mesaj& m); // Constructor de copiere

	int GetLg();
	void Scrie();
	// void Majuscule();
	// Operatori supraincarcati
	mesaj operator~();
	mesaj& operator=(const mesaj& m);
	const mesaj operator+(const mesaj& m) const;
	const mesaj& operator+=(const mesaj& m);
	bool operator==(const mesaj& m) const;
	inline bool operator!=(const mesaj& m) const;
	char operator[] (const int poz) const;
};

