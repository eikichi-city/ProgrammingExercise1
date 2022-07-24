// プログラミング演習Ⅰ第4回 2164204_ex04_1.c
#include <stdio.h>

struct vector{
            double x;
            double y;
            double z;
        };


struct vector gaiseki(struct vector a, struct vector b)
{
        struct vector c;
        c.x = a.y*b.z - a.z*b.y;
        c.y = a.z*b.x - a.x*b.z;
        c.z = a.x*b.y - a.y*b.x;
        return c;
}

int main(void)
{
        struct vector a,b;

        printf("Input the components  x, y and z of the 1st vector (x,y,z) >>");
        scanf("%lf %lf %lf",&a.x,&a.y,&a.z);
        
        printf("Input the components  x, y and z of the 2nd vector (x,y,z) >>");
        scanf("%lf %lf %lf",&b.x,&b.y,&b.z);
        
        printf("gaiseki = (%le,%le,%le)\n",gaiseki(a,b).x,gaiseki(a,b).y,gaiseki(a,b).z);
}
