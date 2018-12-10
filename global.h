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
