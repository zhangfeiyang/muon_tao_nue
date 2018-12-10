#include "rootheader.h"
	double s12 = sqrt(0.308);
	double s13 = sqrt(0.0234);
	double s23 = sqrt(0.437);

	double c12 = sqrt(1-0.308);

	double c13 = sqrt(1-0.0234);
	double c23 = sqrt(1-0.437);

	double pi = 3.141592654;
	double delta = 1.39/180*pi;

	double Ue2[3] = {c12*c13*c12*c13,s12*c13*s12*c13,s13*s13};
	double Umu2[3]= {s12*c23*s12*c23 + c12*s13*s23*c12*s13*s23 + 2*c12*s13*s23*s12*c23*cos(delta), c12*c23*c12*c23 + s12*s13*s23*s12*s13*s23 + 2*s12*s13*s23*c12*c23*cos(pi-delta), c13*s23*c13*s23};
	double Utao2[3]={s12*s23*s12*s23 + c12*s13*c23*c12*s13*c23 + 2*c12*s13*c23*s12*s23*cos(pi-delta), c12*s23*c12*s23 + s12*s13*c23*s12*s13*c23 + 2*s12*s13*c23*c12*s23*cos(delta),c13*c23*c13*c23};

	double M21 = 7.54e-5;
	double M31 = 2.47e-3;
	double M32 = M31 - M21;

double cal_me(double m1,double m2,double m3){
	return sqrt(m1**2*Ue2[0] + m2**2*Ue2[1] + m3**2*Ue2[2]);
	//return (m1*Ue2[0] + m2*Ue2[1] + m3*Ue2[2]);
}

double formula(double m2,double X){

	return m2**2 - (((X-m2)**2 - M31)/2/(X-m2))**2;
};

double cal_m2(double sum){
	
	double high = sum;
	double low = 0;
	double result;
	for(int i=0;i<1000;i++){
		double m2 = (high + low)/2;
		result = formula(m2,sum);	
		if(result > M21) {
			high = m2;
		}
		else{
			low = m2;
		}
	} 
	return m2;
};

double cal_m1(double m2){
	return sqrt(m2*m2 - M21);
}

void draw(){

	const int N = 10;

	double x[N],y[N];	
	for(int i=0;i<N;i++){
		double sum = i*1.0/N + 0.1;
		double m2 = cal_m2(sum);
		double m1 = cal_m1(m2);
		double m3 = sum - m1 - m2;
		double me = cal_me(m1,m2,m3);
		cout << sum << "\t" << me << "\n"; 
		x[i] = sum;
		y[i] = me;
	}
	TGraph *t = new TGraph(N,x,y);
	t->Draw();

}
