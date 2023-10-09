#include <stdio.h>
#include <math.h>
#include <locale.h>


double f1(double x) {
    return 3* pow(x,4) - 8 * pow(x, 3) - 18 * pow(x,2) + 2; 
}

double f2(double x) {
    return tan(0.55 * x + 0.1) - pow(x, 2);
}




double bisection(double (*f)(double), double a, double b, double epsilon) {
    
    double c = 0;
    int it = 0;
    while ((b - a) / 2 > epsilon)
    {
        c = (a + b) / 2;
        if ((f(a) * f(c)) > 0) a = c;
        else b = c;
        it += 1;
    }
    printf("%d ", it);
    return c;


}


double secant(double (*f) (double), double a, double b, double epsilon) {
    int iteration = 0;
    double c, a_temp;

    if (f(a) * f(b) < 0) {

        do {
            //���������� �����
            a_temp = b - ((b - a) / (f(b) - f(a))) * f(b);
            //��������������� ������
            a = b;
            b = a_temp;
            //�������� �� ��������
            c = b - ((b - a) / (f(b) - f(a))) * f(b);

    

            iteration++;


        } while (fabs(c - a_temp) >= epsilon); // ��������� �� ��� ���,���� ������ ������ epsilon
        printf("%d ", iteration);
        return c;


    }

 

}

   

int main() {
    setlocale(LC_ALL, "Russian");
     // �������, � ������� ����� ������ ������
     // �������� ��������
    printf("��� ��������\n");
    for (int i = 1; i < 15; i++) {
        double e = 1 / pow(10, i);
        printf("%.014f\n", bisection(f1, -3.5, -0.5, e));
    }
    printf("\n");
    printf("��� �������������� �������\n");
    for (int i = 1; i < 15; i++) {
        double e = 1 / pow(10, i);
        printf("%.014f\n", bisection(f2, -0.6, 0.4, e));
    }
    printf("\n");
    printf("����� ������� ��������\n");
    for (int i = 1; i < 15; i++) {
        double e = 1 / pow(10, i);
        printf("%.014f\n", secant(f1, -3.5, -0.5, e));
    }
    printf("\n");
    printf("����� ������� �������������� �������\n");
    for (int i = 1; i < 15; i++) {
        double e = 1 / pow(10, i);
        printf("%.014f\n", secant(f2, -0.6, 0.4, e));
    }
    printf("\n");
    return 0;
   
}