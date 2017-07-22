/**
*
* 三分法求凸函数极值
*
*
*/

double solve(double MIN,double MAX)
{
    double Left, Right;
    double mid, midmid;
    double mid_value, midmid_value;
    Left = MIN;
    Right = MAX;
    while (Left +eps < Right)
    {
        mid = (Left + Right) / 2;
        midmid = (mid + Right) / 2;
        mid_value = Calc(mid);
        midmid_value = Calc(midmid);
        ///求最大值改成>= 最小值改成<=
        if (mid_value >= midmid_value) Right = midmid;
        else Left = mid;
    }
    return Left;
}