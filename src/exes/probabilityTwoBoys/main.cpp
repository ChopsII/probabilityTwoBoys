
#include <iostream>
#include <random>

namespace
{
	auto constexpr SAMPLES = 1'000'000'000;
}

int main()
{
	// Seed with a real random value, if available
	std::random_device r;
	std::default_random_engine e1(r());
	std::uniform_int_distribution<int> uniform_dist(0, 1);

	auto totalBoys = 0;
	auto child1Boys = 0;
	auto child2Boys = 0;
	auto numDiscarded = 0;

	auto numTwoBoys = 0;


	for (auto i = 0; i < SAMPLES; ++i)
	{
		auto const child1IsBoy = uniform_dist(e1);
		child1Boys += child1IsBoy;
		totalBoys += child1IsBoy;
		auto const child2isBoy = uniform_dist(e1);
		child2Boys += child2isBoy;
		totalBoys += child2isBoy;

		numDiscarded += (child1IsBoy + child2isBoy == 0) ? 1 : 0;
		numTwoBoys += (child1IsBoy + child2isBoy == 2) ? 1 : 0;
	}

	std::cout << "Total samples: " << SAMPLES << '\n';
	std::cout << "Total discarded: " << numDiscarded << '\n';
	auto const numberOfWomenWithAtLeast1Boy = SAMPLES - numDiscarded;
	std::cout << "Number of women with >= 1 boy: " << numberOfWomenWithAtLeast1Boy << '\n';
	std::cout << "Total boys: " << totalBoys << '\n';
	std::cout << "Number of women with 2 boys: " << numTwoBoys << '\n';
	auto const rateOfWomenWith2Boys = (numTwoBoys * 1.0) / numberOfWomenWithAtLeast1Boy;
	std::cout << "Rate of women with 2 boys: " << rateOfWomenWith2Boys << '\n';
}
