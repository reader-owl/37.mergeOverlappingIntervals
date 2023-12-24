#include <iostream>

/*
                    Q. Merge Overlapping Intervals

                explanation -  we will be given array of 'n' subIntervals
                            subInterval (1, 3) means it starts at 1 and ends at 3

                        our task is to merge overlapping intervals, i.e
                            (1, 3), (2, 6), (8, 9), (9, 11), (8, 10), (2, 4), (15, 18), (16, 17)
                            desired o/p - {1, 6}, {8, 11}, {15, 18}

                        expl -  ---         (1, 3)          --          (8, 9)          ----        (15, 18)
                                 -----      (2, 6)           ---        (9, 11)          --         (16, 17)
                                 ---        (2, 4)          ---         (8, 10)
                         merge  ------      (1, 6)          ----        (8, 11)         ----        (15, 18)

                         small intervals can be written as big subarrays

                Brute force -  firstly sort them up
                                then we try to club all closer intervals together

                            sorting - firstly it will get sorted by 1st element and then by 2nd element, we will get
                                    - (1, 3), (2, 4), (2, 6), (8, 9), (8, 10), (9, 11), (15, 18), (16, 17)

                                lets take (1, 3) as our interval, then we check the 2nd subarray (2, 4)
                                if 1st element of the 2nd subarray is smaller than 2nd element of the 1st subarray that means
                                2nd subarray is overlapping 1st subarray and we can expand 1st subarray, by this they will
                                become - (1, 4)

                                similarly with (1, 4) & (2, 6), will become - (1, 6)

                                then we will check with (1, 6) & (8, 9), and they are not overlapping
                                so we can say that we got our first interval as (1, 6) and we can find next intervals by 
                                further subarrays

                                then take (8, 9), and do the same process as we previously done
                                (8, 9) with (8, 10) become - (8, 10)
                                (8, 10) with (9, 11) become - (8, 11)

                                then take (15, 18)
                                (15, 18) with (16, 17) become - (15, 18)

        Actual code
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());                   // O(N logN)
    vector<vector<int>> ans;

    for(int i = 0; i < n; i++)                      // O(N) // in the sorted subarrays
    {
        int start = arr[i][0];
        int end = arr[i][1];

        if(!ans.empty() && end <= ans.back()[1])    // when there is a big interval and other subarray lying inside it
        {
            continue;                               // this will effect our Time Complexity(will reduce)
        }
        for(int j = i + 1; j < n; j++)              // O(N) // when next subarrays don't lie inside previous interval
        {
            if(arr[j][0] <= end)                    // overlapping situation
            {
                end = max(end, arr[j][1]);
            }
            else
                break;                              // this will effect our Time Complexity(will reduce)
        }
        ans.push_back({start, end});
    }
    return ans;
}

            TC - O(N logN) + O(2N)
            SC - O(N)


                Optimal sol -  we will do it in single iteration 
                                lets take (1, 3), move to next subarray (2, 4) where 2 is smaller than 4 so attah them both
                                now it becomes (1, 4), 
                                then move to next subarray (2, 6) where 2 is smaller than 6 so attach it to (1, 4)
                                now it becomes (1, 6)
                                then moves to (8, 9) where 8 is greater than 6 so we will create new interval
                                and rest will be done as previous

        Actual code
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;

    for(int i = 0; i < n; i++)
    {
        if(ans.empty() || arr[i][0] > ans.back()[1])        // 1 means last from pushed elements
        {
            ans.push_back(arr[i]);
        }
        else
        {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}

            TC - O(N logN) + O(N)               // <- for sorting + pass
            SC - O(N)
*/

int main()
{
    std::cout << "Hello World!\n";
}