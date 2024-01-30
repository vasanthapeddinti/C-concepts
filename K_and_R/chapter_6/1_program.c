// -lm flag has to be linked for math library
#include <stdio.h>
#include <math.h>

struct point {
    int x;
    int y;
};

struct {
    int a;
    int b;
} final, mid;

int main() {

    double dist;

    struct point initial;
    initial.x = 0;
    initial.y = 0;

    mid.a = 1;
    mid.b = 2;

    final.a = 2;
    final.b = 2;

    struct point maxpt = {23, 45};

    dist = sqrt((double)final.a * final.a + (double)final.b * final.b);
    printf("distance between final and initial points is %lf\n", dist);

    struct rect {
        struct point pt1;
        struct point pt2;
    };

    struct rect screen;
    screen.pt1.x = 2;
    screen.pt1.y = 2;
    screen.pt2.x = 4;
    screen.pt2.y = 4;

    return 0;
}