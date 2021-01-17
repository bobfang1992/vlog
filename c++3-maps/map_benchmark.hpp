#include <absl/container/flat_hash_map.h>
#include <map>
#include <unordered_map>
#include <robin_hood.h>
#include <vector>


using namespace std;

class MapSolution {
public:
  bool containsDuplicate(const vector<int> &nums) {
    map<int, int> m;
    for (auto i : nums) {
      m[i] += 1;
    }

    for (auto i : m) {
      if (i.second > 1)
        return true;
    }

    return false;
  }
};

class UnorderedMapSolution {
public:
  bool containsDuplicate(const vector<int> &nums) {
    unordered_map<int, int> m;
    for (auto i : nums) {
      m[i] += 1;
    }

    for (auto i : m) {
      if (i.second > 1)
        return true;
    }

    return false;
  }
};

class FlatHashMapSolution {
public:
  bool containsDuplicate(const vector<int> &nums) {
    absl::flat_hash_map<int, int> m;
    for (auto i : nums) {
      m[i] += 1;
    }

    for (auto i : m) {
      if (i.second > 1)
        return true;
    }

    return false;
  }
};

class RobinHoodSolution {
public:
  bool containsDuplicate(const vector<int> &nums) {
    robin_hood::unordered_map<int, int> m;
    for (auto i : nums) {
      m[i] += 1;
    }

    for (auto i : m) {
      if (i.second > 1)
        return true;
    }

    return false;
  }
};