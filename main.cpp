//
//  main.cpp
//  AddASUEmail
//
//  Created by redoughe on 1/9/14.
//  Copyright (c) 2014 redoughe. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <vector>

// argv[1] is input file name
// argv[2] is output file name
// argv[3] is string to add
int main(int argc, const char * argv[])
{
	if (argc != 4) {
		std::cout << "Needs input file and string to add" << std::endl;
		return EXIT_FAILURE;
	}
	std::ifstream in_file(argv[1]);
	std::string str;
	std::vector<std::string> vec, result_vec;
	while (std::getline(in_file, str)) {
		vec.push_back(str);
	}
	
	std::for_each(vec.begin(), vec.end(), [&](std::string str) {
		result_vec.push_back(str + argv[3]);
	});
	
	std::ofstream out_file(argv[2]);
	std::copy(result_vec.begin(), result_vec.end(), std::ostream_iterator<std::string>(out_file, "\n"));
}