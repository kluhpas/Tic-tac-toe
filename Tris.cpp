#include <iostream>
#include <string.h>
#include <stdlib.h>
#include<conio.h>

using namespace std;

int acquisisci();
void azzeramento(char [][3]);
void stampa(char [][3]);
void input_valido(char [][3], int);
bool vittoria(char [][3], int);
bool pareggio(char [][3], int);

int main ()
{
    char campo[3][3], x, y, scelta;
    int turno;
    bool vitt = false, par = false;
    
    do
	{
		turno = 0;
		vitt = false;
	    par = false;
		azzeramento(campo);
	    
	    cout << "\t\t\t\tGioco del Tris\n\n\n\t\t    ";
	    
	    
	    system("PAUSE");
	    system("CLS");
	
		do{
			switch(turno % 2)
			{
				case 0:
					{
						system("CLS");
						input_valido(campo, turno);
						turno++;
						break;
					}
				case 1:
					{
						system("CLS");
						input_valido(campo, turno);
						turno++;
						break;
					}
			}
			if (turno > 4)
				vitt = vittoria(campo, turno);
			
			if (vitt == false && turno > 5)
				par = pareggio(campo, turno);
		} while(vitt == false && par == false && turno < 9);
		
		stampa(campo);
		
		if (par == true || turno > 8)
			cout << "\n\t\t\t\t PAREGGIO!\n\n";
		else if (turno % 2 == 1)
			cout << "\n\t\t\tVITTORIA DEL GIOCATORE UNO!\n\n";
		else
			cout << "\n\t\t\tVITTORIA DEL GIOCATORE DUE!\n\n";
			
		cout << "Per rigiocare inserire 0, per uscire premere qualsiasi altro tasto.\n";
		cin >> scelta;
		
		system("CLS");
	} while (scelta == '0');

system("PAUSE");
return 0;
}


void azzeramento(char campo[][3])
{
	char a = '1';
	
	for(int i = 2; i >= 0; i--)
	{
		for( int j = 0; j < 3; j++)
		{
	   		campo[i][j] = a;
	   		a++;
		}                                                                        
	}
}


void stampa(char campo[][3])
{
	for (int i = 0; i < 3; i++)
	{
		cout << "\n\t\t\t\t";
			
		for (int j = 0; j < 3; j++)
		{
			if (j == 1)
				cout << char(179) << " " << campo[i][j] << " " << char(179);
			else
				cout << " " << campo[i][j] << " ";
		}
		
		cout << "\n\t\t\t\t";
		
		if (i < 2)
			for (int k = 0; k < 12; k++)
			{
				if (k % 4 == 0 && k != 0)
					cout << char(197);
				else if (k != 0)
					cout << char(196);
			}
	}
}


void input_valido(char campo[][3], int i)
{
	char segno, a;
	int pos, x, y;
	bool b;
	
	if (i % 2 == 0)
		segno = 'X';
	else
		segno = 'O';
	do
	{
		b = true;
		
		do
		{
			system("CLS");
			cout << "\t\t\t   Turno del Giocatore " << (i % 2) + 1 << "\n\n";
			stampa(campo);
			cout << "\n\nPremere il numero della casella corrispondente per inserire la posizione della \nmossa.\n\n";
	    	a = getch();
	    	pos = a - 49;
		} while(pos < 0|| pos > 8);
		
		system("CLS");
		
		x = 2 - (pos / 3);
		y = pos % 3;
		
		if(campo[x][y] != 'X' && campo[x][y] != 'O')
			campo[x][y] = segno;
		else
			b = false;
	} while(b == false);
}


bool vittoria(char campo[][3], int a)
{
    char segno;
    bool vincita = false;

    if ((a - 1) % 2 == 0)
    	segno = 'X';
    else
    	segno = 'O';
    	
	// righe
    if(campo[0][0] == segno && campo[0][1] == segno && campo[0][2] == segno)
       vincita = true;
       
    else if(campo[1][0] == segno && campo[1][1] == segno && campo[1][2] == segno)
       vincita = true;       
       
    else if(campo[2][0] == segno && campo[2][1] == segno && campo[2][2] == segno)
       vincita = true;
    
    // colonne
    else if(campo[0][0] == segno && campo[1][0] == segno && campo[2][0] == segno)
       vincita = true;       
    
    else if(campo[0][1] == segno && campo[1][1] == segno && campo[2][1] == segno)
       vincita = true;
       
    else if(campo[0][2] == segno && campo[1][2] == segno && campo[2][2] == segno)
       vincita = true;
                                
    // diagonali
    else if(campo[0][0] == segno && campo[1][1] == segno && campo[2][2] == segno)
       vincita = true;
       
    else if(campo[2][0] == segno && campo[1][1] == segno && campo[0][2] == segno)
       vincita = true;
       
    return vincita;
}


