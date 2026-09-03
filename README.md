# leetcode-cpp

C++17 solutions to LeetCode-style algorithm problems, organized as a buildable,
tested CMake project rather than a loose pile of snippets.

## Structure

```
problems/
  common/
    leetcode_common.h      # shared prelude (see below)
  medium/
    <problem-name>/
      README.md             # original problem statement
      optimal.cpp           # the primary solution
      alternative.cpp       # a different approach (when present)
      modern.cpp            # a third approach using newer STL features (when present)
```

There are 49 problems, most with 2-3 independent solution files, for 91
`.cpp` files total. Every file is a self-contained translation unit with its
own `main()` that runs the solution against the examples from that problem's
`README.md` and prints `[PASS]`/`[FAIL]` per case — these are not just
snippets that compile, they are small executables that demonstrably produce
the right answer.

### The common header

`problems/common/leetcode_common.h` reproduces the environment LeetCode's own
judge provides: the standard STL headers and `using namespace std;`
pre-included, so solutions can be written in the conventional LeetCode style
without repeating a dozen `#include`s in every file. It also defines the one
canonical `ListNode` used by every linked-list problem (previously each such
file defined its own copy, or in one case used `ListNode` without defining it
at all — which would not have compiled).

`using namespace std` at header scope is ordinarily poor practice. It is
deliberately scoped to this one directory of small, independent, LeetCode-style
example programs, matching both these problems' original authored style and
how virtually every published LeetCode solution looks.

## Building and running

```sh
cmake -B build -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build build
ctest --test-dir build --output-on-failure
```

Every `.cpp` file becomes its own executable and its own CTest case (91 in
total); a test passes only if every check inside that file's `main()`
reported `[PASS]`. There are no external dependencies.

## Building in Visual Studio

With 91 independent solution executables and no single "main app", Visual
Studio's Open Folder / CMake integration has nothing to pick as a default
startup item. Without one, pressing **Debug/Run** (not Build) pops a
blocking "Select Startup Item" dialog -- easy to mistake for the project
failing to build, even though **Build > Build All** (Ctrl+Shift+B)
succeeds regardless of what's selected there. `CMakePresets.json` sets
`CMAKE_VS_STARTUP_PROJECT` to `medium__3-sum__alternative` (alphabetically
first target) so Debug/Run works immediately too; pick a different target
from the dropdown next to the Run button to debug any of the others.

## Bugs found and fixed during cleanup

This repository originally had no build system and had never been compiled
as a whole. Bringing every file up to `-Wall -Wextra -Wpedantic`-clean and
giving each one a real, verified `main()` surfaced several genuine bugs,
not just missing scaffolding:

- **`number-of-islands` and `rotting-oranges`** (all variants of both):
  the grid's column bound was computed as `grid.size()` (the row count)
  instead of `grid[0].size()` (the actual column count). On the square
  example grids in each README this happened to produce the right answer,
  but on a non-square grid it silently truncates the scan — or, if there
  are more rows than columns, reads out of bounds. Fixed in all six files;
  each now includes a non-square regression test that fails under the old
  code and passes under the fix.
- **`course-schedule/modern.cpp`**: the adjacency list was built with
  `adj[p[1]].push_back(p)` — pushing the whole prerequisite pair instead of
  just the prerequisite course id `p[0]`. Fixed.
- **`edit-distance/optimal.cpp`**: the DP base case assigned a whole row/
  column vector to an int (`dp[i] = i`) instead of indexing into the 2D
  table (`dp[i][0] = i`). Didn't compile as originally written. Fixed.
- **`perfect-squares/optimal.cpp`**: same class of bug, `dp = 0` instead of
  `dp[0] = 0`. Fixed.
- **`3-sum/alternative.cpp`**: used `std::set` without including `<set>`.
  Fixed.
- **`coin-change/optimal.cpp`**: an unused variable left over from an
  earlier version of the code. Removed.
- Fifteen files compared a signed loop index against an unsigned
  `.size()`/`.length()` (`-Wsign-compare`). Fixed by casting the size to
  `int` at each comparison site, rather than widening the loop variable —
  several of these functions also do signed arithmetic on the same index
  (e.g. `i - prev`) that a wider type would have disturbed.
- **`perfect-squares/alternative.cpp`**: the class was named `Solution2`
  for no evident reason, inconsistent with every other file in the repo
  (including its own `optimal.cpp` sibling). Renamed to `Solution`.

## CI

`.github/workflows/ci.yml` builds and runs the full CTest suite on a
Linux/macOS/Windows matrix on every push and pull request.
