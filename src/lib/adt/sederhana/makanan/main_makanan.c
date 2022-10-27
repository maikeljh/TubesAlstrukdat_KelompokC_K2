#include <stdio.h>
#include <stdlib.h>
#include "makanan.h"

int main(){
	Makanan food;
	int idm;
	int locate;
	char bebek[NMax];
	TIME lepe, wakpeng;
	idm = 33;
	locate = 3;
	bebek[0] = 'B';
	bebek[1] = 'e';
	bebek[2] = 'b';
	bebek[3] = 'e';
	bebek[4] = 'k';
	bebek[5] = ' ';
	bebek[6] = 'g';
	bebek[7] = 'e';
	bebek[8] = 'p';
	bebek[9] = 'r';
	bebek[10] = 'e';
	bebek[11] = 'k';
	Hour(lepe) = 1;
	Minute(lepe) = 2;
	Second(lepe) = 3;
	
	Hour(wakpeng) = 3;
	Minute(wakpeng) = 2;
	Second(wakpeng) = 1;
	CreateMakanan(&food, idm, locate, bebek, wakpeng, lepe);
	TulisMakanan(food);
}