bool pareggio(char campo[][3], int a)
{
    bool par = false;
    char i = '0';

	switch (a - 1)
	{
		case 5:
			{
				if (campo[0][0] == 'X' && campo[0][1] == 'O' && campo[0][2] == 'X' && campo[2][0] == 'O'&& campo[2][1] == 'X' && campo[2][2] == 'O')
					par = true;
				else if (campo[0][0] == 'X' && campo[1][0] == 'O' && campo[2][0] == 'X' && campo[0][2] == 'O' && campo[1][2] == 'X' && campo[2][2] == 'O')
					par = true;
				else if (campo[0][0] == 'O' && campo[0][1] == 'X' && campo[0][2] == 'O' && campo[2][0] == 'X' && campo[2][1] == 'O' && campo[2][2] == 'X')
					par = true;
				else if (campo[0][0] == 'O' && campo[1][0] == 'X' && campo[2][0] == 'O' && campo[0][2] == 'X' && campo[1][2] == 'O' && campo[2][2] == 'X')
					par = true;
				break;
			}
			
		case 6:
			{
				if (campo[0][0] == 'X' && campo[0][1] == 'X' && campo[0][2] == 'O' && campo[1][0] =='O' && campo[1][1] == 'O' && campo[1][2] == 'X' && campo[2][0] == 'X')
					par = true;
				else if (campo[0][2] == 'X' && campo[1][2] == 'X' && campo[2][2] =='O' && campo[0][1] == 'O' && campo[1][1] == 'O' && campo[2][1] == 'X' && campo[0][0] == 'X')
					par = true;
				else if (campo[2][0] == 'O' && campo[2][1] == 'X' && campo[2][2] =='X' && campo[1][0] == 'X' && campo[1][1] == 'O' && campo[1][2] == 'O' && campo[0][2] == 'X')
					par = true;
				else if (campo[0][0] == 'O' && campo[1][0] == 'X' && campo[2][0] =='X' && campo[0][1] == 'X' && campo[1][1] == 'O' && campo[2][1] == 'O' && campo[2][2] == 'X')
					par = true;
				else if (campo[0][0] == 'O' && campo[0][1] == 'X' && campo[0][2] =='X' && campo[1][0] == 'X' && campo[1][1] == 'O' && campo[1][2] == 'O' && campo[2][2] == 'X')
					par = true;
				else if (campo[0][2] == 'X' && campo[0][1] == 'O' && campo[0][0] =='X' && campo[1][0] == 'X' && campo[1][1] == 'O' && campo[2][1] == 'X' && campo[2][0] == 'O')
					par = true;
				else if (campo[2][0] == 'X' && campo[2][1] == 'X' && campo[2][2] =='0' && campo[1][0] == '0' && campo[1][1] == 'O' && campo[1][2] == 'X' && campo[0][0] == 'X')
					par = true;
				else if (campo[0][1] == 'X' && campo[0][2] == 'O' && campo[1][1] =='O' && campo[1][2] == 'X' && campo[2][0] == 'X' && campo[2][1] == 'O' && campo[2][2] == 'X')
					par = true;
				break;
			}
			
		case 7:
			{
					do
					{
						i++;
					} while (campo[2 - (i / 3)][i % 3] != i && i < 58);
					
					switch (i)
					{
						case 1:
							{
								if(campo[1][1] == 'X' && campo[2][2] == 'X')
       								par = true;
       							else if(campo[0][1] == 'X' && campo[0][2] == 'X')
			       					par = true;
						        else if(campo[1][0] == 'X' && campo[2][0] == 'X')
						       		par = true;
						       	break;
							}
					
						case 2:
							{
								if(campo[0][0] == 'X' && campo[0][2] == 'X')
			       					par = true;
						        else if(campo[1][0] == 'X' && campo[2][0] == 'X')
						       		par = true;
						       	break;
							}
					
						case 3:
							{
								if(campo[2][0] == 'X' && campo[2][2] == 'X')
       								par = true;
       							else if(campo[0][0] == 'X' && campo[0][1] == 'X')
			       					par = true;
						        else if(campo[1][2] == 'X' && campo[2][2] == 'X')
						       		par = true;
						       	break;
							}
					
						case 4:
							{
								if(campo[1][1] == 'X' && campo[1][2] == 'X')
			       					par = true;
						        else if(campo[0][0] == 'X' && campo[2][0] == 'X')
						       		par = true;
						       	break;
							}
					
						case 5:
							{
								if(campo[1][0] != campo[1][2] && campo[0][1] != campo[2][1] && campo[0][0] != campo[2][2] && campo[2][0] != campo[0][2])
       								par = true;
							    break;
							}
					
						case 6:
							{
								if(campo[1][1] == 'X' && campo[1][0] == 'X')
			       					par = true;
						        else if(campo[0][2] == 'X' && campo[2][2] == 'X')
						       		par = true;
						       	break;
							}
					
						case 7:
							{
								if(campo[0][2] == 'X' && campo[2][2] == 'X')
       								par = true;
       							else if(campo[2][1] == 'X' && campo[2][2] == 'X')
			       					par = true;
						        else if(campo[1][0] == 'X' && campo[0][0] == 'X')
						       		par = true;
						       	break;
							}
					
						case 8:
							{
								if(campo[2][0] == 'X' && campo[2][2] == 'X')
			       					par = true;
						        else if(campo[1][1] == 'X' && campo[0][1] == 'X')
						       		par = true;
						       	break;
							}
					
						case 9:
							{
								if(campo[0][0] == 'X' && campo[2][2] == 'X')
       								par = true;
       							else if(campo[2][0] == 'X' && campo[2][1] == 'X')
			       					par = true;
						        else if(campo[1][2] == 'X' && campo[0][2] == 'X')
						       		par = true;
						       	break;
							}
					}
			}
	}
	return par;
}

