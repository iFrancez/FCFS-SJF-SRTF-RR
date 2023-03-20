//#include <vector>
//#include<iostream>
//using namespace std;
//
//struct process
//{
//    int pid;
//    int t_time;
//    int w_time;
//    int c_time;
//    int b_time;
//    int a_time;
//    int r_time;
//    int s_time;
//};
//static bool compare(process a, process b)
//{
//    return a.a_time < b.a_time;
//}
//static bool compare2(process a, process b)
//{
//    return a.pid < b.pid;
//}
//int main()
//{
//    int n;
//    float avg_tt = 0, avg_wt = 0, total_tt = 0, total_wt = 0;
//    cout << "\n Enter No of Process";
//    cin >> n;
//    process p[100];
//    for (int i = 0; i < n; i++)
//    {
//        cout << "\nProcess " << i + 1 << "\n";
//        cout << "\nArrival Time: ";
//        cin >> p[i].a_time;
//        cout << "\nBurst Time: ";
//        cin >> p[i].b_time;
//        p[i].pid = i + 1;
//    }
//     //sort(p, p + n, compare);
//    vector<bool> completed(n, false);
//    int curr = 0, ind = -1, count = 0;
//    cout << "\n" << "Current: ";
//    while (count != n)
//    {
//        cout << curr << " ";
//        int minB = INT_MAX;
//        ind = -1;
//        for (int i = 0; i < n; i++)
//        {
//            if (p[i].a_time <= curr && !completed[i])
//            {
//                if (p[i].b_time < minB)
//                {
//                    minB = p[i].b_time;
//                    ind = i;
//                }
//                if (p[i].b_time == minB)
//                {
//                    if (p[i].a_time < p[ind].a_time)
//                    {
//                        minB = p[i].b_time;
//                        ind = i;
//                    }
//                }
//            }
//        }
//        if (ind != -1)
//        {
//            p[ind].s_time = curr;
//            p[ind].c_time = p[ind].s_time + p[ind].b_time;
//            p[ind].t_time = p[ind].c_time - p[ind].a_time;
//            p[ind].w_time = p[ind].t_time - p[ind].b_time;
//            completed[ind] = true;
//
//            total_wt += p[ind].w_time;
//            total_tt += p[ind].t_time;
//            count++;
//            curr = p[ind].c_time;
//        }
//        else
//        {
//            curr++;
//        }
//    }
//    avg_wt = (total_wt / n);
//    avg_tt = (total_tt / n);
//    cout << "\nPID\t\tAT\t\tBT\t\tTAT\t\tWT";
//    for (int i = 0; i < n; i++)
//    {
//        cout << "\n"
//            << p[i].pid << "\t\t" << p[i].a_time << "\t\t" << p[i].b_time << "\t\t" << p[i].t_time << "\t\t" << p[i].w_time;
//    }
//    cout << "\nAverage Waiting Time :" << avg_wt;
//    cout << "\nAverage TurnAround Time :" << avg_tt;
//    return 0;
//}
///*
//5
//0 10
//1 1
//2 2
//3 1
//4 5
//*/