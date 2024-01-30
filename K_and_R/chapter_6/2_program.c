#include <stdio.h>

#define XMAX   200
#define YMAX   200
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))


struct point {
    int x;
    int y;
};

struct rect {
    struct point pt1;
    struct point pt2;
};

struct diff {
    int len;
    char *str;
};

/* makepoint: make a point from x and y components */
struct point makepoint(int x, int y);

/* addpoint: add two points in p1 */
struct point addpoint(struct point p1, struct point p2);

/* ptinrect: return 1 if p is inside the rectangle, 0 otherwise */
int ptinrect(struct point p, struct rect r);

/* canonrect: canonicalize coordinate of rectangle */
struct rect canonrect(struct rect r);

int main() {

    int result1 = 0;
    int result2 = 0;
    struct rect screen;
    screen = canonrect(screen);
    struct point middle;

    // makepoint
    screen.pt1 = makepoint(0,0);
    screen.pt2 = makepoint(XMAX, YMAX);

    middle = makepoint((screen.pt1.x + screen.pt2.x)/2, (screen.pt1.y + screen.pt2.y)/2);

    // addpoint
    struct point custom1;
    struct point custom2;

    custom1 = makepoint(20, 30);
    custom2 = makepoint(270,200);

    addpoint(custom1, custom2);
    printf("custom1 point is (%d, %d)\n", custom1.x, custom1.y);

    // ptinrect
    result1 = ptinrect(custom1, screen);
    printf("custom1 point is (%d, %d).\n Present inside the rectangle: %d\n", custom1.x, custom1.y, result1);
    result2 = ptinrect(custom2, screen);
    printf("custom2 point is (%d, %d).\n Present inside the rectangle: %d\n", custom2.x, custom2.y, result2);

    // using structure pointers
    struct point origin, *pp;
    origin = makepoint(23, 45);
    pp = &origin;

    printf("Origin is (%d, %d)\n",pp->x, pp->y);
    printf("Origin is (%d, %d)\n",(*pp).x, (*pp).y);

    struct diff p_struct, *pt_struct;
    pt_struct = &p_struct;
    pt_struct->len = 10;
    pt_struct->str = "hello";
    printf("len is %d\n",pt_struct->len);
    printf("string is %s\n", pt_struct->str);

    ++pt_struct->len;
    printf("after increment, len is %d\n",pt_struct->len);
    // It is the same as ++(p->len)
    // (++p)->len - increments the pointer and accesses the member
    // (p++)->len - increments the pointer after accessing the member

    pt_struct->str++;
    printf("after increment, string is %s\n", pt_struct->str);

    return 0;
}

/* makepoint: make a point from x and y components */
struct point makepoint(int x, int y) {
    struct point temp;

    temp.x = x;
    temp.y = y;
    return temp;
}

/* addpoint: add two points in p1*/
struct point addpoint(struct point p1, struct point p2) {
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

/* ptinrect: return 1 if p is inside the rectangle, 0 otherwise */
int ptinrect(struct point p, struct rect r) {
    return (p.x >= r.pt1.x && p.x >= r.pt2.x) && (p.y >= r.pt1.y && p.y >= r.pt2.y);
}

/* canonrect: canonicalize coordinate of rectangle */
struct rect canonrect(struct rect r) {
    struct rect temp;

    temp.pt1.x = min(r.pt1.x, r.pt2.x);
    temp.pt1.y = min(r.pt1.y, r.pt2.y);
    temp.pt2.x = max(r.pt1.x, r.pt2.x);
    temp.pt2.x = max(r.pt1.y, r.pt2.y);

    return temp;
}