#include <algorithm>
#include <benchmark/benchmark.h>
#include <functional>
#include <iostream>
#include <iterator>
#include <map_benchmark.hpp>
#include <random>
#include <vector>
using namespace std;

std::vector<int> generate_random_vector(int size) {
  random_device rnd_device;
  // Specify the engine and distribution.
  mt19937 mersenne_engine{rnd_device()}; // Generates random integers
  uniform_int_distribution<int> dist{1, 5000};

  auto gen = [&dist, &mersenne_engine]() { return dist(mersenne_engine); };
  vector<int> vec(size);
  generate(begin(vec), end(vec), gen);
  return vec;
}

vector<int> v = generate_random_vector(2500);

static void BM_MapSolution_Duplicate(benchmark::State &state) {
  MapSolution s;
  for (auto _ : state)
    s.containsDuplicate(v);
}

BENCHMARK(BM_MapSolution_Duplicate);

static void BM_UnorderedMapSolution_Duplicate(benchmark::State &state) {
  UnorderedMapSolution s;
  for (auto _ : state)
    s.containsDuplicate(v);
}

BENCHMARK(BM_UnorderedMapSolution_Duplicate);

static void BM_FlatHashMap_Duplicate(benchmark::State &state) {
  FlatHashMapSolution s;
  for (auto _ : state)
    s.containsDuplicate(v);
}

BENCHMARK(BM_FlatHashMap_Duplicate);

static void BM_RobinHood_Duplicate(benchmark::State &state) {
  RobinHoodSolution s;
  for (auto _ : state)
    s.containsDuplicate(v);
}

BENCHMARK(BM_RobinHood_Duplicate);

BENCHMARK_MAIN();
