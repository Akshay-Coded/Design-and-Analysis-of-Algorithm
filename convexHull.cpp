#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x, y;
};

int orientation(Point p, Point q, Point r)
{
    int val = ((q.y - p.y) * (r.x - q.x)) - ((q.x - p.x) * (r.y - q.y));

    if (val == 0)
    {
        return 0;
    }
    return (val > 0) ? 1 : 2;
}

// Prints convex hull of a set of n points.
void convexHull(Point points[], int n)
{
    // There must be at least 3 points
    if (n < 3)
        return;

    // Initialize Result
    vector<Point> hull;

    int l = 0;
    for (int i = 1; i < n; i++)
    {
        if (points[i].x <= points[l].x)
        {
            l = i;
        }
    }

    int p = l, q;
    do
    {
        hull.push_back(points[p]);
        q = (p + 1) % n;
        for (int i = 0; i < n; i++)
        {
            if (orientation(points[p], points[i], points[q]) == 2)
                q = i;
        }
        p = q;

    } while (p != l);

    // Print Result
    cout<<"------------/n";
    for (int i = 0; i < hull.size(); i++)
        cout << hull[i].x << " " << hull[i].y << "\n";
}

// Driver program to test above functions
int main()
{
    int num_points;
    cout << "Enter the number of points: ";
    cin >> num_points;

    Point points[num_points];
    cout << "Enter the points:\n";
    for (int i = 0; i < num_points; i++)
    {
        cin >> points[i].x >> points[i].y;
    }
    convexHull(points, num_points);
    return 0;
}
