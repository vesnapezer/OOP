#include <cmath>
#include <iostream>

using namespace std;

struct Point{
    double x;
    double y;
};

void move_by(Point* p, double dx, double dy){
    p->x += dx;
    p->y += dy;
}

double dist(const Point* a, const Point* b){
    const double dx{a->x - b->x};
    const double dy{a->y - b->y};
    return sqrt(dx * dx + dy * dy);
}

void move_by(Point& p, double dx, double dy){
    p.x += dx;
    p.y += dy;
}

double dist(const Point& a, const Point& b){
    const double dx{a.x - b.x};
    const double dy{a.y - b.y};
    return sqrt(dx * dx + dy * dy);
}

int main(){
    Point a{1.0, 2.0};
    Point b{4.0, 6.0};

    cout << "dist(&a, &b) = " << dist(&a, &b) << " (pointeri)" << endl;
    cout << "dist(a, b)   = " << dist(a, b) << " (reference)" << endl;

    move_by(&a, 3.0, 4.0); 
    move_by(b, -3.0, -4.0);
    cout << "a = (" << a.x << ", " << a.y << "), b = (" << b.x << ", " << b.y << ")" << endl;
    cout << "dist(b, Point{0, 0}) = " << dist(b, Point{0.0, 0.0}) << endl;

    const Point ishodiste{0.0, 0.0};
    const Point tocke[5]{{3.0, 4.0}, {-1.0, 2.0}, {0.5, 0.5}, {5.0, -2.0}, {-3.0, -3.0}};

    const Point* najbliza{&tocke[0]};
    for (const Point& t : tocke)   // const auto& bez kopiranja; &t je adresa elementa niza
        if (dist(t, ishodiste) < dist(*najbliza, ishodiste))
            najbliza = &t;

    cout << "Najbliza ishodistu: (" << najbliza->x << ", " << najbliza->y << "), udaljenost "
              << dist(*najbliza, ishodiste) << endl;
}