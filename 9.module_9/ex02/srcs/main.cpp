#include "PmergeMe.hpp"
// #include <chrono>

int main(int argc, char** argv)
{
	PmergeMe list;

	if (argc < 2)
	{
		std::cout << "Usage: ./PmergeMe <set of numbers>" << std::endl;
		return 1;
	}
	else if (argc == 2)
	{
		std::stringstream ss(argv[1]); // Convertit la chaîne de caractères en un flux de lecture
		std::string token;

		while (std::getline(ss, token, ' '))
		{ // Utilise l'espace comme délimiteur
			if (token == "")
				continue; // On ignore les espaces vides (ex: "1 2 3")
			int val = std::stoi(token);
			list.add(val);
		}
	}
	else
	{
		for (int i = 1; i < argc; ++i)
		{ // Commence à 1 pour ignorer le premier argument (nom du programme)
        	int val = std::stoi(argv[i]);
        	list.add(val);
    	}
	}

	srand(time(NULL));

	// auto start = std::chrono::high_resolution_clock::now();
	list.sort();
	// auto end = std::chrono::high_resolution_clock::now();
	// std::chrono::duration<double, std::milli> elapsed = end - start;

	list.print();
	// std::cout << "Elapsed time: " << elapsed.count() << "ms" << std::endl;

	return 0;
}