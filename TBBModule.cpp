
module;
#include <random>
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <algorithm>
#include <execution>
#include <tbb/tbb.h>
module TBBModule;


void TBB_test(std::vector<int>& range)
{
	std::for_each(std::execution::par_unseq,
									range.begin(), range.end(),
										[](auto &&item) {
										std::cout << item << std::endl;
										std::random_device dev;
										std::mt19937 rng(dev());
										std::uniform_int_distribution<std::mt19937::result_type> dist6(10, 100);
										std::this_thread::sleep_for(std::chrono::milliseconds(dist6(rng)));
										std::cout << "Thread ID: " << std::this_thread::get_id() << std::endl;
									});
}