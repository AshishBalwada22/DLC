# DLC

Daily LeetCode, in C++. Solutions filed by month rather than by problem number, because the useful record is the streak and the pattern, not the index.

```
sep2025/    31 problems
oct2025/     9 problems
contest/    weekly-contest-468
```

## What's in it

Beyond the standard array/string/graph grind, the interesting set is the design-an-object problems — the ones LeetCode labels medium but interviewers treat as low-level design:

- `design_a_food_rating_system.cpp` — ordered container + hash map, and why one alone is not enough
- `design_movie_rental_system.cpp` — multi-entity state with invariants across objects
- `design_spreadsheet.cpp` — cell evaluation and dependency handling
- `design_task_manager.cpp` — priority and grouping under mutation

And the graph set, which is where the real practice happened: `pacific_atlantic_water_flow`, `swim_in_rising_water`, `trapping_rain_water_2`.

## Notes kept in the repo

`README.md` at the root of the original history also holds short C++ notes picked up along the way — for example the `stringstream` idioms for tokenising on a delimiter:

```cpp
stringstream ss(str);
string word;
while (ss >> word)        // space-separated
while (getline(ss, word, '.'))   // custom delimiter
```

## Running any solution

```bash
g++ -std=c++17 -O2 sep2025/container_with_most_water.cpp -o sol && ./sol
```
