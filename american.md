# Amex Sample Question 
**Description:**
You are given a 3×3 integer matrix grid representing a grid of cells. Each cell contains a certain number of stones, represented by grid[i][j]. The total number of stones across the entire grid is guaranteed to be exactly 9.

In one move, you can transfer one stone from its current cell to any directly adjacent cell (up, down, left, or right).

Return the minimum number of moves required to place exactly one stone in every cell of the grid.

Input:
A 2D array grid of size 3×3.
Output:
An integer representing the minimum total moves.
Constraints:
grid.length == 3
grid[i].length == 3
0≤grid[i][j]≤9
The sum of all elements in grid is exactly 9.

## Solution

```bash
#include <iostream>
using namespace std;
#include <vector>

int performdp(vector<vector<int>> & arr, vector<pair<int, int>>& non, vector<pair<int, int>>& z,vector<bool> & visited, int index)
{
    if(index>=non.size()) return 0;

    int ans = 0;
    int temp_step = INT_MAX;
    if(arr[non[index].first][non[index].second]>1)
    {
        for(int j = 0; j<z.size(); j++)
        {
            if(visited[j])
            {
                visited[j] = false;
                arr[non[index].first][non[index].second]--;
                int curr = abs(non[index].first- z[j].first)+ abs(non[index].second - z[j].second);
                temp_step = min(temp_step,curr+performdp(arr, non, z, visited, index));
                arr[non[index].first][non[index].second]++;
                visited[j] = true;
            }
        }
    }
    else{
        temp_step = min(temp_step, performdp(arr, non, z, visited, index+1));
    }
    return temp_step;
}
int fun(vector<vector<int>> & arr)
{
    vector<pair<int, int>> non;
    vector<pair<int, int>> z;
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            if(arr[i][j]>1)
            non.push_back({i,j});
            if(arr[i][j]==0)
            {
                z.push_back({i,j});
            }
        }
    }
    vector<bool> visited(z.size(), true);
   int ans = performdp(arr, non, z, visited, 0);
   return ans;
}
int main()
{
    vector<vector<int>> v(3, vector<int>(3,0));
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            int x;
            cin>>x;
            v[i][j] = x;
        }
    }
    int ans = fun(v);
    cout<<ans;
    return 0;
}

```



# Pizza Shop Discount Engine 🍕

## Overview

This repository contains a C++ implementation of a **Checkout Pricing Engine** for a pizza delivery application. The system processes a customer's shopping cart and applies various dynamic discount strategies to calculate the final bill.

This project demonstrates Object-Oriented problem solving, array manipulation, greedy algorithms (for maximizing customer savings), and clean standard input/output parsing typical of Machine Coding interview rounds.

## Problem Statement

You are tasked with designing the checkout system for a pizza restaurant. A customer's cart consists of a list of pizzas, where each pizza has a `Size` ("Small", "Medium", or "Large") and a `Price` (double).

The restaurant offers 4 distinct discount schemes. A customer's cart will only ever have **one** active discount scheme applied at checkout. Your system must read the cart contents, apply the chosen discount rules, and output the final checkout price.

### The 4 Discount Schemes

1. **`FLAT_DISCOUNT(threshold, discount_amount)`**
* If the total sum of the cart is $\ge$ `threshold`, subtract `discount_amount` from the total.
* If the total is $<$ `threshold`, no discount is applied.
* *Edge Case:* The final checkout price can never drop below `$0.0`.


2. **`PERCENTAGE_DISCOUNT(percentage)`**
* Apply a flat `percentage` off the total price of all pizzas in the cart.


3. **`BOGO_BY_SIZE` (Buy One Get One)**
* Group pizzas by their exact `Size`.
* For every pair (2 pizzas) within the same size category, the cheaper pizza in that pair becomes free (`$0.0`).
* **Crucial Rule:** To maximize customer savings, the system must pair the most expensive pizzas together.
* Unpaired pizzas (if there is an odd number in a size category) are charged at full price.


4. **`BULK_COMBO`**
* If the cart contains **3 or more** pizzas (regardless of size), the absolute cheapest pizza in the entire cart receives a 50% discount.
* If there are fewer than 3 pizzas, no discount is applied.



---

## Input Format

The system reads from Standard Input (`stdin`) in the following format:

