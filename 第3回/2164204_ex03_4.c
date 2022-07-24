// プログラミング演習Ⅰ第3回 2164204_ex03_3.c
#include <stdio.h>
#include <math.h>

#define NORM(a) sqrt(pow(a.x,2.0)+pow(a.y,2.0)+pow(a.z,2.0))

struct vector{
            double x;
            double y;
            double z;
        };

double naiseki(struct vector a, struct vector b);
// double norm(struct vector a);

int main(void)
{
        struct vector a,b;
        double angle;

        printf("Input the components  x, y and z of the 1st vector>>\n");
        printf("x=");
        scanf("%lf",&a.x);
        printf("y=");
        scanf("%lf",&a.y);
        printf("z=");
        scanf("%lf",&a.z);
        
        printf("Input the components  x, y and z of the 2nd vector>>\n");
        printf("x=");
        scanf("%lf",&b.x);
        printf("y=");
        scanf("%lf",&b.y);
        printf("z=");
        scanf("%lf",&b.z);
        
        printf("naiseki = %le\n",naiseki(a,b));
        printf("norm(a) = %le\n",NORM(a));
        printf("norm(b) = %le\n",NORM(b));
        
        angle = acos(naiseki(a, b)/(NORM(a)*NORM(b))) * 180 / M_PI;
        printf("angle[deg] = %le\n", angle);
}

double naiseki(struct vector a, struct vector b)
{
        return a.x*b.x+a.y*b.y+a.x*b.y;
}

// double norm(struct vector a)
// {
//         return sqrt(pow(a.x,2.0)+pow(a.y,2.0)+pow(a.z,2.0));
// }