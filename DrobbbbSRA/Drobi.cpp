#include "Drobi.h"
void Drobi :: init (int chis, int znam, int whol) {
	chisl = chis;
	znamen = znam;
	whole = whol;
}
void Drobi::Display() {
	std::cout << whole << "(" << chisl << "/" << znamen << ")" << std::endl;
}
// Отсеивание целых
Drobi Drobi::chis_whol(Drobi dro) {
	if (dro.chisl > dro.znamen|| dro.chisl < dro.znamen && dro.znamen > 0) {
		// ищем целые
		dro.whole = dro.chisl / dro.znamen;
		for (int i = 0; i < dro.whole; i++)
			// уменьшаем числитель еквивалентно полученым целым
			dro.chisl -= dro.znamen;
		// те же действия только для отрицательных значений
		if (dro.chisl < 0) {
			for (int i = 0; i > dro.whole; i--)
				dro.chisl += dro.znamen;
		}
		if (dro.chisl == 0)
			dro.znamen = 0;
		for (int i = 2; i < dro.chisl; i++) {
			if (dro.chisl % i == 0 && dro.znamen % i == 0) {
				dro.chisl /= i;
				dro.znamen /= i;
			}
		}
	}
	return dro;
}





 