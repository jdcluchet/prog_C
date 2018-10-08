nclude <iostream> // cout, cin
#include <cmath>    // floor, sqrt
#include <thread>   // thread, hardware_concurrency
#include <atomic>   // atomic
#include <vector>   // vector
#include <chrono>   // steady_clock

typedef unsigned int base_int;

using namespace std;

inline bool IsOdd(base_int const n) // Répond vrai si n est impair
{
	return (n & 1) == 1;
}

inline bool IsPrime(base_int const n) // Répond vrai si n est premier
{
	base_int const fs = floor(sqrt(n)); // Vaut mieux éviter de le re-calculer à chaque fois
	for(base_int k = 2; k <= fs; ++k)
		if(n % k == 0) return false; // % est l'opérateur qui donne le reste de la divison entière. Si le reste est 0, alors n est divisible par k donc n n'est pas premier.
	return true;
}

int main()
{
	atomic<base_int> thread_count(thread::hardware_concurrency());
	atomic<base_int> prime_count(0);
	base_int n;
	
	/*
		Chaque thread va s'occuper de tester des nombres uniquement impairs. On a donc besoin d'un nombre de threads pair, voir la suite.
	*/
	if(IsOdd(thread_count)) --thread_count;
	if(thread_count == 0) thread_count = 2; // On sera un peu plus lent sur les monoprocesseurs ... tant pis.
	
	vector<thread> thread_pool;
	thread_pool.reserve(thread_count);
	
	cout << "Jusqu'a quel nombre voulez vous afficher les nombres premiers ?" << endl;
	cin >> n;
	
	chrono::steady_clock::time_point tp_start = chrono::steady_clock::now();
	
	if(n > 1)
	{
		cout << "2" << endl;
		++prime_count;
		
		for(base_int start = 3, t = 0;
			t < thread_count;
			start += 2, ++t)
			{
				thread_pool.push_back(
					thread([=, &thread_count, &prime_count]()
						{
							
							for(
								base_int a = start; // On commence sur un nombre impair
								a <= n;
								a += thread_count
								/* 
									On reste sur des nombres impairs car les nombres pairs sont divisibles par 2 et sont donc toujours premiers. thread_count est pair.
								*/
								)
							{
								if(IsPrime(a)) 
								{
									++prime_count;
									//cout << n << endl; // Attention : cout est une opération blocante et afficher du text pendant l'opération va sérieusement ralentir le programme. De plus, on utilise des threads et celà va mélanger tout le texte.
								}
							}
							
						}
					)
				);
			}
	}
	
	for(thread & n : thread_pool) n.join();
	thread_pool.clear();
	
	chrono::steady_clock::time_point tp_end = chrono::steady_clock::now();
	
	cout << "Parmi les " << n << " premiers nombre, " << prime_count << " sont premiers (Resultat donne avec " << thread_count << " threads pour " << thread::hardware_concurrency() << " processeurs logiques en " << chrono::duration_cast<chrono::microseconds>(tp_end - tp_start).count() << " microsecondes, soit " << chrono::duration_cast<chrono::seconds>(tp_end - tp_start).count() << " secondes)." << endl;
	
	// pause
	int p;
	cin >> p;
	return 0;
}