1. An integer `N` representing the total number of pizzas in the cart.
2. The next `N` lines contain a string `Size` and a double `Price` separated by a space.
3. A string `DiscountType` representing the active discount.
4. If the discount requires parameters, they are provided on the next line (e.g., threshold and amount for `FLAT_DISCOUNT`).

## Example Test Cases

### Test Case 1: BOGO By Size

**Input:**

```text
4
Large 20.0
Large 15.0
Large 12.0
Medium 10.0
BOGO_BY_SIZE

```

**Output:**

```text
The final price after the discount is 42

```

*Explanation: The system pairs the $20 and $15 Large pizzas, making the $15 pizza free. The $12 Large and $10 Medium are unpaired. Total: 20 + 0 + 12 + 10 = 42.*

### Test Case 2: Bulk Combo

**Input:**

```text
3
Medium 14.0
Large 20.0
Small 8.0
BULK_COMBO

```

**Output:**

```text
The final amount after the discount is 38

```

*Explanation: There are $\ge 3$ pizzas. The cheapest is the Small at $8.0. It receives a 50% discount ($4.0). Total: 14 + 20 + 4 = 38.*

### Test Case 3: Flat Discount (with zero-floor boundary)

**Input:**

```text
2
Small 10.0
Medium 15.0
FLAT_DISCOUNT
20.0 50.0

```

**Output:**

```text
The meal is free for u, u r a lucky customer

```

*Explanation: Total is $25.0, which meets the $20.0 threshold. Subtracting $50.0 yields -$25.0. The system caps the minimum price at $0.0.*



```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Discount
{
    public:
    void fun1(vector<pair<string, double>> &v, double threshold, double discount_amount){
        double sum = 0;
        for(auto i : v)
        {
            sum+= i.second;
        }
        if(sum>=threshold)
        {
            sum-=discount_amount;
            if(sum<=0)
            cout<<"The meel is free for u, u r a lucky customer"<<endl;
            else
            cout<<"Your final bill after the discount is "<<sum<<endl;
            return;
        }
        else{
            cout<<"The Final amount need to be paid is "<<sum<<endl;
            return;
        }
    }
    void fun1(vector<pair<string , double>> & v, double percentage){
        double sum = 0;
        for(auto i : v)
        {
            sum+= i.second;
        }
        sum = sum-sum*percentage/100;
        cout<<"Final amount after the discount is "<<sum<<endl;
        return;
    }
    void fun1(vector<pair<string, double>> &v, string discounttype){
        if(discounttype == "BOGO_BY_SIZE")
        {
            double sum = 0;
            unordered_map<string,vector<double>> mp;
            for(auto i : v)
            {
                sum+=i.second;
                mp[i.first].push_back(i.second);
            }
            for(auto i : mp)
            {
                sort(i.second.rbegin(), i.second.rend());
                if(i.second.size()>=2)
                {
                    int j = 1;
                    while(j<i.second.size())
                    {
                        sum-=i.second[j];
                        j+=2;
                    }
                }
            }
            cout<<"The final price after the discount is "<<sum<<endl;
            return;
        }
        else{
            int n = v.size();
            if(n>=3)
            {
                sort(v.begin(), v.end(), [](pair<string, double> a, pair<string, double> b){
                    return a.second<b.second;
                });
                double sum = 0;
                v[0].second = v[0].second/2;
                for(auto i : v)
                {
                    sum+=i.second;
                }
                cout<<"The final amount after the discount is "<<sum<<endl;
                return ;
            }
            else{
                double sum = 0;
                for(auto i : v)
                {
                    sum+= i.second;
                }
                cout<<"Sorry you are not elligible for the discount, better luck next time currently pay the amount "<<sum<<endl;
                return;
            }
        }
    }
};
int main()
{
    int n;
    cin>>n;
    vector<pair<string, double>> v;
    for(int i =0 ;i<n; i++)
    {
        string size;
        double price;
        cin>>size>>price;
        v.push_back({size, price});
    }
    string discounttype;
        cin>>discounttype;
        int k;
        Discount d;
        if(discounttype=="FLAT_DISCOUNT")
        {
            k = 2;
            double threshold;
            double amount;
            cin>>threshold>>amount;
            d.fun1(v,threshold, amount);
        }
        else if(discounttype == "PERCENTAGE_DISCOUNT")
        {
            k = 1;
            double percentage;
            cin>>percentage;
            d.fun1(v, percentage);
        }
        else{
            d.fun1(v,discounttype);
        }
        return 0;
    
}

```



