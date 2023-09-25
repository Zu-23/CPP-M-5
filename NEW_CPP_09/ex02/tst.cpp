#include<iostream>
#include<ctime>
#include<unistd.h>
#include<cstdlib>
#include<sys/time.h>
#include<vector>
#include<list>

#include <iostream>
#include <vector>
#include<deque>
#include<algorithm>

void mergeDq(int beg, int mid, int end, std::deque<int> &dq)
{
	int	n1 = mid - beg + 1;
	int	n2 = end - mid;
	int	ri = 0;
	int	li = 0;

	std::deque<int> left(dq.begin() + beg, dq.begin() + mid + 1);
	std::deque<int> right(dq.begin() + mid + 1, dq.begin() + end + 1);
   
    for (int i = beg; i <= end; i++)
	{
		if (ri == n2)
		{
			dq[i] = left[li];
			li++;
		}
		else if (li == n1)
		{
			dq[i] = right[ri];
			ri++;
		}
		else if (right[ri] > left[li])
		{
			dq[i] = left[li];
			li++;
		}
		else
		{
			dq[i] = right[ri];
			ri++;
		}
	}
}

void sortDq(int beg, int end, std::deque<int> &dq)
{
    int treshold = 5;
	if (end - beg > treshold)
	{
		int	mid = (beg + end) / 2;
		sortDq(beg, mid, dq);
		sortDq(mid + 1, end, dq);
		mergeDq(beg, mid, end, dq);
	}
	else
		sort(dq.begin(), dq.end());
}



int main()
{
   srand(time(NULL));
    std::deque<int> dq;
    for (size_t i = 0; i < 7; i++)
    {
        int rnd = rand() % 5;
        std::cout << rnd << " ";
        dq.push_back(rnd);
    }
    std::cout << std::endl;
    
    sortDq(0, dq.size() - 1, dq);
    
    std::deque<int>::iterator it;
    for (it = dq.begin(); it != dq.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}


 // std::deque<int>::iterator it;
    // std::cout << "left" << std::endl;
    // for (it = left.begin(); it != left.end(); it++)
    // {
    //     std::cout << *it << " ";
    // }
    // std::cout << std::endl;
 
    // std::cout << "right" << std::endl;
    // for (it = right.begin(); it != right.end(); it++)
    // {
    //     std::cout << *it << " ";
    // }
    // std::cout << std::endl;
    

    std::cout << "end = " << end << std::endl;
    // int i = 0, j = 0, k = end;
    // while (i < n1 && j < n2)
    // {
    //     if (left[i] <= right[j])
    //     {
    //         dq[k] = left[i];
    //         i++;
    //     }
    //     else
    //     {
    //         dq[k] = right[j];
    //         ++j;
    //     }
    //     ++k;
    // }
    // while (i < n1)
    // {
    //     dq[k] = left[i];
    //     ++i;
    //     ++k;
    // }
    // while(j < n2)
    // {
    //     dq[k] = right[i];
    //     ++j;
    //     ++k;
    // 