#include <bits/stdc++.h>

using namespace std ;

/// Structure for saving the x and y coordinates of a point
typedef struct point
{
    double x ;
    double y ;
} point ;

/// comparator function to compare two sets of points
bool comparator(const point& lhs, const point& rhs) 
{
    if(lhs.x == rhs.x)
    {
        return lhs.y < rhs.y ;
    }
    return lhs.x < rhs.x ;
}

/// driver function
int main()
{
    string s1,s2;
    std::cin>>s1>>s2;
    ifstream in(s1);
    int n ;
    double c ;
    in >> n >> c;

    vector<point> points ;
    point ta ;
    ta.x = INT_MIN;
    ta.y = INT_MIN ;
    points.push_back(ta) ;

    for(int i = 1; i <= n; i++)
    {
        point temp ; 
        int x, y ;
        in >> temp.x >> temp.y ;
        points.push_back(temp) ;
    }

    // time_t start, end;
  
    //  You can call it like this : start = time(NULL);
    //  in both the way start contain total time in seconds 
    //  since the Epoch. 
    // time(&start);
  
    // // unsync the I/O of C and C++.
    // ios_base::sync_with_stdio(false);

    double start = clock();

    sort(points.begin(), points.end(), &comparator) ;

    vector<double> sigmaX(n+1, 0) ;
    vector<double> sigmaY(n+1, 0) ;
    vector<double> sigmaX2(n+1, 0) ;
    vector<double> sigmaXY(n+1, 0) ;
    vector<double> sigmaY2(n+1, 0) ;

    vector<double> M(n+1, 0) ;
    M[0] = 0 ;
    double E[n+1][n+1] ;
    memset(E, 0, sizeof(E)) ;

    for(int i = 1; i <= n; i++)
    {
        sigmaX[i] = sigmaX[i - 1] + points[i].x ;
        sigmaY[i] = sigmaY[i - 1] + points[i].y ;
        sigmaX2[i] = sigmaX2[i - 1] + (points[i].x * points[i].x) ;
        sigmaXY[i] = sigmaXY[i - 1] + (points[i].y * points[i].x) ;
        sigmaY2[i] = sigmaY2[i - 1] + (points[i].y * points[i].y) ;
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = i+1; j <= n; j++)
        {
            double numa, numb ;
            double dena, denb ;
            double aij, bij ;
            int nn = (j - i + 1) ;

            double sigXY, sigX, sigY, sigX2, sigY2 ;
            sigX = sigmaX[j] - sigmaX[i - 1] ;
            sigY = sigmaY[j] - sigmaY[i - 1] ;
            sigXY = sigmaXY[j] - sigmaXY[i - 1] ;
            sigX2 = sigmaX2[j] - sigmaX2[i - 1] ;
            sigY2 = sigmaY2[j] - sigmaY2[i - 1] ;

            numa = ( (nn * sigXY) - (sigX * sigY) ) * 1.0 ;
            dena = ( (nn * sigX2) - (sigX * sigX) ) * 1.0 ;
            aij = numa / dena ;

            numb = ( sigY - (aij * sigX) ) * 1.0 ;
            denb = (double) nn ;
            bij = numb / denb ;

            E[i][j] = aij * aij * sigX2 + 2.0 * aij * bij * sigX - 2.0 * aij * sigXY + nn * bij * bij - 2.0 * bij * sigY + sigY2 ;
        }
    }

    vector<double> path(n+1, 0) ;
    vector<pair<double, double>> x_cord ;

    for(int j = 1; j <= n; j++)
    {
        M[j] = E[1][j] + c ;
        path[j] = 1 ;

        for(int i = 1; i <= j; i++)
        {
            if(M[i - 1] + E[i][j] + c <= M[j])
            {
                M[j] = M[i - 1] + E[i][j] + c ;
                path[j] = i ;
            }
        }
    }

    double a = n ;
    while(a >= 1)
    {
        pair<double, double> tt ;
        tt.first = a ;
        tt.second = path[a] ;

        x_cord.push_back(tt) ;

        a = path[a] - 1 ;
    }

    cout <<setprecision(2)<<"The least error is " << abs(M[n]) <<" or " <<abs(round(M[n])) << endl ;

    ofstream myfile;
    myfile.open (s2);

    for(int k = 0; k < x_cord.size(); k++)
    {
        int j = x_cord[k].first ;
        int i = x_cord[k].second ;

        double numa, numb ;
        double dena, denb ;
        double aij, bij ;
        
        int nn = (j - i + 1) ;

        double sigXY, sigX, sigY, sigX2, sigY2 ;
        
        sigX = sigmaX[j] - sigmaX[i - 1] ;
        sigY = sigmaY[j] - sigmaY[i - 1] ;
        sigXY = sigmaXY[j] - sigmaXY[i - 1] ;
        sigX2 = sigmaX2[j] - sigmaX2[i - 1] ;
        sigY2 = sigmaY2[j] - sigmaY2[i - 1] ;
        
        numa = ( (nn * sigXY) - (sigX * sigY) ) * 1.0 ;
        dena = ( (nn * sigX2) - (sigX * sigX) ) * 1.0 ;
        aij = numa / dena ;
        
        numb = ( sigY - (aij * sigX) ) * 1.0 ;
        denb = (double) nn ;
        bij = numb / denb ;
        if(points[i].x==points[j].x)
        	myfile << aij << " " << bij << " " << points[i].x << " " << points[j].x <<" "<<points[i].y <<" "<<points[j].y<< endl ;
        else
        	myfile << aij << " " << bij << " " << points[i].x << " " << points[j].x <<endl;
    }
    myfile.close();
    // // Calculating total time taken by the program.
    // time(&end);
    // double time_taken = double(end - start);
    // cout << "Time taken by program is : " << fixed
    //      << time_taken << setprecision(10);
    // cout << " sec " << endl;
    double end=clock();
    double(time_taken) = double(end-start)/double(CLOCKS_PER_SEC);
    cout<<"Time taken is "<<time_taken;
    return 0;
}