# Maximum Points in a Rectangle 🧲

## 📌 Problem Statement

Given `N` points on a 2D plane and a maximum allowed perimeter `P`, find the **maximum number of points** that can be completely enclosed by an axis-aligned rectangle whose perimeter is $\le P$.

* **Constraint Rule:** The perimeter of a rectangle is `2 * (Width + Height)`. Therefore, our working budget is $Width + Height \le P / 2$. Let $K = P / 2$.

---

## 🚀 Intuition & Approach

Solving this blindly in 2D space is too slow. Instead, we use a **Sweep Line + 1D Sliding Window** technique to let the points themselves dictate the boundaries of the rectangle, drastically reducing the search space.

### The 3-Step "Elevator" Algorithm

1. **Sort & Sweep (X-Axis):**
* Sort all points by their X-coordinate.
* Lock a `left` point and stretch a `right` point to define the rectangle's Width ($W$).
* *Early Exit:* If $W > K$, the rectangle is too wide. Break the loop immediately.


2. **1D Reduction (Y-Axis):**
* If $W$ is valid, our maximum allowed Height is $H = K - W$.
* Collect the Y-coordinates of all active points between the `left` and `right` boundaries. Keep this list sorted dynamically using binary search (`lower_bound`) for speed.


3. **The Sliding Window ("The Elevator"):**
* Treat the active Y-coordinates like a vertical ruler.
* Slide a window (representing our allowed Height $H$) from bottom to top.
* Expand the `top` of the window. If the distance between `top` and `bottom` exceeds $H$, shrink the window by moving `bottom` up.
* Count the points inside the valid window and update the global maximum.



---

## 💻 Code Structure

```cpp
// 1. The 1D Sliding Window (O(N))
int getMaxInElevator(const vector<int>& y_coords, int max_height);

// 2. The 2D Sweep Line Router 
int maxPointsInRectangle(vector<vector<int>>& points, int p);

```

*(Include your main `cpp` file in the repository alongside this README).*

---

## ⏱️ Complexity Analysis

* **Time Complexity:**
* $O(N \log N)$ to sort by X-coordinate.
* $O(N^2)$ pairs of Left/Right boundaries.
* For each right boundary expansion, inserting the Y-coordinate and running the window is highly optimized, leading to a practical runtime well within limits for standard OA constraints ($N \le 1000$).


* **Space Complexity:** $O(N)$ to store the active Y-coordinates inside the sweeping boundaries.

---

## 🧪 Quick Test Cases

| Points | Perimeter (P) | Expected Output | Notes |
| --- | --- | --- | --- |
| `[[1,1], [1,3], [3,1], [3,3], [2,2], [5,5]]` | 8 | 5 | Covers the main 3x3 grid cluster. |
| `[[0,0], [0,1], [0,2], [0,3], [0,4]]` | 8 | 5 | Vertical straight line. |
| `[[1,0], [3,0], [5,0], [7,0], [2,10]]` | 12 | 4 | Wide horizontal rectangle. |


``` cpp
#include <iostream>
using namespace std;
#include<vector>
int fun2(vector<int> y, int allow)
{
    int max_points = 0;
    int bottom = 0;
    for(int top = 0; top<y.size(); top++)
    {
        while(y[top]-y[bottom]>allow)
        bottom++;
        int curr_points = top-bottom+1;
        max_points = max(max_points, curr_points);
    }
    return max_points;
}
int fun(vector<vector<int>> & v, int k)
{
    int n = v.size();
    if(n ==0 ) return 0;
    int global_max= 0;
    sort(v.begin(), v.end(),[](vector<int> a, vector<int>b){
        return a[0]<b[0];
    });
    for(int left = 0; left<n; left++)
    {
        vector<int> active_y_corrds;
        for(int right = left; right<n; right++)
        {
            int curr = v[right][0]- v[left][0];
            if(curr>k)
            {
                break;
            }
            int allow = k-curr;
            int new_y = v[right][1];
            auto it = lower_bound(active_y_corrds.begin(), active_y_corrds.end(), new_y);
            active_y_corrds.insert(it, new_y);
            int curr_max = fun2(active_y_corrds, allow);
            global_max = max(global_max, curr_max);
        }
    }
    return global_max;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> v;
    for(int i = 0; i<n; i++)
    {
        int x;
        int y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    int p;
    cin>>p;

    int ans = fun(v, p/2);
    cout<<ans;
    return 0;
}
```
