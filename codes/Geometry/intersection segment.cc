struct Point  {
    int x, y;
};

// give three colinear points, the functions check if 
// point b lies on line segment ac
bool onSegment(Point a, Point b, Point c) {
    if( b.x <= max(a.x, c.x) && b.x >= min(a.x, c.x) &&
        b.y <= max(a.y, c.y) && b.y >= min(a.y, c.y))
            return true;
    return false;
}
// To find orientation of ordered triplet
// return 
// 0 -> p, q, and r are colinear
// 1 -> Clockwise
// 2 -> Counterclockwise
int orientation(Point a, Point b, Point c) {
    int val = (b.y - a.y) * (c.x - b.x) - 
            (c.y - b.y) * (b.x - a.x);
    if(val == 0) {
        return 0;       // colinear
    }
    return (val > 0)? 1: 2;  // Clock or Counterclockwise
}