#include "client.h"

string client::GetCodIban()
{
    return CodIban;
}

void client::SetCodIban(const string& sc)
{
    CodIban = sc;
}

void client::Scrie()
{
    cout << Id << ' ' << Nume << ' ' << CodIban << '\n';
}

client::client():Persoana()
{
    CodIban = "";
}

client::client(const string& sn, const string& sc):Persoana(sn)
{
    CodIban = sc;
}
