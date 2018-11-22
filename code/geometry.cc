

struct point{
	long double x, y;
	point(){};
	point(long double x_, long double y_): x(x_), y(y_){}
	point operator + (const point & other)const { return point(x + other.x, y + other.y); }
	point operator - (const point & other)const { return point(x - other.x, y - other.y); }
	point operator * (long double & n)const { return point(x * n, y * n); }
	point operator / (long double & n)const { return point(x / n, y / n); }
};


void centerThreePoints(const point & a, const point & b, const point & c, point & center, long double & r){
	long double A = a.x*a.x + a.y * a.y;	
	long double B = b.x*b.x + b.y * b.y;
	long double C = c.x*c.x + c.y * c.y;
	long double D  = a.x * (b.y - c.y) - b.x * (a.y - c.y) + c.x * (a.y - b.y);
	center.x = (A * (b.y - c.y) - B * (a.y - c.y) + C * ( a.y - b.y))/(2.0*D);
	center.y = (a.x * (B - C) - b.x * ( A - C) + c.x * (A - B))/(2.0*D);
	r = sqrt((a.x - rx) * (a.x - rx) + (a.y - ry) * (a.y - ry));
}

void rotation(point & p, const point & center, long double theta){
	long double _x = p.x;
	p.x = (_x - center.x) * cos(theta) - (p.y - center.y) * sin(theta) + center.x;
	p.y = (p.y - center.y) * cos(theta) + (_x - center.x) * sin(theta) + center.y;
}