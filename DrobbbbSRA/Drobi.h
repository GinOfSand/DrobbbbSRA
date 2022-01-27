#pragma once
#include <iostream>
class Drobi
{
private:
	int chisl;
	int znamen;
	int whole;
public:
	// конструкторы (Чеслитель. Знаменатель. Целые)
	Drobi(int chisl, int znamen, int whole) {
		init(chisl, znamen, whole);
	};
	Drobi() : Drobi(0, 0, 0) {};
	// методы

	void init(int chis, int znam, int whol);
	void Display();

	Drobi chis_whol(Drobi dro);

	Drobi sum_d(Drobi drb1);
	Drobi& operator+(Drobi& name) {
		Drobi res;

		if (znamen != 0 && name.znamen != 0) {
			res.znamen = znamen * name.znamen;
		}
		else {
			if (znamen == 0) {
				res.znamen = name.znamen;
			}
			else {
				res.znamen = znamen;
			}
		}
		if (znamen == 0 || name.znamen == 0)
			res.chisl = ((whole * res.znamen) + chisl) + ((name.whole * res.znamen) + name.chisl);
		else
			res.chisl = ((whole * res.znamen) + (chisl * name.znamen)) + ((name.whole * res.znamen) + (name.chisl * znamen));
		if (whole > 0 || name.whole != 0) {
			res.whole = whole + name.whole;
		}



		res = chis_whol(res);
		return res;
	}

	Drobi operator-(Drobi drb) {
		Drobi res;
		if (znamen != drb.znamen) {
			if (znamen != 0 && drb.znamen != 0) {
				res.znamen = znamen * drb.znamen;
			}
			else {
				if (znamen == 0) {
					res.znamen = drb.znamen;

				}
				else {
					res.znamen = znamen;

				}
			}
		}
		if (znamen == 0 || drb.znamen == 0)
			res.chisl = ((whole * res.znamen) + chisl) - ((drb.whole * res.znamen) + drb.chisl);
		else
			res.chisl = ((whole * res.znamen) + (chisl * drb.znamen)) - ((drb.whole * res.znamen) + (drb.chisl * znamen));
		res = chis_whol(res);
		return res;
	}

	Drobi operator*(Drobi drb2) {
		Drobi res;
		if (znamen != 0 && drb2.znamen != 0) {
			res.znamen = znamen * drb2.znamen;
			res.chisl = (chisl + (whole * znamen)) * (drb2.chisl + (drb2.whole * drb2.znamen));
		}
		else if (znamen != 0) {
			res.znamen = znamen;
			res.chisl = (chisl + (whole * znamen)) * drb2.whole;
		}
		else {
			res.znamen = drb2.znamen;
			res.chisl = whole * (drb2.chisl + (drb2.whole * drb2.znamen));
		}
		res = chis_whol(res);
		return res;
	}

	Drobi operator/(Drobi drb3) {
		Drobi res;
		if (znamen != 0 && drb3.znamen != 0) {
			res.znamen = znamen * (drb3.chisl + (drb3.whole * drb3.znamen));
			res.chisl = (chisl + (whole * znamen)) * drb3.znamen;
		}
		else {
			if (znamen != 0) {
				if (drb3.znamen == 0) {
					res.chisl = chisl;
					res.znamen = drb3.whole * znamen;
				}
				else {
					res.znamen = znamen;
					res.chisl = chisl * (drb3.chisl + (drb3.whole * drb3.znamen));
				}
			}
			else {
				res.znamen = drb3.chisl + (drb3.chisl * drb3.whole);
				res.chisl = whole * drb3.znamen;
			}
		}
		res = chis_whol(res);
		return res;
	}

	
};